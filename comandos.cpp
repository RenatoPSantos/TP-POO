
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

bool checkArguments(int number, string* comandos){
    if(comandos[number + 1] != ""){
        cout << "Numero de argumentos invalido" << endl;
        cout << "Este comando utiliza " << number <<  " argumento(s)" << endl;
        return true;
    }
    return false;
}

string* deconstructor(string comando) //recebe frase, descontroi-a em palavras, devolve ponteiro para array com palavras.
{
    int i = 0;
    string word;
    string comandos[4];
    for (auto x : comando) //separa os diferentes argumentos
    {
        if (x == ' ')
        {
             if (word == "") //se espaços seguidos, avança para próximo caráter
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

/*
void checkBuildings(vector<vector<cell>> &cells,string rows, string cols){
    int irows = stoi(rows);
    int icols = stoi(cols);

    if(cells[irows-1][icols-1].building == ""){
        return 1;
    }
    else{
        return 0;
    }
};
*/

int checkTypeBuildings(string* comandos,vector<vector<cell>> &cells){

    int i,vef=0;

    string buildings[5] = {"mnf","mnc","elec","bat","fun"};

    for(i=0;i<5;i++){
        if(comandos[1] == buildings[i]){
            continue;
        }
        else{
            vef = 1;
        }
    }
    if(vef == 1){
        return 1;
    }

/*    if(comandos[1] == buildings[1]){
        checkBuildings(cells,comandos[2],comandos[3]);
    }
    if(comandos[1] == buildings[2]){
        checkBuildings(cells,comandos[2],comandos[3]);
    }
    if(comandos[1] == buildings[3]){
        checkBuildings(cells,comandos[2],comandos[3]);
    }
    if(comandos[1] == buildings[4]){
        checkBuildings(cells,comandos[2],comandos[3]);
    }
    if(comandos[1] == buildings[5]){
        checkBuildings(cells,comandos[2],comandos[3]);
    }*/
}

/*void checkLinhasColunas(string linha,string coluna,string tipo){

}*/

void commands(vector<vector<cell>> &cells){

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
/*            else{
 *              if(checkTipeBuilding(comandos,cells) == 1){
 *                  continue;
 *              }
 *
            }*/

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

