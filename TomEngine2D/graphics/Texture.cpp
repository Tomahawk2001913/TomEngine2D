#include "Texture.h"

#include <SDL2/SDL_image.h>

namespace tom {
	namespace graphics {
		Texture::Texture(std::string filePath) {
			load(filePath);
		}

		Texture::~Texture() {
			// Delete texture?
		}

		void Texture::bind() {
			glBindTexture(GL_TEXTURE_2D, textureID);
		}

		void Texture::unbind() {
			glBindTexture(GL_TEXTURE_2D, NULL);
		}

		unsigned int Texture::getWidth() {
			return width;
		}

		unsigned int Texture::getHeight() {
			return height;
		}

		// Private

		void Texture::load(std::string filePath) {
			// Generate texture ID.
			glGenTextures(1, &textureID);

			// Bind texture ID.
			glBindTexture(GL_TEXTURE_2D, textureID);

			// Set texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			
			// Set texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			//
			// TODO: add error checking about everywhere in this method.
			//

			// Load image from file.
			SDL_Surface* temp = IMG_Load(filePath.c_str());

			// Set width and height.
			width = temp->w;
			height = temp->h;

			// Determine pixel mode.
			GLuint mode = GL_RGB;
			if(temp->format->BitsPerPixel == 4) mode = GL_RGBA;

			// Send the texture to OpenGL.
			glTexImage2D(GL_TEXTURE_2D, 0, mode, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (unsigned char*) temp->pixels);

			// Free the SDL_Surface.
			SDL_FreeSurface(temp);
			temp = NULL;

			// Unbind the texture ID.
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}