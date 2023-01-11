#pragma once

#include "../entity.hpp"
#include "../../Graphic/resource.hpp"

#define TANK_MAX_HP 90
#define TANK_SPEED 0.65f
#define TANK_MONEY 75
#define TANK_ATTACK 5

#define PLANE_MAX_HP 40
#define PLANE_SPEED 1
#define PLANE_MONEY 100
#define PLANE_ATTACK 2

#define MEDIC_MAX_HP 15
#define MEDIC_SPEED 1
#define MEDIC_MONEY 25
#define HEALING_COOLDOWN 1
#define HEALING_VALUE 2
#define HEALING_RANGE 80
#define MEDIC_ATTACK 1

#define LEADER_MAX_HP 20
#define LEADER_SPEED 1
#define LEADER_MONEY 25
#define LEAD_COOLDOWN 0.5
#define LEAD_RANGE 100
#define LEADER_ATTACK 2

#define WEAK_MAX_HP 15
#define WEAK_SPEED 1
#define WEAK_MONEY 10
#define WEAK_ATTACK 1

#define BRUTE_MAX_HP 30
#define BRUTE_SPEED 0.75f
#define BRUTE_MONEY 25
#define BRUTE_ATTACK 3

#define RUNNER_MAX_HP 15
#define RUNNER_SPEED 2
#define RUNNER_MONEY 25
#define RUNNER_ATTACK 1

enum Destination
{
    RIGHT,
    UP,
    DOWN,
    LEFT,
};

enum ENEMYTYPE
{
    WEAK,
    MEDIC,
    BRUTE,
    RUNNER,
    TANK,
    LEADER,
    PLANE
};

class Enemy : public Entity
{
    protected:

        float pAngle=0;
        int pDest = 0;

        int pCurrentFrame = 15;
        int pCurrentLine = 10;

        bool IsInTheMiddleOfTheTile(const std::vector<int> TileState);
        bool IsOnCrossroad(const std::vector<int> TileState);

        int GetTileUp(const std::vector<int> TileState);
        int GetTileDown(const std::vector<int> TileState);
        int GetTileRight(const std::vector<int> TileState);
        int GetTileLeft(const std::vector<int> TileState);
        int GetTile(const std::vector<int> TileState);

        void Move(const std::vector<int> TileState,const float parSpeed, const int GameSpeed);
        void Fly(const std::vector<int> TileState, const float parSpeed, const collision::Vec2 playerPosition, const int GameSpeed);
        int TurnAround();

        void Draw(const collision::Vec2 playerPosition);
        void SetDest(const std::vector<int> TileState);
        collision::Vec2 GetTilePosition();
    
    public:
        ENEMYTYPE type = WEAK;
        int life=WEAK_MAX_HP;
        int maxLife=WEAK_MAX_HP;
        float speed=WEAK_SPEED;
        float cooldown=0;
        float size=10;
        int money=50;
        int attack=WEAK_ATTACK;
        float range=0;

        float freezingTimer = 0.f;
        float slowedSpeed=0;

        float poisonTimer=0;
        float poisonAttackSpeed = 1;
        float poisonPower = 1;

        Enemy(const collision::Vec2 parPosition){SetName("Enemy");SetPosition({parPosition.x+25,parPosition.y+25});money=WEAK_MONEY;}
        Enemy(){SetName("Enemy");SetPosition(collision::Vec2(0,0));}

        void TakeDamage(const int damage);
        virtual void Update(const std::vector<int> TileState, const collision::Vec2 playerPosition, const int GameSpeed);
        bool CastleReached(const std::vector<int> TileState);
};