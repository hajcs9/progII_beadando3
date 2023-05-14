#include "graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "window.hpp"
#include "widgets.hpp"
#include "kocka.hpp"
#include "vezerlo.hpp"

using namespace genv;
using namespace std;

struct Ablak : public Window
{
    Vezerlo * v;
    vector<Kocka *> kocka_s;
    vector<vector<Kocka *>> kocka_o;
    Ablak() : Window(600,600)
    {
        for(size_t i=0;i<15;i++)
        {
            for(size_t j=0;j<15;j++)
            {
                kocka_s.push_back(new Kocka(100+j*25,100+i*25));
            }
            kocka_o.push_back(kocka_s);
            kocka_s.clear();
        }
        v = new Vezerlo(this,100,100,kocka_o);
    }
};

int main()
{
    Ablak ablak;
    ablak.loop();
    return 0;
}
