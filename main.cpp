 #include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "map.h"

//IDEIAS EDIFICIO X => "Administração" => Reduz chance de despedimento

using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols,vef=1;

    while(vef){
        cout << "Tamanho do mapa: " ;
        cin >> rows >> cols;
        vef =(checkTamanho(rows,cols));
    }

    Map mapa(rows, cols);

    Ferro ferro;
    Aco aco;
    Carvao carvao;
    Madeira madeira;
    Vigas vigas;
    Eletricidade eletricidade;

    Data data(ferro, aco, carvao, madeira, vigas, eletricidade);

    Commands commands(mapa, data);

    while(true) {
        commands.printScreen();
        string command;
        commands.clearCommands();
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        clsConsole();
        if(commands.getNext())
        {
            commands.adicionaDias();
            commands.efeitos();
            commands.entregaRecursos();
            commands.despedimentos();
            data.setDia(data.getDia() + 1);


            commands.setNext(false);
        }
        if(commands.getQuit())
        {
            commands.entregaRecursos();
            break;
        }
    }
  cout << "Dinheiro Final: " << data.getMoney() << endl;
  cout << "Pontuacao Final: " << data.getMoney() +
                                 data.getFerro().Quantidade() * data.getFerro().Preco() +
                                 data.getAco().Quantidade() * data.getAco().Preco() +
                                 data.getCarvao().Quantidade() * data.getCarvao().Preco() +
                                 data.getEletricidade().Quantidade() * data.getEletricidade().Preco() +
                                 data.getMadeira().Quantidade() * data.getMadeira().Preco() +
                                 data.getVigas().Quantidade() * data.getVigas().Preco();

}
