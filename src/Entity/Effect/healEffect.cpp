#include "healEffect.hpp"


void HealEffect::Update(int gameSpeed)
{
    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        DrawCircleLines(pPos.x,pPos.y,range,GREEN);
        if(enemiesInRange[i]->type!=MEDIC)
            enemiesInRange.at(i)->life+=pDamage;

        if(enemiesInRange[i]->life>enemiesInRange[i]->maxLife)
            enemiesInRange[i]->life=enemiesInRange[i]->maxLife;
    }
    
    Effect::Update(gameSpeed);

}