#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "PhysicsObject.h"

// Create a render window and loop
void Window::LoopWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Physics", sf::Style::Close | sf::Style::Resize);
    window.setKeyRepeatEnabled(false);

    // Create object from PhysicsObject class
    PhysicsObject SmallObject(10, sf::Color::Green);
    SmallObject.CreateCircle(10);

    PhysicsObject BigObject(100, sf::Color::Yellow);
    BigObject.CreateCircle(100);

    // Place BigObject in the middle of screen
    BigObject.shape.setPosition(350, 250);

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

            case sf::Event::MouseButtonReleased:
                if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    PhysicsObject(10, sf::Color::Red).CreateCircle(25);

                    printf("MOUSE OBJECT CREATED.");
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            // Create object and render
            PhysicsObject testObject(10, sf::Color::Yellow);

            for (int i = 0; i < 5; i++)
            {
                // window.draw(PhysicsObjArr[i].shape);
                testObject.CreateCircle(20);
            }
            window.draw(testObject.shape);

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            SmallObject.shape.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        // TODO: Detect what object is mouse hoovering on click and be able to move just the selected object

        //sf::RectangleShape shapes[2] = {SmallObject.shape, BigObject.shape};

        // Define what renderer will draw to screen
        window.clear(sf::Color::Black);
        window.draw(BigObject.shape);
        window.draw(SmallObject.shape);

        window.display();
    }
}