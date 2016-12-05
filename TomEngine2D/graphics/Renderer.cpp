#include "Renderer.h"

#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>

namespace tom {
	namespace graphics {
		Renderer::Renderer(std::string vertexShaderPath, std::string fragmentShaderPath) {
			shader = new ShaderProgram(vertexShaderPath, fragmentShaderPath);

			GLuint VBO = NULL;

			GLfloat VBOData[] = {
				1.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 0.0f,
				1.0f, 0.0f
			};

			GLuint indices[] = {
				0, 1, 3,
				1, 2, 3
			};

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(VBOData), VBOData, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*) 0);
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			
			glBindVertexArray(0);
		}

		Renderer::~Renderer() {

		}

		void Renderer::begin() {
			shader->enable();
		}

		void Renderer::end() {
			shader->disable();
		}

		void Renderer::render(Texture* texture, const float& x, const float& y) {
			render(texture, x, y, (float) texture->getWidth(), (float) texture->getHeight());
		}

		void Renderer::render(Texture* texture, const float& x, const float& y, const float& width, const float& height) {
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::translate(model, glm::vec3(x, y, 0.0f));

			model = glm::scale(model, glm::vec3(width, height, 0.0f));

			shader->setUniformMatrix4("modelMatrix", model);

			texture->bind();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			texture->unbind();
		}

		void Renderer::setProjectionMatrix(glm::mat4 matrix) {
			shader->setUniformMatrix4("projectionMatrix", matrix);
		}
	}
}