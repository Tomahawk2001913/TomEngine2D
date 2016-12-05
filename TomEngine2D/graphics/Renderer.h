#pragma once

#include <string>
#include <glm/glm.hpp>
#include "../Common.h"
#include "ShaderProgram.h"
#include "Texture.h"

namespace tom {
	namespace graphics {
		class TOM_API Renderer {
		public:
			Renderer(std::string vertexShaderPath, std::string fragmentShaderPath);
			virtual ~Renderer();

			void begin();
			void end();

			void render(Texture* texture, const float& x, const float& y);
			void render(Texture* texture, const float& x, const float& y, const float& width, const float& height);

			void setProjectionMatrix(glm::mat4 matrix);
		private:
			ShaderProgram* shader;

			GLuint VAO = NULL, EBO = NULL;
		};
	}
}