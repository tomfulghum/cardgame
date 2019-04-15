#include "AssetDatabase.h"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "Toolbox.h"

std::map<std::string, Texture*> AssetDatabase::textures;

Texture* AssetDatabase::LoadTexture(const std::string& _name, const std::string& _path)
{
	if (textures.find(_name) != textures.end())
	{
		std::cout << "[ERROR] AssetDatabase: Texture with name \"" << _name << "\" already exists in database!" << std::endl;
		return nullptr;
	}

	Texture* texture = nullptr;
	SDL_Texture* sdlTexture = nullptr;

	SDL_Surface* surface = IMG_Load(_path.c_str());
	if (surface == nullptr)
	{
		std::cout << "[ERROR] AssetDatabase: Could not load texture from path: " << _path << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}
	else
	{
		sdlTexture = SDL_CreateTextureFromSurface(Toolbox::GetEnvironment()->GetRenderer(), surface);
		if (sdlTexture == nullptr)
		{
			std::cout << "[ERROR] AssetDatabase: Could not create texture from path: " << _path << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}
		else
		{
			texture = new Texture(sdlTexture, surface->w, surface->h);
			textures.insert(std::pair<std::string, Texture*>(_name, texture));
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

Texture* AssetDatabase::GetTexture(const std::string& _name)
{
	return textures[_name];
}