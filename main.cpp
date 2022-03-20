#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "PhysicsObject.h"

/*
    TODO: Create Window class and separate from main.cpp
    TODO: Draw objects from their constructors in physicsobject.cpp
    TODO: Apply some kind of force between object
    TODO: Make minimal UI
*/

int main()
{
	Window window = Window();
	window.LoopWindow();
}