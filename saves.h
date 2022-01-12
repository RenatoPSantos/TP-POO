#ifndef TRABALHO_SAVES_H
#define TRABALHO_SAVES_H

#include <iostream>

#include "map.h"
#include "recursos.h"



class Save{
    string name;

    Map mapa;
    Data data;

public:
    Save(string name, Map mapa, Data data);
    void load(string name);
    string getName();
    Map getMapa();
    Data getData();
};


#endif //TRABALHO_SAVES_H
