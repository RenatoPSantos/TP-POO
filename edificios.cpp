//
// Created by ssasu on 1/6/2022.
//
#include <iostream>
#include <string>

using namespace std;

#include "edificios.h"

Edificios::~Edificios() {

}

void Edificios::upgradeEdificio(){

    if(nivel == 5){
        cout << "Nivel maximo do edificio atingido" << endl;
        return;
    }
    if(nivel < 5){
    producao += upgradeProducao;
    nivel++;
   }
}

bool Edificios::getEstado() const {
    return estado;
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

float Edificios::getUpgradePreco() const{
    return upgradePreco;
}
float Edificios::getPreco() const{
    return preco;
}
float Edificios::getNivel() const{
    return nivel;
}
float Edificios::getPrecoVigas() const{
    return precoVigas;
}
int Edificios::getEfeitos() const {
    return efeitos;
}
float Edificios::getProducao() const {
    return producao;
}
float Edificios::getUpgradeProducao() const {
    return upgradeProducao;
}
float Edificios::getUpgradePrecoVigas() const{
    return upgradePrecoVigas;
}
float Edificios::getUpgradeArmazenamento() const{
    return upgradeArmazenamento;
}
float Edificios::getArmazenamento() const {
    return armanezamento;
}

void Edificios::setEfeitos(bool valor) {
    efeitos = valor;
}
void Edificios::setPreco(float valor) {
    efeitos = valor;
}
void Edificios::setProducao(float valor) {
    producao = valor;
}
void Edificios::setUpgradeProducao(float valor) {
    upgradeProducao = valor;
}

