#include <SFML/Graphics.hpp>
#include<string.h>
class Bullet
{
    public:
    Sprite *bullets;
    Texture bullet_texture;
    Bullet()
    {
        bullets = new Sprite;
        bullet_texture.loadFromFile("img/PNG/Lasers/laserRed14.png");
        for (int i = 0; i < 1; i++) 
		{
            bullets[i].setTexture(bullet_texture);
            bullets[i].setScale(0.5, 0.5);
            bullets[i].setPosition(-1000, -1000);
		}
    }

};