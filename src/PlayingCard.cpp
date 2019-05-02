#include "PlayingCard.h"

#include "AssetDatabase.h"
#include "Config.h"

PlayingCard::PlayingCard(const PlayingCardType _type) : type(_type)
{
	switch (_type)
	{
	case PlayingCardType::ROCK:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_ROCK_NAME);
		break;
	case PlayingCardType::PAPER:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_PAPER_NAME);
		break;
	case PlayingCardType::SCISSORS:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_SCISSORS_NAME);
		break;
	case PlayingCardType::LIZARD:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_LIZARD_NAME);
		break;
	case PlayingCardType::SPOCK:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_SPOCK_NAME);
		break;
	}
}

bool PlayingCard::Beats(PlayingCard* _card)
{
	PlayingCardType cardType = _card->GetType();

	switch (this->GetType())
	{
	case PlayingCardType::ROCK:
		return cardType == PlayingCardType::LIZARD || cardType == PlayingCardType::SCISSORS;
	case PlayingCardType::PAPER:
		return cardType == PlayingCardType::SPOCK || cardType == PlayingCardType::ROCK;
	case PlayingCardType::SCISSORS:
		return cardType == PlayingCardType::LIZARD || cardType == PlayingCardType::PAPER;
	case PlayingCardType::LIZARD:
		return cardType == PlayingCardType::SPOCK || cardType == PlayingCardType::PAPER;
	case PlayingCardType::SPOCK:
		return cardType == PlayingCardType::ROCK || cardType == PlayingCardType::SCISSORS;
	}
}
