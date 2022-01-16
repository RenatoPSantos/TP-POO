#include <string>


#include "trabalhadores.h"

using namespace std;

int Trabalhadores::quantity = 0;

Trabalhadores::Trabalhadores(int dia, float sal, int diasTr,int diasPa) :  salario(sal){

        string stringDia, stringWorkers;
        nome = ' ';




        quantity++;

        stringDia = to_string(dia);
        stringWorkers = to_string(quantity);

        id = stringWorkers + '.' + stringDia;
        diasTrab = diasTr;
        diasPantano = diasPa;
        diasContratado = 0;
}



void Trabalhadores::setDias(int valor){
    diasTrab = valor;
}
int Trabalhadores::getDias() const {
    return diasTrab;
}
char Trabalhadores::designacao() const {
    return nome;
}
string Trabalhadores::getId() {
    return id;
}
void Trabalhadores::setDiasPantano(int valor) {
    diasPantano = valor;
}
int Trabalhadores::getDiasPantano() const{
    return diasPantano;
}
float Trabalhadores::getSalario() const{
    return salario;
}

void Trabalhadores::setDiasContratado(int valor) {
    diasContratado = valor;
}

int Trabalhadores::getDiasContratado() const {
    return diasContratado;
}
