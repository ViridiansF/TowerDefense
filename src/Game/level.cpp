#include "level.hpp"

Level::Level(const Map map, const int startingFunds, const int maxEnemyBySpawn)
{
    mTileMap = Map(map);
    const char* tiles = mTileMap.GetTiles();
    for (int i = 0; tiles[i] != '\0'; i++)
    {
        if (tiles[i] == 'm')
        {
            mTileState.push_back(MOUNTAIN);
        }
        else if (tiles[i] == 'g')
        {
            mTileState.push_back(GRASS);
        }
        else if (tiles[i] == 'r')
        {
            mTileState.push_back(ROAD);
        }
        else if (tiles[i] == 'p')
        {
            mTileState.push_back(CASTLE);
            player=Player(i%26,i/26);
        }
        else if (tiles[i] == 's')
        {
            mTileState.push_back(SPAWN);
            mEnemySpawns.push_back(new EnemySpawn(i%26,i/26,maxEnemyBySpawn));
            mEnemySpawnCount++;
        }
        else
            mTileState.push_back(GRASS);

    }
    
    player.SetMoney(startingFunds);
}

bool Level::Collision(Tower* tower, Enemy enemy)
{
    if(collision::Collision(tower->GetPosition(),tower->range,enemy.GetPosition(),enemy.size))
        return true;
    return false;
}

bool Level::Collision(Effect* effect,Enemy enemy)
{
    if(collision::Collision(effect->GetPosition(),effect->range,enemy.GetPosition(),enemy.size))
        return true;
    return false;
}


bool Level::Collision(Enemy originEnemy, Enemy otherEnemy)
{
    if(collision::Collision(originEnemy.GetPosition(),originEnemy.range,otherEnemy.GetPosition(),otherEnemy.size))
        return true;
    return false;
}


void Level::SetEnemiesInEffectRange()
{

    for(int i=0;i<(int)mEffects.size();i++)
    {
        Effect* effect = mEffects[i];
        for(int j=0;j<(int)mEnemySpawns.size();j++)
        {
            EnemySpawn* enemySpawn = mEnemySpawns[j];
            
            for(int k=0;k<enemySpawn->GetEnemyCount();k++)
            {
                Enemy& enemy = enemySpawn->GetEnemy(k);
                if(Collision(effect,enemy))
                    effect->enemiesInRange.push_back(&enemy);
            }
        }
    }
}



void Level::CollisionCheck()
{
    CollisionTowerEnemy();
    CollisionCastleEnemy();
}

void Level::CollisionCastleEnemy()
{
    for(int j=0;j<mEnemySpawnCount;j++)
    {
        EnemySpawn& enemySpawn = *mEnemySpawns[j];
        for(int k=0;k<enemySpawn.GetEnemyCount();k++)
        {
            Enemy& enemy = enemySpawn.GetEnemy(k);
            collision::Box box = collision::Box(player.GetPosition().x,player.GetPosition().y,50,50);

            if(enemy.CastleReached(mTileState))
            {
                player.life-=enemy.attack;
                enemySpawn.EraseEnemy(k);
            }
        }
    }
}



