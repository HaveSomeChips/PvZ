#ifndef PVZ_PLANT_HPP
#define PVZ_PLANT_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Plants : public GameObject
{
public:
    Plants(ImageID imageID, int x, int y, pGameWorld ptr, int hp)
        : GameObject(imageID, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(ptr), hp, ObjectType::PlANT) {}

    // Do not implement Update, leaving it as an abstract method to be implemented by other classes

    // If you hold a shovel when clicked, your life goes to zero
    void OnClick() override
    {
        // Hold the shovel and click on the planting area to zero life and remove the plant
        if (GetGameWorld()->GetHoldingItem() == PlantType::SHOVEL)
        {
            SetHp(0);
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
        }
    }
};

#endif // PVZ_PLANT_HPP