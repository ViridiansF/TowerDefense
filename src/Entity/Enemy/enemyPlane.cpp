#include "enemyPlane.hpp"

EnemyPlane::EnemyPlane(const collision::Vec2 parPosition)
{
    pDest=-1;
    SetName("Plane");life=PLANE_MAX_HP;maxLife=PLANE_MAX_HP;speed=PLANE_SPEED;range=HEALING_RANGE;type=PLANE;attack=PLANE_ATTACK;money=PLANE_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}