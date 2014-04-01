#pragma once
#ifndef ENEMYSHIPS_H
#define ENEMYSHIPS_H

#include"SFML\Graphics.hpp"

class EnemyShip
{
    public:
        sf::IntRect box;
        sf::RectangleShape rect;
        int xVel,yVel;

        EnemyShip();
        void update();
        void display(sf::RenderWindow *window);
        void changeColor();
};

EnemyShip::EnemyShip()
{
    //position of enemy ship on screen
    box.left=300;
    box.top=200;
    box.height=20;
    box.width=20;
    
    rect.setSize(sf::Vector2f(box.width,box.height));
    rect.setFillColor(sf::Color::Yellow);  // enemy ship is colored yellow
    
    xVel=0;
    yVel=0;

}

void EnemyShip::update()
{
    // since enemy ship doesnt move , we do nothing here in update
}

void EnemyShip::changeColor()
{
    rect.setFillColor(sf::Color::Black);  // when enemy ship is hit by a bullet we change its color
}
void EnemyShip::display(sf::RenderWindow *window)
{
    //enemy ship is drawn here
    rect.setPosition(box.left,box.top);
    window->draw(rect);
}

#endif











