#pragma once
#include "enemy.hpp"

class EnemyPlane : public Enemy
{
    public :
        EnemyPlane(const collision::Vec2 parPosition);
};