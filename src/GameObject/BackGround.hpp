#ifndef PVZ_BACKGROUND_HPP
#define PVZ_BACKGROUND_HPP

#include "pvz/GameObject/GameObject.hpp"

class Background : public GameObject
{
public:
    Background()
        : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}

    void Update() override {}

    void OnClick() override {}
};

#endif // PVZ_BACKGROUND_HPP