#include "explosionEffect.hpp"

void ExplosionEffect::Update(int gameSpeed)
{
    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        enemiesInRange.at(i)->life-=pDamage;
        DrawCircleLines(pPos.x,pPos.y,range,RED);
    }    
    Effect::Update(gameSpeed);
}
