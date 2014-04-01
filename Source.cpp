//Look at basic galaxy shooter - 1 to understand HeroShip.h and Source.cpp easily


#include <SFML/Graphics.hpp>
#include "HeroShip.h"
#include "EnemyShips.h"



int main()
{
    // Create the main window
    sf::RenderWindow *window;
    window=new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
    window->setFramerateLimit(20);

    HeroShip *myship=new HeroShip();
    EnemyShip *es1=new EnemyShip(); // creating an enemy ship
    CM.AssignES(es1); // informing the position of enemy ship to collision manager
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
        //user
        myship->handleEvents();
        myship->update();
        //AI
        es1->update();
        //check flag to know whether collision happened. 
        if ( FLAG==true ) //FLAG is from Bullets.h
        {
            es1->changeColor();
            FLAG=false;
        }
        //Display
        window->clear();
        myship->display(window);
        es1->display(window);
        window->display();
    }
    return 0;
}
