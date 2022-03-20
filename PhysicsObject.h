#pragma once

#include <SFML/Graphics.hpp>

class PhysicsObject
{
public:
	// Declare variables
	float width;
    float height;
	float mass;
	float weight; // weight = mass * currentGravityForce
	sf::Color color;

	sf::CircleShape shape;
	int ObjectsCount;
	// Declare functions

	PhysicsObject(float mass, sf::Color color);

	~PhysicsObject();

	void CreateCircle(float radius);

	void ApplyGravity(float gravityForce = 9.81f);

	void CheckMouse();
};