#ifndef PVZ_CHERRYBOMB_HPP
#define PVZ_CHERRYBOMB_HPP

#include "Plants.hpp"
#include "Fight/Explosion.hpp"

class CherryBomb : public Plants
{
public:
    CherryBomb(int x, int y, pGameWorld ptr)
        : Plants(IMGID_CHERRY_BOMB, x, y, std::move(ptr), 4000) {}

    void Update() override
    {
        if (GetHp() == 0)
            return;
        AddTime();
        if (GetTime() >= 15)
        {
            SetHp(0);
            GetGameWorld()->AddGameObject(std::make_shared<Explosion>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
        }
    }
};

#endif // PVZ_CHERRYBOMB_HPP
