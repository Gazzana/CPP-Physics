#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

// Constructor will have parameters to define every variable in the PhysicsObject class
PhysicsObject::PhysicsObject(float width, float height, float weight, sf::Color color)
{
	PhysicsObject::width = width;
	PhysicsObject::height = height;
	PhysicsObject::weight = weight;
	PhysicsObject::color = color;
}

// Assign functions

void PhysicsObject::CreateShape()
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setOrigin(width / 2, height / 2);

	PhysicsObject::shape = shape;
}
