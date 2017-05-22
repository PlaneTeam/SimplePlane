#include "Input.hpp"
#include "Sprite.hpp"

int main() {
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
    Sprite s(10, 3, 4, 3, map, foreground);
    Input::init();
    Graphics::getInstance()->setFrame(120);
    while (true) {
        //system("cls");
        Graphics::update();
        Input::update();
        if (Input::trigger(Input::W)) {
            s.setRealPosition(s.getRealX(), s.getRealY()-1);
        }
        if (Input::trigger(Input::A)) {
            s.setRealPosition(s.getRealX()-1, s.getRealY());
        }
        if (Input::trigger(Input::S)) {
            s.setRealPosition(s.getRealX(), s.getRealY()+1);
        }
        if (Input::trigger(Input::D)) {
            s.setRealPosition(s.getRealX()+1, s.getRealY());
        }
    }
    system("Pause");
}