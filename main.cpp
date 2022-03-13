#include <SFML/Graphics.hpp>
#include <iostream>

#include "PhysicsObject.h"

class mainClass
{
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

            // TODO: Detect what object is mouse houvering on click and be able to move just the selected object
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                myObj.shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            }

            // Define what renderer will draw to screen
            window.clear(sf::Color(84, 65, 133));
            window.draw(myObj.shape); // TODO: Create an array with all the objects to be rendered and render the whole array
            window.draw(otherObj.shape);
            window.display();
        }

        return 0;
    }
};