#pragma once

#include <string>
#include "Common.h"
#include "graphics/Window.h"
#include "io/InputInterface.h"

namespace tom {
	class TOM_API SimpleApplication {
	public:
		SimpleApplication(std::string title = "SimpleApplication");
		virtual ~SimpleApplication();

		// Pass some kind of batch renderer to the render method in the future?
		virtual void render() = 0;
		virtual void update(float delta) = 0;

		virtual void start();

		virtual void setInputInterface(tom::io::InputInterface* inputInterface);
	protected:
		tom::graphics::Window* window = NULL;
	private:
		tom::io::InputInterface* inputInterface = NULL;
		bool running = false;

		float frameTime = 0.0f;
		Uint32 startingTick = 0, lastTick = 0, frames = 0, frameRate = 0;

		bool loop();
		void limitFrameRate(unsigned int fps);
	};
}