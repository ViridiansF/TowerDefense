#include "enemyRunner.hpp"


EnemyRunner::EnemyRunner(const collision::Vec2 parPosition)
{
    SetName("Runner");life=RUNNER_MAX_HP;maxLife=RUNNER_MAX_HP;speed=RUNNER_SPEED;range=HEALING_RANGE;type=RUNNER;attack=RUNNER_ATTACK;money=RUNNER_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}