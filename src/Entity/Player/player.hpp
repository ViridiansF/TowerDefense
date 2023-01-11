#pragma once
#include "../entity.hpp"
#include "../../Graphic/drawAsset.hpp"

class Player : public Entity
{

    public:
        int maxLife = 20;
        int life=maxLife;
        int money=0;

        Player(){SetPosition({0,0});}

        Player(const int x, const int y){SetPosition({x*50,y*50});}

        int GetMaxLife(){return maxLife;}
        int& GetLife(){return life;}
        int& GetMoney(){return money;}

        void SetLife(const int parLife){life=parLife;}
        void SetMoney(const int parMoney){money=parMoney;}

        void Draw(const Texture2D TilesSet);
};