void Level::CollisionTowerEnemy()
{

    for(int i=0;i<(int)mTowersInGameSpace.size();i++)
    {    
        Tower* tower = mTowersInGameSpace[i];
        for(int j=0;j<mEnemySpawnCount;j++)
        {
            EnemySpawn& enemySpawn = *mEnemySpawns[j];
            for(int k=0;k<enemySpawn.GetEnemyCount();k++)
            {
                Enemy& enemy = enemySpawn.GetEnemy(k);
                if(Collision(tower,enemy))
                {   
                    if(tower->lastTarget != nullptr)
                        tower->Rotate(*tower->lastTarget);
                    if(tower->type==COMBO)
                    {
                        if(tower->CanShoot())
                        {
                            if(enemy.poisonTimer>0 && enemy.freezingTimer>0)
                                mEffects.push_back(new ExplosionEffect(enemy.GetPosition(),COMBO_RADIUS,tower->damage));
                            else if(enemy.poisonTimer>0)
                                mEffects.push_back(new PoisonEffect(enemy.GetPosition(),COMBO_RADIUS,tower->damage));
                            else if(enemy.freezingTimer>0)
                                mEffects.push_back(new FreezeEffect(enemy.GetPosition(),COMBO_RADIUS,tower->damage));
                            tower->lastTarget = &enemy; 
                            tower->Shoot(enemy);
                        }
                    }

                    else if(tower->type==EXPLOSIVE)
                    {
                        tower->lastTarget = &enemy;
                        if(tower->CanShoot())
                        {
                            mEffects.push_back(new ExplosionEffect(enemy.GetPosition(),EXPLOSION_RADIUS,tower->damage));
                            tower->Shoot(enemy);
                        }
                    }
                    else if(tower->type == POISON)
                    {
                        tower->lastTarget = &enemy; 
                        if(tower->CanShoot() && enemy.poisonTimer <= 0)
                        {
                            tower->Shoot(enemy);
                        }
                    }
                    else if(tower->type == FREEZING)
                    {
                        tower->lastTarget = &enemy; 
                        if(tower->CanShoot() && enemy.freezingTimer <= 0)
                        {
                            tower->Shoot(enemy);
                        }
                    }
                    else
                    {
                        if(tower->CanShoot())
                        {
                            tower->Shoot(enemySpawn.GetEnemy(k));
                        }
                    }
                }
            }
        }
    }
}


bool Level::WaveIsOver()
{
    for(int i=0;i<mEnemySpawnCount;i++)
    {
        if(!mEnemySpawns[i]->EnemiesAreDead())
            return false;
    }
    return true;
}

void Level::DrawTimer()
{
    if(mRecoveryTimer>0)
        DrawText(TextFormat("Prochaine vague dans : %.1f\n",mRecoveryTimer),800,25,20,BLACK);
    else    
        DrawText(TextFormat("Vague en cours : %.1f\n",mWaveTimer),800,25,20,BLACK);

}

int Level::GetTileType(int x, int y)
{
    return mTileState[x+y*26];
}


collision::Vec2 Level::GetTile(float x, float y)
{
    return {(int)x/50,(int)y/50};
}

collision::Vec2 GetTile(collision::Vec2 vec)
{
    return {(int)vec.x/50,(int)vec.y/50};
}

collision::Vec2 Level::GetTileOfMouse()
{
    collision::Vec2 posMouse = {GetMouseX(), GetMouseY()};
    int x=(int)posMouse.x/50;
    int y=(int)posMouse.y/50;
    return {x,y};
}

int Level::GetTileOfMouseType()
{
    collision::Vec2 posMouse = {GetMouseX(), GetMouseY()};
    int x=(int)posMouse.x/50;
    int y=(int)posMouse.y/50;
    int tileType = GetTileType(x,y);
    if(tileType>6)
        tileType=0;
    return tileType;
}

bool Level::MouseIsInGameSpace()
{
    collision::Vec2 posMouse = {GetMouseX(), GetMouseY()};
    if(posMouse.x>SCREEN_WIDTH-140)
        return false;
    if(posMouse.y>SCREEN_HEIGHT-100)
        return false;
    return true;
}


