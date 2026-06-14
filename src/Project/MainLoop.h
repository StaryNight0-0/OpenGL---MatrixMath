#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Graphics/Shaders.h"


class MainLoop{

public:


SDL_Event event;
bool quit = false;

void loop();
void preDraw();
void draw();
void Input();

Window win;
Shaders shader;

};
