//
// Created by ssasu on 1/6/2022.
//
#include <iostream>


using namespace std;

#include "edificios.h"

Edificios::~Edificios() {}

void Edificios::upgradeEdificio(){

    if(nivel == 5){
        cout << "Nivel maximo do edificio atingido" << endl;
        return;
    }
/*

    if(....){


    producao += upgradeProducao;
    armanezamento += upgradeArmazenamento;
    nivel++;

   }
*/
}
void Edificios::liga() {

    estado = 1;
}
void Edificios::desliga(){
    estado = 0;
}
string Edificios::designacao() {
    return nome;
}