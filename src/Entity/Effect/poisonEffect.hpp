#pragma once
#include "effect.hpp"

class PoisonEffect : public Effect
{
    public:
        PoisonEffect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
        {
            SetName("Poison");
            SetPosition(parPosition);
            range=parRange;
            pDamage=parDamage;
        };         
        void Update(int GameSpeed) override;
};