#include <iostream>

#include "AssetDatabase.h"
#include "Config.h"
#include "Entity/FPSCounter.h"
#include "Entity/PlayingCardPile.h"
#include "Environment.h"
#include "PlayingCard.h"
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

	cardPile1 = EntityManager::CreateEntity<PlayingCardPile>();
	cardPile1->SetPosition(10, 300);
	cardPile1->SetRenderOrder(100);
	cardPile1->SetOnClickCallback(Test1);

	cardPile2 = EntityManager::CreateEntity<PlayingCardPile>();
	cardPile2->SetPosition(210, 300);
	cardPile2->SetRenderOrder(100);
	cardPile2->SetOnClickCallback(Test2);

	PlayingCard* card1 = cardDeck->DrawCard();
	PlayingCard* card2 = cardDeck->DrawCard();
	PlayingCard* card3 = cardDeck->DrawCard();
	PlayingCard* card4 = cardDeck->DrawCard();
	PlayingCard* card5 = cardDeck->DrawCard();

	cardPile1->AddToTop(card1);
	cardPile1->AddToTop(card2);

	FPSCounter* fpsCounter = EntityManager::CreateEntity<FPSCounter>();

	Environment::Run();

	Environment::Terminate();
	Toolbox::Terminate();

	return 0;
}

void LoadAssets()
{
	const std::vector<std::pair<const char*, const char*>> sprites = 
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