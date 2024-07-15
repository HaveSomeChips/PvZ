#ifndef PVZ_SUNFLOWER_HPP
#define PVZ_SUNFLOWER_HPP

#include "Plants.hpp"
#include "Sun.hpp"

class SunFlower : public Plants
{
public:
    SunFlower(int x, int y, pGameWorld ptr)
        : Plants(IMGID_SUNFLOWER, x, y, std::move(ptr), 300), sunTime(randInt(30, 600)) {}

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

        if (GetTime() >= sunTime)
        {
            sunTime = GetTime() + 600;
            GetGameWorld()->AddGameObject(std::make_shared<Sun>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
        }

        AddTime();
    }

private:
    int sunTime;
};

#endif // PVZ_SUNFLOWER_HPP