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
    int energy;
public:
    Commands(Map& mapa);
    void setCommands(string command);
    int execCommands(); //executa comandos obtidos na consola
    int execFile(); //executa comandos obtidos numa file (comando exec)
    bool checkArguments(int number) const; //verifica se os comandos têm um número certo de argumentos
    void update(string command); //atualiza comandos guardados pela classe
    void list(const string& rows,const string& cols) const; //obtém informação de uma Cell
    void list() const; //Obtém informação geral do jogo
    void setEnergy(int number); //define número de jogadas que se tem por turno
    int getEnergy(); //obtém energia restante
};

bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
void clsConsole(); //dá print em '/n' para limpar o ecrã


#endif //TRABALHO_COMANDOS_H