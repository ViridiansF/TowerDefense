#pragma once
#include "effect.hpp"

class ExplosionEffect : public Effect
{
    public:
        ExplosionEffect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
        {
            SetName("Explosion");
            SetPosition(parPosition);
            range=parRange;
            pDamage=parDamage;
        }
        void Update(int GameSpeed) override;
};