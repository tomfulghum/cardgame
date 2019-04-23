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
