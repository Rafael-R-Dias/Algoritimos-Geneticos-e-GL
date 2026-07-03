#ifndef FORMAGEOMETRICA_HPP
#define FORMAGEOMETRICA_HPP

#include "Vertice.hpp"

class FormaGeometrica2D{
    protected:
    Vertice posicao_;

    public:
    FormaGeometrica2D();
    FormaGeometrica2D(Vertice p);
    virtual Vertice posicao();
    virtual double area();
    virtual double perimetro();
};

#endif