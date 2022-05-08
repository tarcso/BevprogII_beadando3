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

bool Palya::putInSiker(Korong * k)
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

bool Palya::vannyer() const
{
    int mennyi = 0;
    bool red = true;

    for(size_t x = 0; x < m_korong.size(); x++)
    {
        for (size_t y = 1; y < m_korong[x].size(); y++)
        {
            if(!m_korong[x][y]->ures() && !m_korong[x][y-1]->ures())
            {
                if(m_korong[x][y]->red() == m_korong[x][y-1]->red())
                    mennyi++;
                else
                {
                    mennyi = 0;
                    red = m_korong[x][y]->red();
                }

                if(mennyi == 4) return true;
            }
        }
    }

    for(size_t y = 0; y < 6; y++)
    {
        for (size_t x = 1; x < 7; x++)
        {
            if(!m_korong[x][y]->ures() && !m_korong[x-1][y]->ures())
            {
                if(m_korong[x][y]->red() == m_korong[x-1][y]->red())
                    mennyi++;
                else
                {
                    mennyi = 0;
                    red = m_korong[x][y]->red();
                }
            }

            if(mennyi == 4) return true;
        }
    }


    for (size_t y = 2; y < 6; y++)
    {
        for (size_t i = 1; i < y+1; i++)
        {
            if(!m_korong[i][y-1]->ures() && !m_korong[i-1][y-i+1]->ures())
            {
                if(m_korong[i][y-i]->red() == m_korong[i-1][y-i+1]->red())
                    mennyi++;
                else
                {
                    mennyi = 0;
                    red = m_korong[i][y-i]->red();
                }
            }

            if(mennyi == 4) return true;
        }
    }

    for (size_t x = 2; x < 4; x++)
    {
        for (size_t i = 1; x+i < 7; i++)
        {
            if(!m_korong[x+i][5-i]->ures() && !m_korong[x+i-1][5-i+1]->ures())
            {
                if(m_korong[x+i][5-i]->red() == m_korong[x+i-1][5-i+1]->red())
                    mennyi++;
                else
                {
                    mennyi = 0;
                    red = m_korong[x+i][5-i]->red();
                }
            }

            if(mennyi == 4) return true;
        }
    }


    
    for (size_t y = 6; y >= 3; y--)
    {
        for (size_t i = 1; i <= y; i++)
        {
            if(!m_korong[7-i][y-i]->ures() && !m_korong[7-i+1][y-i+1]->ures())
            {
                if(m_korong[7-i][y-i]->red() == m_korong[7-i+1][y-i+1]->red())
                    mennyi++;
                else
                {
                    mennyi = 0;
                    red = m_korong[7-i][y-i]->red();
                }
            }

            if(mennyi == 4) return true;
        }
    }

    for (size_t x = 3; x < 6; x++)
    {
        for (size_t i = 1; i <= x; i++)
        {
                if(!m_korong[x-i][5-i]->ures() && !m_korong[x-i+1][5-i+1]->ures())
                {
                    if(m_korong[x-i][5-i]->red() == m_korong[x-i+1][5-i+1]->red())
                        mennyi++;
                    else
                    {
                        mennyi = 0;
                        red = m_korong[x-i][5-i]->red();
                    }
                }

                if(mennyi == 4) return true;
        }
    }
    return false;
}