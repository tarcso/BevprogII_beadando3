#include "pushbutton.hpp"
#include <iostream>

using namespace genv;

PushButton::PushButton(Window* window, int x, int y, int sx, int sy, std::string s, std::function<void()> f)
                       : Widget(window, x, y, sx, sy), m_szov(s), m_func(f)
{
    m_pushed = false;
}

void PushButton::handle(const event& ev)
{
    if(is_selected(ev.pos_x, ev.pos_y) && ev.type == ev_mouse && ev.button == btn_left)
    {
        m_pushed = true;
        m_func();
    }
    else m_pushed = false;
}

void PushButton::draw() const
{
    gout << color(255, 255, 255) << move_to(m_x, m_y) << box(m_size_x, m_size_y);
    if(m_pushed)
        gout << color(185,185,185) << move_to(m_x + 2, m_y + 2) << box(m_size_x, m_size_y);
    else
        gout << color(125,125,125) << move_to(m_x + 2, m_y + 2) << box(m_size_x, m_size_y);

    gout << move_to(m_x + m_size_x/2.0-gout.twidth(m_szov)/2.0, m_y + m_size_y/2 - (gout.cascent()+ gout.cdescent())/2) << color(255,255,255) << text(m_szov);
}

void PushButton::changefunc(std::function<void()> func)
{
    m_func = func;
}