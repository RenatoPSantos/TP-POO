#include <string>
#include <vector>

#include "trabalhadores.h"
#include "comandos.h"
#include "recursos.h"

using namespace std;

int Trabalhadores::quantity = 0;

Trabalhadores::Trabalhadores(int dia, int salario,int diasTr) :  salario(salario){

        string stringDia,stringWorkers;

        quantity++;

        stringDia = to_string(dia);
        stringWorkers = to_string(quantity);

        id = stringWorkers + '.' + stringDia;
        diasTrab = diasTr;


}

void Trabalhadores::setSalario(int valor) {

    salario = valor;

}
void Trabalhadores::addDias(int valor) {
    diasTrab += valor;
}
int Trabalhadores::getDias() {
    return diasTrab;
}
char Trabalhadores::designacao() {
    return nome;
}
string Trabalhadores::getId() {
    return id;
}