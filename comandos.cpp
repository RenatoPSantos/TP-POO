//     Código feito por: Renato Santos
//                       Sérgio Alves
//     Trabalho prático POO 2021/2022

#include <iostream>
#include <string>
#include <vector>

#include "comandos.h"
#include "trabalhadores.h"

using namespace std;
/*void commands(Map& mapa) { //main dos commands

    int vef = 1;

    while(vef){

        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        Commands commands(mapa, command);
        vef = commands.execCommands();
        clsConsole();
        mapa.print();
    }
}*/
Commands::Commands(Map& mapa, string command) : mapa(mapa){
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
};
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
                    execFile();
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
                if(checkRowsCols(mapa.getCells(),commands[2],commands[3])){
                    mapa.insertBuilding(commands);
                    return 1;
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
            return 1;
        }

    }
    if (commands[0] == "des") {
        if (checkArguments(2)) {
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
            cont(mapa.getCells(),commands[1]);
            return 1;

        }
        return 1;

    }
    if (commands[0] == "list") {
        if (commands[1].empty()) {
            list();
            return 1;
        }
        if (checkArguments(2)) {
            if (isNumber(commands[1]) && isNumber(commands[2]) &&
                checkRowsCols(mapa.getCells(), commands[1], commands[2])) {
                list(commands[1], commands[2], mapa.getCells());
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

void clsConsole(){
    for(int i=0;i<30;i++){
        cout << endl;
    }
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

bool checkRowsCols(vector<vector<Cell>> &cells, const string& rows, const string& cols){

    int irows = stoi(rows);
    int icols = stoi(cols);

    if(irows > cells.size() || icols > cells[0].size()){
        cout << "Por favor introduza linhas/colunas validas"<< endl;
        cout << "Linhas totais: " << cells.size() << " | Colunas totais: " << cells[0].size() << endl;
        system("pause");

        return false;
    }
    else{
        return true;
    }


}
bool Commands::checkArguments(int number){
    if(commands[number].empty()){
        cout << "Numero de argumentos invalido" << endl;
        cout << "Este comando utiliza " << number <<  " argumento(s)" << endl;

        system("pause");

        return false;
    }
    return true;
}

int Commands::execFile() {

    if (commands[0] == "cons") {
        if (checkArguments(3)) {
            if(isNumber(commands[2]) && isNumber(commands[3])){
                if(checkRowsCols(mapa.getCells(),commands[2],commands[3])){
                    mapa.insertBuilding(commands);
                    return 1;
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
            return 1;
        }

    }
    if (commands[0] == "des") {
        if (checkArguments(2)) {
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
        if (checkArguments(1)) {
            cont(mapa.getCells(),commands[1]);
            return 1;

        }
        return 1;

    }
    if (commands[0] == "list") {
        if (commands[1].empty()) {
            list();
            return 1;
        }
        if (checkArguments(2)) {
            if (isNumber(commands[1]) && isNumber(commands[2]) &&
                checkRowsCols(mapa.getCells(), commands[1], commands[2])) {
                list(commands[1], commands[2], mapa.getCells());
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
    return 1;
}
