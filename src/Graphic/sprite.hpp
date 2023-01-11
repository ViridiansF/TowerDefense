#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include "../system/data.hpp"
#include "../system/myMathLib.hpp"



class Sprite
{
private:
    collision::Box mSource;
    Texture2D mTexture;
    collision::Vec2 mOrigin;
    float mRotation = 0;
    void DrawSprite(collision::Box box,Texture2D& tileSet);

public:    
    Sprite(const collision::Vec2 tilePos, const Texture2D _texture, const collision::Vec2 tileSize);
    Sprite(const collision::Vec2 tilePos, const Texture2D _texture, const collision::Vec2 tileSize, const collision::Vec2 _origin);
};