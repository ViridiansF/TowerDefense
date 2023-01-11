#pragma once
#include "effect.hpp"

class HealEffect : public Effect
{
    public:
        HealEffect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
        {
            SetName("Heal");
            SetPosition(parPosition);
            range=parRange;
            pDamage=parDamage;
        };          
        void Update(int GameSpeed) override;
};