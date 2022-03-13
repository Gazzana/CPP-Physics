#pragma once

#include <SFML/Graphics.hpp>

class PhysicsObject
{
public:
	// Declare variables
	float width;
	float height;
	float weight;
	sf::Color color;

	sf::RectangleShape shape;
	static int ObjectsCount;

	// Declare functions

	PhysicsObject(float width, float height, float weight, sf::Color color, int ObjectsCount = ObjectsCount);
	//~PhysicsObject() {ObjectsCount--;}

	void CreateShape();

	void ApplyGravity(float gravityForce = 9.81f);

	void CheckMouse();
};