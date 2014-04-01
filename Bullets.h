#include "SFML\Graphics.hpp"
#include "CollisionManager.h"

bool FLAG=false; // flag to know whether collision happened or not, so that source.cpp is informed
const int VELO=20; // velocity of bullet is 20

class Bullets
{
public:
  sf::IntRect box;
  sf::RectangleShape rect; // rectangle shape to display bullet on screen
  int yVel;

  Bullets(int x,int y);
  
  void update();
  void display(sf::RenderWindow *window);

};

Bullets::Bullets(int x, int y)
{
  //initial position of bullet depends on the position of the hero ship
  box.left=x;
  box.top=y;
  box.height=10;
  box.width=2;
  
  rect.setSize(sf::Vector2f(box.width,box.height));
  rect.setFillColor(sf::Color::Blue); // color of bullet
  
  yVel=-VELO; // bullet will move up the screen . so y velocity is negative .
}

void Bullets::update()
{

  box.top+=yVel; // bullet moves up the screen
  if ( CM.CheckCollide(box) == true )
  {
    FLAG=true;
  }
}

void Bullets::display(sf::RenderWindow *window)
{
  //displaying the bullet
  rect.setPosition(box.left,box.top);
  window->draw(rect);
}

