//     Código feito por: Renato Santos
//                       Sérgio Alves
//     Trabalho prático POO 2021/2022

#include <iostream>
#include <string>
#include <vector>

#include "comandos.h"
#include "trabalhadores.h"



using namespace std;
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
bool checkArguments(int number, string *comandos ){
    if(comandos[number].empty()){
        cout << "Numero de argumentos invalido" << endl;
        cout << "Este comando utiliza " << number <<  " argumento(s)" << endl;

        system("pause");

        return false;
    }
    return true;
}

void deconstructor(const string& comando, string* comandos) //recebe frase, descontroi-a em palavras, devolve ponteiro para array que contém as palavras.
{
    int i = 0;
    string word;
    istringstream iss(comando);
    while(iss >> word)
    {
        comandos[i] = word;
        if(i == 3)
            break;
        i++;
    }
}

void commands(vector<vector<string*>> map,vector<vector<Cell>> &cells) {

    int vef = 1;

    while(vef){

        string *comandos = new string[4];
        string comando;
        cout << "Comando: ";
        getline(cin >> ws, comando);

        deconstructor(comando, comandos);

        vef = execCommands(cells, comandos);

        clsConsole();


       /* clsConsole();*/

        printMap(map,cells);

    }
}
int execCommands(vector<vector<Cell>> &cells, string *comandos) {

        if (comandos[0] == "exec") {
            if (checkArguments(1, comandos) == 1)
            {
                if (comandos[1].substr(comandos[1].length() - 4) != ".txt") {
                    comandos[1]+=".txt";
                    cout << comandos[1] << endl;
                }
                fstream file;
                file.open(comandos[1].c_str(), ios::in);
                if (file.is_open()) {
                    string reader;
                    vector<string> configs;
                    while (getline(file, reader)){

                        configs.push_back(reader);
                    }
                    file.close();
                    for(int i = 0; i < configs.size(); i++)
                    {
                        string* aux = new string[4];
                        deconstructor(configs[i], aux);

                            execFile(cells, aux);

                    }
                    return 1;
                }
                cout << "Falha ao abrir o ficheiro" << endl;
                return 1;
            }
        }
        if (comandos[0] == "cons") {
                if (checkArguments(3, comandos) == 1) {
                    if(isNumber(comandos[2]) && isNumber(comandos[3])){
                        if(checkRowsCols(cells,comandos[2],comandos[3])){
                            checkTypeBuilding(comandos,cells);
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
        if (comandos[0] == "liga") {
            if (checkArguments(2, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "des") {
            if (checkArguments(2, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "move") {
            if (checkArguments(3, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "vende") {
            if (checkArguments(2, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "cont") {
            if (checkArguments(1, comandos)) {
                cont(cells,comandos[1]);
                return 1;

            }
            return 1;

        }
        if (comandos[0] == "list") {
            if (comandos[1].empty()) {
                list();
                return 1;
            }
            if (checkArguments(2, comandos)) {
                if (isNumber(comandos[1]) && isNumber(comandos[2]) &&
                    checkRowsCols(cells, comandos[1], comandos[2])) {
                    list(comandos[1], comandos[2], cells);
                    return 1;
                }
                return 1;
            } else {
                return 1;
            }

        }
        if (comandos[0] == "vende") {
            if (checkArguments(2, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "next") {
            if (checkArguments(0, comandos)) {
                return 0;
            }
            return 1;
        }
        if (comandos[0] == "save") {
            if (checkArguments(1, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "load") {
            if (checkArguments(1, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "apaga") {
            if (checkArguments(1, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "config") {

            if (checkArguments(1, comandos) == 1) {

            if (comandos[1].substr(comandos[1].length() - 4) != ".txt") {
                comandos[1]+=".txt";
                cout << comandos[1] << endl;
            }
            fstream file;
            file.open(comandos[1].c_str(), ios::in);


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
                cout << "Ficheiro " << comandos[1] << " lido com sucesso" << endl;
                cout << "Mudanca a variaveis por implementar" << endl;

            } else {
                cout << "Erro ao verificar file (Requer que ficheiro esteja dentro da pasta cmake-build-debug)"
                     << endl;
            }
            }
        }
        if (comandos[0] == "debcash") {
            if (checkArguments(1, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "debed") {
            if (checkArguments(3, comandos)) {
                return 1;
            }

        }
        if (comandos[0] == "debkill") {
            if (checkArguments(1, comandos)) {
                return 1;
            }

         return 0;
        }
    cout << "O comando que inseriu esta errado"<< endl;
    system("pause");
    return 1;
}
int execFile(vector<vector<Cell>> &cells, string *comandos) {


    if (comandos[0] == "cons") {
        if (checkArguments(3, comandos) == 1) {
            if(isNumber(comandos[2]) && isNumber(comandos[3])){
                if(checkRowsCols(cells,comandos[2],comandos[3])){
                    checkTypeBuilding(comandos,cells);
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
    if (comandos[0] == "liga") {
        if (checkArguments(2, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "des") {
        if (checkArguments(2, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "move") {
        if (checkArguments(3, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "vende") {
        if (checkArguments(2, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "cont") {
        if (checkArguments(1, comandos)) {
            cont(cells,comandos[1]);
            return 1;

        }
        return 1;

    }
    if (comandos[0] == "list") {
        if (comandos[1].empty()) {
            list();
            return 1;
        }
        if (checkArguments(2, comandos)) {
            if (isNumber(comandos[1]) && isNumber(comandos[2]) &&
                checkRowsCols(cells, comandos[1], comandos[2])) {
                list(comandos[1], comandos[2], cells);
                return 1;
            }
            return 1;
        } else {
            return 1;
        }

    }
    if (comandos[0] == "vende") {
        if (checkArguments(2, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "next") {
        if (checkArguments(0, comandos)) {
            return 0;
        }
        return 1;
    }
    if (comandos[0] == "save") {
        if (checkArguments(1, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "load") {
        if (checkArguments(1, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "apaga") {
        if (checkArguments(1, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "debcash") {
        if (checkArguments(1, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "debed") {
        if (checkArguments(3, comandos)) {
            return 1;
        }

    }
    if (comandos[0] == "debkill") {
        if (checkArguments(1, comandos)) {
            return 1;
        }

        return 0;
    }
    cout << "O comando que inseriu esta errado"<< endl;
    system("pause");
    return 1;
}