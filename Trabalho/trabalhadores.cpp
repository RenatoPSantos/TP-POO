#include <string>
#include <vector>

#include "trabalhadores.h"
#include "comandos.h"

using namespace std;

Trabalhadores::Trabalhadores(int salario) :  salario(salario){


    //fazer resto (tem de gerar id)
}

void cont(vector<vector<Cell>> &cells, string type) {
    char type_char;

    if(type != "oper" && type != "len" && type != "miner"){
        return;
    }
    if(type == "oper"){
        type_char = 'O';
    }
    if(type == "len"){
        type_char = 'L';
    }
    if(type == "miner"){
        type_char = 'M';
    }
    for (int i = 0; i < cells.size(); i++) {
        for (int j = 0; j < cells[0].size(); j++) {
            if (cells[i][j].getBiome() == "pas") {
                cells[i][j].addWorker(type_char);
                return;
            }
        }
    }
}
