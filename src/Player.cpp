#include "Player.h"

#include "EntityManager.h"

Player::Player(GameController* _controller, glm::vec2 _position) : controller(_controller), position(_position)
{
	for (int i = 0; i < this->hand.size(); i++)
	{
		this->hand[i] = EntityManager::CreateEntity<PlayingCardSpot>();
		this->hand[i]->SetPosition(glm::vec2(_position.x + i * 120, _position.y));
		this->hand[i]->SetRenderOrder(100 + i);
		this->hand[i]->SetDoHighlight(false);
		this->hand[i]->SetActive(false);
		this->hand[i]->SetOnClickCallback([=](Entity* _cardSpot) {
			this->SpotOnClick(_cardSpot);
		});
	}
}

void Player::SetDoHighlight(bool _doHighlight)
{
	for (int i = 0; i < this->hand.size(); i++)
	{
		this->hand[i]->SetDoHighlight(_doHighlight);
	}
}

bool Player::GiveCard(PlayingCard* _card)
{
	for (int i = 0; i < this->hand.size(); i++)
	{
		if (this->hand[i]->IsFree())
		{
			this->hand[i]->SetCard(_card);
			this->hand[i]->SetActive(true);
			return true;
		}
	}

	return false;
}

void Player::Score()
{
	this->score++;
}

void Player::Reset()
{
	this->score = 0;
	for (int i = 0; i < this->hand.size(); i++)
	{
		this->hand[i]->Clear();
		this->hand[i]->SetActive(false);
	}
}

void Player::SpotOnClick(Entity* _spot)
{
	PlayingCardSpot* spot = static_cast<PlayingCardSpot*>(_spot);
	PlayingCard* card = spot->TakeCard();
	if (card != nullptr)
	{
		bool played = this->controller->PlayCard(card, this);
		if (played)
		{
			spot->SetActive(false);
		}
		else
		{
			spot->SetCard(card);
		}
	}
}