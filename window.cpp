#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "kocka.hpp"
#include "vezerlo.hpp"

Window::Window(int x,int y) : _sx(x), _sy(y)
{
    gout.open(_sx,_sy);
    gout << font("LiberationSans-Regular.ttf",25);
}

void Window::loop()
{
    gout << color(0,0,0) << move_to(0,0) << box_to(_sx,_sy) << color(255,255,255);
    for (size_t i=0;i<widgets.size();i++)
    {
        widgets[i]->rajz(false);
    }
    gout << refresh;
    std::string gyoztes;

    bool fokusz=false;
    size_t fokuszalt=-1;
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(win() == -1)
        {
            gout << move_to(0,0) << color(0,0,0) << box(_sx,_sy) << color(255,255,255);
            if(jtks()==1) gout << move_to(150,50) << color(255,255,255) << text("Kovetkezik: X");
            else if(jtks()==0) gout << move_to(150,50) << color(255,255,255) << text("Kovetkezik: O");
            for (size_t i = 0; i<widgets.size(); i++)
            {
                fokusz=widgets[i]->focus(ev);
                widgets[i]->rajz(false);
                if(fokusz) fokuszalt = i;
                if(fokuszalt == i)
                {
                    widgets[i]->rajz(true);
                    widgets[i]->valt(ev);
                }
            }
        }
        else
        {
            gout << move_to(0,0) << color(0,0,0) << box(_sx,_sy) << color(255,255,255);
            if(win()==0) gyoztes="O";
            if(win()==1) gyoztes="X";
            gout << move_to(150,50) << color(255,255,255) << text("Gyoztes: ") << text(gyoztes);
            for (size_t i = 0; i<widgets.size(); i++)
            {
                widgets[i]->rajz(false);
            }
        }
        gout << refresh;
    }
}
