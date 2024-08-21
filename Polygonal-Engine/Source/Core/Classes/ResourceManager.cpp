#include "ResourceManager.h"

#include "stb/stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Polygame
{
	uint32_t ResourceManager::LoadTextureImpl(const char* name, const char* path)
	{
		// Return the texture if already loaded
		if (TextureMap.find(name) != TextureMap.end())
			return TextureMap[name];

		// Else, load the texture and put it in TextureMap
		uint32_t textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
		if (data)
		{
			GLenum format;
			if (nrChannels == 1)
				format = GL_RED;
			else if (nrChannels == 3)
				format = GL_RGB;
			else if (nrChannels == 4)
				format = GL_RGBA;
			else
			{
				std::cout << "No valid image format found!" << std::endl;
				return 0;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			const char* failureReason = stbi_failure_reason();
			std::cout << "Failed to load image: " << failureReason << std::endl;
			delete failureReason;
		}
		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);

		TextureMap[name] = textureID;
		return textureID;
	}
}

