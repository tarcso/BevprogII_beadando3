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
    Korong* k;

public:
    JatekMester()
    {
        palya = new Palya(this, XX/16.0, XX/8.0*35.0/32.0, XX/8.0*7.0, XX/8.0*6.0);
        k = new Korong(this, XX/16, XX/8.0*35.0/32.0, XX/16.0 * 55.0/60.0, XX/16.0 * 55.0/60.0, false, true);
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
