#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "map.h"
using namespace std;


Cell::Cell(string biome) : biome(biome),n_workers(0){}

void Cell::setBuilding(string type) {
    building = type;
}
void Cell::setBiome(string type) {
    biome = type;
}

void Cell::destroyBuilding() {
    building = "";
}

void Cell::addWorker(char type) {
    workers.push_back(type);
    n_workers += 1;
}

string Cell::getBiome() const {
    return biome;
}

string Cell::getBuilding() const {
    return building;
}

vector<char> Cell::getWorkers() const {
    return workers;
}

int Cell::countWorkers() const {
    return n_workers;
}

Cell::~Cell() {

}



Map::Map(int rows, int cols) : rows(rows), cols(cols) {

    string random[] = {"mnt", "dsr", "flr", "pas", "ptn"};

    for (int i = 0; i < rows; i++) {
        vector<Cell> temp;
        for (int j = 0; j < cols; j++)
            temp.emplace_back(random[rand() % 5]);
        Cells.push_back(temp);
    }

    Cells[rand() % Cells.size()][rand() % Cells[0].size()].setBiome("pas");
    for (int i = 0; i < Cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < Cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<char> workers = Cells[i][j].getWorkers();
            string str(workers.begin(), workers.end());
            line[0] = Cells[i][j].getBiome();
            line[1] = Cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(Cells[i][j].countWorkers());
            stringController(line);
            temp.push_back(line);
        }
        Str.push_back(temp);
    }
}

void Map::print() //atualiza e imprime ilha
{
    for (int i = 0; i < Cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < Cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<char> workers = Cells[i][j].getWorkers();
            string str(workers.begin(), workers.end());
            line[0] = Cells[i][j].getBiome();
            line[1] = Cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(Cells[i][j].countWorkers());
            Str[i][j] = stringController(line);
        }
    }

    for (int h = 0; h < Str.size(); h++)
    {
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < Str[0].size(); j++)
            {
                cout << "|" << (Str[h][j])[i] ;
            }
            cout << "|" << endl;
        }
    }

}
string* Map::stringController(string* str){ //controla dimensão da string de forma a ocupar 4 caráters por linha

    int counter;
    for(int i = 0; i < 4; i++)
    {
        counter = 0;
        for(auto x: str[i]) {

            counter++;
            if(counter >= 4){
                str[i].erase(4);
            }
        }

        for(int j = 0; j < 4 - counter; j++)
            str[i] += ' ';

    }
    return str;
}

void Map::insertBuilding(string *comandos){

    int i;
    int rows = stoi(comandos[2]);
    int cols = stoi(comandos[3]);

    string buildings[6] = {"mnf","mnc","elec","bat","fun","edx"};

    for(i=0;i<6;i++){
        if(comandos[1] == buildings[i]){
            cout << "construindo" << endl;
            if(Cells[rows-1][cols-1].getBuilding().empty() == 1){
                Cells[rows-1][cols-1].setBuilding(comandos[1]);
                return;
            }
            else{
                cout << "Nesse local ja se encontra uma construcao" << endl;
                system("pause");

                return;
            }
        }
        else{
            cout << "A construcao que inseriu e invalida" << endl;
            system("pause");
        }
    }
}

void Map::printInfo(const string& rows,const string& cols){

    int irows = stoi(rows);
    int icols = stoi(cols);

    cout << "\n--Informacoes--"<< endl;
    cout << "Bioma -> " << Cells[irows-1][icols-1].getBiome() << endl;

    if(Cells[irows-1][icols-1].getBuilding().empty()){
        cout << "Construcao -> Vazio " << endl;
    }
    else{
        cout << "Construcao -> " << Cells[irows-1][icols-1].getBuilding() << endl;
    }
    if(Cells[irows-1][icols-1].getWorkers().empty()){
        cout << "Trabalhadores -> Vazio" << endl;
    }
    else{
        cout << "Trabalhadores -> ";
        for(int i = 0;i<Cells[irows-1][icols-1].getWorkers().size();i++){
            cout << Cells[irows-1][icols-1].getWorkers()[i] << " ";
        }
        cout << endl;
    }
    cout << "Numero total de trabalhadores -> " << Cells[irows-1][icols-1].countWorkers() << endl;

    system("pause");


}

void Map::printInfo() {

    cout << "lista geral // EM DESENVOLVIMENTO"<< endl;
    system("pause");
}

vector<vector<Cell>>& Map::getCells() {
    return Cells;
}