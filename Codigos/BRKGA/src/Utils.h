#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>

int resolTSP1(vector<vector<double>> graph, int tamGraf, int s);


int resolTSP1(vector<vector<double>> graph, int tamGraf, int s)
{
    // Armazena todos os vertices
    vector<int> vertex;
    for (int i = 0; i < tamGraf; i++)
        if (i != s)
            vertex.push_back(i);
	

	int contInte = 0;
    // Armazena o peso minimo do ciclo
    int min_path = INT_MAX;
    do {
 
        // Guarda o peso atual do caminho
        int current_pathweight = 0;
 
        // Calcula o peso do caminho atual
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }

		//for (int i = 0; i < vertex.size(); i++) {
        //	std::cout << vertex.at(i) << ' ';
    	//}
        current_pathweight += graph[k][s];
 
        // Atualiza o minimo
        min_path = min(min_path, current_pathweight);

		//cout <<"Interacao " << contLin << " Caminho minimo no momento: " << min_path << endl;

		contInte++;

    } while (
        next_permutation(vertex.begin(), vertex.end()));
	
	//cout<< "Numero de interacoes: " << contInte;
    return min_path;
}

#endif