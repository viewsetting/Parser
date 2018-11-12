#include<iostream>
#include<cstdio>
#include<string>
#include<conio.h>
#include<windows.h>
#include"animation.h"
#include"framework.h"
using namespace std;
//animation::animation();
animation::~animation()
{

    ;
}
animation::animation(int x,int y)
{
    this->posx=x;
    this->posy=y;
}
void animation::change(int x,int y)
{
    this->posx=x;
    this->posy=y;
}
void animation::gotoxy(int x,int y)
{
    COORD pos;
    pos.X=x-1;
    pos.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void animation::freshcord()
{
    gotoxy(this->posx,this->posy);
}
void animation::show_dot( int spl, int dots,int loop,string head)
{
    int t=loop; //amount of loops
    while(t--)
    {
        cout<<head;   //if head is "Loading",then it would be "Loading......"
        for(int i=0; i<dots; i++)  //show those dots one by one at the interval you've set
        {
            cout<<'.';
            Sleep(1000*spl/dots);
        }
        system("cls");  //clean the screen
       // clean_line(int xstart,int ystart,int len)
    }
}

void animation::show_dot_gotoxy( int spl, int dots,int loop,int x,int y,string head)
{
    //freshcord();
    gotoxy(x,y);
    int t=loop;cout<<head;
    int len=head.size();
    while(t--)
    {

        for(int i=0; i<dots; i++)
        {
            cout<<'.';
            Sleep(1000*spl/dots);
        }
        gotoxy(x+len,y);
        //freshcord();
        for(int i=0;i<dots;i++)
        {
            cout<<' ';
        }
       // freshcord();
       gotoxy(x+len,y);
    }
    clean_line(x,y, len);
}

void animation:: rotatesign(int spds,int dots,string head)
{
    //freshcord();
    int p=1;
    cout<<head;
    while(p<dots)
    {

        cout<<"-";
        Sleep(100*spds);

        putchar('\b');
        cout<<"|";
        Sleep(100*spds);
        putchar('\b');
        cout<<"-";
        Sleep(100*spds);
        // system("cls");
        p++;
    }
    system("cls");

}
void animation::processbar_tra(int len,int spd,char style_bar,string style_conti,char style_vertical,int lenconti)
{
    freshcord();
    char bar=style_bar;
    string a=style_conti;
    char b=style_vertical;
    for(int i=0; i<len; i++)
        cout<<bar;
    //cout<<endl;
    gotoxy(posx,posy+1);
    cout<<b;
    for(int i=1; i<len-1; i++)
        cout<<' ';
    cout<<b;
    //cout<<endl;
    gotoxy(posx,posy+2);
    for(int i=0; i<len-1; i++)
        cout<<bar;
    gotoxy(2+posx-1,2+posy-1);
    for(int i=1; i<=len/lenconti-1; i++)
    {
        Sleep(100*spd);
        cout<<a;
    }
    clean_line( posx, posy  , len );
    clean_line( posx, posy+1, len );
    clean_line( posx, posy+2, len );
}

void animation::processbar_winxp(int len,int spd,char style_bar,char style_verticle,int lenchunk ,string style_conti)
{
    freshcord();
    char bar=style_bar;
    string a=style_conti;
    char b=style_verticle;
    for(int i=0; i<len; i++)
        cout<<bar;
   // cout<<endl;
   gotoxy(posx,posy+1);
    cout<<b;
    for(int i=1; i<len-1; i++)
        cout<<' ';
    cout<<b;
    //cout<<endl;
    gotoxy(posx,posy+2);
    for(int i=0; i<len-1; i++)
        cout<<bar;
    gotoxy(posx+1,posy+1);
    for(int p=0; p<lenchunk; p++)
        cout<<a;
    Sleep(100*spd);
    for(int i=2; i<len-lenchunk*2; i+=2)
    {
        gotoxy(i+posx-1,2+posy-1);
        cout<<"  ";
        gotoxy(i+2*lenchunk+posx-1,2-1+posy);
        cout<<a;
        //gotoxy(i+2+lenchunk,2);
        Sleep(100*spd);
    }
    clean_line( posx, posy  , len );
    clean_line( posx, posy+1, len );
    clean_line( posx, posy+2, len );
}


