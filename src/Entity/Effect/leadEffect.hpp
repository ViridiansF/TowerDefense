#pragma once
#include "effect.hpp"

class LeadEffect : public Effect
{
    public:
        LeadEffect(const collision::Vec2 parPosition,const float parRange,const int parDamage)
        {
            SetName("Lead");
            SetPosition(parPosition);
            range=parRange;
            pDamage=parDamage;
        };          
        void Update(int GameSpeed) override;
};