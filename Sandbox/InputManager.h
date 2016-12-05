#pragma once

#include <io/InputInterface.h>
#include <graphics/Camera.h>

class InputManager : public tom::io::InputInterface {
public:
	InputManager(tom::graphics::Camera* camera);
	~InputManager();

	void keyPressed(SDL_Keycode key);
	void keyReleased(SDL_Keycode key);
	void mouseMoved(int x, int y, int dx, int dy);
private:
	tom::graphics::Camera* camera;
};

