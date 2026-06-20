#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Menu{
public:
Sprite sprite;
Texture tex;
Sprite ps;//sprite for pause
Sprite insp;//sprite for instructions
Sprite gs;//sprite for gameover
Texture gt;//texture for gt
Texture tp;//Texture for pause
Texture tins;//texture for instructions 
Sprite lvs;//levels
Texture tl;//levels
Sprite hs;//highscore
Texture th;//highscore

Font font;

string h1,h2,h3;
Text H1,H2,H3;
////////////////////////////////////////

bool dis;
bool pause;
bool resume;
bool ins;
bool newgame;
bool gameover;
bool highscore;
bool levels;

//add menu attributes here
Menu()
{
    //constructors body

    tex.loadFromFile("img/main.jpeg");
    sprite.setTexture(tex);
    sprite.setScale(1,1);
    //////////////////////////////////////////
    tp.loadFromFile("img/pause.jpeg");
    ps.setTexture(tp);
    ps.setScale(1,1);
    //////////////////////////////////////////
    tins.loadFromFile("img/ins.jpeg");
    insp.setTexture(tins);
    insp.setScale(1,1);
    //////////////////////////////////////////
    gt.loadFromFile("img/go.jpeg");
    gs.setTexture(gt);
    gs.setScale(1,1);
    //////////////////////////////////////////
    tl.loadFromFile("img/lvs.jpeg");
    lvs.setTexture(tl);
    lvs.setScale(1,1);
    //////////////////////////////////////////
    th.loadFromFile("img/hs.jpeg");
    hs.setTexture(th);
    hs.setScale(1,1);
    //////////////////////////////////////////

    string info;
    ifstream file;
    file.open("Highscore.txt", ios::in);
     for(int i=0;i<3 && file.eof()==0;i++)
     {
        getline(file,info);
        if(i==0)
        h1=info;
        else if(i==1)
        h2=info;
        else
        h3=info;
     }
    file.close();

    font.loadFromFile("Calibri Bold Italic.ttf");
        //loading font file

        ///////////////////////////////////
        //getting the high scores ready

        H1.setFont(font);
        H2.setFont(font);
        H3.setFont(font);

        H1.setCharacterSize(24);
        H2.setCharacterSize(24);
        H3.setCharacterSize(24);

        H1.setFillColor(Color::Red);
        H2.setFillColor(Color::Red);
        H3.setFillColor(Color::Red);

        H1.setString(h1);
        H1.setPosition(50, 400);
        H2.setString(h2);
        H2.setPosition(50, 430);
        H3.setString(h3);
        H3.setPosition(50, 460);

    /////////////////////////////////////////////////
    
    dis=0;
    pause=0;
    resume=0;
    ins=0;
    newgame=0;
    gameover=0;
    highscore=0;
    levels=0;


}

void display_menu(RenderWindow& window)
{
    
    while(dis==0&&gameover==0)
    {
    
    Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) 
            {
                window.close(); 
                return;
            }                   	    
        }
        if(dis==0 && ins==0 && gameover==0 && levels==0 && highscore==0 ) 
        {        
            window.draw(sprite);
            window.display();
            window.clear();
        }
        if(dis==0 && levels==1 && gameover==0 && ins==0 && highscore==0)  
        {        
            window.clear();
            window.draw(lvs);
            window.display();
            
        }
        if(dis==0 && levels==0 && gameover==0 && ins==1 && highscore==0)
        {
            window.clear();
            window.draw(insp);
            window.display();
        }
        if(dis==0 && levels==0 && gameover==0 && ins==0 && highscore==1)
        {
            window.clear();
            window.draw(hs);

            window.draw(H1);
            window.draw(H2);
            window.draw(H3);
            window.display();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter)) 
        {
            dis=1;
            ins=0;
        }
        if (Keyboard::isKeyPressed(Keyboard::I) && dis==0 && ins==0 && highscore==0 && levels==0 )
        {
            ins=1;
        }
        if ((Keyboard::isKeyPressed(Keyboard::H) && dis==0 && ins==0 && highscore==0 && levels==0 ))
        {
            highscore=1;

        }
        if ((Keyboard::isKeyPressed(Keyboard::L) && dis==0 && ins==0 && highscore==0 && levels==0 ))
        {
            levels=1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)&& dis==0 && (ins==1||highscore==1||levels==1))
        {
            ins=0;
            levels=0;
            highscore=0;
        }

    }

}

void disp_pause(RenderWindow& window)
{
    while(pause==1)
    {
    
    Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) 
            {
                window.close(); 
                return;
            }                   	    
        }
        window.clear();        
        window.draw(ps);
        window.display();
        
        if (Keyboard::isKeyPressed(Keyboard::R) && gameover==0) 
        pause=0;
        
        if (Keyboard::isKeyPressed(Keyboard::N) && gameover==0) 
        {
            newgame=1;
            pause=0;
        }
        
        
    }

}
void disp_gameover(RenderWindow& window)
{
    while(gameover==1)
    {
    
        Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) 
            {
                window.close(); 
                return;
            }                   	    
        }
        
        {
            window.clear();        
            window.draw(gs);
            window.display();
        }
    }
}



};
