#include "VkEngine.h"

#include <SDL.h>
#include <SDL_vulkan.h>

#include <vk_initializers.h>
#include <vk_types.h>

#include <chrono>
#include <thread>


constexpr bool bUseValidationLayers = false;

VulkanEngine* loadedEngine = nullptr;

VulkanEngine& VulkanEngine::Get() {return *loadedEngine; }

void VulkanEngine::init(){

assert(loadedEngine == nullptr);
loadedEngine = this;

SDL_Init(SDL_INIT_VIDEO);
SDL_WindowFlags windowflags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

window = SDL_CreateWindow("Caboodle",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,windowExtent.width,windowExtent.height,windowflags);

_isInitialized = true;

}


void VulkanEngine::cleanup(){
	if(_isInitialized){
		SDL_DestroyWindow(window);
	}

	loadEngine = nullptr;
}

void VulkanEngine::draw(){

}

void VulkanEngine::run(){
SDL_Event event;
bool isRunning = true;

while(isRunning){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT)
				isRunning = false;

			if(event.type == SDL_WINDOWEVENT){
				if(event.winodw.event == SDL_WINDOWEVENT_MINIMIZED){
					stop_rendering = true;
				}
				if(event.window.event == SDL_WINDOWEVENT_RESTORED){
					stop_rendering = false;
				}
			}

			if(event.type == SDL_KEYBOARDEVENT){

			if(state[SDL_SCANCODE_ESCAPE]){
			isRunning = false;
		            }
			}
		}

		
	}


	       if(stop_rendering){
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		continue
	}

	draw();
}
