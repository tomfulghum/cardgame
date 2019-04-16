#include <iostream>

#include "AssetDatabase.h"
#include "Config.h"
#include "Entity/FPSCounter.h"
#include "Entity/PlayingCard.h"
#include "Toolbox.h"

void LoadAssets();

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	Environment::Initialize("Test", 800, 600);

	LoadAssets();

	PlayingCard* card1 = new PlayingCard(PlayingCardType::ROCK, glm::vec2(120, 20), 101);
	PlayingCard* card2 = new PlayingCard(PlayingCardType::PAPER, glm::vec2(220, 10), 102);
	PlayingCard* card3 = new PlayingCard(PlayingCardType::SCISSORS, glm::vec2(10, 40), 100);
	PlayingCard* card4 = new PlayingCard(PlayingCardType::LIZARD, glm::vec2(320, 20), 103);
	PlayingCard* card5 = new PlayingCard(PlayingCardType::SPOCK, glm::vec2(420, 40), 104);
	//layingCard* cardDeck = new PlayingCard(spriteCardDeck, glm::vec2(200, 300), 105);
	EntityManager::AddEntity(card1);
	EntityManager::AddEntity(card2);
	EntityManager::AddEntity(card3);
	EntityManager::AddEntity(card4);
	EntityManager::AddEntity(card5);
	//EntityManager::AddEntity(cardDeck);

	FPSCounter* fpsCounter = new FPSCounter();
	EntityManager::AddEntity(fpsCounter);

	Environment::Run();

	Environment::Terminate();
	Toolbox::Terminate();

	return 0;
}

void LoadAssets()
{
	std::vector<std::pair<const char*, const char*>> sprites = 
	{
		{SPRITE_CARD_ROCK_NAME,      SPRITE_CARD_ROCK},
		{SPRITE_CARD_PAPER_NAME,     SPRITE_CARD_PAPER},
		{SPRITE_CARD_SCISSORS_NAME,  SPRITE_CARD_SCISSORS},
		{SPRITE_CARD_LIZARD_NAME,    SPRITE_CARD_LIZARD},
		{SPRITE_CARD_SPOCK_NAME,     SPRITE_CARD_SPOCK},
		{SPRITE_CARD_HIGHLIGHT_NAME, SPRITE_CARD_HIGHLIGHT},
		{SPRITE_CARD_DECK_NAME,      SPRITE_CARD_DECK}
	};

	for (auto& sprite : sprites)
	{
		AssetDatabase::LoadTexture(sprite.first, sprite.second);
	}
}