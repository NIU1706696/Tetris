#include "Figura.h"

Figura::Figura()
{
	m_mida = 0;
	m_color = NO_COLOR;
	m_tipusFigura = NO_FIGURA;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}	
	}		
}

Figura::Figura(TipusFigura tipusFigura)
{
	m_mida = 0;
	m_tipusFigura = tipusFigura;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;
	
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}
	}
		
	switch (m_tipusFigura)
	{
	case FIGURA_O:
		m_mida = 2;
		m_color = COLOR_GROC;
		m_matriu[0][0] = COLOR_GROC;
		m_matriu[0][1] = COLOR_GROC;
		m_matriu[1][0] = COLOR_GROC;
		m_matriu[1][1] = COLOR_GROC;
		break;

	case FIGURA_I:
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_matriu[1][0] = COLOR_BLAUCEL;
		m_matriu[1][1] = COLOR_BLAUCEL;
		m_matriu[1][2] = COLOR_BLAUCEL;
		m_matriu[1][3] = COLOR_BLAUCEL;
		break;

	case FIGURA_T:
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_matriu[0][1] = COLOR_MAGENTA;
		m_matriu[1][0] = COLOR_MAGENTA;
		m_matriu[1][1] = COLOR_MAGENTA;
		m_matriu[1][2] = COLOR_MAGENTA;
		break;

	case FIGURA_L:
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_matriu[0][1] = COLOR_TARONJA;
		m_matriu[1][1] = COLOR_TARONJA;
		m_matriu[2][1] = COLOR_TARONJA;
		m_matriu[2][2] = COLOR_TARONJA;
		break;

	case FIGURA_J:
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_matriu[0][1] = COLOR_BLAUFOSC;
		m_matriu[1][1] = COLOR_BLAUFOSC;
		m_matriu[2][0] = COLOR_BLAUFOSC;
		m_matriu[2][1] = COLOR_BLAUFOSC;
		break;

	case FIGURA_Z:
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_matriu[0][0] = COLOR_VERMELL;
		m_matriu[0][1] = COLOR_VERMELL;
		m_matriu[1][1] = COLOR_VERMELL;
		m_matriu[1][2] = COLOR_VERMELL;
		break;

	case FIGURA_S:
		m_mida = 3;
		m_color = COLOR_VERD;
		m_matriu[0][1] = COLOR_VERD;
		m_matriu[0][2] = COLOR_VERD;
		m_matriu[1][0] = COLOR_VERD;
		m_matriu[1][1] = COLOR_VERD;
		break;
	}
}

void Figura::incialitza(TipusFigura tipusFigura)
{
	m_mida = 0;
	m_tipusFigura = tipusFigura;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}		
	}
		

	switch (m_tipusFigura)
	{
	case FIGURA_O:
		m_mida = 2;
		m_color = COLOR_GROC;
		m_matriu[0][0] = COLOR_GROC;
		m_matriu[0][1] = COLOR_GROC;
		m_matriu[1][0] = COLOR_GROC;
		m_matriu[1][1] = COLOR_GROC;
		break;

	case FIGURA_I:
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_matriu[1][0] = COLOR_BLAUCEL;
		m_matriu[1][1] = COLOR_BLAUCEL;
		m_matriu[1][2] = COLOR_BLAUCEL;
		m_matriu[1][3] = COLOR_BLAUCEL;
		break;

	case FIGURA_T:
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_matriu[0][1] = COLOR_MAGENTA;
		m_matriu[1][0] = COLOR_MAGENTA;
		m_matriu[1][1] = COLOR_MAGENTA;
		m_matriu[1][2] = COLOR_MAGENTA;
		break;

	case FIGURA_L:
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_matriu[0][2] = COLOR_TARONJA;
		m_matriu[1][0] = COLOR_TARONJA;
		m_matriu[1][1] = COLOR_TARONJA;
		m_matriu[1][2] = COLOR_TARONJA;
		break;

	case FIGURA_J:
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_matriu[0][0] = COLOR_BLAUFOSC;
		m_matriu[1][0] = COLOR_BLAUFOSC;
		m_matriu[1][1] = COLOR_BLAUFOSC;
		m_matriu[1][2] = COLOR_BLAUFOSC;
		break;

	case FIGURA_Z:
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_matriu[0][0] = COLOR_VERMELL;
		m_matriu[0][1] = COLOR_VERMELL;
		m_matriu[1][1] = COLOR_VERMELL;
		m_matriu[1][2] = COLOR_VERMELL;
		break;

	case FIGURA_S:
		m_mida = 3;
		m_color = COLOR_VERD;
		m_matriu[0][1] = COLOR_VERD;
		m_matriu[0][2] = COLOR_VERD;
		m_matriu[1][0] = COLOR_VERD;
		m_matriu[1][1] = COLOR_VERD;
		break;
	}
}

void Figura::girar(const DireccioGir& gir)
{
	ColorFigura trasposada[MAX_ALCADA][MAX_AMPLADA];
	ColorFigura invertir[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < m_mida; ++i)
	{
		for (int j = 0; j < m_mida; ++j)
		{
			trasposada[j][i] = m_matriu[i][j];
		}
	}
		

	for (int i = 0; i < m_mida; ++i)
	{
		for (int j = 0; j < m_mida; ++j)
		{
			m_matriu[i][j] = trasposada[i][j];
		}	
	}
		
	if (gir == GIR_HORARI)
	{
		for (int i = 0; i < m_mida; ++i)
		{
			for (int j = 0; j < m_mida; ++j)
			{
				invertir[i][j] = m_matriu[i][m_mida - 1 - j];
			}
		}	
	}
	else
	{
		for (int i = 0; i < m_mida; ++i)
		{
			for (int j = 0; j < m_mida; ++j)
			{
				invertir[i][j] = m_matriu[m_mida - 1 - i][j];
			}
		}	
	}
		
	for (int i = 0; i < m_mida; ++i)
	{
		for (int j = 0; j < m_mida; ++j)
		{
			m_matriu[i][j] = invertir[i][j];
		}	
	}		
}

void Figura::moure(const int& dirX)
{
	if (dirX == -1)
		m_posicio.horitzontal--;
	else
		m_posicio.horitzontal++;
}

void Figura::baixar(const int& dirY)
{
	if (dirY == -1)
		m_posicio.vertical--;
	else
		m_posicio.vertical++;
}