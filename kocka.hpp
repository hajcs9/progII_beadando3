#ifndef KOCKA_HPP_INCLUDED
#define KOCKA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

int jtks();

class Kocka : public Widget
{
    int ovx=-1;
public:
    Kocka(Window* w,int px, int py);
    void rajz(bool focus);
    void valt(event ev);
    bool focus(event ev);
    int kie(){return ovx;}
    ~Kocka(){}
};

#endif // KOCKA_HPP_INCLUDED
