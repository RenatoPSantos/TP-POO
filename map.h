#ifndef TRABALHO_MAP_H
#define TRABALHO_MAP_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class cell {

    string biome;
    string building;
    vector<char> workers;
    int nworkers = workers.size();

public:
    cell();
    static void getInf(vector<vector<cell>>);
    static void changeInf(vector<vector<cell>> &cells, int rows, int cols, string biome, string building);

    static int checkBuildings(vector<vector<cell>> &cells,string rows, string cols);
};

void createMap(vector<vector<string*>> &map,int rows,int cols);
void createCells(vector<vector<cell>> &cells,int rows,int cols);
void printMap(vector<vector<string*>> &map);


#endif //TRABALHO_MAP_H
