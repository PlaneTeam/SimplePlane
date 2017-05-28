#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <windows.h>
using namespace std;

string save_path;
fstream file;

struct Sprite {
    int width;
    int height;
    char** bitmap;
    char** foreground;
} globe_sprite;

int IndexSelect() {
    system("cls");
    int index;
    cout << "1. New Sprite" << endl
         << "2. Open Sprite" << endl
         << "3. Quit" << endl << endl;
    cout << "Please input the index: ";
    cin >> index;
    return index;
}

int EditSelect() {
    system("cls");
    for (int i = 0; i < globe_sprite.height; i++) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{0, static_cast<short>(i)});
        for (int j = 0; j < globe_sprite.width; j++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), globe_sprite.foreground[i][j] & 0xf);
            putchar(globe_sprite.bitmap[i][j]);
        }
    }
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x27);
    cout << endl << "1. Modify Sprite" << endl
                 << "2. Save Sprite" << endl
                 << "3. Quit" << endl << endl;
    cout << "Please input the index: ";
    int index;
    cin >> index;
    return index;
}

bool InputInfo() {
    cout << "Please input sprite's width: ";
    cin >> globe_sprite.width;
    cout << "Please input sprite's height: ";
    cin >> globe_sprite.height;
    return globe_sprite.width > 0 && globe_sprite.height > 0;
}

bool InputPath() {
    cout << "Please input sprite's path: ";
    cin >> save_path;
    return save_path.size();
}

bool CreateFile() {
    ofstream file;
    file.open(save_path, ios::out);
    if (!file) {
        file.close();
        return false;
    } else {
        globe_sprite.bitmap = new char* [globe_sprite.height];
        globe_sprite.foreground = new char* [globe_sprite.height];
        for (int i = 0; i < globe_sprite.height; i++) {
            globe_sprite.bitmap[i] = new char [globe_sprite.width];
            globe_sprite.foreground[i] = new char [globe_sprite.width];
            for (int j = 0; j < globe_sprite.width; j++) {
                globe_sprite.bitmap[i][j] = ' ';
                globe_sprite.foreground[i][j] = 0;
            }
        }
        file.close();
        return true;
    }
}

bool LoadFile() {
    ifstream file;
    file.open(save_path, ios::in);
    if (!file) {
        file.close();
        return false;
    } else {
        file >> globe_sprite.width >> globe_sprite.height;
        globe_sprite.bitmap = new char* [globe_sprite.height];
        globe_sprite.foreground = new char* [globe_sprite.height];
        for (int i = 0; i < globe_sprite.height; i++) {
            globe_sprite.bitmap[i] = new char [globe_sprite.width];
            globe_sprite.foreground[i] = new char [globe_sprite.width];
            file.get();
            for (int j = 0; j < globe_sprite.width; j++) {
                globe_sprite.bitmap[i][j] = file.get();
            }
            for (int j = 0; j < globe_sprite.width; j++) {
                int var;
                file >> var;
                globe_sprite.foreground[i][j] = static_cast<char>(var);
            }
        }
        file.close();
        return true;
    }
}

bool SaveFile() {
    file.open(save_path, ios::out);
    if (!file) {
        file.close();
        return false;
    } else {
        file << globe_sprite.width << ' ' << globe_sprite.height << endl;
        for (int i = 0; i < globe_sprite.height; i++) {
            for (int j = 0; j < globe_sprite.width; j++) {
                file << globe_sprite.bitmap[i][j];
            }
            file << endl;
            for (int j = 0; j < globe_sprite.width - 1; j++) {
                file << static_cast<int>(globe_sprite.foreground[i][j]) << ' ';
            }
            file << static_cast<int>(globe_sprite.foreground[i][globe_sprite.width-1]) << endl;
        }
        file.close();
        return true;
    }
}

void ModifySprite() {
    int x, y, f;
    char b;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        putchar('0' + i);
    }
    for (int i = 10; i < 16; i++) {
        putchar('a' - 10 + i);
    }
    cout << endl;
    for (int i = 0; i < 16; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2*16+i);
        putchar('a' + i);
    }
    cout << endl;
    cout << "Please input info such as (x, y, bitmap, foreground): " << endl;
    cin >> x >> y >> b >> f;
    globe_sprite.bitmap[x][y] = b;
    globe_sprite.foreground[x][y] = static_cast<char>(f);
}

int main() {
    int index;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x27);
    cout << "Welcome to SpriteMaker!" << endl << endl;
    while (true) {
        index = IndexSelect();
        switch (index) {
            // New Sprite
            case 1:
                while (InputInfo() == false) {
                    cout << "Input invalid!" << endl;
                }
                while (InputPath() == false || CreateFile() == false) {
                    cout << "Input invalid!" << endl;
                }
                while((index = EditSelect()) != 3) {
                    switch (index) {
                        // Modify Sprite
                        case 1:
                            ModifySprite();
                            break;
                        case 2:
                            SaveFile();
                            break;
                    }
                }
                break;

            // Open Sprite
            case 2:
                while (InputPath() == false || LoadFile() == false) {
                    cout << "Input invalid!" << endl;
                }
                while((index = EditSelect()) != 3) {
                    switch (index) {
                        // Modify Sprite
                        case 1:
                            ModifySprite();
                            break;
                        case 2:
                            SaveFile();
                            break;
                    }
                }
                break;
            // Quit
            case 3:
                return 0;
        }
    }
}