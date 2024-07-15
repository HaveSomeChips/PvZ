#ifndef PVZ_SUN_HPP
#define PVZ_SUN_HPP

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Sun : public GameObject
{
public:
    // The constructor of sunlight falling from the sky
    Sun(pGameWorld ptr) : GameObject(IMGID_SUN, randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1,
                                     LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, std::move(ptr)),
                          fromSky(true), existTime(randInt(63, 263)) {}
    // The constructor of sunlight produced by sunflowers
    Sun(int x, int y, pGameWorld ptr) : GameObject(IMGID_SUN, x, y,
                                                   LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, std::move(ptr)),
                                        fromSky(false), existTime(12) {}

    void Update() override
    {
        // The sunlight that falls from the sky does not reach the ground
        if (fromSky == true && GetTime() < existTime)
        {
            MoveTo(GetX(), GetY() - 2);
        } // Sunflowers produce sunlight that does not fall to the ground
        else if (fromSky == false && GetTime() < existTime)
        {
            MoveTo(GetX() - 1, GetY() + (4 * GetTime() - GetTime() * GetTime() / 2));
        }
        // When it falls to the ground,HP is 0 and is deleted uniformly during update
        if (GetTime() - existTime >= 300)
        {
            SetHp(0);
        }

        AddTime();
    }

    void OnClick() override
    {
        GetGameWorld()->SetSun(GetGameWorld()->GetSun() + 25);
        SetHp(0);
        GetGameWorld()->UpdateSunText();
    }

private:
    bool fromSky;
    int existTime;
};

#endif // PVZ_SUN_HPP