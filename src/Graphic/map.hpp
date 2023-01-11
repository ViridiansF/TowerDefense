#pragma once
#include "../system/data.hpp"
#include "../Entity/entity.hpp"
#include "../Graphic/drawAsset.hpp"

enum TileType
{
    MOUNTAIN,
    ROAD,
    GRASS,
    CASTLE,
    SPAWN,
};


enum TileChar
{
    CHAR_MOUNTAIN='m',
    CHAR_ROAD='r',
    CHAR_GRASS='g',
    CHAR_CASTLE='p',
    CHAR_SPAWN='s',
};



class Map
{
private:
    std::string mTiles;
    Texture2D mTileSet;

public:
    int width=26;
    int height=16;
    std::string name="Niveau01";

    Map();
    Map(const std::string level);
    
    Texture2D GetTileSet() const { return mTileSet;}
    const char* GetTiles() const { return mTiles.c_str(); }
    char GetTileAt(int i) const { return mTiles[i]; }

    void SetMap(std::string newMap){ mTiles = newMap;}
    void SetTile(collision::Vec2,TileChar tileCode);
    void SetTile(int position,TileChar tileCode);
    
    void Draw();

};

