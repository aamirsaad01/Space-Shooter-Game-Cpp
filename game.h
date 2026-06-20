//Muhammad Saad Aamir
//22i-1059
//CS-K
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include "player.h"
#include "enemy.h"
using namespace std;

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
    public:
    bool x=0;   /*this variable will become
            true when all invaders are dead
            and monster is about to come*/

    Sprite background; //Game background sprite
    Texture bg_texture;//----------------------
    Sprite background2;//High Score showing sprite
    Texture bg_2;//-------------------------------
    Player* p; //player pointer
    enemy*en;//enemy
    Sprite B1,B2,B3;
    Texture b1,b2,b3;
    int count=0;//count will increment with death of each invader
    int en_loop=9;//Initial invaders
    int mlife=0;//life of monster
    int bcheck=3;//will be used in monster bullet as a check
    int Score;
    Menu m;
    //////////////////////////////////////////////////////
    //---variables for displaying lives and score---//////
    Font font;
    Text text;
    Sprite life;
    Texture life_tex;
    Sprite arr[20];
    /// variables for highscore ///
    string h1,h2,h3;
    Text H1,H2,H3;
    Game()
    {
        
        font.loadFromFile("Calibri Bold Italic.ttf");
        //loading font file

        ///////////////////////////////////
        //getting the high scores ready
        text.setFont(font);

        H1.setFont(font);
        H2.setFont(font);
        H3.setFont(font);

        H1.setCharacterSize(24);
        H2.setCharacterSize(24);
        H3.setCharacterSize(24);

        H1.setFillColor(Color::Red);
        H2.setFillColor(Color::Red);
        H3.setFillColor(Color::Red);

        text.setCharacterSize(24);
        text.setFillColor(Color::Red);

        ///////////////////////////////////
        /***loading necessary sprites*****/
        Score=0;    
        p=new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/background.jpg");
        bg_2.loadFromFile("img/background_1.png");
        b1.loadFromFile("img/PNG/Power-ups/star_gold.png");
        b2.loadFromFile("img/PNG/Power-ups/star_silver.png");
        b3.loadFromFile("img/PNG/Power-ups/star_bronze.png");
        B1.setTexture(b1);
        B2.setTexture(b2);
        B3.setTexture(b3);

        background.setTexture(bg_texture);
        background.setScale(1, 1.5);
        background2.setTexture(bg_2);
        background2.setScale(1, 1.5);
        life_tex.loadFromFile("img/life.png");
        life.setTexture(life_tex);
        for(int i=0;i<10;i++)
        {       
            arr[i]=life;
        }
        ////////////////////////////////////////

    }
    void start_game()
    {
    
        srand(time(0));
        RenderWindow window(VideoMode(1100, 780), title);
        m.display_menu(window);
        Clock clock;
        float timer=0;
        ////////////////////////////////////////
        
        string ScoreString = to_string(Score);
        //Storing Score as string to display on screen

        //Setting Positins on screen
        H1.setString(h1);
        H1.setPosition(800, 30);
        B1.setPosition(950,30);
        H2.setString(h2);
        H2.setPosition(800, 60);
        B2.setPosition(950,60);
        H3.setString(h3);
        H3.setPosition(800, 90);
        B3.setPosition(950,90);   
        text.setString(ScoreString);
        text.setPosition(20, 10);
    
    
    
    
        if(count>=0&&count<9)
        {
            en=new enemy [en_loop];
            //creating enemies
        }
        for(int i=0;i<en_loop;i++)
        {
            //this loop will divide enemies as alpha beta and gama
            enemy*ptr;
            if(i==0||i==1||i==2||i==8||i==7||i==6)
            ptr=new Alpha;
            else if(i==3||i==5)
            ptr=new Beta;
            else if(i==4)
            ptr=new Gamma;
            en[i]=*ptr;
            ptr=NULL;
        }
        
        if(count>=0&&count<=9)
        {
            for(int i=0;i<en_loop && en[i].flag==0;i++)
            {
                //this loop is setting positions
                if(i==4)
                {   
                    en[i].x=i*87;
                    en[i].y=50;
                }
                if(i==0||i==1||i==2||i==8||i==7||i==6)
                {
                    en[i].y=150;
                    if(i==0||i==1||i==2)
                    {
                        en[i].x=(i*90)+150;
                    }
                    else if(i==8||i==7||i==6)
                    {
                        en[i].x=(i*90)-120;
                    }
                }
                else
                {
                    en[i].x=i*90;
                    en[i].y=50;
                }
                    en[i].setEnemy();
                
            }
        }
        m.display_menu(window);
        //displaying initial window
        while (window.isOpen())
        {
            if(count>=9 && x==0)
            {
                x=1;
                delete [] en;
                en=NULL;
                en=new Monster;
                en->x=240;
                en->y=50;
                en->setEnemy();
                    en_loop=1;
            }
        
            bool rb=0;//remove bullet
            float time = clock.getElapsedTime().asSeconds(); 
            clock.restart();
            timer += time; 
 	        Event e;
            while (window.pollEvent(e))
            {  
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game 
                                      	    
            }
        
        
        
          
	        if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
                    p->move("l");    // Player will move to left
	        if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                    p->move("r");  //player will move to right
	        if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
                    p->move("u");    //playet will move upwards
	        if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                    p->move("d");  //player will move downwards
            if (Keyboard::isKeyPressed(Keyboard::Space))
                    p->fire();
            if ((int (timer))%4==0)
                    p->ad();
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                m.pause=1;
                //to check if pause window is open
                m.disp_pause(window);//,count,en,en_loop);
                if(m.newgame)
                {   
                    //if player opts for new game the below condition resets every thing
                    Score=0;
                    p->lives=3;
                    count=0;
                    en_loop=9;
                    mlife=0;
                    if(x==0)
                    {   
                        delete [] en;
                        en=NULL;
                    }
                    if(x==1)
                    {
                        delete en;
                        en=NULL;
                        x=0;
                    }
                    en=new enemy [en_loop];
                    for(int i=0;i<en_loop;i++)
                    {
                
                        enemy*ptr;
                        if(i==0||i==1||i==2||i==8||i==7||i==6)
                        ptr=new Alpha;
                        else if(i==3||i==5)
                        ptr=new Beta;
                        else if(i==4)
                        ptr=new Gamma;

                        en[i]=*ptr;
                        ptr=NULL;
                    }
                    for(int i=0;i<en_loop && en[i].flag==0;i++)
                    {
                        //this loop is setting positions
                        if(i==4)
                        {   
                            en[i].x=i*87;
                            en[i].y=50;
                        }
                        if(i==0||i==1||i==2||i==8||i==7||i==6)
                        {
                            en[i].y=150;
                            if(i==0||i==1||i==2)
                            {
                                en[i].x=(i*90)+150;
                            }
                            else if(i==8||i==7||i==6)
                            {
                                en[i].x=(i*90)-120;
                            }
                        }
                        else
                        {
                            en[i].x=i*90;
                            en[i].y=50;
                        }
                        en[i].setEnemy();
                
                    }
                    m.newgame=0;
                    continue;

                }
            }
        string ScoreString = to_string(Score);
        ////////////////////////////////////////////////
        /////  Call your functions here            ////
        //////////////////////////////////////////////

        window.clear(Color::Black); //clears the screen
        window.draw(background);  // setting background
        background2.setPosition(780,0);
        window.draw(background2);//setting second background
        window.draw(p->sprite);   // setting player on screen

        if(p->lives<=0)
        {
            //displaying gameover
            m.gameover=1;
            m.disp_gameover(window);
        }
    
        Sprite* bullet_array = p->bt->bullets;
        for(int i=0;i<en_loop;i++)
        {
        
            if(bullet_array->getPosition().y>en[i].sprite.getPosition().y && bullet_array->getPosition().y<en[i].sprite.getPosition().y+en[i].sprite.getGlobalBounds().width && bullet_array->getPosition().x>en[i].sprite.getPosition().x && bullet_array->getPosition().x<en[i].sprite.getPosition().x+en[i].sprite.getGlobalBounds().width &&en[i].flag==0)
            {
                //condition to check if enemy is killed
                if(x==0)
                {
                    en[i].flag=1;
                    count++;
                    rb=1;
                    if(en[i].type=="a")
                    {
                        Score+=10;
                    }
                    else if(en[i].type=="b")
                    {
                        Score+=20;
                    }
                    else if(en[i].type=="g")
                    {
                    Score+=30;
                    }
                    break;
                    //all this is incremneting score on the bases of enemy
                }
                else if(x==1)
                {
                    mlife++;
                    rb=1;
                    if(mlife==10)
                    {
                        Score+=40;
                        en[i].flag=1;
                        break;
                    }
                }
            
            }
        }
        for(int i=0;i<en_loop;i++)
        {
            //loop for random falling of enemies

            if(en[i].flag==0)
            {
                //flag checks if enemy is dead or alive
                window.draw(en[i].sprite);
                if (x==0)
                {
                    if(i==0||i==1||i==2||i==8||i==7||i==6)
                    {
                        if(int(timer)%7==0)
                        en[i].fire();
                    }
                    else if(i==3||i==5)
                    {
                        if(int(timer)%3==0)
                        en[i].fire();

                    }
                    else if(i==4)
                    {
                        if(int(timer)%2==0)
                        en[i].fire();
                    }
            }
                if(int(timer)%2==0)
                    en[i].fire();
            }
        
        }
        for (int i = 0; i < en_loop; i++) 
        {
            if(x==0)//if monstert on invaders
            {
                if (en[i].bomb->bullets[0].getPosition().y>p->sprite.getPosition().y && en[i].bomb->bullets[0].getPosition().y<p->sprite.getPosition().y+p->sprite.getGlobalBounds().width && en[i].bomb->bullets[0].getPosition().x>p->sprite.getPosition().x && en[i].bomb->bullets[0].getPosition().x<p->sprite.getPosition().x+p->sprite.getGlobalBounds().width) // If the bullet is visible on the screen
                {   
                    //condition if bomb has hit the player
                    p->lives--;
                    en[i].bomb->bullets[0].setPosition(1000,1000);
                    p->sprite.setPosition(340,550);
                    break;
                }
            }
            else
            {
                if(en[i].bomb->bullets[0].getPosition().x > p->sprite.getPosition().x && en[i].bomb->bullets[0].getPosition().x < p->sprite.getGlobalBounds().width+p->sprite.getPosition().x&&bcheck==1)
                {
                    //a seprate condition for monster laser as it is quite long
                    p->lives--;
                    p->sprite.setPosition(340,550);
                    bcheck=0;
                    en[i].bomb->bullets[0].setPosition(1000,1000);
                    timer+=9;
                    break;
                }
            }
        }
        for (int i = 0; i < en_loop; i++) 
        {
            if(p->sprite.getPosition().y>en[i].sprite.getPosition().y && p->sprite.getPosition().y<en[i].sprite.getPosition().y+en[i].sprite.getGlobalBounds().height && ((p->sprite.getPosition().x>en[i].sprite.getPosition().x && p->sprite.getPosition().x<en[i].sprite.getPosition().x+en[i].sprite.getGlobalBounds().width) || (p->sprite.getPosition().x+p->sprite.getGlobalBounds().width>en[i].sprite.getPosition().x && p->sprite.getPosition().x+p->sprite.getGlobalBounds().width<en[i].sprite.getPosition().x+en[i].sprite.getGlobalBounds().width)) && en[i].flag==0 )
            {
                //condition if player collides with enemy
                p->lives--;
                p->sprite.setPosition(340,550);
            }
        }
        p->display(window);
        p->update_addon(timer);
        for (int i = 0; i < Player::MAX_BULLETS; i++) 
        {
            if (bullet_array[i].getPosition().y >= 0) // If the bullet is visible on the screen
            { 
                 if((p->ft>=timer&&p->flame_ch==1))
                 {    
                    //a condition for flame adon
                    bullet_array[i].move(0, -1); // Move the bullet upwards
                    window.draw(bullet_array[i]); 
                 }
                else if(p->flame_ch==1)
                {
                    p->flame_ch = 0;
                }
                else if(rb==1)
                {
                    //if bullet is to be removed
                    bullet_array[i].move(0, -1000); // Move the bullet upwards
                    window.draw(bullet_array[i]); // Draw the bullet on the screen
                    rb=0;
                }
                else
                {
                    bullet_array[i].move(0, -1); // Move the bullet upwards
                    window.draw(bullet_array[i]); // Draw the bullet on the screen
                }
                
                
            }
            
        }
        for (int i = 0; i < en_loop; i++) 
        {
            
            if (en[i].bomb->bullets[0].getPosition().y < 780) // If the bullet is visible on the screen
            { 
                if(x==0)
                en[i].bomb->bullets[0].move(0, +0.3); //Move the bullet downwards
                else 
                {
                    //conditions for Interval of lasers
                    if(int(timer)%8>=4)
                    {
                        en[i].bomb->bullets[0].setPosition((en[i].sprite.getPosition().x+en[i].sprite.getGlobalBounds().width)-130, en[i].sprite.getPosition().y+70);
                        bcheck=1;
                    }
                    else
                    {
                        en[i].bomb->bullets[0].setPosition(1000,1000);
                        bcheck=0;
                    }
                }
                window.draw(en[i].bomb->bullets[0]); // Draw the bullet on the screen
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        if(x==1)
        {
            //condition for movement of monster
            static int check = 0;
            if(check==0)
            {   
                en->sprite.move(0.5,0);
                if(en->sprite.getPosition().x>520)
                {
                    check = 1;
                }
            }
            else if(check==1)
            {   
                en->sprite.move(-0.5,0);
                if(en->sprite.getPosition().x<0)
                {
                    check = 0;
                }
            }
        }
        for(int i=0;i<p->lives;i++)
        {
            //this loop is drawing small hearts to show no of lives left
            arr[i].setScale(0.5,0.5);
            arr[i].setPosition(740-(i*40),10);
            window.draw(arr[i]);
        }
            string s = "Score: ";
        string temp = s + ScoreString;
        text.setString(temp);
        window.draw(text);
        window.draw(H1);
        window.draw(H2);
        window.draw(H3);
        window.draw(B1);
        window.draw(B2);
        window.draw(B3);
        window.display();  //Displying all the sprites
    }

    
}


};

