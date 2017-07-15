#include "Window.hpp"

HANDLE Window::handle = GetStdHandle(STD_OUTPUT_HANDLE);
SMALL_RECT Window::window = { Left: 0, Top: 0, Right: 80, Bottom: 25 };
