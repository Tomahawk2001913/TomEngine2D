#pragma once

#include <string>
#include <GLEW/GL/glew.h>
#include <glm/glm.hpp>
#include "../Common.h"

namespace tom {
	namespace graphics {
		class TOM_API ShaderProgram {
		public:
			ShaderProgram(std::string vertexPath, std::string fragmentPath);
			virtual ~ShaderProgram();
			
			GLuint getUniformLocation(const GLchar* uniformName);

			void setUniformMatrix4(const GLchar* name, glm::mat4 matrix);

			void setUniformVector2(const GLchar* name, glm::vec2 vector);
			void setUniformVector3(const GLchar* name, glm::vec3 vector);
			void setUniformVector4(const GLchar* name, glm::vec4 vector);

			void enable();
			void disable();
		private:
			GLuint programID = NULL, vertexID = NULL, fragmentID = NULL;
			
			GLuint compileShader(GLenum type, std::string path);



			bool linkShaders();
		};
	}
}