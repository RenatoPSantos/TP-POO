#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "map.h"
#include "comandos.h"


using namespace std;

int main() {
    srand( (unsigned int) time(nullptr) );
    int rows,cols;
    bool vef;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;
    Map mapa(rows, cols);
    mapa.print();

    while(vef = true) {
        string command;
        cout << "Comando: ";
        getline(cin >> ws, command);
        Commands commands(mapa, command);
        mapa.print();
    }

    cout << "\nJOGO EM DESENVOLVIMENTO" << endl;

    return 0;
}
