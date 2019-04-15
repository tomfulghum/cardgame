#pragma once

class Time
{
	friend class Environment;

public:
	static double DeltaTime();

private:
	static double deltaTime;
};