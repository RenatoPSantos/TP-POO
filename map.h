#ifndef TRABALHO_MAP_H
#define TRABALHO_MAP_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "trabalhadores.h"
#include "edificios.h"
#include "zonas.h"
using namespace std;
class Trabalhadores;
class Cell {

    Zona biome;
    Edificios building;
    vector<Trabalhadores> workers;
    int n_workers;

public:
    Cell();
    ~Cell();
    void setBuilding(string type);        //altera a construção da célula
    void setBiome(string type);           //altera o bioma da célula
    void destroyBuilding();               //remove a construção da célula
    void addWorker(Trabalhadores& worker);
    void removeWorker(char type);         //remove trabalhador
    Zona& getBiome();                     //retorna o bioma
    Edificios& getBuilding();             //retorna a construção de uma célula em específico
    vector<Trabalhadores>& getWorkers();  //retorna os trabalhadores de uma célula em específico
    int countWorkers() const;             //retorna o número total de trabalhadores numa célula específica

};

class Map {
    vector<vector<Cell>> Cells;
    vector<vector<string*>> Str;
    int rows, cols;

public:
    Map(int rows, int cols);                                    //createmap() e createCell()
    int getRows();
    int getCols();
    void print();                                               //imprime mapa
    void list(const string& rows,const string& cols);           //equivale a list ()
    string* stringController(string* str);                      //formata strings para impressão do mapa
    bool insertBuilding(string *comandos);                      //constroi edificio
    vector<vector<Cell>>& getCells();                           //obtém mapa de Cells
    bool checkRowsCols(const string& rows, const string& cols); //verifica se as linhas/colunas introduzidas pelo utilizador existem no mapa
    void moveWorker(int r,int c,string id);                     //desloca trabalhador para outra célula
    Trabalhadores& findWorker(string id);
};

#endif //TRABALHO_MAP_H


