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
    int n_workers = workers.size();

public:

    static void getInf(vector<vector<Cell>>);
    static void changeInf(vector<vector<Cell>> &cells, int rows, int cols,string building);


    Cell(string biome);
    ~Cell();
    void setBuilding(string type);
    void destroyBuilding();
    void addWorker(char type);
    string getBiome() const;
    string getBuilding() const;
    vector<char> getWorkers() const;
    int countWorkers() const;

    static bool checkBuildings(vector<vector<Cell>> &cells, int rows, int cols);
    static bool checkTypeBuilding(string* comandos, vector<vector<Cell>> &cells);

    bool checkRowsCols(vector<vector<Cell>> &cells,string rows,string cols);


};

void updateMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells);
void createMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells);
void createCells(vector<vector<Cell>> &cells,int rows,int cols);
void printMap(vector<vector<string*>> &map,vector<vector<Cell>> &cells);


#endif //TRABALHO_MAP_H
