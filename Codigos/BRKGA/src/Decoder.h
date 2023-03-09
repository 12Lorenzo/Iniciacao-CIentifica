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
    void mostraCromossomo(vector<pair<double, int>> cromossomo);

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

void Decoder::mostraCromossomo(vector<pair<double, int>> cromossomo){

    for (auto it = 0; it != cromossomo.size(); ++it) {
        std::cout << "No: " << cromossomo[it].second << " Valor: " << cromossomo[it].first << std::endl;
    
    }
}

#endif