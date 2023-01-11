#include "sprite.hpp"


Sprite::Sprite(const collision::Vec2 tilePos,const Texture2D _texture, const collision::Vec2 tileSize)
{
    collision::Vec2 spriteSize = collision::Vec2{(float)_texture.width/ tileSize.x,
        (float)_texture.height / tileSize.y};
    mSource = collision::Box(tilePos.x * spriteSize.x,
        tilePos.y * spriteSize.y, spriteSize.x, spriteSize.y    );
    mTexture = _texture;
}

Sprite::Sprite(const collision::Vec2 tilePos,const Texture2D _texture, const collision::Vec2 tileSize, const collision::Vec2 _origin)
{
    collision::Vec2 spriteSize = collision::Vec2{(float)_texture.width/ tileSize.x,
        (float)_texture.height / tileSize.y};
    mSource = collision::Box(tilePos.x * spriteSize.x,
        tilePos.y * spriteSize.y, spriteSize.x, spriteSize.y);
    mTexture = _texture;
    mOrigin = _origin;
};
    
void Sprite::DrawSprite(collision::Box box, Texture2D& tileSet)
{
    DrawTexturePro(tileSet, mSource.toRec(), box.toRec(), mOrigin.toVector2(), mRotation, WHITE) ;
}