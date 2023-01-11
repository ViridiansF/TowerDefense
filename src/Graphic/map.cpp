#include "map.hpp"

Map::Map()
{
    mTiles=
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm"
    "mmmmmmmmmmmmmmmmmmmmmmmmmm";
}

Map::Map(const std::string level)
{
    mTiles=level;
}

void Map::SetTile(int position,TileChar tileCode)
{
    mTiles[position]=tileCode;
}

void Map::SetTile(collision::Vec2 position,TileChar tileCode)
{
    int x=(int)position.x/50;
    int y=(int)position.y/50;
    mTiles[x+y*width] = tileCode;
}

void Map::Draw()
{
    for (int i = 0; i < COLUMNS * LINES; i++)
    {
        if (mTiles[i] == 'm')
            DrawAssetTexture(6, 1, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'r')
            DrawAssetTexture(1, 4, ( i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'g')
            DrawAssetTexture(14, 5, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'a')
            DrawAssetTexture(2, 3, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'b')
            DrawAssetTexture(2, 5, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'c')
            DrawAssetTexture(0, 3, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'd')
            DrawAssetTexture(0, 5, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'v')
            DrawAssetTexture(0, 4, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'w')
            DrawAssetTexture(2, 4, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'x')
            DrawAssetTexture(1, 3, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'y')
            DrawAssetTexture(1, 5, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'e')
            DrawAssetTexture(3, 3, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'f')
            DrawAssetTexture(4, 3, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'j')
            DrawAssetTexture(3, 4, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'k')
            DrawAssetTexture(4, 4, (i % 26 * TILE_SIZE + TILE_SIZE / 2), (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 0.80f,WHITE);
        else if (mTiles[i] == 'p')
            DrawAssetTexture(18,7, (i % 26 * TILE_SIZE + TILE_SIZE / 2)+4, (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 1,WHITE);
        else if (mTiles[i] == 's')
            DrawAssetTexture(16,7, (i % 26 * TILE_SIZE + TILE_SIZE / 2)+1, (i / 26 * TILE_SIZE + TILE_SIZE / 2), 0, 1,WHITE);
    }
}
