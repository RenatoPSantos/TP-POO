//
// Created by User on 12/01/2022.
//

#include "saves.h"

Save::Save(string name, Map map, Data data)
            : name(name), mapa(mapa), data(data) {}

string Save::getName(){
    return name;
}

Map Save::getMapa(){
    return mapa;
}

Data Save::getData(){
    return data;
}