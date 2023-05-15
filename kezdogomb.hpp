#ifndef KEZDOGOMB_HPP_INCLUDED
#define KEZDOGOMB_HPP_INCLUDED

#include "widgets.hpp"
#include "window.hpp"

bool leker_kezd();

class Kezdogomb : public Widget
{
    std::string kiir = "Kezdes";
public:
    Kezdogomb(Window* w,int px, int py);
    void rajz(bool focus);
    void valt(event ev);
    bool focus(event ev);
    ~Kezdogomb(){}
};

#endif // KEZDOGOMB_HPP_INCLUDED
