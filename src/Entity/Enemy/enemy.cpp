#include "enemy.hpp"
#include "../../Graphic/map.hpp"

collision::Vec2 Enemy::GetTilePosition()
{
    float x=GetPosition().x-25;
    float y=GetPosition().y-25;

    return {x/TILE_SIZE,y/TILE_SIZE};
}

int Enemy::GetTile(const std::vector<int> TileState)
{
    return TileState[(((int)GetPosition().x / TILE_SIZE) + ((int)GetPosition().y / TILE_SIZE) * COLUMNS)]; 
}

int Enemy::GetTileDown(const std::vector<int> TileState)
{
    return TileState[(((int)GetPosition().x / TILE_SIZE) + ((int)GetPosition().y / TILE_SIZE) * COLUMNS) + COLUMNS]; 
}

int Enemy::GetTileUp(const std::vector<int> TileState)
{
    return TileState[(((int)GetPosition().x / TILE_SIZE) + ((int)GetPosition().y / TILE_SIZE) * COLUMNS) - COLUMNS];
}

int Enemy::GetTileRight(const std::vector<int> TileState)
{
    return TileState[(((int)GetPosition().x / TILE_SIZE) + ((int)GetPosition().y / TILE_SIZE) * COLUMNS) + 1];
}

int Enemy::GetTileLeft(const std::vector<int> TileState)
{
    return TileState[(((int)GetPosition().x / TILE_SIZE) + ((int)GetPosition().y / TILE_SIZE) * COLUMNS) - 1];
}

bool Enemy::IsInTheMiddleOfTheTile(const std::vector<int> TileState)
{
    bool x,y;
    x = (int)GetPosition().x % TILE_SIZE > (TILE_SIZE / 2) - 5 && (int)GetPosition().x% TILE_SIZE < (TILE_SIZE / 2) + 5 ;
    y = (int)GetPosition().y % TILE_SIZE > (TILE_SIZE / 2) - 5 && (int)GetPosition().y% TILE_SIZE < (TILE_SIZE / 2) + 5 ;


    return x and y;
}

bool Enemy::IsOnCrossroad(const std::vector<int> TileState)
{
    if(pDest==UP)
        if(GetTileUp(TileState)!=ROAD && GetTileUp(TileState)!=CASTLE)
            return true;

    if(pDest==DOWN)
        if(GetTileDown(TileState)!=ROAD && GetTileDown(TileState)!=CASTLE)
            return true;

    if(pDest==LEFT)
        if(GetTileLeft(TileState)!=ROAD && GetTileLeft(TileState)!=CASTLE)
            return true;

    if(pDest==RIGHT)
        if(GetTileRight(TileState)!=ROAD && GetTileRight(TileState)!=CASTLE)
            return true;
    return false;
}

int Enemy::TurnAround()
{
    switch (pDest)
    {
    case RIGHT:
        return LEFT;
    case LEFT:
        return RIGHT;    
    case DOWN:
        return UP;
    default:
        return DOWN;
    }
}

void Enemy::SetDest(const std::vector<int> TileState)
{
    if(IsOnCrossroad(TileState) && IsInTheMiddleOfTheTile(TileState))
    {
        int oldpDest = pDest;
        if((GetTileRight(TileState)==ROAD || GetTileRight(TileState)==CASTLE) && oldpDest!=LEFT)
            pDest=RIGHT;
        else if((GetTileUp(TileState)==ROAD || GetTileUp(TileState)==CASTLE) && oldpDest!=DOWN)
            pDest=UP;
        else if((GetTileLeft(TileState)==ROAD || GetTileLeft(TileState)==CASTLE) && oldpDest!=RIGHT)
            pDest=LEFT;
        else if((GetTileDown(TileState)==ROAD || GetTileDown(TileState)==CASTLE) && oldpDest!=UP)
            pDest=DOWN;
        else 
            pDest=TurnAround();
   }  
}


void Enemy::Fly(const std::vector<int> TileState, const float parSpeed, const collision::Vec2 playerPosition, const int GameSpeed)
{
    float x = playerPosition.x+25 - GetPosition().x;
    float y = playerPosition.y+25 - GetPosition().y;

    if(x==0)
    {
        if(y>0)
            pAngle=90;
        else
            pAngle=-90;
    }
    else
    {
        pAngle = atan(y/x);
    }
    
    if(playerPosition.x<pPos.x)
        pAngle+=PI;

    float newX = cos(pAngle) * parSpeed*GameSpeed;
    float newY = sin(pAngle) * parSpeed*GameSpeed;
    collision::Vec2 movement = {newX,newY};
    SetPosition(GetPosition()+movement);


}

