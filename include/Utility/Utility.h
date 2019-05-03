#pragma once

#include "glm.hpp"

/*
	Static utility functions.
*/
namespace util
{
	static bool IsPointInRectangle(const glm::vec2& _point, const glm::vec2& _position, const glm::vec2& _dimensions)
	{
		return _point.x >= _position.x
			&& _point.y >= _position.y
			&& _point.x <= _position.x + _dimensions.x
			&& _point.y <= _position.y + _dimensions.y;
	}
}