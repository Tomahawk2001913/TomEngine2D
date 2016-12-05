#pragma once

#include <string>
#include <SimpleApplication.h>
#include <graphics/Renderer.h>
#include <graphics/Camera.h>
#include <graphics/Texture.h>
#include "InputManager.h"

class SimpleGame : public tom::SimpleApplication {
public:
	SimpleGame();
	~SimpleGame();

	void render();
	void update(float delta);
private:
	tom::graphics::Renderer* renderer;
	tom::graphics::Camera* camera;
	InputManager* input;
	tom::graphics::Texture* texture;
};

