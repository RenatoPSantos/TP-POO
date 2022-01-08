//     Código feito por: Renato Santos
//                       Sérgio Alves
//     Trabalho prático POO 2021/2022

#include <iostream>
#include <string>
#include <vector>

#include "comandos.h"
#include "trabalhadores.h"

using namespace std;

Commands::Commands(Map& mapa, Data& data) : mapa(mapa), data(data), next(false){};

void Commands::setCommands(string command){
    int i = 0;
    string word;
    istringstream iss(command);
    while(iss >> word)
    {
        commands[i] = word;
        if(i == 3)
            break;
        i++;
    }
    execCommands();
}
void Commands::update(string command){
    int i = 0;
    string word;
    istringstream iss(command);
    while(iss >> word)
    {
        commands[i] = word;
        if(i == 3)
            break;
        i++;
    }
}

int Commands::execCommands() {

    if (commands[0] == "exec") {
        if (checkArguments(1))
        {
            if (commands[1].substr(commands[1].length() - 4) != ".txt") {
                commands[1]+=".txt";
            }
            fstream file;
            file.open(commands[1].c_str(), ios::in);
            if (file.is_open()) {
                string reader;
                vector<string> configs;
                while (getline(file, reader)){

                    configs.push_back(reader);
                }
                file.close();
                for(int i = 0; i < configs.size(); i++)
                {
                    update(configs[i]);
                    execCommands();
                }
                return 1;
            }
            cout << "Falha ao abrir o ficheiro" << endl;
            return 1;
        }
    }
    if (commands[0] == "cons") {
        if (checkArguments(3) == 1) {
            if(isNumber(commands[2]) && isNumber(commands[3])){
                if(mapa.checkRowsCols(commands[2],commands[3])){
                    mapa.insertBuilding(commands);
                }
                else{
                    return 1;
                }
            }
            else{
                return 1;
            }

        }
        else{
            return 1;
        }

    }
    if (commands[0] == "liga") {
        if (checkArguments(2)) {
            if(isNumber(commands[1]) && isNumber(commands[2])){
                if(mapa.checkRowsCols(commands[1],commands[2])) {
                    if (mapa.getCells()[stoi(commands[1])][stoi(commands[2])].getBuilding().designacao() != "") {
                        mapa.getCells()[stoi(commands[1])][stoi(commands[2])].getBuilding().liga();
                    } else {
                        cout << "Não existe edificio nestas coordenadas" << endl;
                        return 1;
                    }
                }
                else{
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    if (commands[0] == "des") {
        if (checkArguments(2)) {
            if(isNumber(commands[1]) && isNumber(commands[2])){
                if(mapa.checkRowsCols(commands[1],commands[2])) {
                    if (mapa.getCells()[stoi(commands[1])][stoi(commands[2])].getBuilding().designacao() != "") {
                        mapa.getCells()[stoi(commands[1])][stoi(commands[2])].getBuilding().desliga();
                    } else {
                        cout << "Não existe edificio nestas coordenadas" << endl;
                        return 1;
                    }
                }
                else{
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }

    }
    if (commands[0] == "move") {
        if (checkArguments(3)) {
            return 1;
        }

    }
    if (commands[0] == "vende") {
        if (checkArguments(2)) {
            return 1;
        }

    }
    if (commands[0] == "cont") {
        if (checkArguments(1)){
            if(commands[1] != "oper" && commands[1] != "len" && commands[1] != "miner"){
                return 1;
            }
            if(commands[1] == "oper"){
                Operario oper(data.getDia());
                for (int i = 0; i < mapa.getCells().size(); i++) {
                    for (int j = 0; j < mapa.getCells()[0].size(); j++) {
                        if (mapa.getCells()[i][j].getBiome().designacao() == "pas") {
                            mapa.getCells()[i][j].addWorker(&oper);
                            return 1;
                        }
                    }
                }
            }
            if(commands[1] == "len"){
                Lenhador len(data.getDia());
                for (int i = 0; i < mapa.getCells().size(); i++) {
                    for (int j = 0; j < mapa.getCells()[0].size(); j++) {
                        if (mapa.getCells()[i][j].getBiome().designacao() == "pas") {
                            mapa.getCells()[i][j].addWorker(&len);
                            return 1;
                        }
                    }
                }
            }
            if(commands[1] == "miner"){
                Mineiro min(data.getDia());
                for (int i = 0; i < mapa.getCells().size(); i++) {
                    for (int j = 0; j < mapa.getCells()[0].size(); j++) {
                        if (mapa.getCells()[i][j].getBiome().designacao() == "pas") {
                            mapa.getCells()[i][j].addWorker(&min);
                            return 1;
                        }
                    }
                }
            }

            return 1;

        }
        return 1;

    }
    if (commands[0] == "list") {
        if (commands[1].empty()) {
            mapa.printInfo();
            return 1;
        }
        if (checkArguments(2)) {
            if (isNumber(commands[1]) && isNumber(commands[2]) &&
                mapa.checkRowsCols( commands[1], commands[2])) {
                mapa.printInfo(commands[1], commands[2]);
                return 1;
            }
            return 1;
        } else {
            return 1;
        }

    }
    if (commands[0] == "vende") {
        if (checkArguments(2)) {
            return 1;
        }

    }
    if (commands[0] == "next") {
        if (checkArguments(0)) {
            next = true;
            return 0;
        }
        return 1;
    }
    if (commands[0] == "save") {
        if (checkArguments(1)) {
            return 1;
        }

    }
    if (commands[0] == "load") {
        if (checkArguments(1)) {
            return 1;
        }

    }
    if (commands[0] == "apaga") {
        if (checkArguments(1)) {
            return 1;
        }

    }
    if (commands[0] == "config") {

        if (checkArguments(1) == 1) {

            if (commands[1].substr(commands[1].length() - 4) != ".txt") {
                commands[1]+=".txt";
                cout << commands[1] << endl;
            }
            fstream file;
            file.open(commands[1].c_str(), ios::in);


            if (file.is_open()) {
                string reader;
                vector<string> configs; //armazena dados da file | Formato: "<nome> <valor>"
                while (file >> reader) {
                    configs.push_back(reader);
                }
                file.close();

                vector<string> names;
                vector<int> values;
                for (int i = 0;i < configs.size() / 2; i++) //cria dois vetores, um que contem os nomes das variaveis
                {                                          //e outro que contém os valores das variáveis
                    names.push_back(configs[2 * i]);
                    values.push_back(stoi(configs[(2 * i + 1)]));
                }
                cout << "Ficheiro " << commands[1] << " lido com sucesso" << endl;
                cout << "Mudanca a variaveis por implementar" << endl;

            } else {
                cout << "Erro ao verificar file (Requer que ficheiro esteja dentro da pasta cmake-build-debug)"
                     << endl;
            }
        }
    }
    if (commands[0] == "debcash") {
        if (checkArguments(1)) {
            return 1;
        }

    }
    if (commands[0] == "debed") {
        if (checkArguments(3)) {
            return 1;
        }

    }
    if (commands[0] == "debkill") {
        if (checkArguments(1)) {
            return 1;
        }

        return 0;
    }
    cout << "O comando que inseriu esta errado"<< endl;
    system("pause");
    mapa.print();
    return 1;
}

bool Commands::checkArguments(int number) const{
    if(commands[number].empty()){
        cout << "Numero de argumentos invalido" << endl;
        cout << "Este comando utiliza " << number <<  " argumento(s)" << endl;

        system("pause");

        return false;
    }
    return true;
}
void Commands::setNext(bool state){
    next = state;
}
bool Commands::getNext() const{
    return next;
}

bool isNumber(const string &s){

    for (char i : s){
        if (isdigit(i) == false){

            cout << "As linhas/colunas devem ser numeros inteiros" << endl;
            system("pause");

            return false;
        }
    }
    return true;
}

void clsConsole(){
    for(int i=0;i<30;i++){
        cout << endl;
    }
}
