#include "Utilities.hpp"
#include <fstream>
#include <string>
#include <sstream>

vector<Vertice>* leArq(const char* fname, unsigned int limit){
    ifstream arq = ifstream(fname);

    if(!arq.is_open()){
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(0);
    }

    vector<Vertice>* v = new vector<Vertice>();

    string linha;
    string coluna;
    double x,y;
    getline(arq, linha);
    while(getline(arq, linha)){
        stringstream ss(linha);
        
        getline(ss, coluna, ',');
        //cout << "id: " << coluna;
        getline(ss, coluna, ',');
        //cout << "  nome: " << coluna;
        getline(ss, coluna, ',');
        //cout << "  x: " << coluna;
        x = stod(coluna);
        if(x < -20000.0) continue;
        //x += (30.0 + 6.0/64.0);
        //x *= 1.0;
        getline(ss, coluna, ',');
        //cout << "  y: " << coluna << endl;
        y = stod(coluna);
        if(y < -20000.0) continue;
        //y += (51.0 + 5.0/32.0);
        //y *= 1.0;
        v->push_back(Vertice(x,y));
        if(v->size() >= limit) break;
    }

    arq.close();
    return v;
}