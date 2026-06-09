
#include <iostream>
#include <SDL.h>
// #include <SDL/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>
#include <cstdlib>
#include "Vulkan/VkEngine.h"


	


int main(int argc, char* argv[]) {

VulkanEngine engine;

engine.init();
engine.run();
engine.cleanup();

return 0;

}
