#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <windows.h>

/*  Input类: 处理键盘输入的模块
 *
 *  ## method ##
 *  static bool init(); // 用于初始化键盘输入模块, 未经初始化使用Input类会产生不明错误。
 *      @return: 是否初始化成功
 *
 *  static void update(); // 更新按键信息, 1s内不执行该函数将表示程序出错
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
    static BYTE old_map[256];
    static BYTE new_map[256];
    static bool is_trigger[256];

    public:
    enum key {
        A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        NUM0 = '0', NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
        NUMPAD0 = VK_NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9,
        LSHIFT = VK_LSHIFT
    };

    static bool init() {
        return GetKeyboardState(new_map);
    }

    static void update() {
        memcpy(old_map, new_map, 256 * sizeof(BYTE));
        for (int i = 0; i < 256; i++) {
            short state = GetKeyState(i);
            new_map[i] = static_cast<BYTE>(state & 0xff);
            is_trigger[i] = (state & 0x8000);
        }
    }

    static bool press(key k) {
        return (old_map[k] & 1) != (new_map[k] & 1);
    }

    static bool trigger(key k) {
        return is_trigger[k];
    }
};


BYTE Input::old_map[256] = {0};
BYTE Input::new_map[256] = {0}; 
bool Input::is_trigger[256] = {0};

#endif
