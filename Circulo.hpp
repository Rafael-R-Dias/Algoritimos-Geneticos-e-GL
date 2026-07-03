#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "FormaGeometrica2D.hpp"

class Circulo : FormaGeometrica2D{
    private:
    double raio_;

    public:
    Circulo();
    Circulo(Vertice p, double r);
    Vertice posicao() override;
    double raio();
    double area() override;
    double perimetro() override;
};

#endif