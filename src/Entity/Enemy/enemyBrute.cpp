#include "enemyBrute.hpp"

EnemyBrute::EnemyBrute(const collision::Vec2 parPosition)
{
    SetName("Brute");life=BRUTE_MAX_HP;maxLife=BRUTE_MAX_HP;speed=BRUTE_SPEED;range=HEALING_RANGE;type=BRUTE;attack=BRUTE_ATTACK;money=BRUTE_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}