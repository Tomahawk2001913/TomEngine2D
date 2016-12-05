#include "SimpleApplication.h"

#include <iostream>
#include <GLEW/GL/glew.h>

namespace tom {
	SimpleApplication::SimpleApplication(std::string title) {
		window = new tom::graphics::Window(title);
	}


	SimpleApplication::~SimpleApplication() {
		delete window;
	}

	void SimpleApplication::start() {
		running = true;
		while (loop());
	}

	void SimpleApplication::setInputInterface(tom::io::InputInterface* inputInterface) {
		this->inputInterface = inputInterface;
	}

	bool SimpleApplication::loop() {
		startingTick = SDL_GetTicks();
		float delta = (startingTick - lastTick) / 1000.0f;
		lastTick = startingTick;
		
		frameTime += delta;
		if (frameTime >= 1) {
			frameTime -= 1;
			frameRate = frames;
			frames = 0;
			std::cout << "FPS: " << frameRate << std::endl;
		}

		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (inputInterface != NULL) inputInterface->keyPressed(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				if (inputInterface != NULL) inputInterface->keyReleased(event.key.keysym.sym);
				break;
			default:
				break;
				
			}
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();
		update(delta);

		window->swap();

		++frames;
		limitFrameRate(60);

		return running;
	}

	void SimpleApplication::limitFrameRate(unsigned int fps) {
		if ((1000 / fps) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / fps - (SDL_GetTicks() - startingTick));
		}
	}
}
