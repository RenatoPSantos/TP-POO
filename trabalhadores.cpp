#include <string>
#include <vector>

#include "trabalhadores.h"
#include "comandos.h"
#include "recursos.h"

using namespace std;

int Trabalhadores::quantity = 0;

Trabalhadores::Trabalhadores(int dia, int salario) :  salario(salario){

        string stringDia,stringWorkers;

        quantity++;

        stringDia = to_string(dia);
        stringWorkers = to_string(quantity);

        id = stringWorkers + '.' + stringDia;

    //fazer resto (tem de gerar id)
}

void Trabalhadores::setSalario(int valor) {

    salario = valor;

}

char Trabalhadores::designacao() {
    return nome;
}