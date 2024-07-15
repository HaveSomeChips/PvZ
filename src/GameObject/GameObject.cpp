#include "pvz/GameObject/GameObject.hpp"

// Your everything begins from here.
GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,
                       pGameWorld ptr, int hp, ObjectType type)
    : ObjectBase(imageID, x, y, layer, width, height, animID), gameWorld(std::move(ptr)), Hp(hp), tickCount(0), objectType(type) {}

GameObject::~GameObject() {}

pGameWorld GameObject::GetGameWorld() const { return gameWorld; }

int GameObject::GetHp() const { return Hp; }
void GameObject::SetHp(int hp) { Hp = hp; }

int GameObject::GetTime() const { return tickCount; }
void GameObject::AddTime() { ++tickCount; }

ObjectType GameObject::GetObjectType() const { return objectType; }

bool GameObject::IsCollidingWith(const std::shared_ptr<GameObject>& other) const {
    return (abs(GetX() - other->GetX()) <= (GetWidth() + other->GetWidth()) / 2 && 
            abs(GetY() - other->GetY()) <= (GetHeight() + other->GetHeight()) / 2);
}