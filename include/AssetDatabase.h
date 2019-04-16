#pragma once

#include <map>

#include "SDL_ttf.h"

#include "Texture.h"

class AssetDatabase
{
public:
	static Texture* LoadTexture(const std::string& _name, const std::string& _path);
	static Texture* GetTexture(const std::string& _name);
	static Texture* RenderText(const std::string& _fontPath, const int _size, const std::string& _text);

	static void ClearTextures();
	static void ClearFonts();
	static void ClearTexts();

private:
	static std::map<std::string, Texture*> textures;
	static std::map<std::string, TTF_Font*> fonts;
	static std::map<std::string, Texture*> texts;

	static TTF_Font* LoadFont(const std::string& _path, const int _size);
};