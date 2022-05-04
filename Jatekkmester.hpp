#include "widgets.hpp"
#include <vector>

using namespace genv;

class JatekMester
{
    private:
        Palya* m_palya;
        //std::vector<std::vector<Korong*>> m_korong; //majd pályába kell beletenni zsa
    public:
        JatekMester(Window* window)
        {
            m_palya = new Palya(window, 0, 128, 1024, 876);
            //for (size_t y = 0; y < 6; y++)
            //{
            //    std::vector<Korong*> sorvec;
            //    for (size_t x = 0; x < 7; x++)
            //    {
            //        sorvec.push_back(nullptr);
            //    }
            //    
            //} pálya konstruktorba bele
            
        }
        void handle(const genv::event& ev)
        {
            
        }
        void draw() const;
};