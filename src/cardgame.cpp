#include <iostream>

#include "AssetDatabase.h"
#include "PlayingCard.h"
#include "Toolbox.h"

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	Environment::Initialize("Test", 431, 856);

	Texture* testSprite = AssetDatabase::LoadTexture("sprite_test", "assets/sprite.png");

	PlayingCard* card = new PlayingCard(testSprite);
	EntityManager::AddEntity(card);

	Environment::Run();

	Environment::Terminate();
	Toolbox::Terminate();

	return 0;
}