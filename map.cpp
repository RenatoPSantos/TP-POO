#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"
using namespace std;

string* stringController(string* str){ //controla dimensão da string

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

void printMap(vector<vector<string*>> &map) //imprime ilha
{
    for (int h = 0; h < map.size(); h++)
    {
        for(int i=0;i<(map[0].size()*6)-(map[0].size()-1);i++){
            cout << "-";
        }
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
    for(int i=0;i<(map[0].size()*6)-(map[0].size()-1);i++){
        cout << "-";
    }
}


void createMap(vector<vector<string*>> &map,int rows,int cols) //cria vetores que contêm o mapa
{

    string* line = new string[4];
    line = stringController(line);

    for (int i = 0; i < rows; i++) {
        vector<string*> temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(line);
        }
        map.push_back(temp);
    }

}
void createCells(vector<vector<cell>> &cells,int rows,int cols){

    for(int i = 0;i < rows; i++){
        vector<cell> temp;
        for(int j = 0;j < cols; j++){
            temp.push_back(cell());
        }
        cells.push_back(temp);
    }


}

void cell::getInf(vector<vector<cell>> cells){

    for(int i = 0; i< cells.size();i++){
        for(int j= 0; j < cells[i].size();j++){
            cout << endl;
            cout << cells[i][j].biome << " ";
            cout << cells[i][j].building << " ";
            cout << cells[i][j].nworkers << endl;
        }
    }

}
void cell::changeInf(vector<vector<cell>> &cells, int rows, int cols, string biome, string building){
    cells[rows][cols].biome = biome;
    cells[rows][cols].building = building;
}
cell::cell(){

    biome = "";
    building = "";
    nworkers = 0;

}