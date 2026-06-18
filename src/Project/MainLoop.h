#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Graphics/Shaders.h"
#include <glm/gtc/matrix_transform.hpp>


class MainLoop{

public:


SDL_Event event;
bool quit = false;
const Uint8 *state = SDL_GetKeyboardState(NULL);
float uOffset = 0.0f;

void loop();
void preDraw();
void draw();
void Input();

Window win;
Shaders shader;

};
