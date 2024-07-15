#ifndef PVZ_PEASHOOTER_HPP
#define PVZ_PEASHOOTER_HPP

#include "Plants.hpp"
#include "Peashooter.hpp"
#include "Fight/Pea.hpp"

class Peashooter : public Plants
{
public:
    Peashooter(int x, int y, pGameWorld ptr)
        : Plants(IMGID_PEASHOOTER, x, y, std::move(ptr), 300), peashooterTime(0) {}

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
        //When the attack ability is cooling down, reduce the cooldown by 1, only zombies can fire peas
        AddTime();

        if (GetTime() >= peashooterTime)
        {
            peashooterTime = GetTime() + 30;
            for (const auto &obj : GetGameWorld()->GetAllGameObjects())
            {
                if (obj->GetObjectType() == ObjectType::ZOMBIE && this->GetY() == obj->GetY()) 
                {
                    // Create a pea
                    GetGameWorld()->AddGameObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, GetGameWorld()->shared_from_this()));
                }
            }
        }
}

private:
    int peashooterTime;
};

#endif // PVZ_PEASHOOTER_HPP