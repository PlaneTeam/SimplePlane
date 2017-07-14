#ifndef BITMAP_HPP_
#define BITMAP_HPP_

#include <fstream>
#include <string>
#include <windows.h>
#include <cstdio>
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
class Bitmap {
  public:
    char** bitmap;
    char** foreground;
    int width;
    int height;

    Bitmap(string path) {
      ifstream file;
      file.open(path, ios::in);
      if (!file.is_open()) {
        MessageBox(NULL, path.c_str(), "Invalid Bitmap Path!", 0);
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
        }
        for (int i = 0; i < height; i++) {
          for (int j = 0; j < width; j++) {
            int var;
            file >> var;
            foreground[i][j] = static_cast<char>(var);
          }
        }
        file.close();
      }
    }

    Bitmap(int _width, int _height, string str = "") {
      width = _width;
      height = _height;
      bitmap = new char* [height];
      foreground = new char* [height];
      for (int i = 0; i < height; i++) {
        bitmap[i] = new char [width];
        foreground[i] = new char [width];
        for (int j = 0; j < width; j++) {
          bitmap[i][j] = 0;
          foreground[i][j] = 0x07;
        }
      }
      drawText(str);
    }

    Bitmap(int _width, int _height, char** _bitmap, char** _foreground) {
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
    }

    ~Bitmap() {
      for (int i = 0; i < height; i++) {
        delete [] bitmap[i];
        delete []  foreground[i];
      }
      delete [] bitmap;
      delete [] foreground;
    }

    void drawText(string str, int x = 0, int y = 0) {
      int index = 0;
      while (y < height) {
        if (x == width) {
          x = 0;
        }
        while (x < width) {
          if (index >= str.size()) {
            return;
          }
          bitmap[y][x++] = str[index++];
        }
        y++;
      }
    }

    void setAllForeground(char f) {
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          foreground[i][j] = f;
        }
      }
    }
};

#endif
