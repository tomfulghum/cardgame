#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
};