#include <iostream>
#include "QuadTree.h"


bool QuadTree::isLeaf() const
{
	return m_sw == nullptr && m_se == nullptr && m_ne == nullptr && m_nw == nullptr;
}

QuadTree::QuadTree(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3, const Vector2D& v4)	: m_a{ v1 }, m_b{ v2 }, m_c{ v3 }, m_d{ v4 },m_sw{nullptr}, m_se{nullptr}, m_ne{nullptr}, m_nw{nullptr}
{
//
}
//jnasdjnasdnasndjoansdojansjdna
void QuadTree::subDivide(int n)
{
	if (n > 0) {
		Vector2D v1 = (m_a+m_b) / 2;
		Vector2D v2 = (m_b+m_c) / 2;
		Vector2D v3 = (m_c+m_d) / 2;
		Vector2D v4 = (m_d+m_a) / 2;
		Vector2D m = (m_a+m_c) / 2;
		m_sw = new QuadTree(m_a, v1, m, v4);
		m_sw->subDivide(n - 1);
		m_se = new QuadTree(v1, m_b, v2, m);
		m_se->subDivide(n - 1);
		m_ne = new QuadTree(m, v2, m_c, v3);
		m_ne->subDivide(n - 1);
		m_nw = new QuadTree(v4, m, v3, m_d);
		m_nw->subDivide(n - 1);
	}
}

void QuadTree::print() const
{
	Vector2D c = (m_a + m_c) / 2;
	std::cout << "center = (" << c.x << ", " << c.y << ")" << std::endl;
	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it) {
		std::cout << it->m_name << std::endl;
	}
}

QuadTree* QuadTree::insert(const GameObject& gameObject)
{
	if (isLeaf()) {
		m_gameObjects.push_back(gameObject);
		return this;
	}
	else {
		Vector2D m = (m_a + m_c) / 2;
		if (gameObject.getPosition().y < m.y) {
			if (gameObject.getPosition().x < m.x) {
				m_sw->insert(gameObject);
			}
			else {
				m_se->insert(gameObject);
			}
		}
		else {
			if (gameObject.getPosition().x < m.x) {
				m_nw->insert(gameObject);
			}
			else {
				m_ne->insert(gameObject);
			}
		}
	}
}

QuadTree* QuadTree::find(const Vector2D& p) {
	if (isLeaf()) {
		return this;
	}
	else {
		Vector2D m = (m_a + m_c) / 2;
		if (p.y < m.y) {
			if (p.x < m.x) {
				m_sw->find(p);
			}
			else {
				m_se->find(p);
			}
		}
		else {
			if (p.x < m.x) {
				m_nw->find(p);
			}
			else {
				m_ne->find(p);
			}
		}
	}
}