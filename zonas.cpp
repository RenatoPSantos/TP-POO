//
// Created by ssasu on 1/6/2022.
//

#include "zonas.h"

string Zona::designacao() const{
    return nome;
}
void Zona::setProducao (float valor) {
    prod = valor;
}
void Zona::setTotalArvores(float valor) {
    totalArvores = valor;
}
float Zona::getProducao() {
    return prod;
}
float Zona::getTotalArvores() {
    return totalArvores;
}
int Zona::getDiasAtivos() {
    return diasAtivos;
}
void Zona::setDiasAtivos(int valor) {
    diasAtivos = valor;
}


void Zona::setDias(int valor){
    dias = valor;
}
int Zona::getDias() {
    return dias;
}