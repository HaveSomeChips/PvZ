#ifndef PVZ_COOLDOWNMASK_HPP
#define PVZ_COOLDOWNMASK_HPP

#include "pvz/GameObject/GameObject.hpp"

class CoolDownMask : public GameObject
{
public:
    CoolDownMask(int x, int y, int coolDownTime_)
        : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION), coolDownTime(coolDownTime_) {}


    void Update() override
    {
        if (GetTime() >= coolDownTime)
        {
            SetHp(0);
        }
        
        AddTime();
    }

    void OnClick() override {}

private:
    int coolDownTime;
};

#endif // PVZ_COOLDOWNMASK_HPP
