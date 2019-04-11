#pragma once

#include <map>

#include "SDL.h"

class AssetDatabase
{
public:
	static SDL_Texture* LoadTexture(const std::string& _name, const std::string& _path);

private:
	static std::map<std::string, SDL_Texture*> Textures;
};