#include "Window.h"

#include <iostream>
#include <GLEW/GL/glew.h>

namespace tom {
	namespace graphics {
		Window::Window(std::string title, int width, int height, bool initGL) {
			this->title = title;
			this->width = width;
			this->height = height;

			if (initGL) initOpenGL();
		}

		Window::~Window() {
			// Destroy the window.
			SDL_DestroyWindow(window);
			window = NULL;
		}

		bool Window::initOpenGL() {
			if (!hasInitOpenGL) {
				window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

				resize(width, height);

				if (window == NULL) {
					std::cout << "Window failed to initialize." << std::endl;
					return false;
				}

				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

				SDL_GL_CreateContext(window);

				// Initialize GLEW
				glewExperimental = GL_TRUE;
				if (glewInit() != GLEW_OK) {
					std::cout << "Could not initialize GLEW." << std::endl;
					return false;
				}

				std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
			}
			else {
				std::cout << "OpenGL already initialized." << std::endl;
				return false;
			}

			return true;
		}

		void Window::swap() {
			SDL_GL_SwapWindow(window);
		}

		void Window::resize(int width, int height) {
			int x = 0, y = 0;
			
			SDL_GetWindowPosition(window, &x, &y);
			SDL_SetWindowSize(window, width, height);

			glViewport(x, y, width, height);
		}

		void Window::enableCursor(bool enabled) {
			SDL_ShowCursor(enabled);
		}

		int Window::getWidth() {
			return width;
		}

		int Window::getHeight() {
			return height;
		}
	}
}