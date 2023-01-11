#pragma once
#include "../Graphic/sprite.hpp"
#include "../Graphic/resource.hpp"


class Entity
{

protected:
    std::string pName="Entity";
    collision::Vec2 pPos;

    void Draw(collision::Box box);

public:
    Entity() {};
    Entity(const std::string name,const collision::Vec2 pos1);
    
    std::string& GetName(){return pName;}
    collision::Vec2& GetPosition(){return pPos;}

    void SetName(const std::string parName){pName=parName;}
    void SetPosition(const collision::Vec2 parPosition){pPos=parPosition;}

    
    virtual void Update(){};
};







