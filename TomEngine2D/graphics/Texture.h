#pragma once

#include <iostream>
#include <GLEW/GL/glew.h>
#include "../Common.h"

namespace tom {
	namespace graphics {
		class TOM_API Texture {
		public:
			Texture(std::string filePath);
			virtual ~Texture();

			void bind();
			void unbind();

			unsigned int getWidth();
			unsigned int getHeight();
		private:
			GLuint textureID = NULL;
			unsigned int width = 0, height = 0;

			void load(std::string filePath);
		};
	}
}

