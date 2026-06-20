
#include <SFML/Graphics.hpp>
#include<string.h>
#include <time.h>
#include"addon.h"
#include"menu.h"
#include"bullet.h"
using namespace std;
using namespace sf;
class Player
{
    public:
    Texture tex;
    Sprite sprite;
    int x,y;
    float speed=1;
    static const int MAX_BULLETS = 1;
    //Sprite *bullets;
    static const int an=1;
    Bullet *bt;
    Add_on *addOn;
    int count;//for add on condition
    //Texture bullet_texture;
    int lives;
    int add_check;//tells the type of adon
    bool flame_ch;//check for flame power up
    int ft;//notes the time at whcih power up is catched byh the player
  
   
    Player(string png_path)
    {
       
        flame_ch=0;  
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);            
        x=340;y=550;            
        sprite.setPosition(x,y);          
        sprite.setScale(0.5,0.5);
        bt=new Bullet;
        ///////////////////////////
        lives=3;
        count = 0;
        addOn = NULL;
        
    }
    
    void fire() 
    {
        for (int i = 0; i < MAX_BULLETS; i++) 
	    {
            if (bt->bullets[i].getPosition().y < 0) 
		    {
                bt->bullets[i].setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 5, 
                sprite.getPosition().y);
                break;
            }
        }
    }

    void ad() 
    {
        if(count == 0)
        {
            int rand_an=(rand()%3)+1;
        
            if(rand_an==1)
            addOn = new Life;
            else if(rand_an==2)
            addOn = new Danger;
            else if(rand_an==3)
            addOn = new flame;
            
            count = 1;
            add_check=rand_an;
        }
        
    }

    void display(RenderWindow& window)
    {
        if(count==1)
        {
            window.draw(addOn->sprite);
        }
       
        
    }

    void update_addon(float &timer) 
    {
        if (count == 1) 
        {
            if(addOn->sprite.getPosition().y>sprite.getPosition().y && addOn->sprite.getPosition().y<sprite.getPosition().y+sprite.getGlobalBounds().width && addOn->sprite.getPosition().x>sprite.getPosition().x && addOn->sprite.getPosition().x<sprite.getPosition().x+sprite.getGlobalBounds().width) 
            {
                count = 0;
                delete addOn;
                addOn = NULL;
                if(add_check==2)
                lives--;
                else if(add_check==1)
                lives++;
                else if(add_check==3)
                {    
                    flame_ch=1;
                    ft=timer+5;
                }
            }

            else if (addOn->sprite.getPosition().y < 780) 
            {
                addOn->sprite.move(0, 0.5);
            }
            
            else 
            {
                count = 0;
                delete addOn;
                addOn = NULL;
            }
        }
    }
    void move(string s)
    {
        float delta_x=0,delta_y=0;
        if(s=="l")
	        delta_x=-1;	//move the player left
        else if(s=="r")
	        delta_x=1;	//move the player right
        if(s=="u")
	        delta_y=-1;
        else if(s=="d")
	        delta_y=1;
        
        
        delta_x*=speed;
        delta_y*=speed;
        sprite.move(delta_x, delta_y);
        Wrap();
    }
    void Wrap()
    {
        if(sprite.getPosition().x<0-sprite.getGlobalBounds().width)
            sprite.setPosition(730, sprite.getPosition().y);
        else if(sprite.getPosition().x>740)
            sprite.setPosition(-sprite.getGlobalBounds().width, sprite.getPosition().y);
        if(sprite.getPosition().y<-sprite.getGlobalBounds().height)
            sprite.setPosition(sprite.getPosition().x,780);
        else if(sprite.getPosition().y>780)
            sprite.setPosition(sprite.getPosition().x,-sprite.getGlobalBounds().height);

    }	
};
