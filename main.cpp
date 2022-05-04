#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>

using namespace genv;

const int XX = 1024;
const int YY = 1200;

class Ablak : public Window
{

    GordMenu* g1;
    GordMenu* g2;
    PushButton* jobbtn;
    PushButton* balbtn;

public:
    Ablak()
    {
        g1 = new GordMenu(this, 10, 50, 150, 30, "válassz!", {
                "elso elem", "masodik elem", "harmadik elem","negyedik elem", "otodik elem", "hatodik elem", "hetedik elem", "nyolcadik elem"
        }, 5);

        g2 = new GordMenu(this, 240, 50, 150, 30, "válassz!", {"helo", "sza", "hehe", "egysoros", "nice"}, 3);

        jobbtn = new PushButton(this, 180, 50, 20, 30, "->", [this](){
                std::string s = g1->allapot();
                g2->hozzaadElem(s);
                g1->torolElem(s);
        });

        balbtn = new PushButton(this, 200, 50, 20, 30, "<-", [this](){
                std::string s = g2->allapot();
                g1->hozzaadElem(s);
                g2->torolElem(s);
        });
    }

    void ertek_kiir()
    {
        std::ofstream logfile("main.log");
        logfile << g1->allapot();
        logfile << g2->allapot();
        logfile.close();
    }

    void esemeny(const std::string& ki_mondta)
    {
        if(ki_mondta == "hello") ertek_kiir();
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
