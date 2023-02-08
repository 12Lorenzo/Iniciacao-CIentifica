#include "SampleDecoder.h"
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include "Instancia.h"

#include "Decoder.h"


SampleDecoder::SampleDecoder() { }

SampleDecoder::~SampleDecoder() { }


/*
lerInstancias() seja n o numero de vertices incluindo o deposito
decode(cromosso) vai ter n-1 alellos por cromossomo, um para cada vertice que nao e deposito
obs: ordenar o alelos do cromosso pelo seu valor, definindo assim a ordem em que os vertices sao visitados
Ex: n = 5
				  0    1    2    3
	cromossomo = 0.1, 0.7, 0.5, 0.2
	
	
	vetorParOrd = (0.1, 0), (0.2, 3), (0.5, 2), (0.7, 1)
	Corresponde ao circuito: deposito -> 0 -> 3 -> 2 -> 1 -> deposito
	fitnessCrom = dist(circuito)
*/

Decoder::Decoder(){}

Decoder::~Decoder(){}

//Passar 
double Decoder::decode(const std::vector< double >& chromosome) const {
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
	std::cout << "\n" << get<0>(cromossomo[0]);
}

/*
int main(){

	Instancia inst;
	vector<tuple<int, double, double, float>> cromossomo = inst.recebeInst("doublecenter", "doublecenter-11-n375.txt");
	//inst.printVectorElements(cromossomo);

	ordena(cromossomo);

	return 0;
}*/