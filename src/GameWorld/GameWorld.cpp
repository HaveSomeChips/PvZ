#include "pvz/GameWorld/GameWorld.hpp"
#include "BackGround.hpp"
#include "Plants/PlantSpot.hpp"
#include "Sun.hpp"
#include "Seeds/SunFlowerSeed.hpp"
#include "Seeds/PeashooterSeed.hpp"
#include "Seeds/WallnutSeed.hpp"
#include "Seeds/CherryBombSeed.hpp"
#include "Seeds/Shovel.hpp"
#include "Zombie/RegularZombie.hpp"

GameWorld::GameWorld() : gameObjects(), m_wave(0), m_sun(50), waveTime(1200), sunTime(180), tickCount(10), holdingItem(PlantType::NONE) {}

GameWorld::~GameWorld() {}

int GameWorld::GetWave() const
{
  return m_wave;
}

void GameWorld::SetWave(int wave)
{
  m_wave = wave;
}

int GameWorld::GetSun() const
{
  return m_sun;
}

void GameWorld::SetSun(int sun)
{
  m_sun = sun;
}

void GameWorld::UpdateSunText()
{
  sunText->SetText(std::to_string(m_sun));
}

void GameWorld::Init()
{
  // YOUR CODE HERE
  tickCount = 10;
  // initialize wave and sun
  SetWave(0);
  SetSun(50);
  
  sunTime = 180;
  waveTime = 1200;

  textForLossing = std::make_shared<TextBase>(335, 50, " ");
  textForLossing->SetColor(1,1,1);
  // create background
  std::shared_ptr<GameObject> background = std::make_shared<Background>();
  gameObjects.push_back(background);


  // create seeds
  gameObjects.push_back(std::make_shared<SunFlowerSeed>(shared_from_this()));

  gameObjects.push_back(std::make_shared<PeashooterSeed>(shared_from_this()));

  gameObjects.push_back(std::make_shared<WallnutSeed>(shared_from_this()));

  gameObjects.push_back(std::make_shared<CherryBombSeed>(shared_from_this()));

  gameObjects.push_back(std::make_shared<Shovel>(shared_from_this()));

  // create planting spots
  for (int i = 0; i < GAME_ROWS; i++)
  {
    for (int j = 0; j < GAME_COLS; j++)
    {
      gameObjects.push_back(std::make_shared<PlantSpot>(FIRST_ROW_CENTER + LAWN_GRID_WIDTH * j,
                                                        FIRST_COL_CENTER + LAWN_GRID_HEIGHT * i,
                                                        shared_from_this()));
    }
  }
}

LevelStatus GameWorld::Update()
{
  // YOUR CODE HERE
  ++tickCount;

  // create sun
  if (tickCount >= sunTime)
  {
    sunTime = tickCount + 300;
    gameObjects.push_back(std::make_shared<Sun>(shared_from_this()));
  }

  // generate zombies
  if (tickCount >= waveTime)
  {
    waveTime = tickCount + std::max(150, 600 - 20 * GetWave());
    SetWave(GetWave() + 1);
    int count = (15 + GetWave()) / 10;

    for (int i = 0; i < count; i++)
    {
      gameObjects.push_back(std::make_shared<RegularZombie>(shared_from_this()));
    }
  }

  // update all gameObjects
  for (const auto &obj : gameObjects)
  {
    obj->Update();
  }

  // delete HP = 0
  for (auto it = gameObjects.begin(); it != gameObjects.end();)
  {
    if ((*it)->GetHp() == 0)
    {
      it = gameObjects.erase(it); // 'erase' return the iterator of next obj
    }
    else
    {
      ++it;
    }
  }

  // check collision
  for (const auto &obj : gameObjects)
  {
    if (obj->GetObjectType() == ObjectType::ZOMBIE || obj->GetObjectType() == ObjectType::FIGHT) {
      obj->Collision();
    }
  }
  
  // judge the end
  for (const auto &obj : gameObjects) {
    if (obj->GetObjectType() == ObjectType::ZOMBIE) {
      if (obj->GetX() <= 0) 
      { 
        textForLossing->SetText(std::to_string(GetWave()));
        return LevelStatus::LOSING; 
      }
      //Detect the collision again and let the zombie walk again
      obj->Collision();
    }

  }

  // Set the sunlight value display
  sunText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, std::to_string(m_sun));
  waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 40, "Wave: " + std::to_string(m_wave));

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
  gameObjects.clear();
}

void GameWorld::AddGameObject(std::shared_ptr<GameObject> obj)
{
  gameObjects.push_back(obj);
}

PlantType GameWorld::GetHoldingItem() const { return holdingItem; }

void GameWorld::SetHoldingItem(PlantType item) { holdingItem = item; }

const std::list<std::shared_ptr<GameObject>> &GameWorld::GetAllGameObjects() const {
  return gameObjects;
}