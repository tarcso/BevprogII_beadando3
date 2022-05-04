#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include "Jatekmester.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>

using namespace genv;

const int XX = 1024;
const int YY = 1200;

class Ablak : public Window
{
    Palya* palya;

public:
    Ablak()
    {
        palya = new Palya(this, XX/16.0, XX/8.0*35.0/32.0, XX/8.0*7.0, XX/8.0*6.0);
    }

    void esemeny(const std::string& ki_mondta)
    {
    }


};

int main()
{
    gout.open(XX, YY);
    gout.load_font("LiberationSans-Regular.ttf");
    Ablak* m = new Ablak;
    m->event_loop();
    return 0;
}
