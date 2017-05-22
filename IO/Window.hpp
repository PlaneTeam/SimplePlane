#ifndef BASE_HPP_
#define BASE_HPP_

#include "windows.h"

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
};

#endif
