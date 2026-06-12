
#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <cstdlib>
#include "Project/Window.h"
#include "Project/MainLoop.h"








int main(int argc, char* argv[]) {

MainLoop mainloop;
Window win;

win.init();
mainloop.loop();


win.cleanup();
	





return 0;

}
