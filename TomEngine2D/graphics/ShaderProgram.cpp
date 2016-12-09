#include "ShaderProgram.h"

#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

namespace tom {
	namespace graphics {
		ShaderProgram::ShaderProgram(std::string vertexPath, std::string fragmentPath) {
			programID = glCreateProgram();

			vertexID = compileShader(GL_VERTEX_SHADER, vertexPath);
			fragmentID = compileShader(GL_FRAGMENT_SHADER, fragmentPath);

			linkShaders();
		}

		ShaderProgram::~ShaderProgram() {
			glDetachShader(programID, vertexID);
			glDetachShader(programID, fragmentID);

			glDeleteProgram(programID);
			programID = NULL;
		}

		GLuint ShaderProgram::getUniformLocation(const GLchar* uniformName) {
			GLuint result = glGetUniformLocation(programID, uniformName);
			if(result == -1) std::cout << "Unable to find uniform: " << uniformName << std::endl;
			return result;
		}

		void ShaderProgram::setUniformMatrix4(const GLchar* name, glm::mat4 matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
		}

		void ShaderProgram::setUniformVector2(const GLchar* name, glm::vec2 vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}

		void ShaderProgram::setUniformVector3(const GLchar* name, glm::vec3 vector) {
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void ShaderProgram::setUniformVector4(const GLchar* name, glm::vec4 vector) {
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void ShaderProgram::enable() {
			glUseProgram(programID);
		}

		void ShaderProgram::disable() {
			glUseProgram(NULL);
		}

		// Private

		GLuint ShaderProgram::compileShader(GLenum type, std::string path) {
			GLuint id = glCreateShader(type);
			if(id == NULL) std::cout << "Failed to create shader: " << type << std::endl << "From: " << path << std::endl;

			// Load the shader from its file.

			std::ifstream shaderFile(path);

			if(!shaderFile.is_open()) std::cout << "Failed to open shader file: " << path << std::endl;

			std::string contents = "";
			std::string currentLine;

			while (std::getline(shaderFile, currentLine)) {
				contents.append(currentLine + "\n");
			}

			shaderFile.close();

			// Begin compiling the shader.

			const char* contentsCString = contents.c_str();
			glShaderSource(id, 1, &contentsCString, NULL);
			glCompileShader(id);

			GLint success;
			GLchar compileLog[512];
			glGetShaderiv(id, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(id, 512, NULL, compileLog);
				std::cout << "Failed to compile shader: " << path << std::endl << compileLog << std::endl;
			}

			return id;
		}

		bool ShaderProgram::linkShaders() {
			glAttachShader(programID, vertexID);
			glAttachShader(programID, fragmentID);
			glLinkProgram(programID);

			GLint success;
			glGetProgramiv(programID, GL_LINK_STATUS, &success);

			if (!success) {
				GLchar linkLog[512];
				glGetProgramInfoLog(programID, 512, NULL, linkLog);
				std::cout << "Error linking shaders: " << linkLog << std::endl;

				return false;
			}

			return true;

		}
	}
}