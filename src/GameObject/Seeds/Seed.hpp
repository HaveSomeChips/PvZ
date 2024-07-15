#ifndef PVZ_SEEDS_HPP
#define PVZ_SEEDS_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "CoolDownMask.hpp"

class Seed : public GameObject
{
public:
    Seed(ImageID imageID, int x, pGameWorld ptr, int price_, int coolDownTime_, PlantType seed_)
        : GameObject(imageID, x, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, std::move(ptr)),
          price(price_), coolDownTime(coolDownTime_), seed(seed_) {}

    void Update() override {}

    void OnClick() override
    {   // When the seed packet clicked is a plant,,,
        if (seed != PlantType::SHOVEL && seed != PlantType::NONE)
        {
            if (GetGameWorld()->GetSun() >= price)
            { 
                GetGameWorld()->SetHoldingItem(seed);
                GetGameWorld()->SetSun(GetGameWorld()->GetSun() - price);
                GetGameWorld()->UpdateSunText();

                // Create a cooling cover in place
                GetGameWorld()->AddGameObject(std::make_shared<CoolDownMask>(GetX(), GetY(), coolDownTime));
            }
        }
    }

private:
    int price;
    int coolDownTime;
    PlantType seed;
};

#endif // PVZ_SEEDS_HPP