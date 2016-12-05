#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace tom {
	namespace graphics {
		Camera::Camera(int width, int height) {
			projectionMatrix = glm::ortho(0.0f, (float) width, (float) height, 0.0f, -1.0f, 1.0f);
		}

		Camera::~Camera() {

		}

		void Camera::translate(float x, float y) {
			projectionMatrix = glm::translate(projectionMatrix, glm::vec3(x, y, 0.0f));
		}

		glm::mat4 Camera::getProjectionMatrix() {
			return projectionMatrix;
		}
	}
}