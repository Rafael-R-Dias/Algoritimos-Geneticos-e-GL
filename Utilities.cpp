#include "Utilities.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

vector<Ponto>* leArq(const char* fname){
    ifstream arq = ifstream(fname);

    if(!arq.is_open()){
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(0);
    }

    vector<Ponto>* v = new vector<Ponto>();

    string linha;
    string coluna;
    float x,y;
    getline(arq, linha);
    while(getline(arq, linha)){
        stringstream ss(linha);
        
        getline(ss, coluna, ',');
        //cout << "id: " << coluna;
        getline(ss, coluna, ',');
        //cout << "  nome: " << coluna;
        getline(ss, coluna, ',');
        //cout << "  x: " << coluna;
        x = stof(coluna);
        x += 30.0f;
        x *= 20.0f;
        getline(ss, coluna, ',');
        //cout << "  y: " << coluna << endl;
        y = stof(coluna);
        y += 50.0f;
        y *= 20.0f;
        v->push_back(Ponto(x,y));
    }

    arq.close();
    return v;
}