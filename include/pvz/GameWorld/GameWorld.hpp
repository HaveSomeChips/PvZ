#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"

#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  int GetWave() const;
  void SetWave(int level);

  int GetSun() const;
  void SetSun(int sun);

  void UpdateSunText();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  // put gameObjects into list
  void AddGameObject(std::shared_ptr<GameObject> obj);
  
  // get things player is taking
  PlantType GetHoldingItem() const;
  // set things player should take
  void SetHoldingItem(PlantType item);

  const std::list<std::shared_ptr<GameObject>> &GetAllGameObjects() const;

private:
  std::list<std::shared_ptr<GameObject>> gameObjects;

  int m_wave;
  int m_sun;

  int waveTime;
  int sunTime;

  int tickCount;

  std::shared_ptr<TextBase> sunText;
  std::shared_ptr<TextBase> waveText;

  std::shared_ptr<TextBase> textForLossing;

  // item player is holding
  PlantType holdingItem;
};

#endif // !GAMEWORLD_HPP__
