#ifndef KOCKA_HPP_INCLUDED
#define KOCKA_HPP_INCLUDED

#include "graphics.hpp"

int jtks();

class Kocka
{
    int x,y;
    int ovx=-1;
public:
    Kocka(int px, int py);
    void rajz(bool focus);
    void valt(event ev);
    bool focus(event ev);
    int kie(){return ovx;}
    ~Kocka(){}
};

#endif // KOCKA_HPP_INCLUDED
