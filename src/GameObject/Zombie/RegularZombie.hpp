#ifndef PVZ_REGULARZOMBIE_HPP
#define PVZ_REGULARZOMBIE_HPP

#include "Zombie.hpp"

class RegularZombie : public Zombie
{
public:
    RegularZombie(pGameWorld ptr) : Zombie(IMGID_REGULAR_ZOMBIE, ANIMID_WALK_ANIM, std::move(ptr), 200) {}
};

#endif // PVZ_REGULARZOMBIE_HPP