#include "player.hpp"

void Player::Draw(const Texture2D TilesSet)
{
    DrawAssetTexture(18, 7, GetPosition().x + 29, GetPosition().y + 24, 0, 1.0f, WHITE); 
}