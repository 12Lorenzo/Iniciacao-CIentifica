#ifndef DECODER_H
#define DECODER_H

#include "SampleDecoder.h"
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include "Instancia.h"

class Decoder{

public:
    Decoder();
    ~Decoder();
    double decode(const std::vector< double >& chromosome) const;
    void ordena(vector<tuple<double, double>> cromossomo);
    void mostraCromossomo(vector<tuple<int, double>> cromossomo);

private:

};

Decoder::Decoder(){}

Decoder::~Decoder(){}

double Decoder::decode(const std::vector<double>& chromosome) const {
    //std::cout << "Socorro";

	Instancia inst;

	vector<tuple<int, double, double, float>> grafo(0);

    return 0;
}

//Antes era ordena(vector<tuple<int, double, double, float>> cromossomo)
void ordena(vector<tuple< double, double>> cromossomo){
	vector<tuple<double, double>>::iterator i = cromossomo.end();

	std::cout << "\n" << get<1>(*i);
}

void Decoder::mostraCromossomo(vector<tuple<int, double>> cromossomo){
	int x;
    double y;

    int cont = 0;

    for (auto it = cromossomo.begin(); it != cromossomo.end(); ++it) {
        //auto [x, y] = *it;
        
        std::cout << "No: " << get<0>(cromossomo[cont]) << " Valor: " << get<1>(cromossomo[cont]) << std::endl;
        cont++;
    }
    std::cout<<"Tamanho do cromossomo: " << cont;
    //std::cout << "\n" << get<0>(cromossomo[0]);
}

#endif