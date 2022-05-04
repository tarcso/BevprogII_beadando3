#include "Palya.hpp"
#include <iostream>

using namespace genv;

Palya::Palya(Window * window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
{}

void Palya::handle(const event& ev)
{}

void Palya::draw() const
{
    gout << move_to(m_x, m_y-10) << color(0, 0, 255) << box(m_size_x, m_size_y+10);
    double rad = m_x *55.0/60.0;

    for (int y = m_y; y < m_y + m_size_y; y++)
    {
        if(y % (m_x*2) == 0)
            for (int x = 1; x < m_x * 16; x++)
            {
                if(x % (m_x*2) == 0)
                {
                    kor(x, y - rad, rad, 255, 255, 255);
                }
            }
    }
}

void kor(int x, int y, int rad, int r, int g, int b)
{
    for (int i = -rad; i < rad; i++)
    {
        for (int j = -rad; j < rad; j++)
        {
            if(i*i + j*j < rad*rad) gout << color(r,g,b) << move_to(x-j,y-i) << dot;
        }
    
    }
    
}