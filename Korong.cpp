#include "Korong.hpp"
#include <iostream>

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

bool Korong::red() const
{
    return m_red;
}

void Korong::handle(const event& ev)
{
    if(ev.type == ev_mouse)
    {
        if(ev.pos_x/(m_screensize.first/8) > 0 && (ev.pos_x-m_screensize.first/16)/(m_screensize.first/8) * m_screensize.first/8 + m_screensize.first/8 < m_screensize.first)
            m_x = (ev.pos_x-m_screensize.first/16)/(m_screensize.first/8) * m_screensize.first/8 + m_screensize.first/8;
    }
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
        r = 255;
        g = 255;
        b = 0;
    }
    kor(m_x, m_y, m_rad, r, g, b);
}

void Korong::moveright()
{
    if(m_x + m_screensize.first/8.0 < m_screensize.first)
        m_x += m_screensize.first/8.0;
}

void Korong::moveleft()
{
    if(m_x - m_screensize.first/8.0 > 0)
        m_x -= m_screensize.first/8.0;
}

void Korong::changecolor(bool red)
{
    m_ures = false;
    m_red = red;
}

int Korong::oszlopszam()
{
    return m_x / (m_screensize.first / 8.0);
}

bool Korong::ures() const
{
    return m_ures;
}

void kor(int x, int y, int rad, int r, int g, int b)
{
    for (int i = -rad; i < rad; i++)
    {
        for (int j = -rad; j < rad; j++)
        {
            if(i*i + j*j < rad*rad) gout << color(r,g,b) << move_to(x-j,y+i) << dot;
        }
    }
}

void Korong::changestatus(bool ures)
{
    m_ures = ures;
}

bool Korong::is_selected(int mx, int my) const
{
    return mx >= m_x-m_size_x && mx <= m_x + m_size_x && my >= m_y-m_size_y && my <= m_y + m_size_y;
}