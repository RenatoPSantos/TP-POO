#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"


#ifndef TRABALHO_COMANDOS_H
#define TRABALHO_COMANDOS_H

class Commands{
    string *commands = new string[4];
    Map& mapa;
public:
    Commands(Map& mapa, string command);
    int execCommands();
    int execFile();
    bool checkArguments(int number);
    void update(string command);
};

void commands(Map& mapa); // mostra e gere as verificações de cada comando
bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
void clsConsole(); //dá print em '/n' para limpar o ecrã

bool checkArguments(int number, string *commands );//verifica se comando tem numero de argumentos certo
bool checkRowsCols(vector<vector<Cell>> &cells, const string& rows, const string& cols); //verifica se as linhas/colunas introduzidas pelo utilizador existem no mapa

void list(const string& rows,const string& cols,vector<vector<Cell>> &cells);
void list();
#endif //TRABALHO_COMANDOS_H