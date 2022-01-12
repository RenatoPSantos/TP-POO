//
// Created by ssasu on 1/6/2022.
//

#include "zonas.h"

string Zona::designacao() const{
    return nome;
}
void Floresta::setProducao (int valor) {
    prod = valor;
}
void Floresta::setTotalArvores(int valor) {
    totalArvores = valor;
}
int Floresta::getProducao() {
    return prod;
}
int Floresta::getTotalArvores() {
    return totalArvores;
}
int Floresta::getDiasAtivos() {
    return diasAtivos;
}
void Floresta::setDiasAtivos(int valor) {
    diasAtivos = valor;
}


void Pantano::setDias(int valor){
    dias = valor;
}
int Pantano::getDias() {
    return dias;
}