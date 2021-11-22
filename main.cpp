#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "map.h"
#include "comandos.h"
#include "trabalhadores.h"
using namespace std;

int main() {

    int cols,rows;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;

    string a = "dfs";
    string b = "abc";

    vector<vector<string*>> map;
    vector<vector<cell>> cells;
    createMap(map,rows,cols);
    createCells(cells,rows,cols);
    cell::changeInf(cells,0,0,a,b);
    printMap(map);
    cell::getInf(cells);


    return 0;
}
