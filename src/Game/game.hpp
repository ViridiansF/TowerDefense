#pragma once

#include "../Entity/Tower/tower.hpp"
#include "../Graphic/map.hpp"
#include "../Entity/Player/player.hpp"
#include "../UI/button.hpp"
#include "level.hpp"
#include "../Graphic/drawAsset.hpp"
#include "../system/data.hpp"
#include "../Graphic/renderer.hpp"
#include "../Graphic/sound.hpp"
#include "../Graphic/resource.hpp"
#include "../MapEditor/mapEditor.hpp"


enum GameState
{
    NOT_STARTED,
    RUNNING,
    PAUSED,
    GAMEOVER,
    CREDIT,
    OPTION,
    VICTORY,
    ANIMATION_1,
    ANIMATION_2,
    MAP_EDITOR,
    LEVEL_SELECTION,
};

class Game 
{
private:
    GameState mGameState = NOT_STARTED;         // State of the game, dictates if the game is running or not
    GameState mPreviousGameState = NOT_STARTED; // Previous state of the game
    int mCurrentLevel=0;                        // Index of the level curently loaded
    std::vector<Level*> mLevels;                // Vector containing every level of the game
    TextureTower mTextureTower;
    MapEditor mEditor;
    int mAnimationTimer = 0;
    int mDecal = 0;
    int mDecalTower = 0;
    int mDecalEnemy = 0;

    std::vector<Button*> mLevelButton;

    bool mInPause = false;
    int mSon = 50;
    Color mColor = YELLOW;
    int mX2 = 725;

    //Button
    Button mTestButton = Button(YELLOW, 500, 300, 50, 50);
    Button mPlayButton = Button(YELLOW, 540, 270, 360, 70);
    Button mOptionButton = Button(YELLOW, 590, 380, 270, 60);
    Button mCreditButton = Button(YELLOW, 990, 380, 270, 60);
    Button mMapeditorButton = Button(YELLOW, 190, 380, 270, 60);
    Button mOuiButton = Button(YELLOW, 530, 750, 180, 100);    
    Button mNonButton = Button(YELLOW, 730, 750, 180, 100);

    Button mPauseButton = Button(YELLOW, 1255, 840, 40, 40);
    Button mOption2Button = Button(YELLOW, 1320, 840, 40, 40);
    Button mCroixButton = Button(YELLOW, 1385, 840, 40, 40);
    Button mCroix2Button = Button(YELLOW, 1382, 12, 40, 40);

    Button mPoisonTowerButton = Button(YELLOW, 1315, 85, 50, 50);
    Button mBasicTowerButton = Button(YELLOW, 1315, 175, 50, 50);
    Button mExplosiveTowerButton = Button(YELLOW, 1313, 265, 50, 50);
    Button mFreezingTowerButton = Button(YELLOW, 1315, 360, 50, 50);
    Button mShotgunTowerButton = Button(YELLOW, 1315, 450, 50, 50);
    Button mComboTowerButton = Button(YELLOW, 1315, 540, 50, 50);

    Button mResumeButton = Button(YELLOW, 600, 350, 250, 100);
    Button mRestartButton = Button(YELLOW, 600 ,470, 250, 100);
    Button mExitButton = Button(YELLOW, 600, 590, 250, 100);

    Button mCutSoundButton = Button(YELLOW, 397, 292, 70, 70);
    Button mDecelerationButton = Button(YELLOW, 1320, 10, 50, 50);
    Button mAccelerationButton = Button(YELLOW, 1390, 10, 50, 50);
    Button mEasterEggButton = Button(YELLOW, 100, 100, 50, 50);


    void TitleScreen();
    void GameOver();
    void RunningGame();
    void PauseMenu();
    void OptionMenu();
    void CreditMenu();
    void Victory();
    void Animation(int nb);
    void LevelSelection();
    void MapEditorMenu();

    void UpdateLevelVector();
    void ClearLevelsVector();

    void InitTower(collision::Vec2 pos);
    void Restart();

public:

    std::vector<Level*>& GetLevels(){return mLevels;}
    GameState& GetGamestate(){return mGameState;}
    Level& GetCurrentLevel(){return *mLevels.at(mCurrentLevel);}
    Texture2D GetTileSet(){return gRes->mTileSet;}

    void SetGamestate(const GameState parGameState){mGameState=parGameState;}
    void SetCurrentLevel(const int parLevel){mCurrentLevel=parLevel;}

    Game();
    ~Game();
    void GameLoop();

    float pitch = 1.0f;
};