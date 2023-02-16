#ifndef DECODER_H
#define DECODER_H

#include "SampleDecoder.h"
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include "Instancia.h"

class Decoder{

public:
    Decoder();
    ~Decoder();
    
    double decode(const std::vector< double >& chromosome) const;
    double decode(Instancia inst);
    vector<tuple< int, float, double, double>> ordena(vector<tuple<int, float, double, double>> cromossomo);
    vector<tuple<int, float, double, double>> formaCromossomo(int quantNo, vector<pair<double, double>> coords);
    void mostraCromossomo(vector<tuple<int, float, double, double>> cromossomo);

private:
    double distTotal;
};

Decoder::Decoder(){}

Decoder::~Decoder(){}

//A entrada desse decoder é baseado na do SampleDecoder
double Decoder::decode(const std::vector< double >& chromosome) const {
    //std::cout << "Socorro";
    return distTotal;
}

//Esse decode funciona a partir da instancia que é dada como entrada
double Decoder::decode(Instancia inst){
    double distCir = 0;
	vector<tuple< int, float, double, double>> crom = formaCromossomo(inst.getNumNos(), inst.getNos());
    crom = ordena(crom);
    vector<vector<double>> dist = inst.getMatDistancias();
    
    for (int i = 0; i < inst.getNumNos() - 1; i++){
        distCir += dist[get<0>(crom[i])][get<0>(crom[i+1])];        
    }
 
    distCir += dist[get<0>(crom[inst.getNumNos() - 1])][get<0>(crom[0])];

    distTotal = distCir;

    return distCir;
}

//Foi usado o selection sort para ordenar o cromossomo
vector<tuple< int, float, double, double>> Decoder::ordena(vector<tuple< int, float, double, double>> cromossomo){
    int tamCrom = cromossomo.size();
    int min;

    for (auto it = 1; it < tamCrom; ++it){
        min = it;

        for (auto itj = it + 1; itj < tamCrom; ++itj){
            if (get<1>(cromossomo[itj]) < get<1>(cromossomo[min])){
                min = itj;
            }
        }
        if(min != it){
            swap(cromossomo[min], cromossomo[it]);
        }
    }

    return cromossomo;
}

vector<tuple<int, float, double, double>> Decoder::formaCromossomo(int quantNo, vector<pair<double, double>> coords){
    vector<tuple<int, float, double, double>> crom;
    int i;
    srand(time(0));
    for (i = 0; i < quantNo; i++){
        float valAleatorio = static_cast<double>(rand()) / RAND_MAX;
        crom.push_back(make_tuple(i, valAleatorio, coords[i].first, coords[i].second));
    }

    return crom;
}

void Decoder::mostraCromossomo(vector<tuple<int, float, double, double>> cromossomo){
	int x;
    double y;
    int cont = 0;

    for (auto it = cromossomo.begin(); it != cromossomo.end(); ++it) {
        std::cout << "No: " << get<0>(cromossomo[cont]) << " Valor: " << get<1>(cromossomo[cont]) 
                  << " CoordX: " << get<2>(cromossomo[cont]) << " CoordY: " << get<3>(cromossomo[cont]) << std::endl;
        cont++;
    }
}

#endif