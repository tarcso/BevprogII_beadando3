#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Palya.hpp"
#include "Window.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>

using namespace genv;

const int XX = 800;
const int YY = 1000;

class JatekMester : public Window
{
    Palya* palya;
    Korong* tmp;
    PushButton* right;
    PushButton* left;
    PushButton* enter;
    PushButton* winner;
    std::function<void()> berak;
    bool retry = false;
    bool red = true;

public:
    JatekMester()
    {
        berak = [this](){
            if(palya->putInSiker(tmp))
            {
                bool color = abs(tmp->red()-1);
                tmp->changecolor(color);
                win();
            }
        };
        screenx = XX;
        screeny = YY;
        palya = new Palya(this, XX/16.0, XX/8.0*35.0/32.0, XX/8.0*7.0, XX/8.0*6.0, berak);
        tmp = new Korong(this, XX/2.0, (XX/8.0*35.0/32.0)/2, XX/16.0 * 45.0/60.0, XX/16.0 * 45.0/60.0, false, red);
        right = new PushButton(this, XX * 3/4.0-XX/10.0, YY * 6/7.0, XX/10.0, XX/20.0, "->", [this](){tmp->moveright();});
        left = new PushButton(this, XX/4.0, YY * 6/7.0, XX/10.0, XX/20.0, "<-", [this](){tmp->moveleft();});
        enter = new PushButton(this, XX/2.0 - XX/20.0, YY * 6/7.0, XX/10.0, XX/20.0, "enter", berak);
    }

    void win()
    {
        if(palya->vannyer().first)
        {
            std::string s = "A nyertes: ";
            if(palya->vannyer().second) 
                s += "piros!";
            else
                s += "sárga!";
            s += " Retry here!";
            winner = new PushButton(this, 295, 950, 210, 40, s, [this](){
                right->changefunc([this](){tmp->moveright();});
                left->changefunc([this](){tmp->moveleft();});
                enter->changefunc(berak);
                palya->changefunc(berak);
                palya->empty();
                delete tmp;
                tmp = new Korong(this, XX/2.0, (XX/8.0*35.0/32.0)/2, XX/16.0 * 45.0/60.0, XX/16.0 * 45.0/60.0, false, abs(red-1));
                retry = true;
                torolWidget(winner);
            });

            right->changefunc([](){});
            left->changefunc([](){});
            enter->changefunc([](){});
            palya->changefunc([](){});
        }

        if(retry)
        {
            delete winner;
            retry = false;
        }
    }

    void esemeny(const std::string& ki_mondta)
    {
    }
};

int main()
{
    gout.open(XX, YY);
    gout.load_font("LiberationSans-Regular.ttf");
    JatekMester* j = new JatekMester;
    j->event_loop();
    return 0;
}
