#include <iostream>
#include "Input.hpp"
#include "Sprite.hpp"

int main() {
    Sprite* s;
    int index;
    std::cout << "test (0-1): ";
    std::cin >> index;
    switch (index) {
        case 0:
        char** map;
        char** foreground;
        map = new char* [3];
        foreground = new char* [3];
        for (int i = 0; i < 3; i++) {
            map[i] = new char [4];
            foreground[i] = new char [4];
            for (int j = 0; j < 4; j++) {
                map[i][j] = '0'+i;
                foreground[i][j] = j;
            }
        }
        s = new Sprite(10, 3, 4, 3, map, foreground);
        break;

        case 1:
        s = new Sprite(10, 3, "plane.pbm");
        break;
    }
    Input::init();
    std::cout << "please input the frame:";
    int n;
    std::cin >> n;
    Graphics::getInstance()->setFrame(n);
    while (true) {
        //system("cls");
        Graphics::update();
        Input::update();
        if (Input::trigger(Input::W)) {
            s->setRealPosition(s->getRealX(), s->getRealY()-1);
        }
        if (Input::trigger(Input::A)) {
            s->setRealPosition(s->getRealX()-1, s->getRealY());
        }
        if (Input::trigger(Input::S)) {
            s->setRealPosition(s->getRealX(), s->getRealY()+1);
        }
        if (Input::trigger(Input::D)) {
            s->setRealPosition(s->getRealX()+1, s->getRealY());
        }
    }
    system("Pause");
}