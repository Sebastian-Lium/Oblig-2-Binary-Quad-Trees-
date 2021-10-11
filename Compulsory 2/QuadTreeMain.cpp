#include <iostream>
#include <vector>
#include "QuadTree.h"

int main()
{
	std::vector<GameObject> gameObjects;
	Vector2D a{ -4, -3 };
	Vector2D b{ 4 , -3 };
	Vector2D c{ 4 , 3 };
	Vector2D d{ -4, 3 };
	// Legger inn objektene i gameObjects
	// nw
	Vector2D p{ -3.25,0.25 };
	gameObjects.push_back(GameObject{ p, "grantre 1" });
	p.x = -3.25; p.y = 1.5;
	gameObjects.push_back(GameObject{ p, "grantre 2" });
	p.x = -1.5; p.y = 1.0;
	gameObjects.push_back(GameObject{ p, "grantre 3" });
	// sw = nw
	p.x =  -3.25; p.y = -0.75;
	gameObjects.push_back(GameObject{ p, "stjerne 1" });
	p.x = -2.75; p.y = -1.0;
	gameObjects.push_back(GameObject{ p, "mynt 1" });
	// sw = ne
	p.x = -1.5; p.y = -0.5;
	gameObjects.push_back(GameObject{ p, "stjerne 2" });
	p.x = -0.5; p.y = -0.5;
	gameObjects.push_back(GameObject{ p , "mynt 2" });
	p.x = -1.5; p.y = -1.0;
	gameObjects.push_back(GameObject{ p , "seddel 1" });
	// sw = se
	p.x = -1.75; p.y = -2.0;
	gameObjects.push_back(GameObject{ p , "seddel 2" });
	// se
	p.x = 2.75; p.y = -1.0;
	gameObjects.push_back(GameObject{ p , "grantre 4" });
	p.x = 2.0; p.y = -2.0;
	gameObjects.push_back(GameObject{ p , "vann" });
	// ne = sw
	p.x = 0.5; p.y = 0.5;
	gameObjects.push_back(GameObject{ p , "fiende" });
	// ne = se
	p.x = 3.0; p.y = 0.25;
	gameObjects.push_back(GameObject{ p , "spiller" });

	// Lager quadtree med subdivisjon
	QuadTree root{ a , b , c , d };
	root.subDivide(1);
	QuadTree* subtree= root.find(Vector2D{ -1, -1 });
	subtree->subDivide(1);
	subtree = root.find(Vector2D{ 1 , 1 });
	subtree->subDivide(1);
	std::cout << "=========================" << std::endl;
	std::cout << " Setter inn og skriver ut " << std::endl;
	std::cout << "=========================" << std::endl;
	for(auto go : gameObjects)
	{
		auto p = root.insert(go);
		p->print();
	}
	std::cout << "=====================" << std::endl;
	std::cout << " Skriver ut objektene " << std::endl;
	std::cout << "=====================" << std::endl;
	subtree = root.find(Vector2D{ -1, 1 });
	subtree->print();
	subtree = root.find(Vector2D{ -2.5, -1 });
	subtree->print();
	subtree = root.find(Vector2D{ -1.5, -2 });
	subtree->print();
	subtree = root.find(Vector2D{ -1.5, -1 });
	subtree->print();
	subtree = root.find(Vector2D{ 1, -1 });
	subtree->print();
	subtree = root.find(Vector2D{ 1, 1 });
	subtree->print();
	subtree = root.find(Vector2D{ 3, 1 });
	subtree->print();
	return 0;
}