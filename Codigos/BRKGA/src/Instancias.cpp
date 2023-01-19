/*
Aparentemente esse arquivo é desnecessario :(
*/
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>

#include "Instancias.h"

using namespace std;
*/
/*
Instancias::Instancias(){ }

Instancias::~Instancias(){ }

void Instancias::mostraInst(string nomePasta, string nomeArq){
    int contLine = 0;
    string line;
    string localPadrao = "/home/lorenzo/Downloads/Ciencia da Computacao UFSCar/Iniciacao Cientifica/Codigos/instances";
    string arq = localPadrao + "/" + nomePasta + "/" + nomeArq;
    ifstream myfile(arq, ios::in); // ifstream = padrão ios:in

    if (myfile.is_open()) {
    
        while (! myfile.eof() ){ //enquanto end of file for false continua
            contLine++;
            getline (myfile,line); // como foi aberto em modo texto(padrão) e não binário(ios::bin) pega cada linha

            cout << "Linha " << contLine << ": ";
            cout << line << endl;
            
        }
        myfile.close();

    } else {
        cout << "Unable to open file";
    }

}

tuple<int, double, double, float> Instancias::formaTuplaCoord(int pos, double coordX, double coordY){
    tuple<int, double, double, float> coords;

    get<0>(coords) = pos;
    get<1>(coords) = coordX;
    get<2>(coords) = coordY;
    get<3>(coords) = 0.0;

    return coords;
}


vector<tuple<int, double, double, float>> Instancias::recebeInst(string nomePasta, string nomeArq){
    //Função para ler informações da entrada
    //e criar nossas triplas que representam nós
    //no grafo.
    
    double velDrone, velCam;
    double coordX, coordY;
    int pos, tam, numNos, contLine = 0, contNos = 0;

    vector<tuple<int, double, double, float>> grafo(0);
    string localPadrao = "/home/lorenzo/Downloads/Ciencia da Computacao UFSCar/Iniciacao Cientifica/Codigos/instances";
    string line;
    string arq = localPadrao + "/" + nomePasta + "/" + nomeArq;
    //cout << "\nlocal do arquivo: " << arq;
    ifstream myfile(arq, ios::in); // ifstream = padrão ios:in

    //mostraInst("doublecenter", "doublecenter-1-n5.txt");

    if (myfile.is_open()) {
    
        while (! myfile.eof() ){ //enquanto end of file for false continua
            contLine++;
            getline (myfile,line); // como foi aberto em modo texto(padrão)
                             //e não binário(ios::bin) pega cada linha
            
            //A função find ela retorna a primeira posição do caracter passado, a partir do ponto que começou a procurar
            //nesse caso ele vai procurar a primeira ocorrencia de " "(espaço) a partir da primeira posição da string
            pos = line.find(" ", 0);

            if(contLine == 2){
                
                //cout << "\nLin 2: " << line << "\n";
                velCam = stod(line);
                //cout << velCam;
            } else if(contLine == 4){
                
                //cout << "lin4: " << line.substr(0, pos);
                velDrone = stod(line);
            } else if(contLine == 6) {
                
                //cout << "lin6: " << line.substr(0, pos);
                numNos = stoi(line);
            } else if(line[0] != '/' && contLine > 7 && pos != EOF){
                //cout << "Frase";
                
                //cout << "\nPosicao: " << pos;
                //cout << "\nCoordenada X:" << line.substr(0, pos);
                coordX = stod(line.substr(0, pos));

                tam = pos+1;
                pos = line.find(" ", pos+1);
                //cout << "\nCoordeanada Y: " << line.substr(tam, pos-tam) << "\n";
                //A função substr retorna a string no intervalo passado
                coordY = stod(line.substr(tam, pos-tam));

                grafo.push_back(formaTuplaCoord(contNos, coordX, coordY));

                contNos++;
            }
            
            //cout << "\nX: " << coordX << "Y: " << coordY;
        }
        myfile.close();
        //cout << "Numero de linhas do arquivo: " << contLine;
        //cout << "Velocidade Caminhao: " << velCam << "\nVelocidade Drone: " << velDrone << "\nNumero de nos: " << numNos << "\nCoordenada x: " << coordX << "\nCoordenada y: " << coordY;
        
    } else {
        cout << "Unable to open file";
    } 


   return grafo;
}

template<typename T>
void Instancias::printVectorElements(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++){
        cout << "(" << get<0>(vec[i]) << ", " 
             << get<1>(vec[i]) << ", " 
             << get<2>(vec[i]) << ")\n";
    }

    cout << endl;
}
*/
/*
int main(){

    vector<tuple<int, double, double>> grafo(0);

    grafo = recebeInst("doublecenter", "doublecenter-11-n375.txt");

    pair<double, double> coords;
    coords.first = 1;
    coords.second = 2;

    vector<pair<double, double>> nos(0);

    nos.push_back(coords);

    cout << "\nElementos do grafo: \n"; printVectorElements(grafo);

    return 0;
}*/