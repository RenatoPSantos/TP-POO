#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "map.h"
using namespace std;


Cell::Cell(string biome) : biome(biome),n_workers(0) {

}

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

string* stringController(string* str){ //controla dimensão da string de forma a ocupar 4 caráters por linha

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
void updateMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //atualiza informação do mapa com informação das cells
{

    for (int i = 0; i < cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<char> workers = cells[i][j].getWorkers();
            string str(workers.begin(), workers.end());
            line[0] = cells[i][j].getBiome();
            line[1] = cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(cells[i][j].countWorkers());
            map[i][j] = stringController(line);
        }
    }
}
void printMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //imprime ilha
{
    updateMap(map, cells);
    for (int h = 0; h < map.size(); h++)
    {
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < map[0].size(); j++)
            {
                cout << "|" << (map[h][j])[i] ;
            }
            cout << "|" << endl;
        }
    }

}

void createMap(vector<vector<string*>> &map, vector<vector<Cell>> &cells) //cria mapa inicial
{
    for (int i = 0; i < cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<char> workers = cells[i][j].getWorkers();
            string str(workers.begin(), workers.end());
            line[0] = cells[i][j].getBiome();
            line[1] = cells[i][j].getBuilding();
            line[2] = str;
            line[3] = to_string(cells[i][j].countWorkers());
            stringController(line);
            temp.push_back(line);
        }
        map.push_back(temp);
    }
}

void createCells(vector<vector<Cell>> &cells, int rows, int cols) //cria duplo vetor de objetos (contêm informação)
{
    string random[] = {"mnt", "dsr", "flr", "pas", "ptn"};

    for (int i = 0; i < rows; i++) {
        vector<Cell> temp;
        for (int j = 0; j < cols; j++)
            temp.emplace_back(random[rand() % 5]);
        cells.push_back(temp);
    }
    cells[rand() % cells.size()][rand() % cells[0].size()].setBiome("pas");
}

bool checkBuildings(vector<vector<Cell>> &cells, int rows, int cols){

    if(cells[rows-1][cols-1].getBuilding().empty()){
        return true;
    }
    else{
        return false;
    }
}

void checkTypeBuilding(string *comandos, vector<vector<Cell>> &cells){

    int i;
    int rows = stoi(comandos[2]);
    int cols = stoi(comandos[3]);

    string buildings[6] = {"mnf","mnc","elec","bat","fun","edx"};


    for(i=0;i<6;i++){
        if(comandos[1] == buildings[i]){
            if(checkBuildings(cells, rows, cols)){
                cells[rows-1][cols-1].setBuilding(comandos[1]);
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

void list(const string& rows,const string& cols,vector<vector<Cell>> &cells){

    int irows = stoi(rows);
    int icols = stoi(cols);


    cout << "\n--Informacoes--"<< endl;
    cout << "Bioma -> " << cells[irows-1][icols-1].getBiome() << endl;

    if(cells[irows-1][icols-1].getBuilding().empty()){
        cout << "Construcao -> Vazio " << endl;
    }
    else{
        cout << "Construcao -> " << cells[irows-1][icols-1].getBuilding() << endl;
    }
    if(cells[irows-1][icols-1].getWorkers().empty()){
        cout << "Trabalhadores -> Vazio" << endl;
    }
    else{
        cout << "Trabalhadores -> ";
        for(int i = 0;i<cells[irows-1][icols-1].getWorkers().size();i++){
            cout << cells[irows-1][icols-1].getWorkers()[i] << " ";
        }
        cout << endl;
    }
    cout << "Numero total de trabalhadores -> " << cells[irows-1][icols-1].countWorkers() << endl;

    system("pause");


}
void list(){

    cout << "lista geral // EM DESENVOLVIMENTO"<< endl;
    system("pause");
}



