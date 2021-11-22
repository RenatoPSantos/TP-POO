#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "ilha.h"
using namespace std;

void ilha::printIlha() {

    int i, j, h, a, b, x=0;

    vector<vector<char>> ilha;
    for (h = 0; h < 16; h++) {
        vector<char>temp;
        for(b = 0;b < 16;b++){
            temp.push_back(' ');
        }
        ilha.push_back(temp);
    }
    


    for (b = 0; b < 3; b++) {
        for (a = 0; a < 16; a++) {
            cout << "_";
        }
        cout << endl;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                cout << "|";
                for (h = 0; h < 4; h++) {
                    cout << ilha[x][h];
                }
            }
            x++;
            cout << endl;
        }

    }
    for (a = 0; a < 16; a++) {
        cout << "_";
    }
    cout << endl;
}