:: build
g++ main.cpp ./Character/Player.cpp ./IO/Graphics.cpp ./IO/Input.cpp ./IO/Window.cpp -I. -I./Character -I./IO -I./Scene -std=c++14 -o plane.exe
