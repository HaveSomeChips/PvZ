#ifndef PVZ_CHERRYBOMBSEED_HPP
#define PVZ_CHERRYBOMBSEED_HPP

#include "Seed.hpp"

class CherryBombSeed : public Seed
{
public:
    explicit CherryBombSeed(pGameWorld ptr)
        : Seed(IMGID_SEED_CHERRY_BOMB, 310, std::move(ptr), 150, 1200, PlantType::CHERRYBOMB) {}
};

#endif // PVZ_CHERRYBOMBSEED_HPP