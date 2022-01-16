//
// Created by ssasu on 1/6/2022.
//
#ifndef TRABALHO_RECURSOS_H
#define TRABALHO_RECURSOS_H

#include <string>
#include <iostream>

using namespace std;
class Resources {
    float preco;
    float quantidade;
    float capacidade;
public:
    explicit Resources(float preco = 0,float quantidade = 0, float capacidade = 0) : preco(preco) ,quantidade(quantidade), capacidade(capacidade){};
    float Preco() const;
    float Quantidade() const;
    void setQuantidade(float quantidade);
    void addQuantidade(float quantidade);
    float getCapacidade() const;
    void setCapacidade(float valor);
};
class Ferro : public Resources{
public:
    explicit Ferro(float pre = 1,float quant = 0) : Resources(pre,quant){};
};
class Aco : public Resources{
public:
    explicit Aco(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};
class Carvao : public Resources{
public:
    explicit Carvao(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};
class Madeira : public Resources{
public:
    explicit Madeira(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};
class Vigas : public Resources{
public:
    explicit Vigas(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};
class Eletricidade: public Resources{
public:
    explicit Eletricidade(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};

class Data{
    int day;
    float money;
    Ferro& ferro;
    Aco& aco;
    Carvao& carvao;
    Madeira& madeira;
    Vigas& vigas;
    Eletricidade& eletricidade;
public:
    Data(Ferro& ferro, Aco& aco, Carvao& carvao, Madeira& madeira, Vigas& vigas, Eletricidade& eletricidade);
    int getDia() const;
    void setDia(int d);
    void addMoney(float valor);
    void removeMoney(float valor);
    float getMoney() const;
    Ferro& getFerro();
    Aco& getAco();
    Carvao& getCarvao();
    Madeira& getMadeira();
    Vigas& getVigas();
    Eletricidade& getEletricidade();
};
#endif //TRABALHO_RECURSOS_H
