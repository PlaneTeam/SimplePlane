#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <windows.h>

/*  Input类: 处理键盘输入的模块
 *
 *  ## method ##
 *  static bool init(); // 用于初始化键盘输入模块, 未经初始化使用Input类会产生不明错误。
 *      @return: 是否初始化成功
 *
 *  static bool press(Input::key); // 判断按键是否按下, 检测按下的过程
 *      @param: Input::key 检测按键key值
 *      @return: 是否按下该按键
 *  
 *  static bool trigger(Input::key); // 判断按键是否处于按下状态, 结合{void Sleep(DWORD);}使用
 *      @param: Input::key 检测按键key值
 *      @return: 是否处于按下状态
 *
 *  ## const value ##
 *  Input::A, Input::B, Input::C, ...
 *  Input::NUM0, Input::NUM1, ...
 *  Input::NUMPAD0, Input::NUMPAD1, ... // 小数字键盘, 目前仍有问题 #BUG#
 */
class Input {
    private:
    static BYTE map[256];

    public:
    enum key {
        A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        NUM0 = '0', NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
        NUMPAD0 = VK_NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9,
        LSHIFT = VK_LSHIFT
    };

    static bool init() {
        return GetKeyboardState(map);
    }

    static bool press(key k) {
        short state = GetKeyState(k);
        if ((map[k] & 1) != (state & 1)) {
            map[k] = state & 0xff;
            return true;
        } else {
            return false;
        }
    }

    static bool trigger(key k) {
        short state = GetKeyState(k);
        if ((map[k] & 1) != (state & 1)) {
            map[k] = state & 0xff;
        }
        return state & 0x8000;
    }
};


BYTE Input::map[256] = {0}; 

#endif
