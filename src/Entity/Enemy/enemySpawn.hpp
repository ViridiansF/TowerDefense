#pragma once
#include "enemy.hpp"
#include "enemyMedic.hpp"
#include "enemyBrute.hpp"
#include "enemyRunner.hpp"
#include "enemyTank.hpp"
#include "enemyLeader.hpp"
#include "enemyPlane.hpp"
#include "enemySpawn.hpp"

class EnemySpawn : public Entity
{
    private:
        float mDelayBetweenEnemySpawn=0.2f; //Number of seconds between the spawn of 2 enemies
        bool mFirstEnemyHasSpawned = false;
        std::vector<Enemy*> mEnemies;
        int mMaxEnemyNumber=0;
        int mSpawnedEnemiesCount=0;
        bool mWaveStarted=false;
        int mDifficulty=0;

        void SpawnEnemy();
        void SpawnWeak();
        void SpawnBrute();
        void SpawnMedic();
        void SpawnRunner();
        void SpawnTank();
        void SpawnLeader();
        void SpawnPlane();

        void RemoveDeadEnemies(int& money);

        void Draw(const Texture2D TileSet);

    public:
        EnemySpawn(const int x,const int y,const int maxEnemyBySpawn);
        EnemySpawn(const float x,const float y){}

        std::vector<Enemy*> GetEnemies(){return mEnemies;}
        Enemy& GetEnemy(const int index){return *mEnemies.at(index);}

        int GetEnemyCount(){return (int)mEnemies.size();}
        float& GetDelayBetweenSpawn(){return mDelayBetweenEnemySpawn;}
        void Update(const std::vector<int> TileState, const Texture2D TileSet,int& playerMoney, const collision::Vec2 playerPosition,const int GameSpeed);
       
        bool EnemiesAreDead();

        void EraseEnemy(const int i);         

        void LaunchWave();
        void StopWave();
        bool AllEnemiesHaveSpawn();
        


};