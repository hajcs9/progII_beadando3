#include "graphics.hpp"
#include "widgets.hpp"

bool hitbox(int x,int kx,int y, int ky, event ev)
{
    if((ev.pos_x >= x && ev.pos_x <= kx) &&(ev.pos_y >= y && ev.pos_y < ky)) return true;
    else return false;
}

Widget::Widget(Window* w,int px, int py): _w(w), x(px), y(py)
{
    w->addwidget(this);
}

void Widget::rajz(bool focus)
{
    int bl=0;
    if(focus)bl=100;
    gout << move_to(x,y) << color(200,0,bl) << box_to(x+125,y+50);
    gout << color(255,255,255);
}

bool Widget::focus(event ev)
{
    if(hitbox(x,x+125,y,y+50,ev) && ev.button == btn_left)
    {
        return true;
    }
    else return false;
}
