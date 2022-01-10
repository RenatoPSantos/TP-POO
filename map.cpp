#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <typeinfo>

#include "map.h"
using namespace std;


Cell::Cell() {
    n_workers = 0;
}

void Cell::setBuilding(string type) {
    if(type == "mnf")
    {
        MinaFerro mnf;
        building = mnf;
    }
    if(type == "mnc")
    {
        MinaCarvao mnc;
        building = mnc;
    }
    if(type == "elec")
    {
        CentralEle elec;
        building = elec;
    }
    if(type == "bat")
    {
        Bateria bat;
        building = bat;
    }
    if(type == "fun")
    {
        Fundicao fun;
        building = fun;
    }
    if(type == "edX")
    {
        EdificioX edx;
        building = edx;
    }
}
void Cell::setBiome(string type) {
    if(type == "mnt")
    {
        Montanha mnt;
        biome = mnt;
    }
    if(type == "dsr")
    {
        Deserto dsr;
        biome = dsr;
    }
    if(type == "pas")
    {
        Pastagem pas;
        biome = pas;
    }
    if(type == "flr")
    {
        Floresta flr;
        biome = flr;
    }
    if(type == "pnt")
    {
        Pantano pnt;
        biome = pnt;
    }
    if(type == "znx")
    {
        Zonax znx;
        biome = znx;
    }
}

void Cell::destroyBuilding() {
    Edificios edificio;
    building = edificio;
}
void Cell::addWorker(Trabalhadores& worker) {
    workers.push_back(worker);
}
void Cell::removeWorker(char type) {
    for(int i = workers.size(); i > 0; i--)
    {
        if(type == 'M')
            if (typeid(workers[i]) == typeid(Mineiro)) {
                workers.erase(workers.begin() + i);
                n_workers--;
                break;
            }
        if(type == 'L')
            if (typeid(workers[i]) == typeid(Lenhador)) {
                workers.erase(workers.begin() + i);
                n_workers--;
                break;
            }
        if(type == 'O')
            if (typeid(workers[i]) == typeid(Operario)) {
                workers.erase(workers.begin() + i);
                n_workers--;
                break;
            }
    }
}

/*Trabalhadores& Cell::findWorker(string id) {

    *//*
    for(int i=0;i<workers.size();i++){
        if(workers[i].getId() == id){
            return workers[i];
        }
    }
     *//*

}*/

Zona& Cell::getBiome(){
    return biome;
}

Edificios& Cell::getBuilding(){
    return building;
}

vector<Trabalhadores>& Cell::getWorkers(){
    return workers;
}

int Cell::countWorkers() const {
    return n_workers;
}

Cell::~Cell() {

}

Map::Map(int rows, int cols) : rows(rows), cols(cols) {

    string random[] = {"mnt", "dsr", "flr", "pas", "pnt"};

    for (int i = 0; i < rows; i++) {
        vector<Cell> temp;
        for (int j = 0; j < cols; j++)
        {
            temp.push_back(Cell());
            temp[j].setBiome(random[rand() % 5]);
        }
        Cells.push_back(temp);
    }
    Cells[rand() % Cells.size()][rand() % Cells[0].size()].setBiome("pas");

    for (int i = 0; i < Cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < Cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<Trabalhadores> workers = Cells[i][j].getWorkers();

            string str;
            for(int h = 0; h < workers.size(); h++)
            {
                str.push_back(workers[h].designacao());
            }

            line[0] = Cells[i][j].getBiome().designacao();
            line[1] = Cells[i][j].getBuilding().designacao();
            line[2] = str;
            line[3] = to_string(Cells[i][j].countWorkers());
            stringController(line);
            temp.push_back(line);
        }
        Str.push_back(temp);
    }
    cout << "Map created";
    print();
}

