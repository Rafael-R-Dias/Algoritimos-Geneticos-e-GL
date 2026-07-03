#ifndef FORMAGEOMETRICA_HPP
#define FORMAGEOMETRICA_HPP

#include "Ponto.h"

class FormaGeometrica2D{
    protected:
    Ponto posicao_;

    public:
    FormaGeometrica2D();
    FormaGeometrica2D(Ponto p);
    virtual Ponto posicao();
    virtual double area();
    virtual double perimetro();
};

#endif