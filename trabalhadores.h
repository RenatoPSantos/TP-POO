
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
    float salario;
    static int quantity;
    string id;
    int diasContratado;
    int diasTrab;
    int diasPantano;
protected:
    char nome;
public:
    Trabalhadores(int dia,int sal = 0,int diasTr = 0);
    /* Trabalhadores(const Trabalhadores &t); */
    char designacao() const;
    void setSalario(float valor);
    float getSalario() const;
    string getId();
    int getDias() const;
    void setDias(int valor);
    void addDias(int valor);
    int getQuantity() const;

    void setDiasContratado(int valor);
    int getDiasContratado() const;

    void setDiasPantano(int valor);
    int getDiasPantano() const;
};

class Operario : public Trabalhadores{

public:
    Operario(int dia,int sal = 15,int diasTr = 0) : Trabalhadores(dia,sal,diasTr){nome = 'O';};

};
class Lenhador : public Trabalhadores {

public:
    Lenhador(int dia,int sal = 2,int diasTr = 0) : Trabalhadores(dia,sal,diasTr) {nome = 'L';
    };
};
class Mineiro : public Trabalhadores{

public:
    Mineiro(int dia,int sal = 10,int diasTr = 0) : Trabalhadores(dia,sal,diasTr){nome = 'M';};
};

#endif //TRABALHO_TRABALHADORES_H
