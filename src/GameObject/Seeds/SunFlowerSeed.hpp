#ifndef PVZ_SUNFLOWERSEED_HPP
#define PVZ_SUNFLOWERSEED_HPP

#include "Seed.hpp"

class SunFlowerSeed : public Seed
{
public:
    SunFlowerSeed(pGameWorld ptr)
        : Seed(IMGID_SEED_SUNFLOWER, 130, std::move(ptr), 50, 240, PlantType::SUNFLOWER) {}
};

#endif // PVZ_SUNFLOWERSEED_HPP