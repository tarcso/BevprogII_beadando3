#include "Palya.hpp"

using namespace genv;

Palya::Palya(Window * window, int x, int y, int sx, int sy, std::function<void()> handle) : Widget(window, x, y, sx, sy)
{
    m_handle = handle;
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
    if(ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y))
    {
        m_handle();
    }
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

std::pair<bool, bool> Palya::vannyer() const
{
    int mennyi = 0;
    bool red = true;

    for(size_t x = 0; x < m_korong.size(); x++)
    {
        mennyi = 0;
        for (size_t y = 1; y < m_korong[x].size(); y++)
        {
            if(m_korong[x][y]->red() == m_korong[x][y-1]->red() && !m_korong[x][y]->ures() && !m_korong[x][y-1]->ures())
            {
                mennyi++;
                if(mennyi == 3)
                {
                    red = m_korong[x][y]->red();
                    return std::make_pair(true, red);
                }
            }
            else
            {
                mennyi = 0;
            }
        }
    }

    for(size_t y = 0; y < 6; y++)
    {
        mennyi = 0;
        for (size_t x = 1; x < 7; x++)
        {
            if(m_korong[x][y]->red() == m_korong[x-1][y]->red() && !m_korong[x][y]->ures() && !m_korong[x-1][y]->ures())
            {
                mennyi++;
                if(mennyi == 3)
                {
                    red = m_korong[x][y]->red();
                    return std::make_pair(true, red);
                }
            }
            else
            {
                mennyi = 0;
            }
        }
    }


    for (int x = -7; x < 8; x++)
    {
        mennyi = 0;
        for (size_t i = 0; i < 5; i++)
        {
            if(x + i >= 0 && x + i < 7 && x + i + 1 >= 0 && x + i + 1 < 7)
            {
                if(m_korong[x+i][i]->red() == m_korong[x+i+1][i+1]->red() && !m_korong[x+i][i]->ures() && !m_korong[x+i+1][i+1]->ures())
                {
                    mennyi++;
                    if(mennyi == 3)
                    {
                        red = m_korong[x+i][i]->red();
                        return std::make_pair(true, red);
                    }
                }
                else
                {
                    mennyi = 0;
                }
            }
        }
    }
    

    for (int x = -7; x < 8; x++)
    {
        mennyi = 0;
        for (size_t i = 0; i < 5; i++)
        {
            if(x + i >= 0 && x + i < 7 && x + i + 1 >= 0 && x + i + 1 < 7)
            {
                if(m_korong[x+i][5-i]->red() == m_korong[x+i + 1][5-i-1]->red() && !m_korong[x+i][5-i]->ures() && !m_korong[x+i+1][5-i-1]->ures())
                {
                    mennyi++;
                    if(mennyi == 3)
                    {
                        red = m_korong[x+i][5-i]->red();
                        return std::make_pair(true, red);
                    }
                }
                else
                {
                    mennyi = 0;
                    red = m_korong[x+i][5-i]->red();
                }
            }
        }
    }

    return std::make_pair(false, red);
}

void Palya::changefunc(std::function<void()> func)
{
    m_handle = func;
}

void Palya::empty()
{
    for(std::vector<Korong*> sorvec : m_korong)
    {
        for(Korong* k : sorvec)
        {
            k->changestatus(true);
        }
    }
}