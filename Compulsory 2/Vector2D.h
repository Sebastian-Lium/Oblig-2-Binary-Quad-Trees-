#pragma once

struct Vector2D {
	double x;
	double y;

	Vector2D operator + (const Vector2D& v) const {
		Vector2D u;
		u.x = x + v.x;
		u.y = y + v.y;
		return u;
	}

	Vector2D operator /(int d) {
		Vector2D u;
		u.x = x / d;
		u.y = y / d;
		return u;
	}
};