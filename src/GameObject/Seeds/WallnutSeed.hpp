#ifndef PVZ_WALLNUTSEED_HPP
#define PVZ_WALLNUTSEED_HPP

#include "Seed.hpp"

class WallnutSeed : public Seed
{
public:
    explicit WallnutSeed(pGameWorld ptr)
        : Seed(IMGID_SEED_WALLNUT, 250, std::move(ptr), 50, 900, PlantType::WALLNUT) {}
};

#endif // PVZ_WALLNUTSEED_HPP