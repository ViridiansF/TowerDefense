#include "enemy.hpp"

#include "../../Graphic/drawAsset.hpp"

class EnemyRunner : public Enemy
{
    public :
        EnemyRunner(const collision::Vec2 parPosition);
};