void Level::PrintInfo(int tileType)
{

    switch (tileType)
    {
    case GRASS:
        DrawText("Plaine : Terrain favorable à l'installation d'une tourelle.",80,SCREEN_HEIGHT-80,20,BLACK);
        break;
    case ROAD:
        DrawText("Route : Les ennemis suivent les routes pour atteindre votre Château. Impossible de construire ici.",80,SCREEN_HEIGHT-80,20,BLACK);
        break;
    case CASTLE:
        DrawText("Château : Ne laissez pas les ennemis l'atteindre commandant ! Impossible de construire ici.",80,SCREEN_HEIGHT-80,20,BLACK);
        break;
    case MOUNTAIN:
        DrawText("Montagne : Terrain infranchissable pour les ennemis et nos ingénieurs. Impossible de construire ici.",80,SCREEN_HEIGHT-80,20,BLACK);
        break;
    case SPAWN:
        DrawText("Campement : Terrain où se rassemblent les ennemis et d'où ils lanceront leur assaut. Impossible de construire ici.",80,SCREEN_HEIGHT-80,20,BLACK);
        break;

    default:
        break;
    }

    switch(selectedType)
    {
        case CLASSIC:
            DrawText("Tourelle Classique : Prix : 100, Dégâts : Moyens, Cadence : Moyenne, Effet : Aucun.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        case FREEZING:
            DrawText("Tourelle Cryogénique : Prix : 50, Dégâts : Faibles, Cadence : Moyenne, Effet : Ralentissement.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        case EXPLOSIVE:
            DrawText("Tourelle Lance-Missiles : Prix : 300, Dégâts : Elevés, Cadence : Faible, Effet : Explosion.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        case POISON:
            DrawText("Tourelle Empoisonnante : Prix : 300, Dégâts : Nuls, Cadence : Faible, Effet : Empoisonnement.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        case SHOTGUN:
            DrawText("Tourelle Shotgun : Prix : 300, Dégâts : Enormes, Cadence : Tres Faible, Effet : Aucun.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        case COMBO:
            DrawText("Tourelle Combo : Prix : 200, Dégâts : Nuls, Cadence : Moyenne, Effet : Combo.",80,SCREEN_HEIGHT-50,20,BLACK);     
            break;
        default:
            break;
    }
}

void Level::DeleteEffects()
{
    for(int i=0;i<(int)mEffects.size();i++)
        mEffects.pop_back();
}


void Level::Update(int GameSpeed)
{

    //Info bar
    if(MouseIsInGameSpace())
        PrintInfo(GetTileOfMouseType());

    DrawTimer();

    if(mPlacementErrorTimer>0)
    {
        mPlacementErrorTimer-=GetFrameTime();
        DrawText(TextFormat(mPlacementErrorMessage.c_str()),75,150,20,RED);
    }    
    DrawText(TextFormat("%d",player.money),200,45,26, BLACK);
    DrawText(TextFormat("%d",player.life),80,130,26,BLACK);
 
    player.Draw(gRes->mTileSet);    

    DeathTower();

    for(int i=0;i<(int)mTowersInGameSpace.size();i++)
    {
        mTowersInGameSpace[i]->Update(&player, GameSpeed);
    }


    if(mRecoveryTimer>0)  //The player is still recovering
    {
        mRecoveryTimer-= GetFrameTime() * GameSpeed;  //Reduce timer
    }

    else  //The wave starts
    {
        mWaveTimer+=GetFrameTime() * GameSpeed;

        if(!mWaveStarted)
        {
            for (int i=0;i<mEnemySpawnCount;i++)
            {
                mEnemySpawns[i]->LaunchWave();
            }
            mWaveStarted=true;
        }

        for (int i=0;i<mEnemySpawnCount;i++)
        {
            mEnemySpawns[i]->Update(mTileState, gRes->mTileSet, player.money, player.GetPosition(),GameSpeed);
            
            for(int j=0;j<mEnemySpawns[i]->GetEnemyCount();j++)
            {
                Enemy& enemy = mEnemySpawns[i]->GetEnemy(j);
                
                // HEAL 
                if(enemy.type==MEDIC)
                {
                    if(enemy.cooldown<=0)
                    {
                        enemy.cooldown=HEALING_COOLDOWN;
                        mEffects.push_back(new HealEffect(enemy.GetPosition(),enemy.range,HEALING_VALUE));    
                    }
                    else    
                    {
                        enemy.cooldown-=GetFrameTime();
                    }
                }

                // LEAD
                if(enemy.type==LEADER)
                {
                    if(enemy.cooldown<=0)
                    {
                        enemy.cooldown=LEAD_COOLDOWN;
                        mEffects.push_back(new LeadEffect(enemy.GetPosition(),enemy.range,0));    
                    }
                    else    
                    {
                        enemy.cooldown-=GetFrameTime();
                    }
                }
            }


            
        }

        SetEnemiesInEffectRange();

        for(int i=0;i<(int)mEffects.size();i++)
        {
            mEffects[i]->Update(GameSpeed);
        }

        DeleteEffects();

        if(WaveIsOver())
        {
            mRecoveryTimer=10;
            mWaveTimer=0;
            mWaveStarted=false;
            for (int i=0;i<mEnemySpawnCount;i++)
                mEnemySpawns[i]->StopWave();
            mCurrentWave++;   
        }
        CollisionCheck();

    }
    //Place Tower
    DragAndDrop();

    // Update money gain and loss
    DrawMoney();

}

void Level::InitTower(collision::Vec2 pos, TOWERTYPE towerType)
{
    if(towerType==NONE)
        return;

    collision::Vec2 position;

    if ((int)pos.x % TILE_SIZE < 25  && (int)pos.y % TILE_SIZE < 25)
        position = {pos.x + (TILE_SIZE - ((int)pos.x % TILE_SIZE)) - 25, pos.y + ( TILE_SIZE - ((int)pos.y % TILE_SIZE) - 25)};
    else if ((int)pos.x % TILE_SIZE > 25  && (int)pos.y % TILE_SIZE > 25)
        position = {pos.x - (25 - (25 - ((int)pos.x % 25))), pos.y - (25 - (25 - (int(pos.y) % 25)))};
    else if ((int)pos.x% TILE_SIZE > 25  && (int)pos.y% TILE_SIZE < 25)
        position = {pos.x - (25 - (25 - ((int)pos.x % 25))), pos.y + ( TILE_SIZE - ((int)pos.y % TILE_SIZE) - 25)};
    else if ((int)pos.x% TILE_SIZE < 25  && (int)pos.y% TILE_SIZE > 25)
        position = {pos.x + (TILE_SIZE - ((int)pos.x % TILE_SIZE)) - 25, pos.y - (25 - (25 - (int(pos.y) % 25)))};
    else if ((int)pos.x% TILE_SIZE == 25  && (int)pos.y% TILE_SIZE > 25)
        position = {pos.x, pos.y - (25 - (25 - (int(pos.y) % 25)))};
    else if ((int)pos.x% TILE_SIZE == 25  && (int)pos.y% TILE_SIZE < 25)
        position = {pos.x, pos.y + ( TILE_SIZE - ((int)pos.y % TILE_SIZE) - 25)};
    else if ((int)pos.x% TILE_SIZE < 25  && (int)pos.y% TILE_SIZE == 25)
        position = {pos.x + (TILE_SIZE - ((int)pos.x % TILE_SIZE)) - 25, pos.y};
    else if ((int)pos.x% TILE_SIZE > 25  && (int)pos.y% TILE_SIZE == 25)
        position = {pos.x - (25 - (25 - ((int)pos.x % 25))), pos.y};
    else if ((int)pos.x% TILE_SIZE == 25  && (int)pos.y% TILE_SIZE == 25)
        position = {pos.x, pos.y};


    if(GetTileOfMouseType()!=GRASS)
    {
        mPlacementErrorTimer=5;
        mPlacementErrorMessage="Nous ne pouvons pas construire ici Commandant !";
        return;
    }
    else if(!TileIsFree(GetMousePosition())) 
    {
        mPlacementErrorTimer=5;
        mPlacementErrorMessage="Il y a déjà une tourelle à cet emplacement Commandant !";
        return;
    }
    
    if (towerType != NONE)
    {
        Tower* tower = {};
        switch(towerType)
        {
            case (CLASSIC) : tower = new Tower(position);
                             break;
            case (FREEZING) : tower = new FreezingTower(position);
                              break;
            case (EXPLOSIVE) : tower = new ExplosiveTower(position);
                               break;
            case (POISON) : tower = new PoisonTower(position);
                            break;
            case (SHOTGUN) : tower = new ShotgunTower(position);
                             break;
            case (COMBO) : tower = new ComboTower(position);
                           break;
            default : break;
        }

        if(player.money>=tower->cost)
        {
            player.money-=tower->cost;
            mMoneyIncoming = -tower->cost;
            mTowersInGameSpace.push_back(tower);
        }
        else
        {
            mPlacementErrorTimer=5;
            mPlacementErrorMessage="Nous n'avons pas les fonds nécessaires pour cet investissement Commandant !";
        }
    }
}

bool Level::LevelIsWon()
{
    if(mCurrentWave==mMaxWave)
        return true;
    else
        return false;
}

bool Level::GameIsOver()
{
    if(player.life<=0)
        return true;
    else
        return false;
}

bool Level::TileIsFree(collision::Vec2 position)
{
    collision::Vec2 test = GetTile(position.x,position.y);
    
    for(int i=0;i<(int)mTowersInGameSpace.size();i++)
    {
        Tower* tower = mTowersInGameSpace[i];
        collision::Vec2 vec = tower->GetPosition();
        if(GetTile(vec.x,vec.y) == test)
            return false;
    }
    return true;
}

bool Level::IsWaveStarted()
{
    return mWaveStarted;
}


void Level::DragAndDrop()
{
    if (selectedType == CLASSIC)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), CLASSIC_RANGE, SKYBLUE);
        DrawAssetTexture(19, 8, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == FREEZING)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), FREEZING_RANGE, SKYBLUE);
        DrawAssetTexture(19, 10, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == EXPLOSIVE)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), EXPLOSIVE_RANGE, SKYBLUE);
        DrawAssetTexture(22, 8, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == POISON)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), POISON_RANGE, SKYBLUE);
        DrawAssetTexture(15, 12, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == SHOTGUN)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), SHOTGUN_RANGE, SKYBLUE);
        DrawAssetTexture(22, 9, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == SHOTGUN)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), SHOTGUN_RANGE, SKYBLUE);
        DrawAssetTexture(22, 9, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }
    else if (selectedType == COMBO)
    {
        DrawCircleLines(GetMouseX(), GetMouseY(), COMBO_RANGE, SKYBLUE);
        DrawAssetTexture(16, 12, GetMouseX(), GetMouseY(), 0, 1.0f, WHITE);
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        collision::Vec2 posMouse = GetMousePosition();
        if (MouseIsInGameSpace())
        {
            InitTower(collision::Vec2(posMouse.x, posMouse.y), selectedType);
        }
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT))
    {
        selectedType = NONE;
    }

}

void Level::DrawMoney()
{
    if (mMoneyIncoming > 0)
        DrawText(TextFormat("+%d", mMoneyIncoming), 210, 70, 14, BLACK);
    else if (mMoneyIncoming < 0)
        DrawText(TextFormat("%d", mMoneyIncoming), 210, 70, 14, BLACK);

}

void Level::DeathTower()
{
    for (unsigned int i = 0; i < mTowersInGameSpace.size(); i++)
    {
        if (mTowersInGameSpace[i]->drawMenu == true && mTowersInGameSpace[i]->GetDeleteButton().IsClicked())
        {
            mTowersInGameSpace.erase(mTowersInGameSpace.begin() + i);
            if (mTowersInGameSpace[i]->GetLevel() == 1)
                player.money += mTowersInGameSpace[i]->cost / 2;
            else
                player.money += mTowersInGameSpace[i]->cost+mTowersInGameSpace[i]->pUpgradeCost / 2;
       }
    }
}