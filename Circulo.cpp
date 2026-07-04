#include "Circulo.hpp"

Circulo::Circulo(){
    this->posicao_ = Vertice(0.0f,0.0f);
    this->raio_ = 0.0;
}

Circulo::Circulo(Vertice pos, double r){
    this->posicao_ = pos;
    if(r < 0.0) r *= -1.0;
    this->raio_ = r;
}

Vertice Circulo::posicao(){return this->posicao_;}

double Circulo::raio(){return this->raio_;}

double Circulo::area(){return M_PI * pow(this->raio_, 2.0);}

double Circulo::perimetro(){return 2.0*M_PI*this->raio_;}