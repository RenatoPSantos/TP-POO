//
// Created by ssasu on 1/6/2022.
//

#include "zonas.h"

string Zona::designacao() const{
    return nome;
}

void Zona::setTotalArvores(float valor) {
    totalArvores = valor;
}
float Zona::getProducao() const {
    return prod;
}
float Zona::getTotalArvores() const {
    return totalArvores;
}
int Zona::getDiasAtivos() const {
    return diasAtivos;
}
void Zona::setDiasAtivos(int valor) {
    diasAtivos = valor;
}


void Zona::setDias(int valor){
    dias = valor;
}
int Zona::getDias() const {
    return dias;
}