#include <SFML/Graphics.hpp>
#include <iostream>

#include "PhysicsObject.h"

int main()
{
    // Create a render window and loop
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Physics", sf::Style::Close | sf::Style::Resize);

    // Must create object out of the loop
    sf::RectangleShape rect(sf::Vector2f(30.0f, 30.0f));
    rect.setFillColor(sf::Color::Cyan);
    rect.setOrigin(15.0f, 15.0f);

    // Attempt to create physics object
    PhysicsObject myObj(10, 10, 50, sf::Color::Red);
    myObj.CreateShape();
    
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
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            myObj.shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }

        // Define what renderer will draw to screen
        window.clear(sf::Color(84, 65, 133));
        window.draw(myObj.shape);
        window.display();
    }

    return 0;
}