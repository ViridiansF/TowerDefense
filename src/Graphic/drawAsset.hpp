#pragma once
#include "../Entity/entity.hpp"


class TextureTower
{
public:

    TextureTower() {}


    void DrawBasicTower(const int x,const int y, const Color color);
    void DrawExplosiveTower(const int x, const int y,  const Color color);
    void DrawFreezingTower(const int x, const int y,  const Color color);
    void DrawPoisonTower(const int x, const int y,  const Color color);
    void DrawShotgunTower(const int x, const int y,  const Color color);
    void DrawComboTower(const int x, const int y,  const Color color);
};
void DrawAssetTexture(const int currentFrame, const int currentLine, const int x, const int y, const float angle, const float taille, const Color color);
