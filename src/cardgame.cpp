#include <iostream>

#include "AssetDatabase.h"
#include "Config.h"
#include "Entity/FPSCounter.h"
#include "Entity/PlayingCard.h"
#include "Entity/PlayingCardPile.h"
#include "Environment.h"
#include "PlayingCardDeck.h"
#include "Toolbox.h"

void LoadAssets();

void Test1(Entity* _card);
void Test2(Entity* _card);

PlayingCardDeck* cardDeck;
PlayingCardPile* cardPile1;
PlayingCardPile* cardPile2;

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	Environment::Initialize("Test", 800, 600);

	LoadAssets();

	cardDeck = new PlayingCardDeck();
	cardDeck->Shuffle();

	cardPile1 = new PlayingCardPile(glm::vec2(10, 300), 100);
	cardPile1->SetOnClickCallback(Test1);
	EntityManager::AddEntity(cardPile1);

	cardPile2 = new PlayingCardPile(glm::vec2(210, 300), 100);
	cardPile2->SetOnClickCallback(Test2);
	EntityManager::AddEntity(cardPile2);

	PlayingCard* card1 = cardDeck->DrawCard();
	PlayingCard* card2 = cardDeck->DrawCard();
	PlayingCard* card3 = cardDeck->DrawCard();
	PlayingCard* card4 = cardDeck->DrawCard();
	PlayingCard* card5 = cardDeck->DrawCard();
	//PlayingCard* card1 = new PlayingCard(PlayingCardType::ROCK, glm::vec2(120, 20), 101);
	//PlayingCard* card2 = new PlayingCard(PlayingCardType::PAPER, glm::vec2(220, 10), 102);
	//PlayingCard* card3 = new PlayingCard(PlayingCardType::SCISSORS, glm::vec2(10, 40), 100);
	//PlayingCard* card4 = new PlayingCard(PlayingCardType::LIZARD, glm::vec2(320, 20), 103);
	//PlayingCard* card5 = new PlayingCard(PlayingCardType::SPOCK, glm::vec2(420, 40), 104);
	//PlayingCard* cardDeck = new PlayingCard(spriteCardDeck, glm::vec2(200, 300), 105);
	card1->SetPosition(10, 40);
	card2->SetPosition(120, 20);
	card3->SetPosition(230, 10);
	card4->SetPosition(340, 20);
	card5->SetPosition(450, 40);
	EntityManager::AddEntity(card1);
	EntityManager::AddEntity(card2);
	EntityManager::AddEntity(card3);
	EntityManager::AddEntity(card4);
	EntityManager::AddEntity(card5);
	//EntityManager::AddEntity(cardDeck);

	cardPile1->AddToTop(card1);

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
		{SPRITE_CARD_ROCK_NAME,           SPRITE_CARD_ROCK},
		{SPRITE_CARD_PAPER_NAME,          SPRITE_CARD_PAPER},
		{SPRITE_CARD_SCISSORS_NAME,       SPRITE_CARD_SCISSORS},
		{SPRITE_CARD_LIZARD_NAME,         SPRITE_CARD_LIZARD},
		{SPRITE_CARD_SPOCK_NAME,          SPRITE_CARD_SPOCK},
		{SPRITE_CARD_HIGHLIGHT_NAME,      SPRITE_CARD_HIGHLIGHT},
		{SPRITE_CARD_DECK_NAME,           SPRITE_CARD_DECK},
		{SPRITE_CARD_DECK_HIGHLIGHT_NAME, SPRITE_CARD_DECK_HIGHLIGHT}
	};

	for (auto& sprite : sprites)
	{
		AssetDatabase::LoadTexture(sprite.first, sprite.second);
	}
}

void Test1(Entity* _card)
{
	cardPile2->AddToTop(cardPile1->DrawCard());
}

void Test2(Entity* _card)
{
	cardPile1->AddToTop(cardPile2->DrawCard());
}