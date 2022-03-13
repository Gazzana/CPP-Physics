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


	// Declare functions
	PhysicsObject(float width, float height, float weight, sf::Color color);
	void CreateShape();


};