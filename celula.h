#ifndef TRABALHO_CELULA_H
#define TRABALHO_CELULA_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class celula {

    string zona;
    string edif;
    vector<char> trabalhadores;
    int totalTrabalhadores;

public:

};

vector<vector<string*>>& createMap(vector<vector<string*>> &map);
void printMap(vector<vector<string*>> *map);


#endif //TRABALHO_CELULA_H
