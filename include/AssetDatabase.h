#pragma once

#include <map>

#include "Texture.h"

class AssetDatabase
{
public:
	static Texture* LoadTexture(const std::string& _name, const std::string& _path);
	static Texture* GetTexture(const std::string& _name);

private:
	static std::map<std::string, Texture*> textures;
};