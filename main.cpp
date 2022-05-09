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

public:
    JatekMester()
    {
        screenx = XX;
        screeny = YY;
        palya = new Palya(this, XX/16.0, XX/8.0*35.0/32.0, XX/8.0*7.0, XX/8.0*6.0);
        tmp = new Korong(this, XX/2.0, (XX/8.0*35.0/32.0)/2, XX/16.0 * 45.0/60.0, XX/16.0 * 45.0/60.0, false, true);
        right = new PushButton(this, XX * 3/4.0-XX/10.0, YY * 6/7.0, XX/10.0, XX/20.0, "->", [this](){tmp->moveright();});
        left = new PushButton(this, XX/4.0, YY * 6/7.0, XX/10.0, XX/20.0, "<-", [this](){tmp->moveleft();});
        enter = new PushButton(this, XX/2.0 - XX/20.0, YY * 6/7.0, XX/10.0, XX/20.0, "enter", [this](){
            if(palya->putInSiker(tmp))
            {
                bool color = abs(tmp->red()-1);
                tmp->changecolor(color);
            }
        });
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
