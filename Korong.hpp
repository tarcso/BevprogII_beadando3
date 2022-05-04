#ifndef KORONG_HPP_INCLUDED
#define KORONG_HPP_INCLUDED

#include "widgets.hpp"

class Palya;

class Korong : public Widget
{
    private:

    public:
        Korong(Window* window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
        {}
        void handle(const genv::event& ev);
        void draw() const;
};

#endif //KORONG_HPP_INCLUDED