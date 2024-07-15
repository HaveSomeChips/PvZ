#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

//Object type
enum class ObjectType
{
  NONE,
  PlANT,
  FIGHT,
  ZOMBIE
};

// Planting type
enum class PlantType
{
  NONE,
  SUNFLOWER,
  PEASHOOTER,
  WALLNUT,
  CHERRYBOMB,
  REPEATER,
  SHOVEL
};

// Zombie type
enum class ZombieType
{
  NONE,
  REGULAR,
  BUCKET_HEAD,
  POLE_VAULTING
};

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this;

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, 
             AnimID animID, pGameWorld ptr = nullptr, int hp = -1, ObjectType type = ObjectType::NONE);

  virtual ~GameObject();

  virtual void Update() {}

  virtual void OnClick() {}
  //Collision method virtual function (cannot be created by dynamic_cast)
  virtual void Collision() {};

  // Get world pointer
  pGameWorld GetGameWorld() const;

  // Get HP and modify it
  int GetHp() const;
  void SetHp(int hp);

  // Get time counts and modifications
  int GetTime() const;
  void AddTime();

  //Gets the object type and set type
  ObjectType GetObjectType () const;

  //
  bool IsCollidingWith(const std::shared_ptr<GameObject> &other) const;

private:
  // Determine whether there is a collision
  pGameWorld gameWorld;
  // All objects have HP, which is cleared with refresh when it reaches 0
  int Hp;
  // tick Time counter
  int tickCount;
  //Used to determine the object type
  ObjectType objectType;
};

#endif // !GAMEOBJECT_HPP__