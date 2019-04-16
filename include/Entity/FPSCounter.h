#pragma once

#include "Entity.h"

class FPSCounter : public Entity
{
public:
	FPSCounter();

	void Update() override;
	void Render() override;

private:
	int frameCounter = 0;
	double secondCounter = 0;
	int fps = 0;
};