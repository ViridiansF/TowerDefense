#pragma once
#include "effect.hpp"

class FreezeEffect : public Effect
{
    public:
        FreezeEffect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
        {
            SetName("Freeze");
            SetPosition(parPosition);
            range=parRange;
            pDamage=parDamage;
        };        
        void Update(int GameSpeed) override;
};