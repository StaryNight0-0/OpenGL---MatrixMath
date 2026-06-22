#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Graphics/Shaders.h"
#include <glm/gtc/matrix_transform.hpp>
#include <string>


class MainLoop{

public:


SDL_Event event;
bool quit = false;
bool imguiActive = false;
const Uint8 *state = SDL_GetKeyboardState(NULL);
float uOffsetZ = 0.0f;
float uOffsetX = 0.0f;
float rotation = 0.0f;
float lastTime = 0;


glm::mat4 model = glm::mat4(1.0f);


void loop();
void preDraw();
void draw();
void Input();
void imgui();

Window win;
Shaders shader;

};
