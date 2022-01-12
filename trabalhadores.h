
#ifndef TRABALHO_TRABALHADORES_H
#define TRABALHO_TRABALHADORES_H
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "comandos.h"
/*#include "recursos.h"*/

using namespace std;


class Trabalhadores {
    int salario;
    static int quantity;
    string id;
    int diasTrab;
    int diasPantano;
protected:
    char nome;
public:
    Trabalhadores(int dia,int sal = 0,int diasTr = 0);
    /* Trabalhadores(const Trabalhadores &t); */
    char designacao();
    void setSalario(int valor);
    int getSalario() const;
    string getId();
    int getDias();
    void setDias(int valor);
    void addDias(int valor);
    int getQuantity() const;

    void setDiasPantano(int valor);
    int getDiasPantano();
};

class Operario : public Trabalhadores{
    int diasDesp = 10;
public:
    Operario(int dia,int sal = 15,int diasTr = 0) : Trabalhadores(dia,sal,diasTr){nome = 'O';};

};
class Lenhador : public Trabalhadores {
    int diasTrab;
public:
    Lenhador(int dia,int sal = 2,int diasTr = 0) : Trabalhadores(dia,sal,diasTr) {
        nome = 'L';
        diasTrab = 0;

    };
};
class Mineiro : public Trabalhadores{
    int diasDesp = 2;
public:
    Mineiro(int dia,int sal = 10,int diasTr = 0) : Trabalhadores(dia,sal,diasTr){nome = 'M';};
};

#endif //TRABALHO_TRABALHADORES_H
