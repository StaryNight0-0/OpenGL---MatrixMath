#pragma once
#include <iostream>
#include <SDL2/SDL.h>


class MainLoop{

public:


SDL_Event event;
bool quit = false;

void loop();
void preDraw();
void draw();
void Input();

};
