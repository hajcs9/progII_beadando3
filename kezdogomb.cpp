#include "graphics.hpp"
#include "widgets.hpp"
#include "kezdogomb.hpp"
#include "vezerlo.hpp"

bool elkezd=false;
bool leker_kezd()
{
    return elkezd;
}

Kezdogomb::Kezdogomb(Window* w, int px, int py) : Widget(w,px,py){}

void Kezdogomb::rajz(bool focus)
{
    if(focus == false)
    {
        gout << move_to(x,y) << color(100,100,100) << box_to(x+100,y+50);
        gout << move_to(x+8,y+10) << color(255,255,255) << text(kiir);
    }

}

bool Kezdogomb::focus(event ev)
{
    return false;
}

void Kezdogomb::valt(event ev)
{
    if(hitbox(x,x+100,y,y+50,ev) && ev.button == btn_left && elkezd == false && win()==-1)
    {
        elkezd = true;
        kiir = "Vissza";
    }
    if(hitbox(x,x+100,y,y+50,ev) && ev.button == btn_left && elkezd == true && win()>-1)
    {
        elkezd = false;
        kiir="Kezdes";
    }
}
