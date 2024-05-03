#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
	{
		for (int j = 0; j < MAX_FILA; j++)
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}
	}	
}

Tauler::Tauler(ColorFigura tauler[MAX_COL][MAX_FILA])
{
	for (int i = 0; i < MAX_COL; i++)
	{
		for (int j = 0; j < MAX_FILA; j++)
		{
			m_tauler[i][j] = tauler[i][j];
		}
	}	
}

bool Tauler::posicioValida(const Posicio& pos) const 
{
	bool esCorrecte = true;

	if (0 > pos.horitzontal || pos.horitzontal >= MAX_FILA || pos.vertical >= MAX_COL )
		esCorrecte = false;

	else
	{
		if (m_tauler[pos.vertical][pos.horitzontal] != COLOR_NEGRE)
			esCorrecte = false;
	}

	return esCorrecte;
}

bool Tauler::esMovimentValid(const Figura& figura,const Posicio& pos) const
{
	bool esCorrecte = true;
	int i = 0;

	while (i < figura.getMida() && esCorrecte)
	{
		int j = 0;
		while (j < figura.getMida() && esCorrecte)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				Posicio pos_pos;
				pos_pos.vertical = pos.vertical + i;
				pos_pos.horitzontal = pos.horitzontal + j;

				esCorrecte = posicioValida(pos_pos);
			}
			j++;
		}
		i++;
	}

	return esCorrecte;
}

int Tauler::eliminarFilesPlenes()
{
	int nCompletades = 0;

	for (int i = 0; i < MAX_FILA; ++i)
	{
		bool completada = true;
		int j = 0;

		while (j < MAX_COL && completada)
		{
			if (m_tauler[i][j] == 0) 
			{
				completada = false;
			}
			j++;
		}

		if (completada)
		{
			nCompletades++;
			for (int fila = i; fila > 0; --fila)
			{
				for (int k = 0; k < MAX_COL; ++k)
				{
					m_tauler[fila][k] = m_tauler[fila - 1][k];
				}
			}
				
			for (int k = 0; k < MAX_COL; ++k)
			{
				m_tauler[0][k] = COLOR_NEGRE;
			}	
		}
	}
	return nCompletades;
}

void Tauler::eliminarFigura(Figura figura, const Posicio& pos)
{
	for (int i = 0; i < figura.getMida(); i++)
	{
		for (int j = 0; j < figura.getMida(); j++)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = COLOR_NEGRE;
			}
		}	
	}	
}

void Tauler::situarFigura( Figura figura,const Posicio& pos) //considerem que és vàlida
{
	for (int i = 0; i < figura.getMida(); i++)
	{
		for (int j = 0; j < figura.getMida(); j++)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = figura.getColor();
			}
		}
	}
		
	figura.setPosicio(pos);
}