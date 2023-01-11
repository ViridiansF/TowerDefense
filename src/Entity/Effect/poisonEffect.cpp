#include "poisonEffect.hpp"

void PoisonEffect::Update(int gameSpeed)
{
    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        enemiesInRange.at(i)->poisonTimer=POISON_DURATION;
        enemiesInRange.at(i)->poisonAttackSpeed=0.5f;
        DrawCircleLines(pPos.x,pPos.y,range,PURPLE);
    }    
    Effect::Update(gameSpeed);

}
