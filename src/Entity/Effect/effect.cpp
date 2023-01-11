#include "effect.hpp"

Effect::Effect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
{
    SetName("Effect");
    SetPosition(parPosition);
    range=parRange;
    pDamage=parDamage;
}

void Effect::DeleteEnemiesInRange()
{
    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        enemiesInRange.pop_back();
    }
}

void Effect::Update(const int GameSpeed)
{
    DeleteEnemiesInRange();
    pDamage=0;
}
