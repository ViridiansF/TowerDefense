#include "leadEffect.hpp"


void LeadEffect::Update(int gameSpeed)
{
    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        enemiesInRange.at(i)->freezingTimer=0;
        enemiesInRange.at(i)->poisonTimer=0;
        DrawCircleLines(pPos.x,pPos.y,range,ORANGE);
    }
    Effect::Update(gameSpeed);

}