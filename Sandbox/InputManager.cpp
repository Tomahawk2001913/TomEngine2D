#include "InputManager.h"

#include <iostream>
#include <SDL2/SDL.h>

InputManager::InputManager(tom::graphics::Camera* camera) {
	this->camera = camera;
}

InputManager::~InputManager() {

}

void InputManager::keyPressed(SDL_Keycode key) {
	std::cout << "Key pressed!" << std::endl;
	camera->translate(0, 20);
}

void InputManager::keyReleased(SDL_Keycode key) {

}

void InputManager::mouseMoved(int x, int y, int dx, int dy) {

}
