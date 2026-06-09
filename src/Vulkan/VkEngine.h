#pragma once

#include <VkTypes.h>

class VulkanEngine{

public:
	bool _isInitialized{false};
	int _frameNumber {0};
	bool stop_rendering{false};
	VkExtent2D _windowExtent{ 1700 , 900};

	struct SDL_Window* window{nullptr};

	static VulkanEngine& Get();


	void init();

	void cleanup();

	void draw();

	void run();




	
};
