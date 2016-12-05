#pragma once

#include <glm/glm.hpp>
#include "../Common.h"

namespace tom {
	namespace graphics {
		class TOM_API Camera {
		public:
			Camera(int width, int height);
			virtual ~Camera();

			virtual void translate(float x, float y);
			
			glm::mat4 Camera::getProjectionMatrix();
		private:
			glm::mat4 projectionMatrix;
			glm::vec3 position;
		};
	}
}