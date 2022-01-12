//
// Created by ssasu on 1/6/2022.
//
#ifndef TRABALHO_ZONAS_H
#define TRABALHO_ZONAS_H

#include <stdlib.h>
#include <string>

using namespace std;



class Zona {
protected:
    string nome;
public:
    Zona(){}
    string designacao() const;
    virtual void setTotalArvores(int valor) {}
    virtual void setProducao(int valor) {}
    virtual int getTotalArvores() {return 1;}
    virtual int getProducao() {return 1;}
    virtual void setDiasAtivos(int valor) {}
    virtual int getDiasAtivos() {return 1;}

    virtual int getDias() {return 1;}
    virtual void setDias(int valor) {}


};
class Montanha : public Zona{

public:
    Montanha(){ nome = "mnt";};
};
class Deserto : public Zona{

public:
    Deserto(){ nome = "dsr";};
};
class Pastagem : public Zona{

public:
    Pastagem(){ nome = "pas";};
};
class Floresta : public Zona{

    int totalArvores;
    int maxArvores;
    int prod;
    int diasAtivos;


public:
    Floresta(){
        nome = "flr";
        totalArvores = rand()% 21 + 20;
        prod = 1;
        maxArvores = 100;
        diasAtivos = 0;
    };
    void setTotalArvores(int valor) override;
    void setProducao(int valor) override;
    int getTotalArvores() override;
    int getProducao() override;
    int getDiasAtivos() override;
    void setDiasAtivos(int valor) override ;
};
class Pantano : public Zona{
        int dias;

public:
    Pantano(){ nome = "pnt";
               dias = 0;
    };
    int getDias();
    void setDias(int valor);

};
class Tundra : public Zona{

public:
    Tundra(){ nome = "tnd";};
};



#endif //TRABALHO_ZONAS_H
