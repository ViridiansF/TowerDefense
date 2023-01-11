#pragma once
#include "../system/myMathLib.hpp"

#include "../system/data.hpp"

class Button
{
    private:
        collision::Box mBox;
        std::string mText;
        Color mColor;

        Color mTextColor;
        collision::Vec2 mTextPosition={0,0};
        float mTextSize=20;

    public:
        collision::Box& GetBox(){return mBox;}
        std::string& GetText(){return mText;}
        Color& GetColor(){return mColor;}
        Color& GetTextColor(){return mTextColor;}
        collision::Vec2& GetTextPosition(){return mTextPosition;}
        float& GetTextSize(){return mTextSize;}

        void SetBox(collision::Box parBox){parBox=mBox;}
        void SetColor(Color parColor){parColor=mColor;}
        void SetTextColor(Color parTextColor){parTextColor=mTextColor;}
        void SetText(std::string parText){parText=mText;}
        void SetTextPosition(collision::Vec2 parTextPosition){mTextPosition=parTextPosition;}
        void SetTextSize(float parTextSize){mTextSize=parTextSize;}

        Button(){}
        Button(collision::Box parBox, std::string parText, Color parColor,Color parTextColor,collision::Vec2 parTextPosition,float parTextSize);
        Button(Color parColor, int x, int y, int Width, int Height);

        bool IsClicked();
        bool IsPressed();
        void Draw();
        bool IsMouseOn(int x, int y);


};