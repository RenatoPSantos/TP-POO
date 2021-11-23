#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"
using namespace std;


Cell::Cell(string biome) : biome(biome) {

}

void Cell::setBuilding(string type) {
    building = type;
}

void Cell::destroyBuilding() {
    building = "";
}

void Cell::addWorker(char type) {
    workers.push_back(type);
}

string Cell::getBiome() const {
    return biome;
}

string Cell::getBuilding() const {
    return building;
}

vector<char> Cell::getWorkers() const {
    return workers;
}

int Cell::countWorkers() const {
    return n_workers;
}

Cell::~Cell() {

}

void Cell::getInf(vector<vector<Cell>> cells){ //usada para debug

    for(int i = 0; i< cells.size();i++){
        for(int j= 0; j < cells[i].size();j++){
            cout << endl;
            cout << cells[i][j].biome << " ";
            cout << cells[i][j].building << " ";
            cout << cells[i][j].n_workers << endl;
        }
    }
}

void Cell::changeInf(vector<vector<Cell>> &cells, int rows, int cols, string building){

    cells[rows][cols].building = building;
}

string* stringController(string* str){ //controla dimensão da string de forma a ocupar 4 caráters por linha

    int counter;
    for(int i = 0; i < 4; i++)
    {
        counter = 0;
        for(auto x: str[i])
            counter++;

        for(int j = 0; j < 4 - counter; j++)
            str[i] += ' ';

    }
    return str;
}
void updateMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //atualiza informação do mapa com informação das cells
{

    for (int i = 0; i < cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < cells[0].size(); j++)
        {
            string* line = new string[4];
            ostringstream oss;
            string str(oss.str());
            for(int x = 0; x < cells[i][j].getWorkers().size(); x++) //conversão de vetor de chars para string usando oss
                oss << x;
            line[0] = cells[i][j].getBiome();
            line[1] = cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(cells[i][j].countWorkers());
            map[i][j] = stringController(line);
        }
    }
}
void printMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //imprime ilha
{
    updateMap(map, cells);
    for (int h = 0; h < map.size(); h++)
    {
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < map[0].size(); j++)
            {
                cout << "|" << (map[h][j])[i] ;
            }
            cout << "|" << endl;
        }
    }

}

void createMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //cria mapa inicial
{
    for (int i = 0; i < cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < cells[0].size(); j++)
        {
            string* line = new string[4];
            ostringstream oss;
            string str(oss.str());
            for(int x = 0; x < cells[i][j].getWorkers().size(); x++) //conversão de vetor de chars para string usando oss
                oss << x;
            line[0] = cells[i][j].getBiome();
            line[1] = cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(cells[i][j].countWorkers());
            stringController(line);
            temp.push_back(line);
        }
        map.push_back(temp);
    }
}

void createCells(vector<vector<Cell>> &cells, int rows, int cols) //cria duplo vetor de objetos (contêm informação)
{
    string random[] = {"mnt", "dsrt", "frst", "pst", "ptn"};

    for (int i = 0; i < rows; i++) {
        vector<Cell> temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(Cell(random[rand() % 5])); //células declaradas com biomas aleatórios
        }
        cells.push_back(temp);
    }
}



