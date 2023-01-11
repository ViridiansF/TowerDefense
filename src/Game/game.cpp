
#include <filesystem>

#include "game.hpp"

Game::Game()
{

    UpdateLevelVector();
    mGameState = NOT_STARTED;

    mTextureTower = TextureTower();
    mEditor.newMap = Map();
}

Game::~Game()
{
}

void Game::TitleScreen()
{ 
    DrawTitleScreen(mDecalTower, mDecalEnemy, mDecal);
    
    if (mPlayButton.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = LEVEL_SELECTION;
    }
    
    else if (mOptionButton.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = OPTION;
    }
    
    else if(mCreditButton.IsClicked())
        mGameState = CREDIT;

    
    else if(mMapeditorButton.IsClicked())
        mGameState = MAP_EDITOR;

    else if(mEasterEggButton.IsClicked())
    {
        std::cout << "easter egg" << std::endl;    
    }
}


void Game::Victory()
{

    DrawVictory(mCurrentLevel);
      
    if (mOuiButton.IsClicked())
    {
        mPreviousGameState = mGameState;
        Restart();
        mGameState = RUNNING;
    }
    
    if (mNonButton.IsClicked())
    {   
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }
}

void Game::GameOver()
{
    DrawGameOver(mCurrentLevel);
      
    if (mOuiButton.IsClicked())
    {
        mPreviousGameState = mGameState;
        Restart();
        mGameState = RUNNING;
    }
    
    if (mNonButton.IsClicked())
    {   
        Restart();
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }
    
}

void Game::LevelSelection()
{
    DrawLevelSelection();

    int k=0;int j=0;
    for(int i=0;i<(int)mLevelButton.size();i++)
    {
        if(k>12)
        {
            j++;
            k=0;
        }

        mLevelButton.at(i)->Draw();
        DrawRectangleLinesEx({10, 120 + (float)60*i, 150, 50}, 3, BLACK);
        
        DrawText(TextFormat("%s",mLevels[i]->GetMap().name.c_str()),30+250*j,135+k*60,20,BLACK);

        if(mLevelButton.at(i)->IsClicked())
        {
            mCurrentLevel=i;
            mGameState=ANIMATION_1;
        }
     
        k++;
    }
    
    if (mCroix2Button.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }   
   

}

