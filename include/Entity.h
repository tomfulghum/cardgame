#pragma once

class Entity
{
public:
	Entity();

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
};