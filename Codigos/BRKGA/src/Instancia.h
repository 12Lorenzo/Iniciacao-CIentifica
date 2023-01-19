#ifndef INSTANCIA_H
#define INSTANCIA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

class Instancia{
public:
    Instancia();
    Instancia(string nomeArq);
    ~Instancia();

    int getNumNos();

    //Funcao para calcular a distancia entre dois pontos
    double getDist(int no1, int no2);

    vector<vector<double>> getDistancias();

    //Matriz para conter a distancia entre os pontos

    void mostraInst(string nomeArq);
    pair<double, double> formaPairCoord(double coordX, double coordY);
    //vector<tuple<int, double, double, float>> recebeInst(string nomeArq);
    
   
    void printInst();


private:
    float velCam, velDrone;
    int numNos;
    vector<pair<double, double>> nos;
    vector<vector<double>> distancias;
};


#endif