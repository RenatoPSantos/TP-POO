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
void Edificios::setPreco(int valor) {
    preco = valor;
}
bool Edificios::getEstado() {
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
void Edificios::setProducao(float valor) {
    producao = valor;
}
void Edificios::setUpgradeProducao(int valor) {
    producao = valor;
}
float Edificios::getProducao() const {
    return producao;
}
float Edificios::getUpgradeProducao() const {
    return upgradeProducao;
}
void Edificios::setEfeitos(bool valor) {
    efeitos = valor;
}
int Edificios::getArmazenamento() const {
    return armanezamento;
}
void Edificios::setArmazenamento(int valor) {
    armanezamento = valor;
}
int Edificios::getUpgradePrecoVigas() const{
    return upgradePrecoVigas;
}
int Edificios::getUpgradeArmazenamento() const{
    return upgradeArmazenamento;
}