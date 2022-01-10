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
    int quantidade;
public:
    Resources(float preco = 0,float quantidade = 0) : preco(preco) ,quantidade(quantidade){};
    void adicionaResources(int quant);
    int Preco() const;
    int Quantidade() const;
    void setPreco(float preco);
    void setQuantidade(int quantidade);
    void addQuantidade(int quantidade);
    void subtractQuantidade(int quantidade);
};

class Ferro : public Resources{
    
public:
    Ferro(float pre = 1,float quant = 0) : Resources(pre,quant){};
};

class Aco : public Resources{
public:
    Aco(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};

class Carvao : public Resources{
public:
    Carvao(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};

class Madeira : public Resources{
public:
    Madeira(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};

class Vigas : public Resources{
public:
    explicit Vigas(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};

class Eletricidade: public Resources{
public:
    Eletricidade(float pre = 1, float quant = 0) : Resources(pre, quant) {};
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
    void addMoney(float valor);
    void removeMoney(float valor);
    float getMoney();
    Ferro& getFerro();
    Aco& getAco();
    Carvao& getCarvao();
    Madeira& getMadeira();
    Vigas& getVigas();
    Eletricidade& getEletricidade();

};
#endif //TRABALHO_RECURSOS_H
