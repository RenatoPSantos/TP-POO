#ifndef TRABALHO_COMANDOS_H
#define TRABALHO_COMANDOS_H

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"
#include "recursos.h"

using namespace std;

class Map;

class Commands{

    string *commands = new string[4];
    Map& mapa;
    Data& data;
    bool next;
public:
    Commands(Map& mapa, Data& data);
    void setCommands(string command);
    int execCommands(); //executa comandos obtidos na consola
    int execFile(); //executa comandos obtidos numa file (comando exec)
    bool checkArguments(int number) const; //verifica se os comandos têm um número certo de argumentos
    void update(string command); //atualiza comandos guardados pela classe
    void list(const string& rows,const string& cols) const; //obtém informação de uma Cell
    void list() const; //Obtém informação geral do jogo
    void setNext(bool state);
    bool getNext() const;
    void vende(string tipo,int quant);
    void vende(int linha,int coluna);
    void efeitos();
    int cons(string* commands, int row, int col);


};

bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
bool isInteger(const string& s);
void clsConsole(); //dá print em '/n' para limpar o ecrã


#endif //TRABALHO_COMANDOS_H