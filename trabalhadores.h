
#ifndef TRABALHO_TRABALHADORES_H
#define TRABALHO_TRABALHADORES_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "map.h"
#include "comandos.h"
#include "recursos.h"




class Trabalhadores {
    int salario;
    static int quantity = 0;
    string id;
protected:
    char nome;
public:
    Trabalhadores(int dia,int sal = 0);
    char designacao();
    void setSalario(int valor);
};

class Operario : public Trabalhadores{
    int diasDesp = 10;
public:
    Operario(int dia,int sal = 15) : Trabalhadores(dia,sal){nome = 'O';};

};
class Lenhador : public Trabalhadores {
    int diasTrab;
public:
    Lenhador(int dia,int sal = 20) : Trabalhadores(dia,sal) {
        nome = 'L';
        diasTrab = 0;

    };
};
class Mineiro : public Trabalhadores{
    int diasDesp = 2;
public:
    Mineiro(int dia,int sal = 10) : Trabalhadores(dia,sal){nome = 'L';};
};





void cont(vector<vector<Cell>> &cells, string type);
#endif //TRABALHO_TRABALHADORES_H
