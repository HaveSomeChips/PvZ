#ifndef PVZ_PROJECTILES_HPP
#define PVZ_PROJECTILES_HPP

#include "pvz/GameObject/GameObject.hpp"

class Fight : public GameObject
{
public:
    Fight(ImageID imageID, int x, int y, int width, int height, pGameWorld ptr, int hp, int damage_)
        : GameObject(imageID, x, y, LAYER_PROJECTILES, width, height, ANIMID_NO_ANIMATION, std::move(ptr), hp, ObjectType::FIGHT), damage(damage_) {}

    void OnClick() override {}

    void Collision() override
    {
        for (const auto &obj : GetGameWorld()->GetAllGameObjects()) 
        {
            if (obj.get() != this && this->IsCollidingWith(obj)) 
            {   //Only zombies can be attacked
                if (obj->GetObjectType() == ObjectType::ZOMBIE) {
                    obj->SetHp(obj->GetHp() - damage);
                }            
            }
        }
    }

private:
    int damage;
};

#endif // PVZ_PROJECTILES_HPP
