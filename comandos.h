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
    string *commands = new string[5];
    Map& mapa;
    Data& data;
    bool next, quit;
public:
    Commands(Map& mapa, Data& data);
    void setCommands(const string& command);
    int execCommands();                                     //executa comandos obtidos na consola
    void clearCommands();                                   //dá clear na string dos comandos


    bool checkArguments(int number) const;                  //verifica se os comandos têm um número certo de argumentos
    void update(const string& command);                     //atualiza comandos guardados pela classe
    void list(const string& rows,const string& cols) const; //obtém informação de uma Cell
    void list() const;                                      //obtém informação geral do jogo
    string listWorkers(char type) const;
    int contTrabalhador(const string& trabalhador);         //contrata um trabalhador
    void setNext(bool state);            
    bool getNext() const;
    bool getQuit() const;
    void vende(const string& tipo,float quant);             //vende recursos
    void vende(int linha,int coluna);                       //vende edificios
    void upgrade(string * commands);                        //upgrade dos edificios
    void efeitos();                                         //efeitos das zonas
    void inf();                                             //informaçao dos recursos/trabalhadores/edificios
    void despedimentos();                                   //despede os funcionarios
    void entregaRecursos();                                 //entrega os recursos no final do dia
    int recolheRecursosElec(int i, int j);
    int recolheRecursosFund(int i, int j);
    void adicionaDias();                                    //adiciona dias trabalhados aos trabalhadores
    int cons(string* commands, int row, int col);           //constroi edificios
    void increaseCapacity(Edificios edificio, float quantidade = 100);
    void decreaseCapacity(Edificios edificio, float quantidade = -100);
    void printScreen() const;
    int execConfig(string nome);
    int countWorkers() const;
};

bool isNumber(const string& s); //verifica se string introduzida pelo utilizador é um número inteiro
bool isNumber(const string &s, bool value);
bool isInteger(const string& s);
void clsConsole(); //dá print em '/n' para limpar o ecrã
int checkTamanho(int rows,int cols);

#endif //TRABALHO_COMANDOS_H