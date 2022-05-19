#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "widgets.hpp"
#include "Korong.hpp"
#include <functional>

class Palya : public Widget
{
    private:
        int meretx, merety;
        std::vector<std::vector<Korong*>> m_korong;
        std::function<void()> m_handle;
    public:
        Palya(Window* window, int x, int y, int sx, int sy, std::function<void()>);
        void handle(const genv::event& ev);
        void draw() const;
        bool putInSiker(Korong*);
        std::pair<bool, bool> vannyer() const;
        void changefunc(std::function<void()> func);
        void empty();
        void unfocus(){}
};

#endif //PALYA_HPP_INCLUDED
