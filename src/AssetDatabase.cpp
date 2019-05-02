#include "AssetDatabase.h"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "Toolbox.h"

std::map<std::string, Texture*> AssetDatabase::textures;
std::map<std::string, TTF_Font*> AssetDatabase::fonts;
std::map<std::string, Texture*> AssetDatabase::texts;

Texture* AssetDatabase::LoadTexture(const std::string& _name, const std::string& _path)
{
	if (textures.find(_name) != textures.end())
	{
		std::cout << "[WARNING] AssetDatabase: Texture \"" << _name << "\" already exists in database!" << std::endl;
		return textures[_name];
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
			textures.insert_or_assign(_name, texture);
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

Texture* AssetDatabase::GetTexture(const std::string& _name)
{
	if (textures.find(_name) == textures.end())
	{
		std::cout << "[ERROR] AssetDatabase: Texture \"" << _name << "\" does not exist in database!" << std::endl;
		return nullptr;
	}

	return textures[_name];
}

Texture* AssetDatabase::RenderText(const std::string& _fontPath, const int _size, const std::string& _text, Color _color, const bool _save)
{
	std::string identifier = _fontPath + std::to_string(_size) + _color.ToString() + _text;

	if (_save && texts.find(identifier) != texts.end())
	{
		//std::cout << "[WARNING] AssetDatabase: Text \"" << identifier << "\" already exists in database!" << std::endl;
		return texts[identifier];
	}

	TTF_Font* font = LoadFont(_fontPath, _size);
	if (font == nullptr)
	{
		return nullptr;
	}

	Texture* texture = nullptr;
	SDL_Texture* sdlTexture = nullptr;
	SDL_Color color;
	color.r = _color.r;
	color.g = _color.g;
	color.b = _color.b;
	color.a = _color.a;
	SDL_Surface* surface = TTF_RenderText_Solid(font, _text.c_str(), color);

	if (surface == nullptr)
	{
		std::cout << "[ERROR] AssetDatabase: Could not create surface from text!" << std::endl;
		std::cout << TTF_GetError() << std::endl;
	}
	else
	{
		sdlTexture = SDL_CreateTextureFromSurface(Toolbox::GetEnvironment()->GetRenderer(), surface);
		if (sdlTexture == nullptr)
		{
			std::cout << "[ERROR] AssetDatabase: Could not create texture from surface!" << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}
		else
		{
			texture = new Texture(sdlTexture, surface->w, surface->h);
			if (_save)
			{
				texts.insert_or_assign(identifier, texture);
			}
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

void AssetDatabase::ClearTextures()
{
	for (auto& texture : textures)
	{
		delete(texture.second);
	}
	textures.clear();
}

void AssetDatabase::ClearFonts()
{
	for (auto& font : fonts)
	{
		TTF_CloseFont(font.second);
	}
	fonts.clear();
}

void AssetDatabase::ClearTexts()
{
	for (auto& text : texts)
	{
		delete(text.second);
	}
	texts.clear();
}

TTF_Font* AssetDatabase::LoadFont(const std::string& _path, const int _size)
{
	std::string name = _path + std::to_string(_size);

	if (fonts.find(name) != fonts.end())
	{
		//std::cout << "[WARNING] AssetDatabase: Font \"" << name << "\" already exists in database!" << std::endl;
		return fonts[name];
	}

	TTF_Font* font = TTF_OpenFont(_path.c_str(), _size);

	if (font == nullptr)
	{
		std::cout << "[ERROR] AssetDatabase: Could not load font from path: " << _path << std::endl;
		std::cout << TTF_GetError() << std::endl;
	}
	else
	{
		fonts.insert_or_assign(name, font);
	}

	return font;
}