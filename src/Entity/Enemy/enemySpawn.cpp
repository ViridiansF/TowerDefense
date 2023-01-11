#include "enemySpawn.hpp"


EnemySpawn::EnemySpawn(const int x,const int y,const int maxEnemyBySpawn)
{
    mMaxEnemyNumber=maxEnemyBySpawn;
    collision::Vec2 vec = {x*50,y*50};
    SetPosition(vec);
}

void EnemySpawn::RemoveDeadEnemies(int& money)
{
    for(int i=0;i<(int)mEnemies.size();i++)
    {

        if(mEnemies[i]->life<=0)
        {
            money+=mEnemies[i]->money;
            mEnemies.erase(mEnemies.begin()+i);
        }
    }
}

void EnemySpawn::EraseEnemy(int i)
{
    mEnemies.erase(mEnemies.begin()+i);
}

void EnemySpawn::LaunchWave()
{
    mWaveStarted=true;
}


void EnemySpawn::StopWave()
{
    mWaveStarted=false;
    mSpawnedEnemiesCount=0;
    mMaxEnemyNumber+=5;
    mFirstEnemyHasSpawned=false;
    mDifficulty++;
}


bool EnemySpawn::AllEnemiesHaveSpawn()
{
    if(mSpawnedEnemiesCount==mMaxEnemyNumber)
        return true;
    return false;
}

void EnemySpawn::Update(const std::vector<int> TileState, const Texture2D TileSet,int& playerMoney, const collision::Vec2 playerPosition,const int GameSpeed)
{
    RemoveDeadEnemies(playerMoney);

    if(!AllEnemiesHaveSpawn())
    {
        // Spawning new enemies
        if(mDelayBetweenEnemySpawn>0)
        {
            mDelayBetweenEnemySpawn-=GetFrameTime() * GameSpeed;
        }
        else if((int)mEnemies.size()<mMaxEnemyNumber)
        {
            SpawnEnemy();
            mDelayBetweenEnemySpawn=1;
        }
    }

    // Updating enemies
    for(int i=0;i<(int)mEnemies.size();i++)
    {
        mEnemies[i]->Update(TileState, playerPosition, GameSpeed);
    }
    Draw(TileSet);
}


void EnemySpawn::SpawnTank()
{
    mEnemies.push_back(new EnemyTank(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnLeader()
{
    mEnemies.push_back(new EnemyLeader(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnWeak()
{
    mEnemies.push_back(new Enemy(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnMedic()
{
    
    mEnemies.push_back(new EnemyMedic(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnRunner()
{
    mEnemies.push_back(new EnemyRunner(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnPlane()
{
    mEnemies.push_back(new EnemyPlane(GetPosition()));
    mSpawnedEnemiesCount++;
}

void EnemySpawn::SpawnBrute()
{
    mEnemies.push_back(new EnemyBrute(GetPosition()));
    mSpawnedEnemiesCount++;
}

bool EnemySpawn::EnemiesAreDead()
{
    if(mSpawnedEnemiesCount==mMaxEnemyNumber && mEnemies.size()==0)
        return true;
    return false;
}



void EnemySpawn::SpawnEnemy() 
{
    int randomNumber = rand() % 100;
    if(!mFirstEnemyHasSpawned)
        mFirstEnemyHasSpawned=true;

/* Introduction Wave
Weak 100%
*/    if(mDifficulty==0)
    {
        SpawnWeak();
    }

/* Easy Wave
Weak 50%
Brute 30%
Medic 20%
*/
    else if(mDifficulty==1)
    {
        if(randomNumber<50)
            SpawnWeak();        
        else if(randomNumber<80)
            SpawnBrute();
        else
            SpawnMedic();
    }

/* Very random Wave
Weak 20%
Brute 30%
Medic 20%
Leader 10%
Runner 20%
*/
    else if(mDifficulty==2)
    {
        if(randomNumber<20)
            SpawnWeak();     
        else if(randomNumber<30)
            SpawnLeader();
        else if(randomNumber<60)
            SpawnBrute();
        else if(randomNumber<80)
            SpawnRunner();
        else
            SpawnMedic();
    }

/* Fast Wave
Weak 0%
Brute 20%
Medic 10%
Leader 5%
Runner 50%
Tank 5%
Plane 10%
*/
    else if(mDifficulty==3)
    {
        if(randomNumber<20)
            SpawnBrute();
        else if(randomNumber<30)
            SpawnMedic();
        else if(randomNumber<35)
            SpawnLeader();
        else if(randomNumber<85)
            SpawnRunner();
        else if(randomNumber<90)
            SpawnTank();        
        else
            SpawnPlane();
    }

/* Tanky Wave
Weak 0%
Brute 40%
Medic 20%
Leader 5%
Runner 0%
Tank 25%
Plane 10%
*/
    else 
    {
        if(randomNumber<40)
            SpawnBrute();
        else if(randomNumber<60)
            SpawnMedic();
        else if(randomNumber<65)
            SpawnLeader();
        else if(randomNumber<90)
            SpawnTank();
        else
            SpawnPlane();
    }
}


void EnemySpawn::Draw(const Texture2D TileSet)
{
    DrawAssetTexture(16, 7, GetPosition().x + 26, GetPosition().y + 25, 0, 1.0f, WHITE); 
}