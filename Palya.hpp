#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "widgets.hpp"
#include "Korong.hpp"

class Palya : public Widget
{
    private:
        int meretx, merety;
        std::vector<Korong*> m_korong;
    public:
        Palya(Window* window, int x, int y, int sx, int sy);
        void handle(const genv::event& ev);
        void draw() const;
};

#endif //PALYA_HPP_INCLUDED