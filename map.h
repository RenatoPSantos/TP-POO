#ifndef TRABALHO_MAP_H
#define TRABALHO_MAP_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Cell {

    string biome;
    string building;
    vector<char> workers;
    int n_workers ;

public:

    Cell(string biome);
    ~Cell();
    void setBuilding(string type);   //altera a construção da célula
    void setBiome(string type);      //altera o bioma da célula
    void destroyBuilding();          //remove a construção da célula
    void addWorker(char type);       //adiciona um trabalhador à célula
    string getBiome() const;         //retorna o bioma
    string getBuilding() const;      //retorna a construção de uma célula em específico
    vector<char> getWorkers() const; //retorna os trabalhadores de uma celula em específico
    int countWorkers() const;        //retorna o número total de trabalhadores em uma célula específica


};

void updateMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells); //atualiza e dá print no mapa
void createMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells); //cria mapa
void createCells(vector<vector<Cell>> &cells,int rows,int cols);           //cria as diversas partes do mapa
void printMap(vector<vector<string*>> &map,vector<vector<Cell>> &cells);   //dá print ao mapa


#endif //TRABALHO_MAP_H
