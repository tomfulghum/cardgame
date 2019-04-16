#include "Entity/FPSCounter.h"

#include "AssetDatabase.h"
#include "Environment.h"
#include "Texture.h"
#include "Time.h"


FPSCounter::FPSCounter() : Entity(glm::vec2(Environment::GetWindowWidth(), 0), 10000)
{

}

void FPSCounter::Update()
{
	this->frameCounter++;
	this->secondCounter += Time::DeltaTime();

	if (this->secondCounter >= 1.0)
	{
		this->fps = frameCounter;
		this->frameCounter = 0;
		this->secondCounter = 0;
	}
}

void FPSCounter::Render()
{
	Texture* text = AssetDatabase::RenderText("assets/fonts/uni0553-webfont.ttf", 24, std::to_string(fps));
	text->Render(glm::vec2(this->position.x - text->GetWidth() - 10, this->position.y), 1);
}

