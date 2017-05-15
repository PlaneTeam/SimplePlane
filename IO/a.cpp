#include "Sprite.hpp"
#include <conio.h>

int main() {
    char** map;
    map = new char* [3];
    for (int i = 0; i < 3; i++) {
        map[i] = new char [4];
        for (int j = 0; j < 4; j++) {
            map[i][j] = '0'+i;
        }
    }
    Sprite s(10, 3, 4, 3, map);
    s.print();
    system("Pause");
}