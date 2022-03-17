#include "PhysicsObject.h"
// #include "main.cpp"
#include <SFML/Graphics.hpp>

// Constructor will have parameters to define every variable in the PhysicsObject class
PhysicsObject::PhysicsObject(float width, float height, float weight, sf::Color color)
{
	PhysicsObject::width = width;
	PhysicsObject::height = height;
	PhysicsObject::weight = weight;
	PhysicsObject::color = color;
	// PhysicsObject::ObjectsCount += 1;
}

// Destructor will only be responsable for restauring the "ObjectsCount" variable
PhysicsObject::~PhysicsObject()
{
	// PhysicsObject::ObjectsCount--;
}

// Assign functions

void PhysicsObject::CreateShape()
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setOrigin(width / 2, height / 2);


	PhysicsObject::shape = shape;
}

void PhysicsObject::ApplyGravity(float gravityForce)
{
}

// Detect if mouse x and y coords match with some PhysicsObject coords
void PhysicsObject::CheckMouse()
{
	if (sf::Event::MouseMoved)
	{

		sf::Vector2f shapePostitions = shape.getPosition();
	}
}