#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "widgets.hpp"
#include "Palya.hpp"
#include <vector>

using namespace genv;

class JatekMester
{
    private:
        Palya* m_palya;
        //std::vector<std::vector<Korong*>> m_korong; //majd pályába kell beletenni zsa
    public:
        JatekMester(Window* window)
        {
            m_palya = new Palya(window, 0, 128, 1024, 876);
            
        }
        void handle(const genv::event& ev)
        {
            
        }
        void draw() const;
};

#endif //JATEKMESTR_HPP_INCLUDED