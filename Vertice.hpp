#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <iostream>
#include <cmath>
using namespace std;

class Vertice{
    public:
        double x,y,z;
        Vertice();
        Vertice(double x, double y, double z=0);
        void set(double x, double y, double z=0);
        void imprime();
        void imprime(char const *msg);
        void imprime(char const *msgAntes, char const *msgDepois);
        void multiplica(double x, double y, double z);
        void soma(double x, double y, double z);
        void versor();
        double modulo();
        void rotacionaX(float angulo);
        void rotacionaY(float angulo);
        void rotacionaZ(float angulo);

        bool operator==(const Vertice& other) const;
};


Vertice ObtemMinimo (Vertice P1, Vertice P2);

Vertice ObtemMaximo (Vertice P1, Vertice P2);

Vertice operator+(Vertice P1, Vertice P2);
Vertice operator- (Vertice P1, Vertice P2);
Vertice operator* (Vertice P1, double k);
Vertice operator-(Vertice P1);

double ProdEscalar(Vertice v1, Vertice v2);
void ProdVetorial (Vertice v1, Vertice v2, Vertice &vresult);
int intersec2d(Vertice k, Vertice l, Vertice m, Vertice n, double &s, double &t);
bool HaInterseccao(Vertice k, Vertice l, Vertice m, Vertice n);

long int getContadorInt();
void resetContadorInt();

int lado(Vertice P1, Vertice P2, Vertice A); // retorna uma das constantes a seguir

enum{
    ESQUERDA,
    DIREITA,
    SOBRE
};


double calculaDistancia(Vertice P, Vertice Q);
#endif /* Ponto_hpp */
