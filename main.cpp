#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "map.h"
#include "edificios.h"
#include "comandos.h"
#include "recursos.h"
#include "trabalhadores.h"
#include "zonas.h"

//IDEIAS EDIFICIO X => "Administração" => Reduz chance de despedimento

using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols;
    bool vef = true;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;
    Map mapa(rows, cols);

    Ferro ferro;
    Aco aco;
    Carvao carvao;
    Madeira madeira;
    Vigas vigas;
    Eletricidade eletricidade;

    Data data(ferro, aco, carvao, madeira, vigas, eletricidade);
    data.getVigas().setQuantidade(10);
    Commands commands(mapa, data);

    while(1) {
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        commands.printScreen();
        if(commands.getNext() == true)
        {
            commands.entregaRecursos();
            data.setDia(data.getDia() + 1);
            cout << "Dia: " << data.getDia() << endl;
            commands.setNext(false);
        }
    }
}
