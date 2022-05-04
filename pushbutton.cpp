#include "pushbutton.hpp"
#include <iostream>

using namespace genv;

PushButton::PushButton(Window* window, int x, int y, int sx, int sy, std::string s, std::function<void()> f)
                       : Widget(window, x, y, sx, sy), m_szov(s), m_func(f)
{}

void PushButton::handle(const event& ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        m_pushed = true;
        m_func();
    }
}

void PushButton::draw() const
{
    gout << color(255, 255, 255) << move_to(m_x, m_y) << box(m_size_x, m_size_y);
    gout << color(125,125,125) << move_to(m_x + 2, m_y + 2) << box(m_size_x, m_size_y);
}