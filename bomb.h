#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
class Bomb
{
    public:
    Sprite *bullets;
    Texture bullet_texture;
    Bomb()
    {
       
        bullets = new Sprite[1];
        bullet_texture.loadFromFile("img/PNG/Lasers/laserBlue08.png");
        for (int i = 0; i < 1; i++) 
		{
            bullets[i].setTexture(bullet_texture);
            bullets[i].setScale(0.5, 0.5);
            bullets[i].setPosition(1000, 1000);
		}
    }
};