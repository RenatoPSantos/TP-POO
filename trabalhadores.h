
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
    Trabalhadores(int dia,float sal = 0,int diasTr = 0, int diasPa = 0);
    
    char designacao() const;
    float getSalario() const;
    string getId();
    int getDias() const;
    void setDias(int valor);

    void setDiasContratado(int valor);
    int getDiasContratado() const;

    void setDiasPantano(int valor);
    int getDiasPantano() const;
};

class Operario : public Trabalhadores{

public:
    Operario(int dia,int sal = 15,int diasTr = 0, int diasPa = 0) : Trabalhadores(dia,sal,diasTr,diasPa){nome = 'O';};

};
class Lenhador : public Trabalhadores {

public:
    Lenhador(int dia,int sal = 20,int diasTr = 0, int diasPa = 0) : Trabalhadores(dia,sal,diasTr,diasPa) {nome = 'L';
    };
};
class Mineiro : public Trabalhadores{

public:
    Mineiro(int dia,int sal = 10,int diasTr = 0, int diasPa = 0) : Trabalhadores(dia,sal,diasTr,diasPa){nome = 'M';};
};

#endif //TRABALHO_TRABALHADORES_H