void Enemy::Move(const std::vector<int> TileState, const float parSpeed, const int GameSpeed)
{
    SetDest(TileState);
    float x; float y;
    switch(pDest)
    {
        case (RIGHT) :
            x=GetPosition().x + parSpeed * GameSpeed;
            y=GetPosition().y;
            break; 
        case (UP) :
            x=GetPosition().x;
            y=GetPosition().y - parSpeed * GameSpeed;
            break; 
        case (DOWN) :
            x=GetPosition().x;
            y=GetPosition().y + parSpeed * GameSpeed;
            break; 
        case (LEFT) :
            x=GetPosition().x - parSpeed * GameSpeed;
            y=GetPosition().y;
            break; 
    }

    SetPosition({x,y});
}

void Enemy::TakeDamage(const int damage)
{
    life-=damage;
    DrawCircle(GetPosition().x,GetPosition().y,10,WHITE);
}

bool Enemy::CastleReached(const std::vector<int> TileState)
{
    if(GetTile(TileState)==CASTLE)
        return true;
    return false;
}


void Enemy::Update(const std::vector<int> TileState, const collision::Vec2 playerPosition, const int GameSpeed)
{
    if(life>0)
    {
        if(freezingTimer>0)
        {
            freezingTimer-=GetFrameTime();
            if(type==PLANE)
                Fly(TileState,slowedSpeed,playerPosition, GameSpeed);
            else
                Move(TileState,slowedSpeed, GameSpeed);  
        }
        else
        {
            if(type==PLANE)
                Fly(TileState,speed,playerPosition, GameSpeed);
            else
                Move(TileState,speed, GameSpeed);  
        }

        if(poisonTimer>0)
        {
            poisonTimer-=GetFrameTime();
            
            if(poisonAttackSpeed<0)
            {
                life-=poisonPower;
                poisonAttackSpeed=0.5f;
            }
            else
            {
                poisonAttackSpeed-=GetFrameTime();
            }
        }
        Draw(playerPosition);   
    }
    else
    {
        Draw(playerPosition);
        SetPosition({-100,-100});
    }
}

void Enemy::Draw(const collision::Vec2 playerPosition)
{
    DrawText(TextFormat("%d", life), GetPosition().x - 5, GetPosition().y -30, 7, poisonTimer > 0 ? GREEN : WHITE);

    if(type == WEAK)
        pCurrentFrame = 15;
    else if (type == MEDIC)
        pCurrentFrame = 16;
    else if (type == BRUTE)
        pCurrentFrame = 17;
    else if (type == LEADER)
        pCurrentFrame = 18;
    else if (type == RUNNER)
    {
        pCurrentFrame = 15;
        pCurrentLine = 8;
    }

    else if (type == TANK)
    {
        pCurrentLine=11;
        pCurrentFrame = 15;
    }
    else if (type == PLANE)
    {
        pCurrentLine=11;
        pCurrentFrame = 17;
    }

    
    if(type!=PLANE)
    {
        if (pDest == 0)
            pAngle = 0;
        else if(pDest == 1)
            pAngle = -90;
        else if(pDest == 2)
            pAngle = 90;
        else if(pDest == 3)
            pAngle = 180;
    }
    else   
        pAngle*=57.2958;

    if (freezingTimer > 0)
    {
        DrawAssetTexture(pCurrentFrame, pCurrentLine, GetPosition().x, GetPosition().y, pAngle/57.2958, 1.0f, SKYBLUE);
        if(type==TANK)
            DrawAssetTexture(pCurrentFrame, pCurrentLine+1, GetPosition().x, GetPosition().y, pAngle/57.2958, 1.0f, SKYBLUE);
    }
    else
    {
        DrawAssetTexture(pCurrentFrame, pCurrentLine, GetPosition().x, GetPosition().y, pAngle/57.2958, 1.0f, WHITE);
        if(type==TANK)
            DrawAssetTexture(pCurrentFrame, pCurrentLine+1, GetPosition().x, GetPosition().y, pAngle/57.2958, 1.0f, WHITE);
    }
    


}
