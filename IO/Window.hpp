#ifndef BASE_HPP_
#define BASE_HPP_

#include "windows.h"

/*  Window类: 窗体类, 控制台类, 控制控制台窗体
 *
 *  ## method ##
 *  static void cursorDisable(); // 隐藏光标
 *
 *  static void windowInfoDisable(); // 禁止窗体大小修改
 *
 *  static void cleanWindow(); // 清屏
 */
class Window {
    public:
    static void cursorDisable() {
        CONSOLE_CURSOR_INFO cursor_info;
        cursor_info.dwSize = 1;
        cursor_info.bVisible = false;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    }

    static void windowInfoDisable() {
        SMALL_RECT window;
        window.Left = 0;
        window.Top = 0;
        window.Right = 80;
        window.Bottom = 25;
        SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &window);
    }

    static void cleanWindow() {
        DWORD charsWritten;
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', info.dwSize.X * info.dwSize.Y, COORD{0,0}, &charsWritten);
    }
};

#endif
