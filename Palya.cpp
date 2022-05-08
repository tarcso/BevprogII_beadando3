#include "Palya.hpp"
#include <iostream>

using namespace genv;

Palya::Palya(Window * window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
{
    for (int x = 1; x < m_x * 16; x++)
    {
        if(x % (m_x * 2) == 0)
        {
            std::vector<Korong*> oszlopvec;
            for (int y = 0; y < m_size_y; y++)
            {
                if(y % (m_x * 2) == 0)
                    oszlopvec.push_back(new Korong(window, x, m_y + m_x + y, m_x *45.0/60.0, m_x *45.0/60.0, true, false));
            }
            m_korong.push_back(oszlopvec);
        }
    }
}

void Palya::handle(const event& ev)
{
}

void Palya::draw() const
{
    gout << move_to(m_x, m_y) << color(0, 0, 255) << box(m_size_x, m_size_y);
}

bool Palya::putInsiker(Korong * k)
{
    if(!m_korong[k->oszlopszam()-1][0]->ures()) return false;

    for(size_t i = 0; i < m_korong[k->oszlopszam()-1].size(); i++)
    {

        if(!m_korong[k->oszlopszam()-1][i]->ures())
        {
            m_korong[k->oszlopszam()-1][i-1]->changecolor(k->red());
            return true;
        }
        else if(m_korong[k->oszlopszam()-1][i]->ures() && i+1  == m_korong[k->oszlopszam()-1].size())
        {
            m_korong[k->oszlopszam()-1][i]->changecolor(k->red());
            return true;
        }
    }
    return false;
}