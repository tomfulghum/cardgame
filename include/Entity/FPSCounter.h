#pragma once

#include "Entity.h"
#include "Texture.h"

/*
	Displays a FPS counter in the top right corner of the window.
*/

class FPSCounter : public Entity
{
	friend class EntityManager;

public:
	FPSCounter();

	void Update() override;
	void Render() override;

private:
	int frameCounter = 0;
	double secondCounter = 0;
	int fps = 0;
	Texture* text;
};