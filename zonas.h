//
// Created by ssasu on 1/6/2022.
//
#include <stdlib.h>
#include <string>

using namespace std;
#ifndef TRABALHO_ZONAS_H
#define TRABALHO_ZONAS_H


class Zona {
protected:
    string nome;
public:
    designacao();
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

    int totalArvoresIniciais;
    int maxArvores;
    int prod;

public:
    Floresta(){
        nome = "flr";
        totalArvoresIniciais = rand()% 21 + 20;

    };
};
class Pantano : public Zona{

public:
    Pantano(){ nome = "pnt";};
};
class Zonax : public Zona{

public:
    Zonax(){ nome = "znx";};
};



#endif //TRABALHO_ZONAS_H