void Map::print() //atualiza e imprime ilha
{
    for (int i = 0; i < Cells.size(); i++) {
        vector<string*> temp;
        for (int j = 0; j < Cells[0].size(); j++)
        {
            string* line = new string[4];
            vector<Trabalhadores> workers = Cells[i][j].getWorkers();

            string str;
            for(int h = 0; h < workers.size(); h++)
            {
                str.push_back(workers[h].designacao());
            }

            line[0] = Cells[i][j].getBiome().designacao();
            line[1] = Cells[i][j].getBuilding().designacao();
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

bool Map::insertBuilding(string *comandos){

    int i;
    int rows = stoi(comandos[2]);
    int cols = stoi(comandos[3]);

    string buildings[6] = {"mnf","mnc","elec","bat","fun","edx"};

    for(i=0;i<6;i++){
        if(comandos[1] == buildings[i]){
            if(Cells[rows-1][cols-1].getBuilding().designacao() == ""){
                Cells[rows-1][cols-1].setBuilding(comandos[1]);
                return true;
            }
            else{
                cout << "Nesse local ja se encontra uma construção" << endl;
                system("pause");
                return false;
            }
        }
    }
    cout << "A construção que inseriu e invalida" << endl;
    system("pause");
    return false;
}

void Map::moveWorker(int r,int c,string id) {
    /*
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

           if(Cells[i][j].findWorker(id) == 1){

           }
        }
    }

    */
}


void Map::printInfo(const string& rows,const string& cols){

    int irows = stoi(rows);
    int icols = stoi(cols);

    cout << "\n--Informacoes--"<< endl;

    if (Cells[irows-1][icols-1].getBiome().designacao() == "pas")
        cout << "Bioma -> Pastagem" << endl;
    if (Cells[irows-1][icols-1].getBiome().designacao() == "flr")
        cout << "Bioma -> Floresta" << endl;
    if (Cells[irows-1][icols-1].getBiome().designacao() == "mnt")
        cout << "Bioma -> Montanha" << endl;
    if (Cells[irows-1][icols-1].getBiome().designacao() == "dsr")
        cout << "Bioma -> Deserto" << endl;
    if (Cells[irows-1][icols-1].getBiome().designacao() == "pnt")
        cout << "Bioma -> Pantano" << endl;
    if (Cells[irows-1][icols-1].getBiome().designacao() == "znX") //Desenvolver
        cout << "Bioma -> Zona X" << endl;

    if(Cells[irows-1][icols-1].getBuilding().designacao() == ""){
        cout << "Construcao -> Vazio " << endl;
    }
    else{
        cout << "Construcao -> " << Cells[irows-1][icols-1].getBuilding().designacao() << endl;
    }
    if(Cells[irows-1][icols-1].getWorkers().empty()){
        cout << "Trabalhadores -> Vazio" << endl;
    }
    else{
        int m = 0, o = 0, l = 0;
        cout << "Lista Trabalhadores -> ";
        for(int i = 0;i<Cells[irows-1][icols-1].getWorkers().size();i++){
            cout << Cells[irows-1][icols-1].getWorkers()[i].designacao() << " ";
            if (Cells[irows-1][icols-1].getWorkers()[i].designacao() == 'M')
            {
                m++;
                continue;
            }
            if (Cells[irows-1][icols-1].getWorkers()[i].designacao() == 'O') {
                l++;
                continue;
            }
            if (Cells[irows-1][icols-1].getWorkers()[i].designacao() == 'L') {
                o++;
                continue;
            } // bruh
        }
        cout << endl;
        cout << "Numero Mineiros -> " << m << endl;
        cout << "Numero Lenhadores -> " << l << endl;
        cout << "Numero Operarios -> " << o << endl;
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

bool Map::checkRowsCols(const string& rows, const string& cols){

    int irows = stoi(rows);
    int icols = stoi(cols);

    if(irows > Cells.size() || icols > Cells[0].size()){
        cout << "Por favor introduza linhas/colunas validas"<< endl;
        cout << "Linhas totais: " << Cells.size() << " | Colunas totais: " << Cells[0].size() << endl;
        system("pause");

        return false;
    }
    else{
        return true;
    }
}
int Map::getRows(){
    return rows;

}
int Map::getCols(){
    return cols;
}