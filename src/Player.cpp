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

/*
	Gives the player a card.
	Returns false if no spot in the player's hand is free.
*/
bool Player::GiveCard(PlayingCard* _card)
{
	if (_card != nullptr)
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
	}

	return false;
}

void Player::Score()
{
	this->score++;
}

/*
	Resets the player to its initial state.
*/
void Player::Reset()
{
	this->score = 0;
	for (int i = 0; i < this->hand.size(); i++)
	{
		this->hand[i]->Clear();
		this->hand[i]->SetActive(false);
	}
}

/*
	Callback function for all PlayingCardSpots that belong to the player.
	This is called when the PlayingCardSpot is clicked on.
*/
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