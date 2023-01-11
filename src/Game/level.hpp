#pragma once
#include "../Graphic/map.hpp"

#include "../Entity/Enemy/enemySpawn.hpp"

#include "../Entity/Tower/freezingTower.hpp"
#include "../Entity/Tower/explosiveTower.hpp"
#include "../Entity/Tower/tower.hpp"
#include "../Entity/Tower/poisonTower.hpp"
#include "../Entity/Tower/shotgunTower.hpp"
#include "../Entity/Tower/comboTower.hpp"

#include "../Entity/Player/player.hpp"

#include "../Entity/Effect/effect.hpp"
#include "../Entity/Effect/leadEffect.hpp"
#include "../Entity/Effect/healEffect.hpp"
#include "../Entity/Effect/freezeEffect.hpp"
#include "../Entity/Effect/explosionEffect.hpp"
#include "../Entity/Effect/poisonEffect.hpp"

#include "../UI/button.hpp"

#include "../Graphic/drawAsset.hpp"

#define TILE_SIZE 50

#define SHOP_WIDTH 140
#define SHOP_HEIGHT 100

class Level
{
    private:
        int mCurrentWave=0;     //Actual wave
        int mMaxWave=5;
        float mRecovery = 1.0f;         //Number of waves in the level
        float mRecoveryTimer=mRecovery; //Number of seconds the player has to recover between waves
        float mWaveTimer=0;    
        bool mWaveStarted = false;

        Tower mTower;
        
        std::vector<Effect*> mEffects;

        std::vector<EnemySpawn*> mEnemySpawns;
        int mEnemySpawnCount=0;

        std::vector<Tower*> mTowersInGameSpace;

        Map mTileMap; //Contains the map of the current level


        float mPlacementErrorTimer=0;
        std::string mPlacementErrorMessage;

        int mMoneyIncoming = 0;
        int mGameSpeed = 1;

        std::vector<int> mTileState; // Contains the int-state of current level tiles
        void NextWave(){mCurrentWave++;}
        void SetMaxWave(int parMaxWave){mMaxWave=parMaxWave;}


        void CollisionCheck();
        void CollisionCastleEnemy();
        void CollisionTowerEnemy();

        void DragAndDrop();
        void PrintInfo(int tileType);

        void SetEnemiesInEffectRange();
        void DrawTimer();

        void DeleteEffects();

        void DrawMoney();
        void DeathTower();
        Tower TypeToSpawn(TOWERTYPE type);
        void EraseInRange();

        collision::Vec2 GetTileOfMouse();
        collision::Vec2 GetTile(const float x,const float y);
        bool TileIsFree(const collision::Vec2 position);
        void InitTower(const collision::Vec2 pos,const TOWERTYPE towerType);

        int GetTileType(const int x,const int y);
        int GetTileOfMouseType();
        bool MouseIsInGameSpace();

        bool Collision(Effect* effect,Enemy enemy);
        bool Collision(Tower* tower,Enemy enemy);
        bool Collision(Enemy originEnemy,Enemy otherEnemy);

    public:
        TOWERTYPE selectedType=NONE;        
        Player player;            //Mainly contains the player HP and Money

        Level(const Map map, const int startingFunds, const int maxEnemyBySpawn);
        Level(const int level,const int startingFunds,const int maxEnemyBySpawn);

        int& GetCurrentWave(){return mCurrentWave;}
        int& GetMaxWave(){return mMaxWave;}
        float& GetRecoveryTimer(){return mRecoveryTimer;}
        float GetRecovery(){return mRecovery;}
        std::vector<EnemySpawn*>& GetSpawnEnemiesInGameSpace(){return mEnemySpawns;}
        std::vector<Tower*>& GetTowerInGameSpace(){return mTowersInGameSpace;} 
        std::vector<Effect*>& GetEffectsInGameSpace(){return mEffects;}

        Map& GetMap(){return mTileMap;}
        int& GetSpeed(){return mGameSpeed;}
        
        void Update(const int Gamespeed);

        bool WaveIsOver();
        bool GameIsOver();
        bool LevelIsWon();
        bool IsWaveStarted();

};

