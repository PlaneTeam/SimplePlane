#include <iostream>
#include <time.h>
#include "Input.hpp"
#include "Graphics.hpp"
using namespace std;

int main() {
    Input::init();
    int var;
    int b;
    cout << "Test Case(0,1): ";
    cin >> var;
    switch (var) {
        case 0:
        while (true) {
            Graphics::update();
            Input::update();
            if (Input::trigger(Input::LSHIFT) && Input::trigger(Input::C)) {
                cout << "Your always press C" << endl;
            }
            Sleep(100);
        }
        case 1:
        while (true) {
            Graphics::update();
            Input::update();
            if (Input::press(Input::C)) {
                cout << "Your press C" << endl;
            }
        }
        case 2:
            cin >> b;
            Graphics::getInstance()->setFrame(b);
        while(true){
            Graphics::update();
        }
    }
}
