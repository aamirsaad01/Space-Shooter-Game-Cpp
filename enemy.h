#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "bomb.h"
using namespace std;
class enemy
{
    public:
    Texture texture;
    Sprite sprite;
    int x,y;
    Bomb *bomb;
    bool flag=0;
    bool bf=0;//bf=bullet flag
    bool mons=0;
    string type;
    enemy()
    {
        bomb=new Bomb;
    }
    virtual void setEnemy()
    {
        sprite.setPosition(x,y);
        sprite.setScale(0.5,0.5);
    }
    virtual void fire()
    {
        for (int i = 0; i < 1; i++) 
	    {
            if (bomb->bullets[i].getPosition().y >= 780) 
		    {
                bomb->bullets[i].setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 5, 
                sprite.getPosition().y);
                break;
            }
        }
    }
    enemy operator=(enemy &a)
    {
        texture=a.texture;
        sprite=a.sprite;
        x=a.x;
        y=a.y;
        bomb->bullets=a.bomb->bullets;
        bomb->bullet_texture=a.bomb->bullet_texture;
        flag=a.flag;
        mons=a.mons;
        type=a.type;
        return *this;
    }
};
class Invader:public enemy
{
    public:
    virtual void setEnemy()
    {
        
    }
    void fire() 
    {
        for (int i = 0; i < 1; i++) 
	    {
            if (bomb->bullets[i].getPosition().y >= 780) 
		    {
                bomb->bullets[i].setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 5, 
                sprite.getPosition().y);
                break;
            }
        }
    }
   
};
class Monster:public enemy
{
    public:
    Monster()
    {
        texture.loadFromFile("img/monster.png");
        sprite.setTexture(texture);
        bomb->bullets = new Sprite[1];
        bomb->bullet_texture.loadFromFile("img/PNG/Lasers/laserRed13.png");
        for (int i = 0; i < 1; i++) 
		{
            bomb->bullets[i].setTexture(bomb->bullet_texture);
            bomb->bullets[i].setScale(0.5, 15);
            bomb->bullets[i].setPosition(1000, 1000);
		}
        flag = 0;
        type="m";
    }
    void setEnemy()
    {
        sprite.setPosition(x,y);
        sprite.setScale(0.2,0.2);
    }
    void fire() 
    {
        for (int i = 0; i < 1; i++) 
	    {
            if (bomb->bullets[i].getPosition().y >= 780) 
		    {
                bomb->bullets[i].setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 5, 
                sprite.getPosition().y);
                break;
            }
        }
    }
    
};
class Alpha:public Invader
{
    public:
    Alpha()
    {
        texture.loadFromFile("img/enemy_1.png");
        sprite.setTexture(texture);
        flag = 0;
        type="a";
    }
    void setEnemy()
    {
        sprite.setPosition(x,y);
        sprite.setScale(0.5,0.5);
    }
};
class Beta:public Invader
{
    public:
    Beta()
    {
        texture.loadFromFile("img/enemy_2.png");
        sprite.setTexture(texture);   
        flag = 0;
        type="b";
    }
};

class Gamma:public Invader
{
    public:
    Gamma()
    {
        texture.loadFromFile("img/enemy_3.png");
        sprite.setTexture(texture);
        flag = 0;
        type="g";
    }
};








