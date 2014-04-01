#include"SFML\Graphics.hpp"
#include"Bullets.h"

//Look at basic galaxy shooter -1 to understand heroship and source.cpp easily
const int VEL=10;
class HeroShip
{
public:
    sf::IntRect box;
    sf::RectangleShape rect;
    int xVel,yVel;
    
    Bullets *myBullets[10]; // 10 bullets can only be fired. can be increased if needed
    int num_of_bullets;

    HeroShip();
    void handleEvents();
    void update();
    void display(sf::RenderWindow *window);
    void shoot();

};

HeroShip::HeroShip()
{
    box.left=200;
    box.top=500;
    box.height=20;
    box.width=20;
    
    rect.setSize(sf::Vector2f(box.width,box.height));
    rect.setFillColor(sf::Color::Red);
    
    xVel=0;
    yVel=0;

    num_of_bullets=0;
}
void HeroShip::handleEvents()
{
    //top or down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        yVel=-VEL;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        yVel=VEL;
    else
        yVel=0;
    //left or right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        xVel=-VEL;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        xVel=VEL;
    else
        xVel=0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        shoot();
    
}

void HeroShip::update()
{
    box.left+=xVel;
    box.top+=yVel;

    for(int i=0;i<num_of_bullets;i++)
        myBullets[i]->update(); // updating every bullet position
}

void HeroShip::display(sf::RenderWindow *window)
{
    for(int i=0;i<num_of_bullets;i++)
        myBullets[i]->display(window); // calling display function of all bullets

    rect.setPosition(box.left,box.top);
    window->draw(rect);
}

void HeroShip::shoot()
{
    //to shoot bullets
    if(num_of_bullets<10)
    {
        myBullets[num_of_bullets]=new Bullets(box.left+box.width/2,box.top-10); // position of bullet : x = middle of hero ship ; y = 10 pixels above the top of enemy ship
        num_of_bullets++;
    }
}














