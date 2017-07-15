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
    static HANDLE handle;
    static SMALL_RECT window;

    static void cursorDisable() {
        CONSOLE_CURSOR_INFO cursor_info;
        cursor_info.dwSize = 1;
        cursor_info.bVisible = false;
        SetConsoleCursorInfo(handle, &cursor_info);
    }

    static void windowInfoDisable() {
        SetConsoleWindowInfo(handle, true, &window);
    }

    static void cleanWindow() {
        DWORD charsWritten;
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(handle, &info);
        FillConsoleOutputCharacter(handle, ' ', info.dwSize.X * info.dwSize.Y, COORD{0,0}, &charsWritten);
    }
};

#endif
