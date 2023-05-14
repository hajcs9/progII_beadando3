#ifndef VEZERLO_HPP_INCLUDED
#define VEZERLO_HPP_INCLUDED

#include "widgets.hpp"
#include "window.hpp"
#include "kocka.hpp"
#include "graphics.hpp"

int win();

class Vezerlo : public Widget
{
    std::vector<std::vector<Kocka *>> k;
public:
    Vezerlo(Window* w, int px, int py, std::vector<std::vector<Kocka *>> kocka);
    void rajz(bool focus);
    void valt(event ev);
    bool focus(event ev);
};

#endif // VEZERLO_HPP_INCLUDED
