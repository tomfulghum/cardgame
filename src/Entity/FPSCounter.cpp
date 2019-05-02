#include "Entity/FPSCounter.h"

#include "AssetDatabase.h"
#include "Config.h"
#include "Environment.h"
#include "Time.h"


FPSCounter::FPSCounter() : Entity(glm::vec2(Environment::GetWindowWidth(), 0), 10000)
{

}

void FPSCounter::Update()
{
	this->frameCounter++;
	this->secondCounter += Time::DeltaTime();

	if (this->secondCounter >= (1.0 / 1.0))
	{
		this->fps = (int)(frameCounter * 1.0);
		this->frameCounter = 0;
		this->secondCounter = 0;
		delete(text);
		this->text = AssetDatabase::RenderText(FONT_PATH, 24, std::to_string(fps), { 255, 255, 255, 255 }, false);
	}
}

void FPSCounter::Render()
{
	this->text->Render(glm::vec2(this->position.x - text->GetWidth() - 10, this->position.y), 1);
}

