#pragma once

#include <vector>
#include "Vector2D.h"
#include "GameObject.h"

class QuadTree {
	Vector2D m_a;
	Vector2D m_b;
	Vector2D m_c;
	Vector2D m_d;
	QuadTree* m_sw;
	QuadTree* m_se;
	QuadTree* m_nw;
	QuadTree* m_ne;
	std::vector<GameObject> m_gameObjects;
	bool isLeaf() const;
	//aasdasdadasdsdasdasdadasdaeda

public:
	QuadTree();
	QuadTree(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3, const Vector2D& v4);
	void subDivide(int n);
	void print() const;
	QuadTree* insert(const GameObject& gameObject);
	QuadTree* find(const Vector2D& p);
};