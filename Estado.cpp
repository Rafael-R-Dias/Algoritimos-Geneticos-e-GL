#include "Estado.hpp"
#include <random>

Estado::Estado(){
    this->vec = nullptr;
    this->dist = 0.0;
}

Estado::Estado(vector<Ponto>* v){
    this->vec = v;
    this->calculaDist();
}

Estado::Estado(const Estado& other){
    if(other.vec) this->vec = new vector<Ponto>(*other.vec);
    else this->vec = nullptr;
    
    this->dist = other.dist;
}

Estado::~Estado(){
    delete this->vec;
}

void Estado::calculaDist(){
    this->dist = 0.0;
    for(int i = 0; i < this->vec->size()-1; i++){
        this->dist += calculaDistancia((*this->vec)[i], (*this->vec)[i+1]);
    }
    this->dist += calculaDistancia((*this->vec)[(*this->vec).size()-1], (*this->vec)[0]);
}

Ponto Estado::get(int i){
    return this->vec->at(i);
}

Estado Estado::geraUmMelhor(){
    vector<Ponto>* m = new vector<Ponto>(*this->vec);
    Estado melhor;
    melhor.vec = m;
    melhor.dist = this->dist;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(0, m->size()-1);
    int i1, i2;
    while(true){
        i1 = distr(gen);
        do{
            i2 = distr(gen);
        }while(i1 == i2);

        Ponto aux = (*m)[i1];
        (*m)[i1] = (*m)[i2];
        (*m)[i2] = aux;
        melhor.calculaDist();
        if(this->dist <= melhor.dist){
            aux = (*m)[i1];
            (*m)[i1] = (*m)[i2];
            (*m)[i2] = aux;
        }else break;
    }

    return melhor;
}

Estado& Estado::operator=(const Estado& other){
    if(this == &other) return *this;

    delete this->vec;
    if(other.vec) this->vec = new vector<Ponto>(*other.vec);
    else this->vec = nullptr;
    
    this->dist = other.dist;
    return *this;
}