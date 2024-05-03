#ifndef FIGURA_H
#define FIGURA_H

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef struct
{
    int vertical;
    int horitzontal;
} Posicio;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura);
      
    void incialitza(TipusFigura figura);
    void girar(const DireccioGir& gir);
    void baixar(const int& dirY);
    void moure(const int& dirX);

    int getMida() const { return m_mida; }
    void setPosicio(const Posicio& pos) { m_posicio = pos; }
    ColorFigura getFigura(const int& x,const int& y) const { return m_matriu[x][y]; }
    ColorFigura getColor() const { return m_color; }
    Posicio getPosicio() const { return m_posicio; }
    

private:
    TipusFigura m_tipusFigura;
    ColorFigura m_color;
    Posicio m_posicio;
    ColorFigura m_matriu[MAX_ALCADA][MAX_AMPLADA]; //matriu de la figura

    int m_mida;
};
#endif
