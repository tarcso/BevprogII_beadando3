#include "Palya.hpp"
#include <iostream>

using namespace genv;

Palya::Palya(Window * window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
{
    for (int y = 0; y < m_size_y; y++)
    {
        if(y % (m_x*2) == 0)
            for (int x = 1; x < m_x * 16; x++)
            {
                if(x % (m_x*2) == 0)
                {
                    new Korong(window, x, m_y - m_x *55.0/60.0 + y, m_x *55.0/60.0, m_x *55.0/60.0, true, false);
                }
            }
    }
}

void Palya::handle(const event& ev)
{}

void Palya::draw() const
{
    gout << move_to(m_x, m_y-10) << color(0, 0, 255) << box(m_size_x, m_size_y);
    for(Korong* k : m_korong)
    {
        k->draw();
    }
}