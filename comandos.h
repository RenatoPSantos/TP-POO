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
#include "edificios.h"


using namespace std;

class Map;

class Commands{
    string *commands = new string[4];
    Map& mapa;
    Data& data;
    bool next, quit;
   /* vector<Save> saves;*/
public:
    Commands(Map& mapa, Data& data);
    void setCommands(const string& command);
    int execCommands(); //executa comandos obtidos na consola
    int execFile(); //executa comandos obtidos numa file (comando exec)
    int execConfig(vector<string>names,vector<int>values);

    bool checkArguments(int number) const; //verifica se os comandos têm um número certo de argumentos
    void update(const string& command); //atualiza comandos guardados pela classe

    void list(const string& rows,const string& cols) const; //obtém informação de uma Cell
    void list() const; //Obtém informação geral do jogo
    string listWorkers(char type) const;
    int contTrabalhador(string trabalhador);

    void setNext(bool state);
    bool getNext() const;

    void setQuit(bool state);
    bool getQuit() const;

    void vende(string tipo,float quant);
    void vende(int linha,int coluna);
    void upgrade(string * commands);

    void efeitos();
    void despedimentos();
    void entregaRecursos();
    int recolheRecursosElec(int i, int j);
    int recolheRecursosFund(int i, int j);
    void adicionaDias();

    int cons(string* commands, int row, int col);

    void increaseCapacity(Edificios edificio, float quantidade = 100);
    void decreaseCapacity(Edificios edificio, float quantidade = -100);

    void printScreen() const;

    int Commands::execConfig(string nome);

    int countWorkers() const;
    int getProd(string type) const;



    

};

bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
bool isNumber(const string &s, bool value);
bool isInteger(const string& s);
void clsConsole(); //dá print em '/n' para limpar o ecrã
int checkTamanho(int rows,int cols);

#endif //TRABALHO_COMANDOS_H