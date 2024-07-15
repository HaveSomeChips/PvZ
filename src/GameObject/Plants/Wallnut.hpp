#ifndef PVZ_WALLNUT_HPP
#define PVZ_WALLNUT_HPP

#include "Plants.hpp"

class Wallnut : public Plants
{
public:
    Wallnut(int x, int y, pGameWorld ptr)
        : Plants(IMGID_WALLNUT, x, y, std::move(ptr), 4000) {}

    void Update() override
    {
        if (GetHp() < 0)
        {
            SetHp(0);
        }

        if (GetHp() == 0)
        {
            return;
        }
        else if (GetHp() <= 4000 / 3)
        {
            ChangeImage(IMGID_WALLNUT_CRACKED);
        }
    }
};

#endif // PVZ_WALLNUT_HPP
