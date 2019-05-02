#pragma once

#include "Entity.h"
#include "Texture.h"
#include "Utility/Color.h"

class TextButton : public Entity
{
	friend class EntityManager;

public:
	void Update() override;
	void Render() override;

	void SetText(const std::string& _text);
	void SetColor(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a);
	void SetColor(Color _color);
	void SetHighlightColor(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a);
	void SetHighlightColor(Color _color);
	void SetSize(const unsigned int _size);
	void SetInteractable(const bool _interactable);

private:
	TextButton();

	std::string text;
	Texture* textTexture;
	Texture* highlightTextTexture;
	Color color;
	Color highlightColor;
	unsigned int size;
	bool interactable = true;
	bool highlight = false;
	bool changed = true;

	void OnMouseOver() override;
	void OnClick() override;

	void RenderText();
};