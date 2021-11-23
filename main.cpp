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

    srand(time(NULL));
    int rows,cols;
    cout << "rows, cols" << endl;
    cin >> rows >> cols;

    vector<vector<string*>> map;
    vector<vector<Cell>> cells;
    createCells(cells, rows, cols);
    createMap(map, cells);
    printMap(map, cells);
  /*  commands();*/

   commands();
   updateMap(map,cells);




    return 0;
}
