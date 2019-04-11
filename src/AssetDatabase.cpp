#include "AssetDatabase.h"

#include <iostream>

#include "SDL_image.h"

#include "SDLManager.h"

std::map<std::string, SDL_Texture*> AssetDatabase::Textures;

SDL_Texture* AssetDatabase::LoadTexture(const std::string& _name, const std::string& _path)
{
	if (Textures.find(_name) == Textures.end())
	{
		std::cout << "[ERROR] AssetDatabase: Texture with name \" " << _name << "\" already exists in database!" << std::endl;
		return nullptr;
	}

	SDL_Texture* texture = nullptr;

	SDL_Surface* surface = IMG_Load(_path.c_str());
	if (surface == nullptr)
	{
		std::cout << "[ERROR] AssetDatabase: Could not load texture from path: " << _path << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(SDLManager::Instance()->GetRenderer(), surface);
		if (texture == nullptr)
		{
			std::cout << "[ERROR] AssetDatabase: Could not create texture from path: " << _path << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}
		else
		{
			Textures.insert(std::pair<std::string, SDL_Texture*>(_name, texture));
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}