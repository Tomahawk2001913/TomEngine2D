#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "../Common.h"

namespace tom {
	namespace graphics {
		class TOM_API Window {
		public:
			Window(std::string title, int width = 1280, int height = 720, bool initGL = true);
			virtual ~Window();

			bool initOpenGL();

			void swap();

			void resize(int width, int height);

			void enableCursor(bool enabled);

			int getWidth();
			int getHeight();
		private:
			SDL_Window* window;
			std::string title;
			int width, height;

			bool hasInitOpenGL = false;
		};


	}
}