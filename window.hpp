#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

struct Widget;

class Window
{
    int _sx=800, _sy=800;
    std::vector<Widget *> widgets;
public:
    Window(int x,int y);
    virtual ~Window(){}
    void loop();
    void addwidget(Widget* w) {widgets.push_back(w);}
};

#endif // WINDOW_HPP_INCLUDED
