#ifndef FRAMEWORK_H_INCLUDED
#define FRAMEWORK_H_INCLUDED
#include<string>
using namespace std;
void basic_frame(int x=1,int y=1,int height=10,int width=40,char log='-',char ver='|');
void gotoxy(int x,int y);
void caption(int x,int y,string inputstr);
void clean_line(int xstart,int ystart,int len);
void clean_line_row(int xstart,int ystart,int len);
void clean_area(int x,int y,int width,int height);
void draw_column(int xstart,int  ystart,int len,char op='|');
void draw_row(int xstart,int ystart,int len,char op='-');
void msgboxer(int x,int y,string inform,int linewidth,int height,int width,int blankline);
void move_frame(int x,int y,string inputstr,int speed_per_char=100,int len=110,int height=1,char style_log='-',char style_ver='|');
string psdbox(int x,int y);
void draw_grid(int xstart,int ystart ,int length,int height);
void parse();
#endif // FRAMEWORK_H_INCLUDED
