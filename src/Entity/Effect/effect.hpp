#pragma once
#include "../entity.hpp"
#include "../Enemy/enemy.hpp"
#include "../Tower/tower.hpp"

class Effect : public Entity
{

    protected:
        void DeleteEnemiesInRange();
        int pDamage;

    public:
        float range;
        std::vector<Enemy*> enemiesInRange;

        Effect(){};
        Effect(const collision::Vec2 parPosition,const float parRange,const int parDamage);
        virtual void Update(int GameSpeed);

};