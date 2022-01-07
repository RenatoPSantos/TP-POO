
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




class Trabalhadores {
    int salario;
public:
    Trabalhadores(int sal = 0) : salario(sal){};
};


class Operario : public Trabalhadores{
    int diasDesp = 10;
public:
    Operario(int sal = 15) : Trabalhadores(sal){};

};
class Lenhador : public Trabalhadores {
    int diasTrab;
public:
    Lenhador(int sal = 20) : Trabalhadores(sal) {
        diasTrab = 0;
    };
};
class Mineiro : public Trabalhadores{
    int diasDesp = 2;
public:
    Mineiro(int sal = 10) : Trabalhadores(sal){};
};





void cont(vector<vector<Cell>> &cells, string type);
#endif //TRABALHO_TRABALHADORES_H
