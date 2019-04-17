#include "Entity/PlayingCardPile.h"

#include "AssetDatabase.h"
#include "InputManager.h"
#include "Config.h"

PlayingCardPile::PlayingCardPile(const glm::vec2& _position, const int _renderOrder) : Entity(_position, _renderOrder)
{
	this->texture = AssetDatabase::GetTexture(SPRITE_CARD_DECK_NAME);
	this->dimensions = glm::vec2(this->texture->GetWidth(), this->texture->GetHeight());
	this->scale = 10.0;
}

void PlayingCardPile::Update()
{
	if (this->highlight && InputManager::GetMouseButtonDown(MouseButton::LEFT))
	{
		this->position.x += 10;
	}
}

void PlayingCardPile::Render()
{
	this->texture->Render(this->position, this->scale);

	if (this->highlight)
	{
		Texture* highlight = AssetDatabase::GetTexture(SPRITE_CARD_DECK_HIGHLIGHT_NAME);
		highlight->Render(this->position, this->scale);
		this->highlight = false;
	}
}

void PlayingCardPile::OnMouseOver()
{
	this->highlight = true;
}