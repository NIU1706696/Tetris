#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
	public:
		Tauler();
		Tauler(ColorFigura tauler[MAX_COL][MAX_FILA]);

		ColorFigura getTauler(const int& x, const int& y) const { return m_tauler[x][y]; }
		void setTauler(ColorFigura color, int posX, int posY) { m_tauler[posX][posY] = color; }

		int eliminarFilesPlenes();
		bool esMovimentValid(const Figura& figura,const Posicio& pos) const;
		void eliminarFigura(Figura figura, const Posicio& pos);
		void situarFigura(Figura figura,const Posicio& pos);

	private:
		bool posicioValida(const Posicio& pos) const;
		ColorFigura m_tauler[MAX_COL][MAX_FILA];
};
#endif
