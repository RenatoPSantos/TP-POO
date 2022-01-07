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
    void printInfo();

};
class Map{
    vector<vector<Cell>> Cells;
    vector<vector<string*>> Str;
    int rows, cols;

public:
    Map(int rows, int cols); //createmap() e createCell()
    void print(); //imprime mapa
    void printInfo(); //equivale a list()
    void printInfo(const string& rows,const string& cols); //equivale a list
    string* stringController(string* str); //formata strings para impressão do mapa
    void insertBuilding(string *comandos); //constroi edificio
    vector<vector<Cell>>& getCells();
};

#endif //TRABALHO_MAP_H
