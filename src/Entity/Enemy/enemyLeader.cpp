#include "enemyLeader.hpp"

EnemyLeader::EnemyLeader(const collision::Vec2 parPosition)
{
    SetName("Leader");life=LEADER_MAX_HP;maxLife=LEADER_MAX_HP;speed=LEADER_SPEED;range=HEALING_RANGE;type=LEADER;attack=LEADER_ATTACK;money=LEADER_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}