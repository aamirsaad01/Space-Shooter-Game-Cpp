#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include"game.h"

int main()
{  
    Game g;
    
   
    string name;
    cin >> name;

    string info;
    int score;
    bool check=0;

    ifstream file;
    file.open("Highscore.txt", ios::in);
     for(int i=0;i<3 && file.eof()==0;i++)
     {
        getline(file,info);
        if(i==0)
        g.h1=info;
        else if(i==1)
        g.h2=info;
        else
        g.h3=info;
     }
    file.close();


     g.start_game();
     
    /////////////////////////////////////////
    file.open("Highscore.txt", ios::in);
    ofstream newFile ("new.txt", ios::out | ios::app);
    while(file.eof()==0)
    {
        getline(file, info);

        int i=0;
        for(i; info[i-1]!='\t' && info[i]!='\0'; )
        {
            i++;
        }
        string temp = info.substr(i);
        cout << temp <<endl;
        if(temp[0]<48||temp[0]>56)
        break;
        score = stoi(temp);
        cout << score <<endl;

        if(score<g.Score && check==0)
        {
            newFile << name << "\t" << g.Score << "\n";
            newFile << info << "\n";
            check = 1;
        }
        else
        {
            newFile << info << "\n";
        }
    }

    if(check==0)
    {
        newFile << name << "\t" << g.Score << "\n";
    }

    file.close();
    newFile.close();

    remove ("Highscore.txt");
    rename ("new.txt", "Highscore.txt");
    return 0;
}
