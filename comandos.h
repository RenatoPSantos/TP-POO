#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"


#ifndef TRABALHO_COMANDOS_H
#define TRABALHO_COMANDOS_H


int execCommands(vector<vector<Cell>> &cells, string* comandos); //executa os comandos
int execFile(vector<vector<Cell>> &cells, string *comandos);

void commands(vector<vector<string*>> map,vector<vector<Cell>> &cells); // mostra e gere as verificações de cada comando
bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
void clsConsole(); //dá print em '/n' para limparo ecrã

void checkTypeBuilding(string *comandos, vector<vector<Cell>> &cells); //verifica se o argumento introduzido pelo utilizador é válido e altera a construção na célula indicada pelo utilizador
bool checkBuildings(vector<vector<Cell>> &cells, int rows, int cols); //verifica se numa célula existe algum tipo de construção

bool checkRowsCols(vector<vector<Cell>> &cells, const string& rows, const string& cols); //verifica se as linha/colunas introduzidas pelo utilizador existem no mapa

void list(const string& rows,const string& cols,vector<vector<Cell>> &cells);
void list();
#endif //TRABALHO_COMANDOS_H
