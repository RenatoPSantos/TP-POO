//
// Created by ssasu on 1/6/2022.
//

#include "recursos.h"
using namespace std;

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
void Resources::addQuantidade(int ammount){
    quantidade += ammount;
}
void Resources::subtractQuantidade(int ammount){
    quantidade -= ammount;
}

Data::Data(Ferro& ferro, Aco& aco, Carvao& carvao, Madeira& madeira, Vigas& vigas, Eletricidade& eletricidade)
: ferro(ferro), aco(aco), carvao(carvao), madeira(madeira), vigas(vigas), eletricidade(eletricidade){
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

void Data::addMoney(float valor) {

    money = money + valor;
}
void Data::removeMoney(float valor){
    money = money - valor;
}
float Data::getMoney() {
    return money;
}
int Data::getDia() const{
    return day;
}



