#pragma once

#include "Vector2D.h"
#include <string>

struct GameObject {
	Vector2D m_position;
	std::string m_name;
	GameObject() {/* to do */ }
	GameObject(const Vector2D& position, std::string name) :m_position(position), m_name(name) { }
	Vector2D getPosition() const { return m_position; }
};