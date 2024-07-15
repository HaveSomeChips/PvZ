#ifndef PVZ_PEA_HPP
#define PVZ_PEA_HPP

#include "Fight.hpp"

class Pea : public Fight
{
public:
    Pea(int x, int y, pGameWorld ptr) : Fight(IMGID_PEA, x, y, 28, 28, std::move(ptr), 20, 20) {}

    void Update() override
    {
        if (GetHp() == 0)
        {
            return;
        }
        MoveTo(GetX() + 8, GetY());
        if (GetY() >= WINDOW_WIDTH)
        {
            SetHp(0);
        }
    }
};

#endif // PVZ_PEA_HPP
