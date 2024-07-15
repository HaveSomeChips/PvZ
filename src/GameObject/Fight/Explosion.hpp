#ifndef PVZ_EXPLOSION_HPP
#define PVZ_EXPLOSION_HPP

#include <utility>

#include "Fight.hpp"

class Explosion : public Fight
{
public:
    Explosion(int x, int y, pGameWorld ptr)
        : Fight(IMGID_EXPLOSION, x, y, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_WIDTH, std::move(ptr), 4000, 1000000) {}

    void Update() override
    {
        if (GetHp() == 0)
            return;
        AddTime();
        if (GetTime() > 3)
            SetHp(0);
    }
};

#endif // PVZ_EXPLOSION_HPP
