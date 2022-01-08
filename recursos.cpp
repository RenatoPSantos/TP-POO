//
// Created by ssasu on 1/6/2022.
//

#include "recursos.h"

void Resources::adicionaResources(int quant) {

    quantidade += quant;
}

int Resources::Preco() const{
    return preco;
}
int Resources::Quantidade() const{
    return quantidade;
}
void Resources::setPreco(float p){
    preco = p;
}
void Resources::setQuantidade(int q){
    quantidade = q;
}

Data::Data(){
    day = 1 ;
    money = 50;
}

Ferro& Data::getFerro(){
    return ferro;
}
Aco& Data::getAco(){
    return aco;
}
Carvao& Data::getCarvao(){
    return carvao;
}
Madeira& Data::getMadeira(){
    return madeira;
}
Vigas& Data::getVigas(){
    return vigas;
}
Eletricidade& Data::getEletricidade(){
    return eletricidade;
}




