#include "AssetDatabase.h"

#include <iostream>

#include "SDL_image.h"

#include "Toolbox.h"

std::map<std::string, SDL_Texture*> AssetDatabase::textures;

SDL_Texture* AssetDatabase::LoadTexture(const std::string& _name, const std::string& _path)
{
	if (textures.find(_name) == textures.end())
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
		texture = SDL_CreateTextureFromSurface(Toolbox::GetSDLManager()->GetRenderer(), surface);
		if (texture == nullptr)
		{
			std::cout << "[ERROR] AssetDatabase: Could not create texture from path: " << _path << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}
		else
		{
			textures.insert(std::pair<std::string, SDL_Texture*>(_name, texture));
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

SDL_Texture* AssetDatabase::GetTexture(const std::string& _name)
{
	return textures[_name];
}