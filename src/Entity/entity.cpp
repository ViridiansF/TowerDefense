#include "entity.hpp"


Entity::Entity(const std::string name,const collision::Vec2 pos1)
{
    pName = name;
    pPos = pos1;
}



void Entity::Draw(collision::Box box)
{
    DrawRectanglePro(box.toRec(),{0,0},0,RED);
}