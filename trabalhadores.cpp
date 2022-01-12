#include <string>
#include <vector>

#include "trabalhadores.h"
#include "comandos.h"
#include "recursos.h"

using namespace std;

int Trabalhadores::quantity = 0;

Trabalhadores::Trabalhadores(int dia, int sal, int diasTr) :  salario(sal){

        string stringDia, stringWorkers;


        quantity++;

        stringDia = to_string(dia);
        stringWorkers = to_string(quantity);

        id = stringWorkers + '.' + stringDia;
        diasTrab = diasTr;
}
/* Trabalhadores::Trabalhadores(const Trabalhadores &t){
    salario = t.salario;
    id = t.id;
    diasTrab = t.diasTrab;
} */

void Trabalhadores::setSalario(int valor) {

    salario = valor;

}
void Trabalhadores::addDias(int valor) {
    diasTrab += valor;
}
void Trabalhadores::setDias(int valor){
    diasTrab = valor;
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
int Trabalhadores::getQuantity() const{
    return quantity;
}
void Trabalhadores::setDiasPantano(int valor) {
    diasPantano = valor;
}
int Trabalhadores::getDiasPantano(){
    return diasPantano;
}
int Trabalhadores::getSalario() const{
    return salario;
}