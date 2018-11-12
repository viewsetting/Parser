#include<iostream>
#include<string>
#include"framework.h"
#include<conio.h>
#include<windows.h>
#include"animation.h"
#include<cstdio>
using namespace std;


void gotoxy(int x,int y)
{
    COORD pos;
    pos.X=x-1;
    pos.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void draw_column(int xstart,int  ystart,int len,char op)
{
    gotoxy(xstart,ystart);
    for(int i=1;i<=len;i++)
    {
        cout<<op;
        gotoxy(xstart,ystart+i);
    }
}
void draw_row(int xstart,int ystart,int len,char op)
{
     gotoxy(xstart,ystart);
    for(int i=0;i<len;i++)
    {
        cout<<op;
    }
}
void basic_frame(int x,int y,int height,int width,char log,char ver)
{
    gotoxy(x,y);
    for(int i=0;i<=width+1;i++)
    {
        cout<<log;
    }
    gotoxy(x,y+height+1);
    for(int i=0;i<=width+1;i++)
    {
        cout<<log;
    }
    gotoxy(x,y);
    for(int i=0;i<height;i++)
    {

        gotoxy(x,y+i+1);
        cout<<ver;
    }
    for(int i=0;i<height;i++)
    {

        gotoxy(x+width+1,y+i+1);
        cout<<ver;
    }
    gotoxy(1,1);

}
void caption(int x,int y,string inputstr)
{
    gotoxy(x,y);
    cout<<inputstr;
}
void clean_line(int xstart,int ystart,int len)
{
    gotoxy(xstart,ystart);
    for(int i=0;i<len;i++)
    {
        cout<<' ';
    }
}
void clean_line_row(int xstart,int ystart,int len)
{
    gotoxy(xstart,ystart);
    for(int i=1;i<=len;i++)
    {
        cout<<' ';
        gotoxy(xstart,ystart+i);
    }
}
void clean_area(int x,int y,int width,int height)
{
    for(int i=0;i<y;i++)
    {
        clean_line(x,y+i,width);
        gotoxy(x,y+i+1);
    }
}
void msgboxer(int x,int y,string inform,int linewidth,int height,int width,int blankline)
{
    basic_frame(x,y,height,width);
    int len=inform.size();
    int ans=len;
    int ori_x=x;
    int ori_y=y;
    y+=blankline;
    x+=(-linewidth)/2+width/2;

    while(ans)
    {
        gotoxy(x,y);
        for(int i=0;i<linewidth;i++)
           {
               if(len-ans<len)
               {
                   cout<<inform[-ans+len];
                   ans--;
               }
               else break;

           }
           y++;

    }

   // animation tem (13,27);
   // tem.show_dot_gotoxy(1,4,1000,"Press Enter To Quit");
}

void move_frame(int x,int y,string inputstr,int speed_per_char,int len,int height,char style_log,char style_ver)
{
   // gotoxy (x,y);
    int strl=inputstr.size();
    basic_frame(x-1,y,height,len+1,style_log,style_ver);
    //caption(5,2,"99");
   // Sleep(1500);
    int h=y+(height+1)/2;
    //clean_line(x+1,h,len);
    //const int lenth=len;
    char opstr[150];
    for(int i=0;i<len;i++)
    {
        if(i<strl)
            opstr[i]=inputstr[i];
        else
            opstr[i]=' ';
    }
    int pos=1;
    while(1)   ////here's a unstoppable loop!!!
    {
        gotoxy(x+pos,h);

        for(int i=0;i<len-pos;i++)
            cout<<opstr[i];
        gotoxy(x,h);
        for(int i=len-pos;i<len;i++)
            cout<<opstr[i];
        Sleep(speed_per_char);
        clean_line(x+1,h,len);
        if(pos==len) pos=0;
        else pos++;

    }

}
/*string psdbox(int x,int y)
{
    basic_frame(x,y,11,40,'-','|');
    caption(x+15,y+4,"输入密码");
    basic_frame(x+15,y+5,1,6);
    gotoxy(x+16,y+6);
    string tem;
    char k[6];
    char passwd[6+1] = "";

    unsigned char c;
    int i=0;

    while ((c=getch())!='\r')       //密码回显功能的实现
    {
        if (i<6 && isprint(c))
        {
            passwd[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b')
        {
            --i;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
    }
    putchar('\n');
    passwd[i] = '\0';

    tem=passwd;

    return tem;
}*/
void draw_grid(int xstart,int ystart ,int length,int height)
{
    gotoxy(xstart,ystart);
    for(int i=0;i<height;i+=1)
    {
        draw_row(xstart,ystart+i,length);
        gotoxy(xstart,ystart+i+1);
    }
    for(int i=0;i<=length;i+=2)
    {
        draw_column(xstart+i,ystart,height);
        gotoxy(xstart+i+1,ystart+i);
    }

}

void parse()
{
    //msgboxer(2,2,"陈真皞 20167867  160212",16,5,10,2);
   // gotoxy(1,8);
    basic_frame(2,1,1,26);
    caption(5,2,"陈真皞 20167867 160212");
    gotoxy(1,4);
}
