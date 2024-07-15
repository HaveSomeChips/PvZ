#ifndef PVZ_PLANTSPOT_HPP
#define PVZ_PLANTSPOT_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "SunFlower.hpp"
#include "Peashooter.hpp"
#include "Wallnut.hpp"
#include "CherryBomb.hpp"

class PlantSpot : public GameObject
{
public:
    PlantSpot(int x, int y, pGameWorld ptr) 
        : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, std::move(ptr))
    {
    }

    void Update() override {}

    void OnClick() override
    {
        PlantType plantType = GetGameWorld()->GetHoldingItem();
        if (plantType == PlantType::SUNFLOWER)
        {
            GetGameWorld()->AddGameObject(std::make_shared<SunFlower>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
        }
        else if (plantType == PlantType::PEASHOOTER)
        {
            GetGameWorld()->AddGameObject(std::make_shared<Peashooter>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
        }
        else if (plantType == PlantType::WALLNUT)
        {
            GetGameWorld()->AddGameObject(std::make_shared<Wallnut>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
        }
        else if (plantType == PlantType::CHERRYBOMB)
        {
            GetGameWorld()->AddGameObject(std::make_shared<CherryBomb>(GetX(), GetY(), GetGameWorld()->shared_from_this()));
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
        }
    }
};

#endif // PVZ_PLANTSPOT_HPP