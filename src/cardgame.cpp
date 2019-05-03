#include "AssetDatabase.h"
#include "Config.h"
#include "Entity/FPSCounter.h"
#include "Entity/GameController.h"
#include "Environment.h"
#include "Toolbox.h"

void LoadAssets();

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	Environment::Initialize("Ropascilispo", 1280, 720);

	LoadAssets();

	GameController* controller = EntityManager::CreateEntity<GameController>();
	controller->Initialize();

	//FPSCounter* fpsCounter = EntityManager::CreateEntity<FPSCounter>();

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