#pragma once

#include "../Graphic/map.hpp"
#include "../Graphic/drawAsset.hpp"
#include "../UI/button.hpp"

#include <fstream>
#include <string>
#include <iostream>

#define MAX_LETTER_COUNT 20




class MapEditor
{

    private:
        //Editing
        Button mGrassButton = Button(YELLOW, 1315, 175, 50, 50);
        Button mRoadButton = Button(YELLOW, 1315, 230, 50, 50);
        Button mMountainButton = Button(YELLOW, 1315, 285, 50, 50);
        Button mSpawnButton = Button(RED, 1315, 285+55, 50, 50);
        Button mCastleButton = Button(YELLOW, 1315, 285+110, 50, 50);

        //Options
        Button mHelpButton = Button(SKYBLUE, 1325, SCREEN_HEIGHT-45, 100, 30);
        Button mMenuButton = Button(SKYBLUE, 1325, SCREEN_HEIGHT-80, 100, 30);

        //Menu
        Button mBackButton = Button(RED, 1365-100, 20, 50, 50);
        Button mSaveButton = Button(SKYBLUE, 800, 340, 145, 40);
        Button mLoadButton = Button(SKYBLUE, 850, 390, 100, 40);

        //Starting Money
        Button mPlusMoneyButton = Button(GREEN, 180, SCREEN_HEIGHT-60, 50, 50);
        Button mMinusMoneyButton = Button(RED, 50, SCREEN_HEIGHT-60, 50, 50);

        //Max Enemy By Wave
        Button mPlusEnemyButton = Button(GREEN, 550, SCREEN_HEIGHT-60, 50, 50);
        Button mMinusEnemyButton = Button(RED, 450, SCREEN_HEIGHT-60, 50, 50);

        void DrawBottomPanel();
        void DrawRightPanel();
        void DrawLevelPanel();
        void ChangeTile(collision::Vec2 posMouse);
        bool MouseIsInGameSpace();
        collision::Vec2 GetTileOfMouse();
        void ChangeSelection();
        void SaveMap();
        void DrawOutlineOfSelectedTile();
        void SaveMenu();
        void HelpMenu();
        void LoadMap();

        void UpdateMaxEnemyByWave();
        void UpdateStartingMoney();

        bool mEditingStartingMoney=false;
        bool mEditingMaxEnemyByWave=false;
        bool mLevelIsSaved=false;
        bool mLevelIsLoaded=false;
        int mLetterCount=0;
        bool mSaving=false;
        bool mHelp=false;
        TileChar mSelectedTile=CHAR_GRASS;
        int mYSelectedTileOutline=-100;
        int mStartingMoney=300;
        int mMaxEnemyByWave=5;

    public:
        void LevelCreation();

        Map newMap;
};
