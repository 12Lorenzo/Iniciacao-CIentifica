#include <iostream>
#include "SampleDecoder.h"
#include "MTRand.h"
#include "BRKGA.h"
#include "Instancia.h"
#include "Utils.h"
#include "Decoder.h"

int main(int argc, char* argv[]) {
	const unsigned n = 100;		// size of chromosomes
	const unsigned p = 1000;	// size of population
	const double pe = 0.20;		// fraction of population to be the elite-set
	const double pm = 0.10;		// fraction of population to be replaced by mutants
	const double rhoe = 0.70;	// probability that offspring inherit an allele from elite parent
	const unsigned K = 3;		// number of independent populations
	const unsigned MAXT = 2;	// number of threads for parallel decoding
	
	if(argc < 2){
		std::cout << "Quantidade invalida de paremetros, passar por exemplo: ../../instances/doublecenter/doublecenter-1-n375.txt" << endl;
	}else{
		Instancia inst = Instancia(argv[1]);
		
		//inst.printInst();
		//inst.formaMatDistancias();
		//inst.mostraMatDistancias();
		/*
		Decoder dec;
		
		vector<tuple<int, float, double, double>> crom;

		tuple<int, float, double, double> tupla1, tupla2, tupla3, tupla4, tupla5;

		tupla1 = make_tuple(0, 0.7, 0, 0);
		tupla2 = make_tuple(1, 0.1, 0, 0);
		tupla3 = make_tuple(2, 0.8, 0, 0);
		tupla4 = make_tuple(3, 0.5, 0, 0);
		tupla5 = make_tuple(4, 0.431, 0, 0);

		crom.push_back(tupla1);
		crom.push_back(tupla2);
		crom.push_back(tupla3);
		crom.push_back(tupla4);
		crom.push_back(tupla5);
		
		vector<tuple<int, float, double, double>> crom = dec.formaCromossomo(inst.getNumNos(), inst.getNos());

		dec.mostraCromossomo(crom);
		cout<< endl;
		crom = dec.ordena(crom);
		cout<<endl;
		dec.mostraCromossomo(crom);
		*/
		//std::cout << "Passou";
		//double resul = dec.decode(inst);

		//cout <<"Custo do caminho: " << resul << endl;
	
	
		SampleDecoder decoder;			// initialize the decoder
		Decoder dec;


		const long unsigned rngSeed = 0;	// seed to the random number generator
		MTRand rng(rngSeed);				// initialize the random number generator
		
		// initialize the BRKGA-based heuristic
		BRKGA< SampleDecoder, MTRand > algorithm(n, p, pe, pm, rhoe, decoder, rng, K, MAXT);
		//BRKGA< Decoder, MTRand > algorithm(n, p, pe, pm, rhoe, dec, rng, K, MAXT);
		
		unsigned generation = 0;		// current generation
		const unsigned X_INTVL = 100;	// exchange best individuals at every 100 generations
		const unsigned X_NUMBER = 2;	// exchange top 2 best
		const unsigned MAX_GENS = 1000;	// run for 1000 gens
		do {
			algorithm.evolve();	// evolve the population for one generation
			
			if((++generation) % X_INTVL == 0) {
				algorithm.exchangeElite(X_NUMBER);	// exchange top individuals
			}
		} while (generation < MAX_GENS);
		
		std::cout << "Best solution found has objective value = "
				<< algorithm.getBestFitness() << std::endl;

	
	}
	
	return 0;
}