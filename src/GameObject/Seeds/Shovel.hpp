#ifndef PVZ_SHOVEL_HPP
#define PVZ_SHOVEL_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "Seed.hpp"

class Shovel : public Seed
{
public:
    Shovel(pGameWorld ptr)
        : Seed(IMGID_SHOVEL, 600, std::move(ptr), 0, 0, PlantType::SHOVEL),firstClick(true) {}

    void OnClick() override {    
        // Pick up a shovel
        if (firstClick == true || GetGameWorld()->GetHoldingItem() == PlantType::NONE)
        {
            GetGameWorld()->SetHoldingItem(PlantType::SHOVEL);
             firstClick=false;
            return;
        }
        
       // Put down the shovel
       if (firstClick==false && GetGameWorld()->GetHoldingItem() == PlantType::SHOVEL){
            // If the player is holding a shovel, put the shovel down
            GetGameWorld()->SetHoldingItem(PlantType::NONE);
            firstClick=true;
            
        }
    }
private:
    bool firstClick;
};

#endif // PVZ_SHOVEL_HPP
