#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "window.hpp"

using namespace genv;

bool hitbox(int x,int kx,int y, int ky, event ev);

struct Window;

class Widget
{
protected:
    Window* _w;
    int x,y;
public:
    Widget(Window* w,int px, int py);
    virtual void rajz(bool focus);
    virtual void valt(event ev){}
    virtual bool focus(event ev);
    virtual ~Widget(){}
};

#endif // WIDGETS_HPP_INCLUDED
