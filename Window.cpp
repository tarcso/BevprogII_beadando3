#include "Window.hpp"
#include <iostream>

using namespace genv;

Window::Window()
{
    
}

void Window::event_loop() {
    event ev;
    Widget* focus = nullptr;
    for (Widget * w : widgets) {
        w->draw();
    }
    gout << refresh;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            for(Widget* w: widgets)
            if(w->is_selected(ev.pos_x, ev.pos_y))
            {
                focus = w;
            }
        }
        if(focus != nullptr) focus->handle(ev);

        gout << move_to(0, 0) << color(0, 0, 0) << box(screenx, screeny);
        for (Widget * w : widgets) {
            w->draw();
        }

        gout << refresh;
    }
}