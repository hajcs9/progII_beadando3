#include "graphics.hpp"
#include "widgets.hpp"
#include "kocka.hpp"
#include "vezerlo.hpp"
#include "kezdogomb.hpp"

#include <iostream>
#include <vector>

using namespace std;

int victor=-1;
int win()
{
    return victor;
}

Vezerlo::Vezerlo(Window* w, int px, int py, vector<vector<Kocka *>> kocka) : Widget(w,px,py), k(kocka){}

void osszekotott(size_t sor, size_t oszlop, int eltol_s, int eltol_o, vector<vector <Kocka*>> k, int &db, int xvo)
{
    int h=0;
    int g=0;
    while((oszlop+h)<k[sor].size() && (sor+g)<k.size() && k[sor+g][oszlop+h]->kie()==xvo)
    {
        db++;
        if(eltol_s == 5)g++;
        if(eltol_o == 5)h++;
        if(eltol_s == -5)g--;
        if(eltol_o == -5)h--;
    }
    h=0;
    g=0;
    while((oszlop-h)<k[sor].size() && (sor-g)<k.size() && k[sor-g][oszlop-h]->kie()==xvo)
    {
        db++;
        if(eltol_s == 5)g++;
        if(eltol_o == 5)h++;
        if(eltol_s == -5)g--;
        if(eltol_o == -5)h--;
    }
}

void Vezerlo::valt(event ev)
{
    if(leker_kezd() && win()==-1)
    {
        vector<int> counter_O = {-1,-1,-1,-1};
        vector<int> counter_X = {-1,-1,-1,-1};
        int betelt=0;
        for(size_t i=0;i<k.size();i++)
        {
            for(size_t j=0;j<k[i].size();j++)
            {
                if(k[i][j]->kie()>-1 && k[i][j]->focus(ev))
                    {
                        //sor
                        osszekotott(i,j,0,5,k,counter_O[0],0);
                        osszekotott(i,j,0,5,k,counter_X[0],1);
                        //oszlop
                        osszekotott(i,j,5,0,k,counter_O[1],0);
                        osszekotott(i,j,5,0,k,counter_X[1],1);
                        //atlos1
                        osszekotott(i,j,5,5,k,counter_O[2],0);
                        osszekotott(i,j,5,5,k,counter_X[2],1);
                        //atlos2
                        osszekotott(i,j,5,-5,k,counter_O[3],0);
                        osszekotott(i,j,5,-5,k,counter_X[3],1);
                        //reset
                        for(int n=0;n<4;n++)
                        {
                            if(counter_O[n] > 4) {victor=0;}
                            else if(counter_X[n] > 4) {victor=1;}
                        }
                        counter_O={-1,-1,-1,-1};
                        counter_X={-1,-1,-1,-1};
                    }
                    if(k[i][j]->kie()==-1)betelt++;
            }
        }
        if(betelt == 0)
        {
            victor = 2;
        }
    }
    else if(!leker_kezd())
    {
        victor=-1;
        for(size_t i=0;i<k.size();i++)
        {
            for(size_t j=0;j<k[i].size();j++)
            {
                k[i][j]->valt(ev);
            }
        }
    }
}

