#include "EnemyShips.h"
//to detect collisions between bullets and enemy ship

class CollisionManager
{

    sf::IntRect *esbox[10]; // enemy ship's position values. can store upto 10 ships' values. but here we use only 1
    sf::IntRect *bulletBox[10]; // to store position of bullets
public:
    int no_of_eships;
    void AssignES(EnemyShip *es); // to fill esbox[] array with enemy ship's positon values
    bool CheckCollide(sf::IntRect box); // to check collision
    
};

CollisionManager CM; // an external object for Collision manager class to use whenever needed from anywhere

void CollisionManager::AssignES(EnemyShip *es)
{
    //Assigning position of enemy ship's to the array esbox
    no_of_eships=0;
    esbox[no_of_eships]=new sf::IntRect;
    esbox[no_of_eships]->left=es->box.left;
    esbox[no_of_eships]->top=es->box.top;
    esbox[no_of_eships]->height=es->box.height;
    esbox[no_of_eships]->width=es->box.width;
    no_of_eships++;
}

bool CollisionManager::CheckCollide(sf::IntRect box)
{
    //checking boundaries of bullet and enemy ship to find whether they collide
    if(box.left > esbox[0]->left 
            && box.left < esbox[0]->left + esbox[0]->width
            && box.top > esbox[0]->top 
            && box.top < esbox[0]->top + esbox[0]->height )
     return true;
    else 
        return false;
}
