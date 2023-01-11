#include "button.hpp"

Button::Button(Color parColor, int x, int y, int Width, int Height)
{
    collision::Vec2 Pmin = {x, y};
    collision::Vec2 Pmax = {x + Width, y + Height};
    collision::Box parBox = collision::Box(Pmin, Pmax);
    mBox=parBox;mColor=parColor;
}

Button::Button(collision::Box parBox, std::string parText, Color parColor,Color parTextColor,collision::Vec2 parTextPosition,float parTextSize)
{
    mBox=parBox;
    mText=parText;
    mColor=parColor;
    mTextColor=parTextColor;
    mTextPosition=parTextPosition;
    mTextSize=parTextSize;
}

void Button::Draw()
{
    DrawRectanglePro(mBox.toRec(),{0,0},0,mColor);
    DrawText(mText.c_str(),mTextPosition.x,mTextPosition.y,mTextSize,mTextColor);
}

bool Button::IsClicked()
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        
        Vector2 posMouse = GetMousePosition();
        if( (posMouse.x>=mBox.min.x && posMouse.x<=mBox.max.x) 
            &&
            posMouse.y>=mBox.min.y && posMouse.y<=mBox.max.y )
        {
            return true;
        }
    }
    return false;
}

bool Button::IsPressed()
{
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        
        Vector2 posMouse = GetMousePosition();
        if( (posMouse.x>=mBox.min.x && posMouse.x<=mBox.max.x) 
            &&
            posMouse.y>=mBox.min.y && posMouse.y<=mBox.max.y )
        {
            return true;
        }
    }
    return false;
}

bool Button::IsMouseOn(int x, int y)
{
    if (x > mBox.min.x && x < mBox.max.x && y > mBox.min.y && y < mBox.max.y)
        return true;
    return false;
}