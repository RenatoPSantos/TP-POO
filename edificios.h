

#ifndef TRABALHO_EDIFICIOS_H
#define TRABALHO_EDIFICIOS_H

#include <string>

using namespace std;

class Edificios {

    int preco;
    int precoVigas;
    bool estado;

    bool efeitos;

protected:
    string nome;
    int producao;
    int nivel;
    int upgradeProducao;
    int upgradeArmazenamento;
    int upgradePreco;
    int upgradePrecoVigas;
    int armanezamento;



public:
    Edificios(int pre = 0,int precoVigas = 0,int prod = 0, int nivel = 1,int upgradeProducao = 1,int upgradeArmazenamento = 1, int upgradePreco = 1, int upgradePrecoVigas = 0, int armanezamento = 100,bool estado = 0)
            : preco(pre),precoVigas(precoVigas),producao(prod),upgradeProducao(upgradeProducao),upgradeArmazenamento(upgradeArmazenamento),upgradePreco(upgradePreco),upgradePrecoVigas(upgradePrecoVigas){};
    ~Edificios();
    void upgradeEdificio();
    void liga();
    void desliga();
    void setUpgradeProducao(int valor);
    int getUpgradePreco() const;
    int getPreco() const;
    int getProducao() const;
    int getUpgradeProducao() const;
    int getArmazenamento() const;

    void setProducao(int valor);
    int getNivel() const;
    string designacao();
    int getPrecoVigas() const;
    int getEfeitos();
    void setEfeitos(bool valor);


    void setArmazenamento(int valor);
};

class MinaFerro : public Edificios{

public:
    MinaFerro(int pre = 0 ,int precoVigas = 10,int prod = 2,int upgradeProducao = 1,int upgradeArmazenamento = 10,int upgradePreco = 15 ,int upgradePrecoVigas = 1)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){ nome = "mnf";};
};

class MinaCarvao : public Edificios{
public:
    MinaCarvao(int pre = 0,int precoVigas = 10,int prod = 2,int upgradeProducao = 1,int upgradeArmazenamento = 10,int upgradePreco = 10 ,int upgradePrecoVigas = 1)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){ nome = "mnc";};
};

class CentralEle : public Edificios{
public:
    CentralEle(int pre = 15,int precoVigas = 0,int prod = 0,int upgradeProducao = 0,int upgradeArmazenamento = 0,int upgradePreco = 0 ,int upgradePrecoVigas = 0)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){ nome = "elec";};
};

class Bateria : public Edificios{
public:
    Bateria(int pre = 10,int precoVigas = 10, int prod = 0 ,int upgradeProducao = 0,int upgradeArmazenamento = 20,int upgradePreco = 5 ,int upgradePrecoVigas = 0)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){nome = "bat";};
};

class Fundicao : public Edificios{
public:
    Fundicao(int pre = 10,int precoVigas = 0,int prod = 0,int upgradeProducao = 1,int upgradeArmazenamento = 1,int upgradePreco = 15 ,int upgradePrecoVigas = 0)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){nome = "fun";};
};

class EdificioX: public Edificios{
public:
    EdificioX(int pre = 1,int precoVigas = 0,int prod = 0,int upgradeProducao = 1,int upgradeArmazenamento = 1,int upgradePreco = 15 ,int upgradePrecoVigas = 0)
            : Edificios(pre,precoVigas,prod,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas){nome = "edx";};
};







#endif //TRABALHO_EDIFICIOS_H
