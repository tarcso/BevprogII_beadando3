#ifndef KORONG_HPP_INCLUDED
#define KORONG_HPP_INCLUDED

#include "widgets.hpp"

class Korong : public Widget
{
    private:
        double m_rad;
        bool m_ures;
        bool m_red;
        bool m_palya;

    public:
        Korong(Window* window, int x, int y, int sx, int sy, bool ures, bool rd);
        void handle(const genv::event& ev);
        void draw() const;
        bool red() const;
        bool ures() const;
        void moveright();
        void moveleft();
        void changecolor(bool red);
        int oszlopszam();
};

void kor(int x, int y, int rad, int r, int g, int b);

#endif //KORONG_HPP_INCLUDED