#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <windows.h>
#include <cstdio>

class Sprite {
    private:
    static HANDLE console_handle;
    char** bitmap;
    short width;
    short height;
    short real_x;
    short real_y;

    public:
    Sprite(short _real_x, short _real_y, short _width, short _height, char** _bitmap) {
        real_x = _real_x;
        real_y = _real_y;
        width = _width;
        height = _height;
        bitmap = new char* [height];
        for (int i = 0; i < height; i++) {
            bitmap[i] = new char [width];
            for (int j = 0; j < width; j++) {
                bitmap[i][j] = _bitmap[i][j];
            }
        }
    }

    ~Sprite() {
        for (int i = 0; i < height; i++) {
            delete [] bitmap[i];
        }
        delete [] bitmap;
    }

    void print() {
        for (int i = 0; i < height; i++) {
            SetConsoleCursorPosition(console_handle, COORD{real_x, static_cast<short>(real_y + i)});
            for (int j = 0; j < width; j++) {
                putchar(bitmap[i][j]);
            }
        }
    }
};

HANDLE Sprite::console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

#endif
