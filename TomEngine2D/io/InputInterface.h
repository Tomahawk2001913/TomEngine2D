#pragma once

#include <SDL2/SDL.h>
#include "../Common.h"

namespace tom {
	namespace io {
		class TOM_API InputInterface {
		public:
			// Use SDL2's keycode system.
			virtual void keyPressed(SDL_Keycode keyCode) = 0;
			virtual void keyReleased(SDL_Keycode keyCode) = 0;
			
			// Gets the mouse's x, y, x difference, and y difference everytime the mouse is moved.
			virtual void mouseMoved(int x, int y, int dx, int dy) = 0;
		};
	}
}

