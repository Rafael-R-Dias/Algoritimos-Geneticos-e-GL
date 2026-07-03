#ifndef ESTADO_HPP
#define ESTADO_HPP

#include <vector>
#include "Vertice.hpp"

using namespace std;

class Estado{
    public:
    vector<Vertice>* vec;
    long double dist;
    Estado();
    Estado(vector<Vertice>* v);
    Estado(const Estado& other);
    ~Estado();
    void calculaDist();
    Vertice get(int i);
    Estado geraUmMelhor();
    Estado& operator=(const Estado& other);
};

#endif