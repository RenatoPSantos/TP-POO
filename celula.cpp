#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "celula.h"
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

void printMap(vector<vector<string*>> map)//imprime ilha
{
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


vector<vector<string*>>& createMap(vector<vector<string*>> &map) //cria vetores que contêm o mapa
{
    int cols,rows;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;


    for (int i = 0; i < rows; i++) {
        vector<string*> temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(NULL);
        }
        map.push_back(temp);
    }
    return map;
}