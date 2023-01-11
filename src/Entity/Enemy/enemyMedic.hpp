#include "enemy.hpp"


class EnemyMedic : public Enemy
{
    private:
        int mHealingValue = HEALING_VALUE;
        float mHealingCoolDown = HEALING_COOLDOWN;


    public :
        EnemyMedic(){SetName("Medic");life=MEDIC_MAX_HP;maxLife=MEDIC_MAX_HP;speed=MEDIC_SPEED;range=HEALING_RANGE;type=MEDIC;}

        EnemyMedic(const collision::Vec2 parPosition);

        float GetHealingCooldown(){return mHealingCoolDown;}

        virtual void Update(const std::vector<int> TileState,collision::Vec2 playerPosition, const int GameSpeed) override;
};