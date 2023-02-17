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
    Decoder(Instancia *inst);
    ~Decoder();
    
    double decode(const std::vector< double >& chromosome) const;
    void mostraCromossomo(vector<tuple<int, float, double, double>> cromossomo);

private:
    Instancia *inst;
};

Decoder::Decoder(Instancia *inst){
    this->inst = inst;
}

Decoder::~Decoder(){}

//A entrada desse decoder é baseado na do SampleDecoder
double Decoder::decode(const std::vector< double >& chromosome) const {
    double distCir = 0;
    vector<pair< double, int>> crom;
    for (unsigned int i = 0; i < chromosome.size(); i++){
        crom.push_back(make_pair(chromosome[i], i));
    }

	sort(crom.begin() + 1, crom.end());
    
    for (int i = 0; i < crom.size() - 1; i++){
        distCir += inst->getDist(crom[i].second, crom[i+1].second);
    }
 
    distCir += inst->getDist(crom[crom.size() - 1].second, 0);

    return distCir;
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