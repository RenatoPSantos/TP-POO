#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "map.h"
#include "comandos.h"

//IDEIAS EDIFICIO X => "Gestor" => Dá mais energia por dia ao jogador
//                  => "Administração" => Reduz chance de despedimento

using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols;
    bool vef = true;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;
    Map mapa(rows, cols);
    mapa.print();
    Commands commands(mapa);


    commands.setEnergy(5);
    while(commands.getEnergy() > 0) {
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        mapa.print();
        if(commands.getEnergy() <= 0)
            cout << "Energia acabou!" << endl;
    }

    cout << "Próximo dia" << endl; //Próximo dia

    return 0;
}
