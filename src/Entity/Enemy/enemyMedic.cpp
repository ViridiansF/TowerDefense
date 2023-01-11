#include "enemyMedic.hpp"


EnemyMedic::EnemyMedic(const collision::Vec2 parPosition)
{
    SetName("Medic");life=MEDIC_MAX_HP;maxLife=MEDIC_MAX_HP;speed=MEDIC_SPEED;range=HEALING_RANGE;type=MEDIC;attack=MEDIC_ATTACK;money=MEDIC_MONEY;
    SetPosition({parPosition.x+25,parPosition.y+25});
}


void EnemyMedic::Update(std::vector<int> TileState, collision::Vec2 playerPosition, const int GameSpeed) 
{
    Enemy::Update(TileState, playerPosition, GameSpeed);
} 
