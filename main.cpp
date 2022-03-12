#include <SFML/Graphics.hpp>
#include <iostream>

#include "PhysicsObject.h"

using namespace sf;

int main()
{
    // Create a render window and loop
    RenderWindow window(VideoMode(800, 600), "C++ Physics", Style::Close | Style::Resize);
    while (window.isOpen())
    {
        Event evnt;

        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::Resized:
                // Print current screen size
                printf("New Window Width: %i New Window Height: %i\n", evnt.size.width, evnt.size.height);
                break;
            case Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }
            }
        }


    // Attempt to create physics object
    PhysicsObject myObj(50, 10, 10, sf::Color::Green);
        
        RectangleShape rect(Vector2f(30.0f, 30.0f));
        rect.setFillColor(Color::Black);
        rect.setOrigin(15.0f, 15.0f);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);

            rect.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }


        // Define what renderer will draw to screen
        window.clear(Color::Blue);

        window.display();
    }

    return 0;
}