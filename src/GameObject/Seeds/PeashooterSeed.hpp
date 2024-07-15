#ifndef PVZ_PEASHOOTERSEED_HPP
#define PVZ_PEASHOOTERSEED_HPP

#include "Seed.hpp"

class PeashooterSeed : public Seed
{
public:
    PeashooterSeed(pGameWorld ptr)
        : Seed(IMGID_SEED_PEASHOOTER, 130 + 60, std::move(ptr), 100, 240, PlantType::PEASHOOTER) {}
};

#endif // PVZ_PEASHOOTERSEED_HPP