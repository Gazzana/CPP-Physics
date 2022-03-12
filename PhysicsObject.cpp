#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

// Constructor
PhysicsObject::PhysicsObject(float width, float height, float weight, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setOrigin(width / 2, height / 2);
	
}

