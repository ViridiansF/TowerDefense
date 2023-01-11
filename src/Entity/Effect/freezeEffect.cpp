#include "freezeEffect.hpp"


void FreezeEffect::Update(int GameSpeed)
{

    for(int i=0;i<(int)enemiesInRange.size();i++)
    {
        enemiesInRange[i]->freezingTimer=FREEZE_DURATION;
        enemiesInRange[i]->slowedSpeed=enemiesInRange[i]->speed*FREEZE_VALUE;  
        enemiesInRange[i]->slowedSpeed+=0.25f;
        DrawCircleLines(pPos.x,pPos.y,range,BLUE);
    }
}