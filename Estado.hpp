#ifndef ESTADO_HPP
#define ESTADO_HPP

#include <vector>
#include "Ponto.hpp"

using namespace std;

class Estado{
    public:
    vector<Ponto>* vec;
    long double dist;
    Estado();
    Estado(vector<Ponto>* v);
    Estado(const Estado& other);
    ~Estado();
    void calculaDist();
    Ponto get(int i);
    Estado geraUmMelhor();
    Estado& operator=(const Estado& other);
};

#endif