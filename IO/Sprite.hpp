#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <fstream>
#include <string>
#include <windows.h>
#include <cstdio>
#include "Bitmap.hpp"
#include "SpriteBase.hpp"
#include "Graphics.hpp"
using namespace std;

#ifndef UNICODE
#define UNICODE
#endif

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
    int real_x;
    int real_y;
    Bitmap* pic;

    public:
    Sprite(int _real_x, int _real_y, string path) {
        real_x = _real_x;
        real_y = _real_y;
        pic = new Bitmap(path);
        Graphics::getInstance()->pushSprite(this);
    }

    Sprite(int _real_x, int _real_y, int _width, int _height, string str = "") {
        real_x = _real_x;
        real_y = _real_y;
        pic = new Bitmap(_width, _height, str);
        Graphics::getInstance()->pushSprite(this);
    }

    Sprite(int _real_x, int _real_y, int _width, int _height, char** _bitmap, char** _foreground) {
        real_x = _real_x;
        real_y = _real_y;
        pic = new Bitmap(_width, _height, _bitmap, _foreground);
        Graphics::getInstance()->pushSprite(this);
    }

    ~Sprite() {
        delete pic;
        Graphics::getInstance()->popSprite(this);
    }

    virtual void print() {
        for (int i = 0; i < pic->height; i++) {
            SetConsoleCursorPosition(Window::handle, COORD{static_cast<short>(real_x), static_cast<short>(real_y + i)});
            for (int j = 0; j < pic->width; j++) {
                SetConsoleTextAttribute(Window::handle, pic->foreground[i][j] & 0xf);
                putchar(pic->bitmap[i][j]);
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

    Bitmap& bitmap() {
        return *pic;
    }
};

#endif
