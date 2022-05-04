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

const int XX = 400;
const int YY = 400;

struct Ablak : public Window
{

    GordMenu* g1;
    GordMenu* g2;
    PushButton* jobbtn;
    PushButton* balbtn;

public:
    Ablak()
    {
        std::vector<std::string> v;
        v.push_back("elso elem");
        v.push_back("masodik elem");
        v.push_back("harmadik elem");
        v.push_back("negyedik elem");
        v.push_back("otodik elem");
        v.push_back("hatodik elem");
        v.push_back("hetedik elem");
        v.push_back("nyolcadik elem");
        std::vector<std::string> v1;
        v1.push_back("helo");
        v1.push_back("sza");
        v1.push_back("hehe");
        GordMenu* g1 = new GordMenu(this, 10, 50, 150, 30, "válassz!", v, 5);
        GordMenu* g2 = new GordMenu(this, 240, 50, 150, 30, "válassz!", v1, 3);
        PushButton* jobbtn = new PushButton(this, 180, 50, 20, 30, "->", [g1, g2](){std::string s = g1->allapot();
                                                       g2->hozzaadElem(s);
                                                       g1->torolElem(s);});
        PushButton* baltn = new PushButton(this, 200, 50, 20, 30, "<-", [g1, g2](){std::string s = g2->allapot();
                                                       g1->hozzaadElem(s);
                                                       g2->torolElem(s);});
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
    gout.open(400, 400);
    gout.load_font("LiberationSans-Regular.ttf");
    Ablak* m = new Ablak;
    m->event_loop();
    return 0;
}