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
    cout << "VIGAS: "<< data.getVigas().Quantidade() << endl;
    Commands commands(mapa, data);


    while(1) {
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        mapa.print();
        cout << "Vigas: "<< data.getVigas().Quantidade() << endl;
        if(commands.getNext() == true)
            break;
    }

    cout << "Próximo dia" << endl; //Próximo dia

    return 0;
}
