#include "Sprite.hpp"
#include <conio.h>

int main() {
    char** map;
    char** foreground;
    map = new char* [3];
    foreground = new char* [3];
    for (int i = 0; i < 3; i++) {
        map[i] = new char [4];
        foreground[i] = new char [4];
        for (int j = 0; j < 4; j++) {
            map[i][j] = '0'+i;
            foreground[i][j] = j;
        }
    }
    Sprite s(10, 3, 4, 3, map, foreground);
    s.print();
    system("Pause");
}