void Game::RunningGame()
{   
    GetCurrentLevel().GetMap().Draw();

    DrawRunningGame();

    // King Draw
    if (GetCurrentLevel().player.GetLife() >= GetCurrentLevel().player.GetMaxLife() / 2)
        DrawTexturePro(gRes->King, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {132, 100, (float)gRes->King.width / 2, (float)gRes->King.height / 2}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    else 
        DrawTexturePro(gRes->KingFear, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {132, 100, (float)gRes->King.width / 2, (float)gRes->King.height / 2}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    DrawRectangleLinesEx({132 - (float)gRes->King.width / 2, 100 - (float)gRes->King.height / 2, (float)gRes->King.width / 2, (float)gRes->King.height / 2}, 3, BLACK);

    // Pause button
    if (mPauseButton.IsClicked())
    {   
        mPreviousGameState = mGameState;
        mGameState = PAUSED;
    }
    if (mPauseButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Permet de mettre le jeu en pause",80, SCREEN_HEIGHT - 70,40,BLACK);     
    }

    // Option button
    if (mOption2Button.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = OPTION;
    }
    if (mOption2Button.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Permet d'aller dans les options",80, SCREEN_HEIGHT - 70,40,BLACK);     
    }

    // Menu button
    if (mCroixButton.IsClicked())
    { 
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }
    if (mCroixButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Permet de retourner au menu",80, SCREEN_HEIGHT - 70,40,BLACK);     
    }

    // Acceleration button
    if (mAccelerationButton.IsClicked())
    {
        if(GetCurrentLevel().GetSpeed() < 4)
        {    
            GetCurrentLevel().GetSpeed()++;
        }
    }
    if (mAccelerationButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Augmente la vitesse de jeu (jusqu'a x4)",80, SCREEN_HEIGHT - 60,30,BLACK);     
    }

    // Deceleration button
    if (mDecelerationButton.IsClicked())
    {
        if(GetCurrentLevel().GetSpeed() > 1)
        {
            GetCurrentLevel().GetSpeed()--;
        }
    }
    if (mDecelerationButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Reduit la vitesse de jeu (jusqu'a x1)",80, SCREEN_HEIGHT - 60,30,BLACK);     
    }

    
    DrawText(TextFormat("x%d", GetCurrentLevel().GetSpeed()), 1250, 15, 40, BLACK);
    //============================================================================//


    // Basic tower button
    mTextureTower.DrawBasicTower(1340, 200, GetCurrentLevel().player.money >= CLASSIC_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", CLASSIC_COST), 1380, 192, 20, BLACK);
    if (mBasicTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = CLASSIC;
    }
    if (mBasicTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Classique : Prix : 100, Dégâts : Moyens, Cadence : Moyenne, Effet : Aucun.",80,SCREEN_HEIGHT-50,20,BLACK);
    }

    // Explosive tower button
    mTextureTower.DrawExplosiveTower(1338, 290, GetCurrentLevel().player.money >= EXPLOSIVE_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", EXPLOSIVE_COST), 1380, 282, 20, BLACK);
    if (mExplosiveTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = EXPLOSIVE;
    }
    if (mExplosiveTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Lance-Missiles : Prix : 300, Dégâts : Elevés, Cadence : Faible, Effet : Explosion.",80,SCREEN_HEIGHT-50,20,BLACK);     
    }

    // Freezing tower button
    mTextureTower.DrawFreezingTower(1340, 385, GetCurrentLevel().player.money >= FREEZING_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", FREEZING_COST), 1380, 377, 20, BLACK);
    if (mFreezingTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = FREEZING;
    }
    if (mFreezingTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Cryogénique : Prix : 50, Dégâts : Faibles, Cadence : Moyenne, Effet : Ralentissement.",80,SCREEN_HEIGHT-50,20,BLACK);     
    }

    // Poison tower button
    mTextureTower.DrawPoisonTower(1340, 110, GetCurrentLevel().player.money >= POISON_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", POISON_COST), 1380, 102, 20, BLACK);
    if (mPoisonTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = POISON;
    }
    if (mPoisonTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Empoisonnante : Prix : 300, Dégâts : Nuls, Cadence : Faible, Effet : EmpoimSonnement.",80,SCREEN_HEIGHT-50,20,BLACK);     
    }

    // Shotgun tower button
    mTextureTower.DrawShotgunTower(1340, 475, GetCurrentLevel().player.money >= SHOTGUN_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", SHOTGUN_COST), 1380, 467, 20, BLACK);
    if (mShotgunTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = SHOTGUN;
    }
    if (mShotgunTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Shotgun : Prix : 300, Dégâts : Enormes, Cadence : Tres Faible, Effet : Aucun.",80,SCREEN_HEIGHT-50,20,BLACK);     
    }

    // Combo tower button
    mTextureTower.DrawComboTower(1340, 565, GetCurrentLevel().player.money >= COMBO_COST ? WHITE : GRAY);
    DrawText(TextFormat("%d", COMBO_COST), 1380, 557, 20, BLACK);
    if (mComboTowerButton.IsClicked())
    {
        GetCurrentLevel().selectedType = COMBO;
    }
    if (mComboTowerButton.IsMouseOn(GetMouseX(), GetMouseY()))
    {
        DrawText("Tourelle Combo : Prix : 500, Dégâts : Nuls, Cadence : Moyenne, Effet : Combo.",80,SCREEN_HEIGHT-50,20,BLACK);     
    }

    GetCurrentLevel().Update(GetCurrentLevel().GetSpeed());

    if (GetCurrentLevel().GameIsOver())
    {
        mPreviousGameState = mGameState;
        mGameState = GAMEOVER;
    }
    else if(GetCurrentLevel().LevelIsWon())
    {
        if(mCurrentLevel+1==(int)mLevels.size())
        {
            mPreviousGameState = mGameState;
            mGameState = VICTORY;
        }
        else
        {
            mCurrentLevel++;
            mPreviousGameState = mGameState;
            mGameState = ANIMATION_2;
        }
    
    }
}

void Game::PauseMenu()
{
    
    DrawPause();
    
    // Resume button
    if (mResumeButton.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = RUNNING;
    }
    
    // Restart button
    if (mRestartButton.IsClicked())
    {
        mGameState = RUNNING;
        Restart();
    }
    
    // Exit button
    if (mExitButton.IsClicked())
    {    
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }
}


void Game::OptionMenu()
{   
    DrawOption();

    // Sound buttons
    if (mCutSoundButton.IsClicked())
    {
        if (mInPause == false)
        {
            mInPause = true;
            PauseMusicStream(gRes->music);
            MySetVolume(0);
        }
        else
        {
            mInPause = false;
            ResumeMusicStream(gRes->music);
            MySetVolume(0.5f);
        }
    }
    if (mInPause == false)
    {
        DrawTexture(gRes->SoundOn, 395, 290, WHITE);
    }
    else
    {
        DrawTexture(gRes->SoundOff, 395, 290, WHITE);
    }

    mTestButton.Draw();
    DrawText(TextFormat("%d", mSon), 725, 275, 20, BLACK);
    if (GetMouseX() >= 500 && GetMouseX() <= 1000)
    {
        int x = GetMouseX() - 25;
        if (mTestButton.IsPressed())
        {
            mColor = BLUE;
            mTestButton = Button(mColor, x, 300, 50, 50);
            mX2 = x;
            mSon = ((GetMouseX() - 500) / 5);
            pitch = 0.01f * ((GetMouseX() - 500) / 5);
            SetMusicVolume(gRes->music, pitch);
            MySetVolume(pitch);
        }
        else
        {
            mColor = RED;
            mTestButton = Button(mColor, mX2, 300, 50, 50);
        }
    }

    // Option button
    if (mCroix2Button.IsClicked())
    {
        if (mPreviousGameState == RUNNING)
        {
            mPreviousGameState = mGameState;
            mGameState = RUNNING;
        }
        else if (mPreviousGameState == NOT_STARTED)
        {
            mPreviousGameState = mGameState;
            mGameState = NOT_STARTED;
        }
    }
}

void Game::CreditMenu()
{   
    DrawCredit();
    if (mCroix2Button.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
    }
}

void Game::Animation(int nb)
{
    // Show the animation for the game's beginning
    if (nb == 1)
    {
        DrawAnimation1();
        DrawText("Le château est en grand danger !", 450, 255, 30, BLACK);
        if (GetCurrentLevel().GetMaxWave() == 1)
            DrawText(TextFormat("%d vague approche !", GetCurrentLevel().GetMaxWave()), 550, 325, 30, BLACK);
        else if (GetCurrentLevel().GetMaxWave() > 1)
            DrawText(TextFormat("%d vagues approchent!", GetCurrentLevel().GetMaxWave()), 550, 325, 30, BLACK);
        DrawText(TextFormat("Vous avez %.f secondes pour", GetCurrentLevel().GetRecovery()), 490, 395, 30, BLACK);
        DrawText("preparer nos défenses !", 520, 455, 30, BLACK);
        mAnimationTimer++;
        if(mAnimationTimer / 60 >= 5 || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            mAnimationTimer = 0;
            mPreviousGameState = mGameState;
            mGameState = RUNNING;
        }
    }
    
    // Show the animation between levels
    else if (nb == 2)
    {
        DrawAnimation2();
        DrawText(TextFormat("Bien ! Vous avez passé le niveau %d", mCurrentLevel), 440, 255, 30, BLACK);
        if (GetCurrentLevel().GetMaxWave() > 1)
            DrawText(TextFormat("%d nouvelles vagues arrivent!", GetCurrentLevel().GetMaxWave()), 500, 325, 30, BLACK);
        else
            DrawText(TextFormat("%d nouvelle vague arrive !", GetCurrentLevel().GetMaxWave()), 500, 325, 30, BLACK);
        DrawText(TextFormat("Vous avez %.f secondes pour", GetCurrentLevel().GetRecovery()), 480, 395, 30, BLACK);
        DrawText("preparer nos défenses !", 510, 455, 30, BLACK);
        mAnimationTimer++;
        if(mAnimationTimer / 60 >= 5 || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            mAnimationTimer = 0;
            mPreviousGameState = mGameState;
            mGameState = RUNNING;
        } 
    }
        
}

void Game::ClearLevelsVector()
{
    while((int)mLevels.size()>0)
        mLevels.pop_back();

    while((int)mLevelButton.size()>0)
        mLevelButton.pop_back();
}

void Game::UpdateLevelVector()
{   
    ClearLevelsVector();
    
    int i=0,j=0;
    std::string levelLoaded,levelInfo;
    for (const auto & entry : std::filesystem::directory_iterator("assets/levels"))
    {    
        Map* map= new Map();
        int startingmoney, maxEnemyByWave;
        map->name=entry.path().string();
        map->name.erase(0,14);

        i++;


        levelLoaded = entry.path().string();
        std::ifstream levelFile(levelLoaded);

        getline (levelFile, levelInfo);
        map->SetMap(levelInfo);

        getline (levelFile, levelInfo);
        sscanf(levelInfo.c_str(), "%d", &startingmoney);

        getline (levelFile, levelInfo);
        sscanf(levelInfo.c_str(), "%d", &maxEnemyByWave);

        levelFile.close();
        mLevels.push_back(new Level(*map,startingmoney,maxEnemyByWave));
    }

    int k=0;
    for(int i=0;i<(int)mLevels.size();i++)
    {
        if(k>12)
        {
            k=0;
            j++;
        }
        mLevelButton.push_back(new Button(YELLOW,10+250*j,120+60*k,150,50));
        k++;
    }
}

void Game::MapEditorMenu()
{
    mEditor.LevelCreation(); 
    DrawTexture(gRes->CroixButton2, 1380, 10, WHITE);
    if (mCroix2Button.IsClicked())
    {
        mPreviousGameState = mGameState;
        mGameState = NOT_STARTED;
        UpdateLevelVector();    
    }   
}

void Game::GameLoop()
{
    // Manage all state of the game
    switch (mGameState)
    {
    case RUNNING:
        RunningGame();
        break;
    case NOT_STARTED:
        TitleScreen();
        break;
    case MAP_EDITOR:
        MapEditorMenu();
        break;
    case LEVEL_SELECTION:
        LevelSelection();
        break;
    case PAUSED:
        PauseMenu();
        break;
    case OPTION:
        OptionMenu();
        break;
    case CREDIT:
        CreditMenu();
        break;
    case VICTORY:
        Victory();
        break;
    case ANIMATION_1:
        Animation(1);
        break;
    case ANIMATION_2:
        Animation(2);
        break;
    default:
        GameOver();
        break;
    }
}

void Game::Restart()
{
    // Delete all pointers and restart the game
    for (long unsigned int i = 0; i < mLevels.size(); i++)
    {
        mLevels[i]->GetSpawnEnemiesInGameSpace().clear();
        mLevels[i]->GetTowerInGameSpace().clear();
        mLevels[i]->GetEffectsInGameSpace().clear();
    }
    mLevels.clear();

    UpdateLevelVector();
}    
