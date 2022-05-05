#include "Korong.hpp"

using namespace genv;

Korong::Korong(Window* window, int x, int y, int sx, int sy, bool ures, bool rd) : Widget(window, x, y, sx, sy)
{
    m_ures = ures;

    if(!ures)
    {
        m_red = rd;
    }

    m_rad = sx;
}

void Korong::handle(const event& ev)
{

}

void Korong::draw() const
{
    unsigned r, g, b;
    if(m_ures)
    {
        r = 255;
        g = 255;
        b = 255;
    }
    else if(m_red)
    {
        r = 255;
        g = 0;
        b = 0;
    }
    else
    {
        r = 0;
        g = 255;
        b = 0;
    }
    kor(m_x, m_y - m_rad, m_rad, r, g, b);
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