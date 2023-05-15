#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "kocka.hpp"
#include "vezerlo.hpp"
#include "kezdogomb.hpp"

Window::Window(int x,int y) : _sx(x), _sy(y)
{
    gout.open(_sx,_sy);
    gout << font("LiberationSans-Regular.ttf",25);
}

const int a=50;

void clear_box(int bx,int by)
{
    gout << move_to(0,0) << color(0,0,0) << box(bx,by) << color(255,255,255);
}

void title(int tx, int ty)
{
    gout << move_to(tx/2-(a+a/2),a-a/2) << color(255,0,0) << text("X ") << color(255,255,255) << text("Amoba")
    << color(0,0,255) << text(" O");
    gout << move_to(tx/2-(a+a/2-a/10),a) << color(255,255,255) << text("(2 jatekos)");
}

void Window::loop()
{
    title(_sx,_sy);
    for (size_t i=0;i<widgets.size();i++)
    {
        widgets[i]->rajz(false);
    }
    gout << refresh;
    std::string gyoztes;
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(!leker_kezd())
        {
            clear_box(_sx,_sy);
            title(_sx,_sy);
            for (size_t i = 0; i<widgets.size(); i++)
            {
                widgets[i]->rajz(false);
                widgets[i]->valt(ev);
            }
        }
        else if(win() == -1 && leker_kezd())
        {
            clear_box(_sx,_sy);
            gout << move_to(a*4,a) << color(255,255,255) << text("Kovetkezik: ");
            if(jtks()==1){gout << color(255,0,0) << text("X");}
            else if(jtks()==0){gout << color(0,0,255) << text("O");}
            for (size_t i = 0; i<widgets.size(); i++)
            {
                widgets[i]->rajz(true);
                widgets[i]->valt(ev);
            }
        }
        else if(win()>-1 && leker_kezd())
        {
            clear_box(_sx,_sy);
            gout << move_to(a*4+a/2,a) << color(255,255,255) << text("Gyoztes: ");
            if(win()==0) {gout << color(0,0,255) << text("O");}
            if(win()==1) {gout << color(255,0,0) << text("X");}
            if(win()==2) {gout << color(255,255,255) << text("Dontetlen");}
            gout << color(255,255,255);
            for (size_t i = 0; i<widgets.size(); i++)
            {
                widgets[i]->rajz(false);
                widgets[i]->valt(ev);
            }
        }
        gout << refresh;
    }
}
