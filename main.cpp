#include "graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "window.hpp"
#include "widgets.hpp"
#include "kocka.hpp"
#include "vezerlo.hpp"
#include "kezdogomb.hpp"

using namespace genv;
using namespace std;

const int SX = 600;
const int SY = 600;
const double scaleX = (double)SX/600;
const double scaleY = (double)SY/600;

struct Ablak : public Window
{
    Vezerlo * v;
    Kezdogomb * kezd;
    vector<Kocka *> kocka_s;
    vector<vector<Kocka *>> kocka_o;
    Ablak() : Window(SX,SY)
    {
        for(size_t i=0;i<15;i++)
        {
            for(size_t j=0;j<15;j++)
            {
                kocka_s.push_back(new Kocka(this,100*scaleX+j*25*scaleX,100*scaleY+i*25*scaleY));
            }
            kocka_o.push_back(kocka_s);
            kocka_s.clear();
        }
        kezd = new Kezdogomb(this,SX/2-50*scaleX,SY-100*scaleY);
        v = new Vezerlo(this,100*scaleX,100*scaleY,kocka_o);
    }
};

int main()
{
    Ablak ablak;
    ablak.loop();
    return 0;
}
