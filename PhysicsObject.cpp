#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

int ObjectsCount;

// Constructor will have parameters to define every variable in the PhysicsObject class
PhysicsObject::PhysicsObject(float mass, sf::Color color)
{
	PhysicsObject::mass = mass;
	PhysicsObject::color = color;
	PhysicsObject::ObjectsCount = ObjectsCount + 1; // ObjCount += 1;
}

// Destructor will only be responsable for restauring the "ObjectsCount" variable
PhysicsObject::~PhysicsObject()
{
	ObjectsCount--;
}

// Assign functions

void PhysicsObject::CreateCircle(float radius)
{
	sf::CircleShape shape(radius);
	shape.setFillColor(color);
	shape.setOrigin(radius / 2, radius / 2);

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