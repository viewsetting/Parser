#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include "windows.h"
#include<iostream>
#include<string>
using namespace std;
class animation
{
public:
    void show_dot( int spl,int dots,int loop, string head="loading");
    void rotatesign ( int spcs,int dots,string head);
    void processbar_tra(int len,int spd,char style_bar='-',string style_conti="■",char style_verticle='|',int lenconti=2);
    void processbar_winxp(int len,int spd,char style_bar='-',char style_verticle='|',int lenchunk=2,string style_conti="■" );
    animation(int x=1,int y=1);
    ~animation();
    void change(int x,int y);
    void show_dot_gotoxy( int spl, int dots,int loop,int x,int y,string head="Loading");
   // animation();
    void gotoxy(int x,int y);
    void freshcord();
    int posx;
    int posy;
};

#endif // ANIMATION_H_INCLUDED
