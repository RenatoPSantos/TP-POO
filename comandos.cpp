//     Código feito por: Renato Santos
//                       Sérgio Alves
//     Trabalho prático POO 2021/2022

#include <iostream>
#include <string>
#include <vector>

#include "comandos.h"
#include "trabalhadores.h"
#include "recursos.h"

using namespace std;

Commands::Commands(Map& mapa, Data& data) : mapa(mapa), data(data), next(false){}

void Commands::printScreen() const {
    mapa.print();
    cout << "Dinheiro: "<< data.getMoney();
    cout << " | ";
    cout << "Vigas: "<< data.getVigas().Quantidade();
    cout << " | ";
    cout << "Ferro: "<< data.getFerro().Quantidade();
    cout << " | ";
    cout << "Aco: "<< data.getAco().Quantidade();
    cout << " | ";
    cout << "Madeira: "<< data.getMadeira().Quantidade();
    cout << " | ";
    cout << "Carvao: "<< data.getCarvao().Quantidade();
    cout << " | ";
    cout << "Eletricidade: "<< data.getEletricidade().Quantidade();
    cout << endl;
}
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
            if (isNumber(commands[2]) && isNumber(commands[3])) {
                if (mapa.checkRowsCols(commands[2], commands[3])) {
                    cons(commands, stoi(commands[2]) - 1, stoi(commands[3]) - 1);
            } else {
                return 1;
            }
        } else {
            return 1;
            }
        }
        else{
            return 1;
        }
        return 1;
    }
    if (commands[0] == "liga") {
        if (checkArguments(2)) {
            if(isNumber(commands[1]) && isNumber(commands[2])){
                if(mapa.checkRowsCols(commands[1],commands[2])) {
                    if (mapa.getCells()[stoi(commands[1])-1][stoi(commands[2])-1].getBuilding().designacao() != "") {
                        mapa.getCells()[stoi(commands[1])-1][stoi(commands[2])-1].getBuilding().liga();
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
        return 1;
    }
    if (commands[0] == "des") {
        if (checkArguments(2)) {
            if(isNumber(commands[1]) && isNumber(commands[2])){
                if(mapa.checkRowsCols(commands[1],commands[2])) {
                    if (mapa.getCells()[stoi(commands[1])-1][stoi(commands[2])-1].getBuilding().designacao() != "") {
                        mapa.getCells()[stoi(commands[1])-1][stoi(commands[2])-1].getBuilding().desliga();

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
        return 1;
    }
    if (commands[0] == "move") {
        if (checkArguments(3)) {
            if(isNumber(commands[2]) && isNumber(commands[3])){
                if(mapa.checkRowsCols(commands[2],commands[3])){
                    cout << commands[0] << endl;
                    cout << commands[1] << endl;
                    cout << commands[2] << endl;
                    cout << commands[3] << endl;
                    mapa.moveWorker(stoi(commands[2]) - 1,stoi(commands[3]) - 1,commands[1]);
                    // sempre que mover um worker os dias de trabalho no local vao voltar ao 0, nao o global
                }
                return 1;
            }
            return 1;
        }
        return 1;

    }
    if (commands[0] == "vende") {
        if (checkArguments(2)) {
            if (isNumber(commands[1]) && isNumber(commands[2])) {
                if (mapa.checkRowsCols(commands[1], commands[2])) {

                    vende(stoi(commands[1]) - 1,stoi(commands[2]) - 1);

                } else {
                    return 1;
                }
            }
        } else {
            if (isNumber(commands[2])){

                vende(commands[1],stoi(commands[2]));

            } else {
                return 1;
            }
        }
        return 1;
    }
    if (commands[0] == "cont") {
        if (checkArguments(1)){
            if(commands[1] != "oper" && commands[1] != "len" && commands[1] != "miner"){
                cout << "Tipo de trabalhador invalido!";
                return 1;
            }
            if(commands[1] == "oper"){
                Operario oper(data.getDia());
                for (int i = 0; i < mapa.getCells().size(); i++) {
                    for (int j = 0; j < mapa.getCells()[0].size(); j++) {
                        if (mapa.getCells()[i][j].getBiome().designacao() == "pas") {
                            mapa.getCells()[i][j].addWorker(oper);
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
                            mapa.getCells()[i][j].addWorker(len);
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
                            mapa.getCells()[i][j].addWorker(min);
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
            list();
            return 1;
        }
        if (checkArguments(2)) {
            if (isNumber(commands[1]) && isNumber(commands[2]) &&
                mapa.checkRowsCols( commands[1], commands[2])) {
                list(commands[1], commands[2]);
                return 1;
            }
            return 1;
        } else {
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
            if (isInteger(commands[1])) {
                data.addMoney(stoi(commands[1]));
            } else {
                return 1;
            }
            return 1;
        }
    }
    if (commands[0] == "debed") {
        if (checkArguments(3) == 1) {
            if(isNumber(commands[2]) && isNumber(commands[3])){
                if(mapa.checkRowsCols(commands[2],commands[3])){
                    mapa.insertBuilding(commands);
                    increaseCapacity(mapa.getCells()[stoi(commands[2]) - 1][stoi(commands[3]) - 1].getBuilding());
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
        return 1;
    }
    if (commands[0] == "debkill") {
        if (checkArguments(1)) {
            mapa.findWorker(commands[1]); //Aaa
            return 1;
        }
    }else {
        cout << "O comando que inseriu esta errado" << endl;
        return 0;
    }
    system("pause");
    mapa.print();
    return 1;
}
int Commands::execConfig(vector<string> names,vector<int> values){

    if(names.size() != values.size()){
        cout << "O ficheiro config possui diferente numero de atributos"<< endl;
        return 1;
    }

    for(int i = 0; i < names.size();i++){ //dada

        if(values[i] >= 0){

            if(names[i] == "mnf"){

            }
            if(names[i] == "mnc"){

            }
            if(names[i] == "elec"){

            }
            if(names[i] == "bat"){

            }
            if(names[i] == "fun"){

            }
            if(names[i] == "Edificiox"){

            }
            if(names[i] == "oper"){

            }
            if(names[i] == "len"){

            }
            if(names[i] == "min"){

            }
        }
    }
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

void Commands::vende(int linha, int coluna) {

    if(mapa.getCells()[linha][coluna].getBuilding().designacao() != ""){
        data.addMoney(mapa.getCells()[linha][coluna].getBuilding().getPreco() +
                           mapa.getCells()[linha][coluna].getBuilding().getNivel() *
                           mapa.getCells()[linha][coluna].getBuilding().getUpgradePreco());
        decreaseCapacity(mapa.getCells()[linha][coluna].getBuilding());
        mapa.getCells()[linha][coluna].destroyBuilding();
    }
    else{
        cout << "Nao se encontra nenhum edificio nesse local" << endl;
    }
}

void Commands::vende(string tipo, int quant) {
    if(tipo == "ferro"){
        if(data.getFerro().Quantidade()>quant){
            data.getFerro().setQuantidade(data.getFerro().Quantidade()-quant);

            data.addMoney(quant * data.getFerro().Preco());
            return;
        }
        else {
            cout << "O jogador possui apenas: " << data.getFerro().Quantidade() << " de Ferro" << endl;
            return;
        }
    }
    if(tipo == "aco"){
        if(data.getCarvao().Quantidade()>quant){
            data.getCarvao().setQuantidade(data.getCarvao().Quantidade()-quant);

            data.addMoney(quant * data.getCarvao().Preco());
            return;

        }
        else {
            cout << "O jogador possui apenas: " << data.getCarvao().Quantidade() << " de Carvao" << endl;
            return;
        }
    }
    if(tipo == "mad"){
        if(data.getMadeira().Quantidade()>quant){
            data.getMadeira().setQuantidade(data.getMadeira().Quantidade()-quant);

            data.addMoney(quant * data.getMadeira().Preco());
            return;
        }
        else {
            cout << "O jogador possui apenas: " << data.getMadeira().Quantidade() << " de Madeira" << endl;
            return;
        }
    }
    if(tipo == "viga"){
        if(data.getVigas().Quantidade()>quant){
            data.getVigas().setQuantidade(data.getVigas().Quantidade()-quant);

            data.addMoney(quant * data.getVigas().Preco());
            return;
        }
        else {
            cout << "O jogador possui apenas: " << data.getVigas().Quantidade() << " de Vigas" << endl;
            return;
        }
    }
    if(tipo == "eletr"){
        if(data.getEletricidade().Quantidade()>quant){
            data.getEletricidade().setQuantidade(data.getEletricidade().Quantidade()-quant);

            data.addMoney(quant * data.getEletricidade().Preco());
            return;
        }
        else {
            cout << "O jogador possui apenas: " << data.getEletricidade().Quantidade() << " de Eletrecidade" << endl;
            return;
        }
    }
    cout << "O tipo de recurso introduzido encontra-se invalido" << endl;

}

void Commands::efeitos() {
   for(int i = 0;i < mapa.getRows();i++){
       for(int j = 0; j < mapa.getCols();j++){

           if(mapa.getCells()[i][j].getBuilding().getEfeitos() == 1){
               return;
           }
           else{
               if(mapa.getCells()[i][j].getBiome().designacao() == "dsr") {
                   if (mapa.getCells()[i][j].getBuilding().designacao() == "mnf" || mapa.getCells()[i][j].getBuilding().designacao() == "mnc"){
                       mapa.getCells()[i][j].getBuilding().setProducao(mapa.getCells()[i][j].getBuilding().getProducao()/2);
                       mapa.getCells()[i][j].getBuilding().setUpgradeProducao(mapa.getCells()[i][j].getBuilding().getUpgradeProducao()/2);

                       mapa.getCells()[i][j].getBuilding().setEfeitos(1);
                   }
               }
               if(mapa.getCells()[i][j].getBiome().designacao() == "flr"){
                   if(mapa.getCells()[i][j].getBuilding().designacao() != ""){

                       if(mapa.getCells()[i][j].getBiome().getTotalArvores()!= 0){
                           mapa.getCells()[i][j].getBiome().setTotalArvores(mapa.getCells()[i][j].getBiome().getTotalArvores()-1);
                       }
                       mapa.getCells()[i][j].getBiome().setProducao(0);
                       mapa.getCells()[i][j].getBiome().setDiasAtivos(0);
                   }
                   else{
                       mapa.getCells()[i][j].getBiome().setProducao(1);
                       if(mapa.getCells()[i][j].getBiome().getDiasAtivos() == 2){
                           if(mapa.getCells()[i][j].getBiome().getTotalArvores() != 100) {
                               mapa.getCells()[i][j].getBiome().setDiasAtivos(0);
                               mapa.getCells()[i][j].getBiome().setTotalArvores(mapa.getCells()[i][j].getBiome().getTotalArvores() + 1);
                           }
                       }
                   }
               }
               if(mapa.getCells()[i][j].getBiome().designacao() == "mnt"){

               }
               if(mapa.getCells()[i][j].getBiome().designacao() == "pnt"){

                   if(mapa.getCells()[i][j].getBiome().getDias() == 10){
                       //destruir edificio
                       mapa.getCells()[i][j].getBiome().setDias(0);
                   }
                   for(int k = 0;k < mapa.getCells()[i][j].getWorkers().size();k++){
                       if(mapa.getCells()[i][j].getWorkers()[k].getDias() == 10){
                           //remove workers
                       }
                       else{
                           mapa.getCells()[i][j].getWorkers()[k].addDias(1);
                       }
                   }
               }
           }
       }
   }
}

void Commands::decreaseCapacity(Edificios edificio){
    string str = edificio.designacao();
    if(str == "mnf"){
        data.getFerro().setCapacidade(-100);
    }
    if(str == "mnc"){
        data.getCarvao().setCapacidade(-100);
    }
    if(str == "elec"){
        data.getCarvao().setCapacidade(-100);
    }
    if(str == "bat"){
        data.getEletricidade().setCapacidade(-100);
    }
    if(str == "fun"){
        data.getAco().setCapacidade(-100);
    }
}
void Commands::increaseCapacity(Edificios edificio)
{
    string str = edificio.designacao();
    if(str == "mnf"){
        data.getFerro().setCapacidade(100);
    }
    if(str == "mnc"){
        data.getCarvao().setCapacidade(100);
    }
    if(str == "elec"){
        data.getCarvao().setCapacidade(100);
    }
    if(str == "bat"){
        data.getEletricidade().setCapacidade(100);
    }
    if(str == "fun"){
        data.getAco().setCapacidade(100);
    }
}

int Commands::cons(string* commands, int row, int col){

    string type = commands[1];
    int falta = mapa.getCells()[row][col].getBuilding().getPrecoVigas() - data.getVigas().Quantidade();
    if(mapa.insertBuilding(commands) == false)
        return 0;
    increaseCapacity(mapa.getCells()[row][col].getBuilding());

    if(data.getVigas().Quantidade() >= mapa.getCells()[row][col].getBuilding().getPrecoVigas()) {
        if (data.getMoney() >= mapa.getCells()[row][col].getBuilding().getPreco()) {
                cout << "dinheiro antes da venda " << data.getMoney() << endl;
                data.removeMoney(mapa.getCells()[row][col].getBuilding().getPreco());
                data.getVigas().setQuantidade(data.getVigas().Quantidade() - mapa.getCells()[row][col].getBuilding().getPrecoVigas());
                cout << "dinheiro depois da venda " << data.getMoney() << endl;
                return 1;
            } else {
                cout << "Dinheiro insuficiente" << endl;
                decreaseCapacity(mapa.getCells()[row][col].getBuilding());
                mapa.getCells()[row][col].destroyBuilding();
                return 0;
            }
    }else{
        if (data.getMoney() >= mapa.getCells()[row][col].getBuilding().getPreco() +
            falta * 10)
        {
            if (mapa.insertBuilding(commands)) {
                cout << "dinheiro antes da venda " << data.getMoney() << endl;
                data.removeMoney(mapa.getCells()[row][col].getBuilding().getPreco() + 10 * falta );
                data.getVigas().setQuantidade(data.getVigas().Quantidade() - (10 - falta));
                cout << "dinheiro depois da venda " << data.getMoney() << endl;
                return 1;
            }
        } else {
            cout << "Dinheiro insuficiente" << endl;
            decreaseCapacity(mapa.getCells()[row][col].getBuilding());
            mapa.getCells()[row][col].destroyBuilding();
            return 0;
        }
    }
    return 2;
}
void Commands::entregaRecursos(){
    cout << endl << "inicio" << endl;

    for(int i = 0; i < mapa.getRows()-1 ; i++){
        for(int j = 0; j < mapa.getCols()-1; j++){

            if(mapa.getCells()[i][j].getBuilding().designacao() != "") {

                if (mapa.getCells()[i][j].getBuilding().designacao() == "mnf") {
                    for (int k = 0; k < mapa.getCells()[i][j].getWorkers().size(); k++) {
                        if (mapa.getCells()[i][j].getWorkers()[k].designacao() == 'M') {
                            if (data.getFerro().Quantidade() + mapa.getCells()[i][j].getBuilding().getProducao() >= data.getFerro().getCapacidade()){
                                    data.getFerro().setCapacidade(data.getFerro().getCapacidade());


                            }
                            else{
                                data.getFerro().addQuantidade(mapa.getCells()[i][j].getBuilding().getProducao());


                            }
                        }
                    }
                }
                if(mapa.getCells()[i][j].getBuilding().designacao() == "mnc"){
                    for(int k = 0; k < mapa.getCells()[i][j].getWorkers().size();k++){
                        if(mapa.getCells()[i][j].getWorkers()[k].designacao() == 'M'){
                            if(data.getCarvao().Quantidade() + mapa.getCells()[i][j].getBuilding().getProducao() >= data.getCarvao().getCapacidade()){
                                data.getCarvao().setCapacidade(data.getCarvao().getCapacidade());
                                break;
                            }
                            else{
                                data.getCarvao().addQuantidade(mapa.getCells()[i][j].getBuilding().getProducao());
                                break;
                            }
                        }
                    }
                }
                if(mapa.getCells()[i][j].getBiome().designacao() == "flr"){
                    for(int k = 0; k < mapa.getCells()[i][j].getWorkers().size();k++){
                        if(mapa.getCells()[i][j].getWorkers()[k].designacao() == 'L' ){
                            if(mapa.getCells()[i][j].getWorkers()[k].getDias()<4){
                                if(data.getMadeira().Quantidade()+mapa.getCells()[i][j].getBuilding().getProducao()>= data.getMadeira().getCapacidade()){
                                    data.getMadeira().setCapacidade(data.getCarvao().getCapacidade());
                                    break;
                                }
                                else{
                                    data.getMadeira().addQuantidade(mapa.getCells()[i][j].getBuilding().getProducao());
                                    break;
                                }
                            }
                            mapa.getCells()[i][j].getWorkers()[k].setDias(0);
                        }
                    }
                }
                if(mapa.getCells()[i][j].getBuilding().designacao() == "elec"){
                    for(int k = 0; k < mapa.getCells()[i][j].getWorkers().size();k++){
                        if(mapa.getCells()[i][j].getWorkers()[k].designacao() == 'O'){
                            if(data.getMadeira().Quantidade() >= 1 && data.getCarvao().Quantidade()>=1){
                                if(i == 0 && j == 0) {
                                    if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {
                                                if(mapa.getCells()[i][j + 1].getWorkers()[l].getDias()<4){
                                                    if (mapa.getCells()[i+1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i][j + 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    } else if (mapa.getCells()[1][0].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[1][0].getWorkers().size(); l++) {
                                            if (mapa.getCells()[1][0].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[1][0].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[0][1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[0][0].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[0][0].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[1][0].getWorkers()[l].setDias(0);
                                            }

                                        }

                                    }
                                }
                                else if(i == 0 && j == mapa.getCols()-1){
                                    if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j-1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j - 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i + 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                              }
                                                mapa.getCells()[i][j - 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    } else if (mapa.getCells()[i+1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i+1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i+1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i + 1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j-1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i + 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                }
                                else if(i == mapa.getRows()-1 && j == 0){
                                    if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i-1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i - 1][j].getWorkers()[l].getDias() < 4){
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    } else if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j + 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i - 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i][j + 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                }
                                else if(i == mapa.getRows()-1 && j == mapa.getCols()-1){
                                    if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i-1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i - 1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }

                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    } else if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j-1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j-1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i - 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i][j-1].getWorkers()[l].setDias(0);
                                                }
                                            }

                                        }

                                    }
                                }
                                else if(i>0 && i<mapa.getRows()-1 && j == 0){
                                    if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i-1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i - 1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }

                                                }
                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i+1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i+1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i+1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i + 1][j].getWorkers()[l].getDias() < 4){
                                                    if (mapa.getCells()[i][j+1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                    else if(mapa.getCells()[i-1][j].getBuilding().designacao() == "bat"){
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }

                                            }
                                                mapa.getCells()[i + 1][j].getWorkers()[l].setDias(0);
                                        }}
                                    }
                                    if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j + 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i - 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i][j + 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                }
                                else if( i > 0 && i < mapa.getRows()-1 and j == mapa.getCols()-1 ){
                                    if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j - 1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j - 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i + 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i][j - 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i-1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i - 1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    if (mapa.getCells()[i+1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i+1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i + 1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i + 1][j].getWorkers()[l].getDias() < 4){
                                                    if (mapa.getCells()[i][j-1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                    else if(mapa.getCells()[i-1][j].getBuilding().designacao() == "bat"){
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }

                                            }
                                                mapa.getCells()[i + 1][j].getWorkers()[l].setDias(0);
                                        }
                                    }

                                }
                                else if( i == 0 &&  j > 0 && j < mapa.getCols() ){
                                    if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j-1].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i][j-1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i + 1][j].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i][j + 1].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }
                                                mapa.getCells()[i][j-1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i][j+1].getWorkers()[l].getDias() < 4){

                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }

                                                }
                                                mapa.getCells()[i][j+1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    if (mapa.getCells()[i+1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i+1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i+1][j].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i+1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i][j + 1].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }

                                                mapa.getCells()[i + 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }

                                }
                                else if( i == mapa.getRows()-1  &&  j > 0 && j < mapa.getCols()-1  ){
                                    if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j-1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j-1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }
                                                mapa.getCells()[i][j - 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i-1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i-1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i][j + 1].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }

                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i][j + 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }
                                                mapa.getCells()[i][j + 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }

                                }
                                else{
                                    if (mapa.getCells()[i+1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i+1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i+1][j].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i+1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i][j - 1].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }


                                                mapa.getCells()[i + 1][j].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i][j+1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j+1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j+1].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i][j+1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j - 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }
                                                mapa.getCells()[i][j + 1].getWorkers()[l].setDias(0);
                                            }
                                        }
                                    }
                                    else if (mapa.getCells()[i-1][j].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i-1][j].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i - 1][j].getWorkers()[l].designacao() == 'L') {

                                                if (mapa.getCells()[i - 1][j].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i][j - 1].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                                }
                                                mapa.getCells()[i - 1][j].getWorkers()[l].setDias(0);
                                        }
                                        }
                                    }
                                    else if (mapa.getCells()[i][j-1].getBiome().designacao() == "flr") {
                                        for (int l = 0; l < mapa.getCells()[i][j-1].getWorkers().size(); l++) {
                                            if (mapa.getCells()[i][j - 1].getWorkers()[l].designacao() == 'L') {
                                                if (mapa.getCells()[i][j - 1].getWorkers()[l].getDias() < 4) {
                                                    if (mapa.getCells()[i][j + 1].getBuilding().designacao() == "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i - 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    } else if (mapa.getCells()[i + 1][j].getBuilding().designacao() ==
                                                               "bat") {
                                                        if (data.getEletricidade().Quantidade() +
                                                            mapa.getCells()[i][j].getBuilding().getProducao() >=
                                                            data.getEletricidade().getCapacidade()) {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().setCapacidade(
                                                                    data.getEletricidade().getCapacidade());
                                                            break;
                                                        } else {
                                                            data.getMadeira().setQuantidade(
                                                                    data.getMadeira().Quantidade() - 1);
                                                            data.getCarvao().setQuantidade(
                                                                    data.getCarvao().Quantidade() - 1);
                                                            data.getEletricidade().addQuantidade(
                                                                    (mapa.getCells()[i][j].getBuilding().getProducao()));
                                                            break;
                                                        }
                                                    }
                                            }
                                                mapa.getCells()[i][j - 1].getWorkers()[l].setDias(0);
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "fim" << endl;
}
void Commands::despedimentos() {

    for(int i = 0;i < mapa.getRows();i++){
        for(int j = 0; j < mapa.getCols();j++){

            for(int k = 0; k < mapa.getCells()[i][j].getWorkers().size();k++){
                if(mapa.getCells()[i][j].getWorkers()[k].designacao() == 'O' && mapa.getCells()[i][j].getWorkers()[k].getDias() >= 10){
                    if((1+rand()% 100) < 5){
                        mapa.getCells()[i][j].getWorkers().erase(mapa.getCells()[i][j].getWorkers().begin() + k);
                    }
                }
            };
        }
    }

}
void Commands::list(const string& rows,const string& cols) const {
    mapa.list(rows, cols);
}
void Commands::list() const{ //aaaa
    cout << endl << "--Informação Geral--" << endl;
    cout << "Dinheiro -> " << data.getMoney() << endl;

}


bool isNumber(const string &s){

    for(char i : s){
        if (isdigit(i) == false) {
            cout << "As linhas/colunas devem ser numeros inteiros" << endl;
            system("pause");

            return false;
        }
    }
    return true;
}
bool isInteger(const string &s){ //aaaaa

    if(s[0] == '-'){
        for(int i = 1; i<s.size() ;i++){
            if(isdigit(s[i]) == false){
                cout << "Deve introduzir um numero inteiro como parametro" << endl;
                system("pause");

                return false;
            }

        }
        return true;
    }
    else{
        for(int i = 0; i < s.size() ; i++){
            if(isdigit(s[i]) == false){
                cout << "Deve introduzir um numero inteiro como parametro" << endl;
                system("pause");
                return false;
            }

        }
    }
    return true;
}

void clsConsole(){
    for(int i=0;i<30;i++){
        cout << endl;
    }
}

