#pragma once

/*
	Globally provides acces to deltaTime
*/
class Time
{
	friend class Environment;

public:
	static double DeltaTime();

private:
	static double deltaTime;
};