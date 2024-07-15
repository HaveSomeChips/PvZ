#ifndef PVZ_ZOMBIE_HPP
#define PVZ_ZOMBIE_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

enum class ZombieState
{
    Walk = 1,
    Eat
};

class Zombie : public GameObject
{
public:
    Zombie(ImageID imageID, AnimID animID, pGameWorld ptr, int hp, ZombieState state = ZombieState::Walk)
        : GameObject(imageID, randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_COL_CENTER, LAYER_ZOMBIES,
                     20, 80, animID, std::move(ptr), hp, ObjectType::ZOMBIE), zombieState(state) {}

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
        
        if (zombieState == ZombieState::Walk)
        {
            MoveTo(GetX() - 1, GetY());
        }
    }

    void OnClick() override {}

    void Collision() override
    {
        for (const auto &obj : GetGameWorld()->GetAllGameObjects())
        {
            // Not zombies, and there's a collision
            if (obj.get() != this && this->IsCollidingWith(obj) == true)
            {
                // If it's a plant
                if (obj->GetObjectType() == ObjectType::PlANT)
                {
                    if (this->zombieState != ZombieState::Eat) 
                    {
                        this->zombieState = ZombieState::Eat;
                        this->PlayAnimation(ANIMID_EAT_ANIM);
                    }
                    obj->SetHp(obj->GetHp() - 3);
                    // HP is zero (there may be a frame that does not update the bleed setting to 0), 
                    //and the zombie resumes walking
                    if (obj->GetHp() <= 0)
                    {
                        this->zombieState = ZombieState::Walk;
                        this->PlayAnimation(ANIMID_WALK_ANIM);
                    }
                }
                // If it's a flying object
                if (obj->GetObjectType() == ObjectType::FIGHT)
                {
                    obj->SetHp(0);
                }
            }
            // Current zombie, and no collision
            if (obj.get() == this && this->IsCollidingWith(obj) == false)
            {   if (this->zombieState != ZombieState::Walk) 
                {
                    zombieState = ZombieState::Walk;
                    PlayAnimation(ANIMID_WALK_ANIM);
                }
            }
        }
    }

private:
    ZombieState zombieState;
};

#endif // PVZ_ZOMBIE_HPP