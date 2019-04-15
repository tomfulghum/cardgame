#include <iostream>

#include "PlayingCard.h"
#include "Toolbox.h"

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	Environment::Initialize("Test", 640, 480);

	PlayingCard* card = new PlayingCard();
	EntityManager::AddEntity(card, 0);

	Environment::Run();

	Environment::Terminate();
	Toolbox::Terminate();

	return 0;
}