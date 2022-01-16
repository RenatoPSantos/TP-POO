//
// Created by ssasu on 1/6/2022.
//
#ifndef TRABALHO_ZONAS_H
#define TRABALHO_ZONAS_H

#include <cstdlib>
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
    Zona(){totalArvores = 0;
        maxArvores = 0;
        diasAtivos = 0;
        dias = 0;
        prod = 0;}
    string designacao() const;
    void setTotalArvores(float valor) ;
    float getTotalArvores() const;
    float getProducao() const;
    int getDiasAtivos() const;
    void setDiasAtivos(int valor);
    float getMaxArvores();
    int getDias() const;
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
    Floresta(){
        nome = "flr";
        totalArvores = rand() % 21 + 20;
        maxArvores = 100;
        diasAtivos = 0;
        dias = 0;
        prod = 1;
            };
};
class Pantano : public Zona{
public:
    Pantano(){ nome = "pnt";
                dias = 0;};
};
class Tundra : public Zona{
public:
    Tundra(){ nome = "tnd";};
};



#endif //TRABALHO_ZONAS_H
