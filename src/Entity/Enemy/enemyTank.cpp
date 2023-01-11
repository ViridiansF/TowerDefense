#include "enemyTank.hpp"

EnemyTank::EnemyTank(const collision::Vec2 parPosition)
{
    SetName("Tank");life=TANK_MAX_HP;maxLife=TANK_MAX_HP;speed=TANK_SPEED;range=HEALING_RANGE;type=TANK;attack=TANK_ATTACK;money=TANK_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}