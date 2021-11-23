
//     Código feito por: Renato Santos
//                       Sérgio Alves
//     Trabalho prático POO 2021/2022

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>

#include "comandos.h"
#include "map.h"


using namespace std;

bool isNumber(const string &s){

    for (char i : s){
        if (isdigit(i) == false){

            cout << "As linhas/colunas devem ser numeros inteiros" << endl;
            return false;
        }
    }



    return true;
}
bool checkRowsCols(vector<vector<Cell>> &cells,const string& rows,const string& cols){

    int irows = stoi(rows);
    int icols = stoi(cols);

    if(irows >= cells.size() || icols >= cells[0].size()){
        cout << "Por favor introduza linha/colunas validas";
        return false;
    }
    else{
        return true;
    }


}
bool checkArguments(int number, string* comandos){
    if(!comandos[number + 1].empty()){
        cout << "Numero de argumentos invalido" << endl;
        cout << "Este comando utiliza " << number <<  " argumento(s)" << endl;
        return true;
    }
    return false;
}

string* deconstructor(const string& comando) //recebe frase, descontroi-a em palavras, devolve ponteiro para array com palavras.
{
    int i = 0;
    string word;
    string comandos[4];
    for (auto x : comando) //separa os diferentes argumentos
    {
        if (x == ' ')
        {
             if (word.empty()) //se espaços seguidos, avança para próximo caráter
                 continue;

            comandos[i] = word;
            word = "";
            i++;
            if (i == 4)
                break;
        }
        else
        {
            word += x;
        }
        comandos[3] = word;
    }
    return comandos;
}

void fileLine(string* comandos){

}

bool Cell::checkBuildings(vector<vector<Cell>> &cells, int rows, int cols){

    if(cells[rows][cols].building == ""){
        return true;
    }
    else{
        return false;
    }
}

bool Cell::checkTypeBuilding(string* comandos,vector<vector<Cell>> &cells){

    int i;
    int rows = stoi(comandos[2]);
    int cols = stoi(comandos[3]);

    string buildings[6] = {"mnf","mnc","elec","bat","fun","edx"};

    for(i=0;i<5;i++){

        if(comandos[1] == buildings[i]){
            if(checkBuildings(cells,rows,cols) == 1){

                cells[rows-1][cols-1].building = comandos[1];
                return true;
            }
            else{
                cout << "Nesse local já se encontra uma construcao" << endl;
                return false;
            }
        }
        else{
            continue;
        }
    }



    return false;
}



void commands(vector<vector<Cell>> &cells){

    int fase = 1;
    string* comandos;
    string comando;

    while(fase) {
    comando = "";
    getline(cin, comando);
    comandos = deconstructor(comando);

        cout << "comando 0 " << comandos[0] << endl;
        cout << "comando 1 " << comandos[1] << endl;
        cout << "comando 2 " << comandos[2] << endl;
        cout << "comando 3 " << comandos[3] << endl;

        if (comandos[0] == "exec") {
         /*   if (checkArguments(1, comandos) == 1) {
                continue;
            }
            else{
                fstream file;
                file.open(comandos[1],ios::in);
                if(file.is_open()){
                    string fileLine;
                    while(getline(file,fileLine)){

                        fileExec(fileLine);

                    }
                }
            }
*/

        }
        if (comandos[0] == "cons") {
            if (checkArguments(3, comandos) == 1) {
                continue;
            }
            else{
                if(isNumber(comandos[2]) && isNumber(comandos[3])){
                    if(checkRowsCols(cells,comandos[2],comandos[3])){
                        if(Cell::checkTypeBuilding(comandos,cells) == false){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        continue;
                    }
                }
                else{
                    continue;
                }
            }

        }
        if (comandos[0] == "liga") {
            if (checkArguments(2, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "des") {
            if (checkArguments(2, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "move") {
            if (checkArguments(3, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "vende") {
            if (checkArguments(2, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "cont") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "list") {
            if (checkArguments(2, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "vende") {
            if (checkArguments(2, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "next") {
            if (checkArguments(0, comandos) == 1) {
                continue;
            }
            fase = 0; //acaba fase de receção de comandos
        }
        if (comandos[0] == "save") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "load") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "apaga") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "config") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }
            if (comandos[1].substr(comandos[1].length() - 4) != ".txt")
            {
                cout << "Tipo de ficheiro errado" << endl
                << "Esperado (.txt)" << endl;
                continue;
            }
                ifstream file (comandos[1]);

                string reader;
                vector<string> configs; //armazena dados da file | Formato: "<nome> <valor>"
                while(file >> reader)
                {
                    configs.push_back(reader);
                }
                vector<string> name;
                vector<int> value;
                string word;
                for(int i = 0; i < configs.size(); i++) //separa configs em devidos vetores
                {
                    for(auto c: configs[i])
                    {
                        if(c == ' ')
                        {
                            name.push_back(word);
                            word = "";
                        }
                        if(c == '\n')
                        {
                            value.push_back(stoi(word));
                            word = "";
                        }
                        else
                            word += c;
                    }
                }

        }
        if (comandos[0] == "debcash") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "debed") {
            if (checkArguments(3, comandos) == 1) {
                continue;
            }

        }
        if (comandos[0] == "debkill") {
            if (checkArguments(1, comandos) == 1) {
                continue;
            }

        }
    }
}

