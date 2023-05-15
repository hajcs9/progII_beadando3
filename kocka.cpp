#include "graphics.hpp"
#include "widgets.hpp"
#include "kezdogomb.hpp"
#include "kocka.hpp"

int jatekos=1;

int jtks()
{
    return jatekos;
}

const int a=25;
const int b=1;

Kocka::Kocka(int px, int py): x(px), y(py){ovx=-1;}
void Kocka::rajz(bool focus)
{
    int bl=150;
    if(focus)bl=255;
    gout << move_to(x,y) << color(100,100,100) << box_to(x+a,y+a);
    gout << move_to(x+b,y+b) << color(250,250,250) << box_to(x+a-b,y+a-b);
    if(ovx == 0)
    {
        gout << move_to(x+b*3,y-a/a) << color(0,0,0+bl) << text("O");
    }
    if(ovx == 1)
    {
        gout << move_to(x+a/5,y-a/a) << color(0+bl,0,0) << text("X");
    }
}

bool Kocka::focus(event ev)
{
    if(hitbox(x+b,x+a-b,y+b,y+a-b,ev) && ev.button == btn_left) return true;
    return false;
}

void Kocka::valt(event ev)
{
    if(leker_kezd())
    {
        if(hitbox(x,x+a,y,y+a,ev) && ev.button == btn_left && ovx == -1 && jatekos == 1)
        {
            ovx = 1;
            jatekos = 0;
        }
        else if(hitbox(x+b,x+a-b,y+b,y+a-b,ev) && ev.button == btn_left && ovx == -1 && jatekos == 0)
        {
            ovx = 0;
            jatekos = 1;
        }
    }
    else
    {
        ovx=-1;
        jatekos=1;
    }
}
