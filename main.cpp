 #include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "map.h"

//IDEIAS EDIFICIO X => "Administração" => Reduz chance de despedimento

using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols;

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

    data.getVigas().setQuantidade(50);

    data.getMadeira().setQuantidade(50);
   

    Commands commands(mapa, data);

    while(1) {
        commands.printScreen();
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        commands.setCommands(command);
        if(commands.getNext() == true)
        {
            commands.adicionaDias();
            commands.efeitos();
            commands.entregaRecursos();
            commands.despedimentos();
            data.setDia(data.getDia() + 1);



            commands.setNext(false);
        }
        if(commands.getQuit() == true)
        {
            commands.entregaRecursos();
            break;
        }
    }
  cout << "Dinheiro Final: " << data.getMoney() << endl;
  cout << "Pontuação Final: " << data.getMoney() +
                                 data.getFerro().Quantidade() * data.getFerro().Preco() +
                                 data.getAco().Quantidade() * data.getAco().Preco() +
                                 data.getCarvao().Quantidade() * data.getCarvao().Preco() +
                                 data.getEletricidade().Quantidade() * data.getEletricidade().Preco() +
                                 data.getMadeira().Quantidade() * data.getMadeira().Preco() +
                                 data.getVigas().Quantidade() * data.getVigas().Preco();

}
