#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "celula.h"
#include "comandos.h"
#include "trabalhadores.h"
using namespace std;

int main() {
    
    int rows,cols;

    vector<vector<string*>> mapa;
    mapa = createMap(mapa);
    printMap(&mapa);



    commands();

    return 0;
}
