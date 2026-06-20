
#include <SFML/Graphics.hpp>
#include<time.h>
using namespace sf;

class Add_on
{
    public:
    Texture texture;
    Sprite sprite;
    int x,y;
};
class Life:public Add_on
{   
    public:
    Life()
    {
        srand(time(0));
        texture.loadFromFile("img/PNG/Power-ups/powerupGreen_bolt.png");
        sprite.setTexture(texture);
        x=rand()%750;
        y=0;
        sprite.setPosition(x,y);
        sprite.setScale(1,1);
    }
};

class Danger:public Add_on
{    
    public:
    Danger()//constructor
    {
        srand(time(0));
        texture.loadFromFile("img/PNG/Meteors/meteorBrown_big4.png");
        sprite.setTexture(texture);
        x=rand()%750;
        y=0;
        sprite.setPosition(x,y);
        sprite.setScale(0.3,0.3);
       
    }
};
class flame:public Add_on
{    
    public:
    flame()//constructor
    {
        srand(time(0));
        texture.loadFromFile("img/PNG/Power-ups/bolt_gold.png");
        sprite.setTexture(texture);
        x=rand()%750;
        y=0;
        sprite.setPosition(x,y);
        sprite.setScale(1,1);
       
    }
};
