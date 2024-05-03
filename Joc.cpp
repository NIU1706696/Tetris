#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	Posicio posicio;
	int tipus, gir;
	ifstream fitxer;
	m_matriuSituada = false;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> tipus;
		m_matriu.incialitza(TipusFigura(tipus));

		fitxer >> posicio.vertical >> posicio.horitzontal;

		posicio.vertical--;
		posicio.horitzontal--;

		m_matriu.setPosicio(posicio);
		m_posicio = posicio;
		
		fitxer >> gir;
		for (int i = 0; i < gir; i++)
		{
			m_matriu.girar(GIR_HORARI);
		}

		for (int i = 0; i < MAX_COL; i++)
		{
			for (int j = 0; j < MAX_FILA; j++)
			{
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
			}
		}

		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool gira = true;
	m_matriu.girar(direccio);

	if (!m_tauler.esMovimentValid(m_matriu, m_posicio))
	{
		if (direccio == GIR_HORARI)
			m_matriu.girar(GIR_ANTI_HORARI);
		else
			m_matriu.girar(GIR_HORARI);
		gira = false;
	}

	return gira;
}

bool Joc::mouFigura(int dirX)
{
	bool mou = true;
	m_matriu.moure(dirX);

	if (!m_tauler.esMovimentValid(m_matriu, m_matriu.getPosicio()))
	{
		if (dirX == -1)
			m_matriu.moure(1);
		else
			m_matriu.moure(-1);
		mou = false;
	}
	else
		m_posicio = m_matriu.getPosicio();

	return mou;
}

int Joc::baixaFigura()
{
	int nFiles = 0;
	m_matriu.baixar(1);

	if (!m_tauler.esMovimentValid(m_matriu, m_matriu.getPosicio()))
	{
		m_matriu.baixar(-1);
		m_tauler.situarFigura(m_matriu, m_matriu.getPosicio());
		m_matriuSituada = true;
		nFiles = m_tauler.eliminarFilesPlenes();
	}
	else
		m_posicio = m_matriu.getPosicio();

	return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	int i, j;
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		if (!m_matriuSituada)
			m_tauler.situarFigura(m_matriu, m_posicio);

		for (int i = 0; i < MAX_COL; i++)
		{
			for (int j = 0; j < MAX_FILA; j++)
			{
				fitxer << int(m_tauler.getTauler(i, j)) << " ";
			}
			fitxer << endl;
		}

		if(!m_matriuSituada)
			m_tauler.eliminarFigura(m_matriu, m_posicio);
		fitxer.close();
	}
}
