//
// Created by ssasu on 1/6/2022.
//
#include <iostream>


using namespace std;

#include "edificios.h"

Edificios::~Edificios() {

}

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
int Edificios::getUpgradePreco() const{
    return upgradePreco;
}
int Edificios::getPreco() const{
    return preco;
}
int Edificios::getNivel() const{
    return nivel;
}
int Edificios::getPrecoVigas() const{
    return precoVigas;
}
int Edificios::getEfeitos() {
    return efeitos;
}
void Edificios::setProducao(int valor) {
    producao = valor;
}
void Edificios::setUpgradeProducao(int valor) {
    producao = valor;
}
int Edificios::getProducao() const {
    return producao;
}
int Edificios::getUpgradeProducao() const {
    return upgradeProducao;
}
void Edificios::setEfeitos(bool valor) {
    efeitos = valor;
}