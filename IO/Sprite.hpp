#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <fstream>
#include <string>
#include <windows.h>
#include <cstdio>
#include "SpriteBase.hpp"
#include "Graphics.hpp"
using namespace std;

#define UNICODE

/*  Sprite类: 精灵类, 处理精灵储存图片输出
 *
 *  ## method ##
 *  Sprite(int _real_x, int _real_y, int _width, int _height, char** _bitmap, char** _foreground);
 *      // 构造函数, 精灵的初始化
 *      @param: _real_x 绝对x坐标, _real_y 绝对y坐标, _width 精灵宽度, _height 精灵高度, _bitmap 精灵图, _foreground 精灵前景色
 *
 *  void print(); // 输出精灵, 不建议使用
 *  
 *  void setRealPosition(int _real_x, int _real_y); // 设置精灵绝对x,y坐标
 *      @param: _real_x 绝对x坐标, _real_y 绝对y坐标
 */
class Sprite : public SpriteBase {
    private:
    static HANDLE console_handle;
    char** bitmap;
    char** foreground;
    int width;
    int height;
    int real_x;
    int real_y;

    public:
    Sprite(int _real_x, int _real_y, string path) {
        real_x = _real_x;
        real_y = _real_y;
        ifstream file;
        file.open(path, ios::in);
        if (!file) {
            MessageBox(NULL, path.c_str(), "Invalid Sprite Path!", 0);
            file.close();
            exit(-1);
        } else {
            file >> width >> height;
            bitmap = new char* [height];
            foreground = new char* [height];
            for (int i = 0; i < height; i++) {
                bitmap[i] = new char [width];
                foreground[i] = new char [width];
                file.get();
                for (int j = 0; j < width; j++) {
                    bitmap[i][j] = file.get();
                }
                for (int j = 0; j < width; j++) {
                    int var;
                    file >> var;
                    foreground[i][j] = static_cast<char>(var);
                }
            }
            file.close();
        }
        Graphics::getInstance()->pushSprite(this);
    }

    Sprite(int _real_x, int _real_y, int _width, int _height, char** _bitmap, char** _foreground) {
        real_x = _real_x;
        real_y = _real_y;
        width = _width;
        height = _height;
        bitmap = new char* [height];
        foreground = new char* [height];
        for (int i = 0; i < height; i++) {
            bitmap[i] = new char [width];
            foreground[i] = new char [width];
            for (int j = 0; j < width; j++) {
                bitmap[i][j] = _bitmap[i][j];
                foreground[i][j] = _foreground[i][j];
            }
        }
        Graphics::getInstance()->pushSprite(this);
    }

    ~Sprite() {
        for (int i = 0; i < height; i++) {
            delete [] bitmap[i];
            delete []  foreground[i];
        }
        delete [] bitmap;
        delete [] foreground;
        Graphics::getInstance()->popSprite(this);
    }

    virtual void print() {
        for (int i = 0; i < height; i++) {
            SetConsoleCursorPosition(console_handle, COORD{static_cast<short>(real_x), static_cast<short>(real_y + i)});
            for (int j = 0; j < width; j++) {
                SetConsoleTextAttribute(console_handle, foreground[i][j] & 0xf);
                putchar(bitmap[i][j]);
            }
        }
    }

    void setRealPosition(int _real_x, int _real_y) {
        real_x = _real_x;
        real_y = _real_y;
    }

    int getRealX() {
        return real_x;
    }

    int getRealY() {
        return real_y;
    }
};

HANDLE Sprite::console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

#endif
