// Oi gibi e polese

#include <SFML/Graphics.hpp>
#include <iostream>

#include "PhysicsObject.h"

void CreateAndRender()
{
}

int main()
{
    // Create a render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Physics", sf::Style::Close | sf::Style::Resize);

    // Create object from PhysicsObject class
    PhysicsObject myObj(10, 10, 50, sf::Color::Red);
    myObj.CreateShape();

    PhysicsObject otherObj(50, 50, 10, sf::Color::Blue);
    otherObj.CreateShape();

    sf::Vector2i cursorPos;

    // Window loop
    while (window.isOpen())
    {
        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::Resized:
                // Print current screen size
                printf("New Window Width: %i New Window Height: %i\n", evnt.size.width, evnt.size.height);
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }
            case sf::Event::MouseMoved:
                cursorPos = sf::Mouse::getPosition(window);
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            // Create object and render
            PhysicsObject testObject(50, 150, 10, sf::Color::Yellow);

            for (int i = 0; i < 5; i++)
            {
                // window.draw(PhysicsObjArr[i].shape);
                testObject.CreateShape();
            }
            window.draw(testObject.shape);
        }

        CreateAndRender();

        // TODO: Detect what object is mouse hoovering on click and be able to move just the selected object

        sf::RectangleShape shapes[2] = {myObj.shape, otherObj.shape};

        // Define what renderer will draw to screen
        window.clear(sf::Color(84, 65, 133));
        window.draw(myObj.shape);    // TODO: Create an array with all the objects to be rendered and render the whole array
        window.draw(otherObj.shape); // OR: Create a function that creates one object from a click, and auto render it, in the same function

        window.display();
    }

    return 0;
}
