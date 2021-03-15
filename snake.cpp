#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void draw()
{
    system("cls");
    for(int i=0;i<width+1;i++)
        cout<<"#";
    for(int i=0;i<height;i++)
    {
        cout<<endl;
        for(int j=0;j<width;j++)
        {
            if(j==0||j==(width-1))
                cout<<"#";
            if(i==fruitX && j==fruitY)
                cout<<"F";
            else if(i==x && j==y)
                cout<<"0";
            else
                cout<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<width+1;i++)
        cout<<"#";
    cout<<endl;
    cout<<"GAME SCORE "<<score;
}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            dir=LEFT;
            break;
        case 's':
            dir=RIGHT;
            break;
        case 'd':
            dir=DOWN;
            break;
        case 'a':
            dir=UP;
            break;
        case 'x':
            gameOver=true;
            break;
        }
    }

}
void logic()
{
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x>width || x<0 || y>height || y<0)
        gameOver=true;
    if(fruitX==x && fruitY==y)
    {
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;
    }

}
int main()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
    }
    return 0;
}