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

    float totalArvores;
    float maxArvores;
    float prod;
    int diasAtivos;
    int dias;

public:
    Zona(){}
    string designacao() const;
    void setTotalArvores(float valor) ;
    void setProducao(float valor);
    float getTotalArvores() ;
    float getProducao();
    int getDiasAtivos();
    void setDiasAtivos(int valor);

    int getDias();
    void setDias(int valor);


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

public:
     Floresta(){nome = "flr";};

};
class Pantano : public Zona{


public:
    Pantano(){ nome = "pnt";};

};
class Tundra : public Zona{

public:
    Tundra(){ nome = "tnd";};
};



#endif //TRABALHO_ZONAS_H
