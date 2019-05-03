#pragma once

#include <string>

/*
	Data structure to save a 32bit RGBA color.
*/

struct Color 
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	std::string ToString()
	{
		return std::to_string(r) + std::to_string(g) + std::to_string(b) + std::to_string(a);
	}

	bool operator==(const Color _comp)
	{
		return this->r == _comp.r 
			&& this->g == _comp.g 
			&& this->b == _comp.b 
			&& this->a == _comp.a;
	}

	bool operator!=(const Color _comp)
	{
		return this->r != _comp.r
			|| this->g != _comp.g
			|| this->b != _comp.b
			|| this->a != _comp.a;
	}
};