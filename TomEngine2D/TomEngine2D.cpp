#include "TomEngine2D.h"

#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include <GLEW/GL/glew.h>

namespace tom {
	bool initialize() {
		SDL_SetMainReady();

		std::cout << "Initializing TomEngine2D version " << VERSION << "." << std::endl;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			std::cout << "Error initializing SDL2: " << std::endl << SDL_GetError() << std::endl;
			return false;
		}

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
			std::cout << "Error initializing SDL2_image: " << std::endl << IMG_GetError() << std::endl;
		}

		std::cout << "Done initializing TomEngine2D." << std::endl;

		return true;
	}

	void quit() {
		SDL_Quit();
	}
}