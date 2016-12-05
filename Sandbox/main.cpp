#include <iostream>
#include <graphics/Window.h>
#include <TomEngine2D.h>
#include "SimpleGame.h"
#include "InputManager.h"

int main(int argc, char* argv[]) {
	using namespace tom::graphics;

	tom::initialize();

	SimpleGame game;
	game.start();

	tom::quit();

	return 0;
}