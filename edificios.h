

#ifndef TRABALHO_EDIFICIOS_H
#define TRABALHO_EDIFICIOS_H

#include <string>

using namespace std;

class Edificios {

    float preco;
    float precoVigas;
    bool estado;

    bool efeitos;

protected:
    string nome;
    float producao;
    float nivel;
    float upgradeProducao;
    float upgradeArmazenamento;
    float upgradePreco;
    float upgradePrecoVigas;
    float armanezamento;



public:
    Edificios(float pre = 0,float precoVigas = 0,float prod = 0, float nivel = 1,float upgradeProducao = 1,float upgradeArmazenamento = 1, float upgradePreco = 1, float upgradePrecoVigas = 0, float armanezamento = 100,bool estado = 0 ,bool efeitos = 0)
            : preco(pre),precoVigas(precoVigas),producao(prod),nivel(nivel),upgradeProducao(upgradeProducao),upgradeArmazenamento(upgradeArmazenamento),upgradePreco(upgradePreco),upgradePrecoVigas(upgradePrecoVigas),armanezamento(armanezamento),estado(estado),efeitos(efeitos){};
    ~Edificios();
    void upgradeEdificio();
    void liga();
    void desliga();
    bool getEstado();
    void setUpgradeProducao(float valor);
    void setPreco(float valor);
    float getUpgradePreco() const;
    float getUpgradePrecoVigas() const;
    float getUpgradeArmazenamento() const;
    float getPreco() const;
    float getProducao() const;
    float getUpgradeProducao() const;
    float getArmazenamento() const;

    void setProducao(float valor);
    float getNivel() const;
    string designacao();
    float getPrecoVigas() const;
    int getEfeitos();
    void setEfeitos(bool valor);


    void setArmazenamento(float valor);
};

class MinaFerro : public Edificios{

public:
    MinaFerro(float pre = 0 ,float precoVigas = 10,float prod = 2,float nivel = 1,float upgradeProducao = 1,float upgradeArmazenamento = 10,float upgradePreco = 15 ,float upgradePrecoVigas = 1, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){ nome = "mnf";};
};

class MinaCarvao : public Edificios{
public:
    MinaCarvao(float pre = 0,float precoVigas = 10,float prod = 2,float nivel = 1,float upgradeProducao = 1,float upgradeArmazenamento = 10,float upgradePreco = 10 ,float upgradePrecoVigas = 1, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){ nome = "mnc";};
};

class CentralEle : public Edificios{
public:
    CentralEle(float pre = 15,float precoVigas = 0,float prod = 1,float nivel = 1,float upgradeProducao = 0,float upgradeArmazenamento = 0,float upgradePreco = 0 ,float upgradePrecoVigas = 0, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){ nome = "elec";};
};

class Bateria : public Edificios{
public:
    Bateria(float pre = 10,float precoVigas = 10, float prod = 0 ,float nivel = 1,float upgradeProducao = 0,float upgradeArmazenamento = 20,float upgradePreco = 5 ,float upgradePrecoVigas = 0, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){nome = "bat";};
};

class Fundicao : public Edificios{
public:
    Fundicao(float pre = 10,float precoVigas = 0,float prod = 1,float nivel = 1,float upgradeProducao = 0,float upgradeArmazenamento = 0,float upgradePreco = 0 ,float upgradePrecoVigas = 0, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){nome = "fun";};
};
class Serracao : public Edificios{

public:
    Serracao(float pre = 10 ,float precoVigas = 0,float prod = 2,float nivel = 1,float upgradeProducao = 1,float upgradeArmazenamento = 10,float upgradePreco = 20 ,float upgradePrecoVigas = 0, float armanezamento = 100,bool estado = 0,bool efeitos = 0)
            : Edificios(pre,precoVigas,prod,nivel,upgradeProducao,upgradeArmazenamento,upgradePreco,upgradePrecoVigas,armanezamento,estado,efeitos){ nome = "serr";};
};
#endif //TRABALHO_EDIFICIOS_H
