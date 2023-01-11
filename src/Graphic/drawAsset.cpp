#include <cmath>

#include "../Graphic/drawAsset.hpp"

int frameWidth, frameHeight;
Rectangle frameRec, destRec;
Vector2 center;

void DrawAssetTexture(const int currentFrame,const int currentLine,const int x,const int y,const float angle,const float taille,const Color color)
{

    frameWidth = gRes->mTileSet.width / 23;
    frameHeight = gRes->mTileSet.height / 13;

    frameRec = {1.0f, 1.0f, (float)frameWidth, (float)frameHeight};
    
    frameRec.x = currentFrame * frameWidth;
    frameRec.y = currentLine * frameHeight;

    destRec = {(float)x, (float)y, frameWidth * taille, frameHeight * taille};
    center = { std::floor(destRec.width / 2), std::floor(destRec.height / 2) };

    DrawTexturePro(gRes->mTileSet, frameRec, destRec, center, angle * 57.2958, color);
}


void TextureTower::DrawBasicTower(const int x,const int y,const Color color)
{

    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(19, 8, x, y, 0, 1.0f, color);
}

void TextureTower::DrawExplosiveTower(const int x,const int y,const Color color)
{
    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(22, 8, x, y, 0, 1.0f, color);
}

void TextureTower::DrawFreezingTower(const int x,const int y,const Color color)
{
    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(19, 10, x, y-13, 0, 1.0f, color);
}

void TextureTower::DrawPoisonTower(const int x,const int y,const Color color)
{
    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(15, 12, x, y, 0, 1.0f, color);
}

void TextureTower::DrawShotgunTower(const int x,const int y,const Color color)
{
    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(22, 9, x, y, 0, 1.0f, color);
}

void TextureTower::DrawComboTower(const int x,const int y,const Color color)
{
    DrawAssetTexture(19, 7, x, y, 0, 1.0f, color);

    DrawAssetTexture(16, 12, x, y, 0, 1.0f, color);
}
