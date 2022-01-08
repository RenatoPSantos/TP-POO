#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "edificios.h"
#include "recursos.h"
#include "map.h"
#include "comandos.h"

//IDEIAS EDIFICIO X => "Administração" => Reduz chance de despedimento

using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols;
    bool vef = true;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;
    Map mapa(rows, cols);
    Data data;
    mapa.print();
    Commands commands(mapa, data);

    while(1) {
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        mapa.print();
        if(commands.getNext() == true)
            break;
    }

    cout << "Próximo dia" << endl; //Próximo dia

    return 0;
}
