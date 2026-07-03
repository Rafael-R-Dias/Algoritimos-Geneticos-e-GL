#include "FormaGeometrica2D.hpp"

FormaGeometrica2D::FormaGeometrica2D(){this->posicao_ = Vertice(0.0f,0.0f);}

FormaGeometrica2D::FormaGeometrica2D(Vertice pos){this->posicao_ = pos;}

Vertice FormaGeometrica2D::posicao(){return this->posicao_;}

double FormaGeometrica2D::area(){return 0.0;}

double FormaGeometrica2D::perimetro(){return 0.0;}