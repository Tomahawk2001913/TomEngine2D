#include "SimpleGame.h"

SimpleGame::SimpleGame() {
	renderer = new tom::graphics::Renderer(std::string("assets/shaders/vertex.glsl"), std::string("assets/shaders/fragment.glsl"));
	camera = new tom::graphics::Camera(window->getWidth(), window->getHeight());
	input = new InputManager(camera);
	texture = new tom::graphics::Texture(std::string("assets/textures/test.png"));

	setInputInterface(input);
}

SimpleGame::~SimpleGame() {
	delete renderer;
	delete camera;
	delete input;
	delete texture;
}

void SimpleGame::render() {
	renderer->begin();
	renderer->setProjectionMatrix(camera->getProjectionMatrix());
	renderer->render(texture, 0, 0, 300, 300);
	renderer->end();
}

void SimpleGame::update(float delta) {

}