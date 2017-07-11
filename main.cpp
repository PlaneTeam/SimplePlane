#include <iostream>
#include "IO.hpp"
#include "SceneStart.hpp"

int main() {
    Input::init();
    std::cout << "please input the frame:";
    int n;
    std::cin >> n;
    Graphics::getInstance()->setFrame(n);
    SceneStart scene;
    scene.main();
}