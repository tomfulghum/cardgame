#include "Entity/TextButton.h"

#include "AssetDatabase.h"
#include "Config.h"

TextButton::TextButton() : Entity(glm::vec2(), 0)
{
	this->text = "TEXT";
	this->color = COLOR_BASE;
	this->highlightColor = COLOR_HIGHLIGHT;
	this->size = 12;
}

void TextButton::Update()
{

}

void TextButton::Render()
{
	if (this->changed)
	{
		this->RenderText();
	}

	if (this->highlight && this->interactable)
	{
		this->highlightTextTexture->Render(this->position, this->scale);
		this->highlight = false;
	}
	else
	{
		this->textTexture->Render(this->position, this->scale);
	}
}

void TextButton::OnMouseOver()
{
	this->highlight = true;
}

void TextButton::OnClick()
{

}

void TextButton::SetText(const std::string& _text)
{
	if (this->text != _text)
	{
		this->text = _text;
		this->changed = true;
	}
}

void TextButton::SetColor(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a)
{
	this->SetColor({ _r, _g, _b, _a });
}

void TextButton::SetColor(Color _color)
{
	if (this->color != _color)
	{
		this->color = _color;
		this->changed = true;
	}
}

void TextButton::SetHighlightColor(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a)
{
	this->SetColor({ _r, _g, _b, _a });
}

void TextButton::SetHighlightColor(Color _color)
{
	if (this->highlightColor != _color)
	{
		this->color = _color;
		this->changed = true;
	}
}

void TextButton::SetSize(const unsigned int _size)
{
	if (this->size != _size)
	{
		this->size = _size;
		this->changed = true;
	}
}

void TextButton::SetInteractable(const bool _interactable)
{
	this->interactable = _interactable;
}

void TextButton::RenderText()
{
	delete(this->textTexture);
	delete(this->highlightTextTexture);
	this->textTexture = AssetDatabase::RenderText(FONT_PATH, this->size, this->text, this->color, false);
	this->highlightTextTexture = AssetDatabase::RenderText(FONT_PATH, this->size, this->text, this->highlightColor, false);
	this->dimensions = glm::vec2(this->textTexture->GetWidth(), this->textTexture->GetHeight());
	this->changed = false;
}