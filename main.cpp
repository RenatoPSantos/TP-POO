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
    cout << "rows, cols" << endl;
    cin >> rows >> cols;

    vector<vector<string*>> map;
    vector<vector<Cell>> cells;

    createCells(cells, rows, cols);
    createMap(map, cells);
    printMap(map, cells);
  /*  commands();*/

   commands(map,cells);
   
   cout << "\nJOGO EM DESENVOLVIMENTO" << endl;




    return 0;
}
