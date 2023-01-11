#include "mapEditor.hpp"


void MapEditor::DrawOutlineOfSelectedTile()
{

    int x=1315;
    int y=175;
        
    for(int i=0;i<3;i++)
    {
        DrawRectangleLines(x,y,50,50,BLACK);
        y+=55;
    }

    if(mGrassButton.IsPressed())
        mYSelectedTileOutline=175;
    else if(mRoadButton.IsPressed())
        mYSelectedTileOutline=230;  
    else if(mMountainButton.IsPressed())
        mYSelectedTileOutline=285;
    else if(mCastleButton.IsPressed())
        mYSelectedTileOutline=285+110;  
    else if(mSpawnButton.IsPressed())
        mYSelectedTileOutline=285+55;  

    DrawRectangleLines(x,mYSelectedTileOutline,50,50,YELLOW);
}

void MapEditor::DrawLevelPanel()
{
    newMap.Draw();

    for(int i=0;i<newMap.width;i++)
        DrawLine(i*TILE_SIZE,0,i*TILE_SIZE,SCREEN_HEIGHT-100,BLACK);
    for(int i=0;i<newMap.height;i++)
        DrawLine(0,i*TILE_SIZE,SCREEN_WIDTH-140,i*TILE_SIZE,BLACK);

}

void MapEditor::DrawRightPanel()
{



    DrawTexture(gRes->BgWood, 1300, 0, WHITE);
    DrawRectangle(1300, 0, 10, 900, DARKBROWN);

    mGrassButton.Draw();
    DrawAssetTexture(14, 5, 1315+25, 175+25, 0, 0.80f,WHITE);
    
    mRoadButton.Draw();
    DrawAssetTexture(1,4, 1315+25, 230+25, 0, 0.80f,WHITE);

    mMountainButton.Draw();
    DrawAssetTexture(6,1, 1315+25, 285+25, 0, 0.80f,WHITE);

    mSpawnButton.Draw();
    DrawAssetTexture(16,7, 1315+26, 285+80, 0, 1,WHITE);

    mCastleButton.Draw();
    DrawAssetTexture(18,7, 1315+29, 285+80+55, 0, 1,WHITE);

    DrawOutlineOfSelectedTile();


}


void MapEditor::DrawBottomPanel()
{

    
    DrawTexture(gRes->BgWood2, 0, 800, WHITE);
    DrawRectangle(0, 800, 1440, 10, DARKBROWN);

    mMenuButton.Draw();
    DrawText("Menu",1345, SCREEN_HEIGHT-75,20,BLACK);

    mHelpButton.Draw();
    DrawText("Aide",1345, SCREEN_HEIGHT-40,20,BLACK);

    DrawText("Fonds de départ :", 50,SCREEN_HEIGHT-85,20,BLACK);

    mPlusEnemyButton.Draw();
    mPlusMoneyButton.Draw();
    DrawTexture(gRes->Plus, 550, SCREEN_HEIGHT-55, WHITE);
    DrawTexture(gRes->Plus, 180, SCREEN_HEIGHT-55, WHITE);

    DrawText("Nombre d'ennemis par campement pour la première vague :",400,SCREEN_HEIGHT-85,20,BLACK);
    mMinusEnemyButton.Draw();
    mMinusMoneyButton.Draw();
    DrawTexture(gRes->Moins, 453, SCREEN_HEIGHT-60, WHITE);
    DrawTexture(gRes->Moins, 53, SCREEN_HEIGHT-60, WHITE);


    DrawText(TextFormat("%d",mStartingMoney),110,SCREEN_HEIGHT-50,30,BLACK);

    DrawText(TextFormat("%d",mMaxEnemyByWave),510,SCREEN_HEIGHT-50,30,BLACK);

}


collision::Vec2 MapEditor::GetTileOfMouse()
{
    collision::Vec2 posMouse = {GetMouseX(), GetMouseY()};
    int x=(int)posMouse.x/TILE_SIZE;
    int y=(int)posMouse.y/TILE_SIZE;
    return {x,y};
}

bool MapEditor::MouseIsInGameSpace()
{
    collision::Vec2 posMouse = {GetMouseX(), GetMouseY()};
    if(posMouse.x>SCREEN_WIDTH-140)
        return false;
    if(posMouse.y>SCREEN_HEIGHT-100)
        return false;
    return true;
}

void MapEditor::ChangeTile(collision::Vec2 posMouse)
{
    //printf("%c\n",newMap.GetTileAt(0));
    if(MouseIsInGameSpace() && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        //if there's already a castle it is replaced by a plain
        if(mSelectedTile==CHAR_CASTLE)
        {
            int i=0;
            while(newMap.GetTileAt(i)!=CHAR_CASTLE && i<newMap.height*newMap.width)
                i++;
            newMap.SetTile(i,CHAR_GRASS);
        }
        newMap.SetTile(posMouse,mSelectedTile);
    }
} 

void MapEditor::ChangeSelection()
{
    if(mGrassButton.IsClicked())
        mSelectedTile=CHAR_GRASS;
    else if(mRoadButton.IsClicked())
        mSelectedTile=CHAR_ROAD;  
    else if(mMountainButton.IsClicked())
        mSelectedTile=CHAR_MOUNTAIN;  
    else if(mCastleButton.IsClicked())
        mSelectedTile=CHAR_CASTLE;  
    else if(mSpawnButton.IsClicked())
        mSelectedTile=CHAR_SPAWN;  
}


void MapEditor::SaveMenu()
{
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height * 2, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);

    DrawRectangleRounded({370, 310, 700, 200}, 0.8, 5, YELLOW);
    DrawRectangleRoundedLines({370, 310, 700, 200}, 0.8, 5, 3, BLACK);



    if(mLevelIsLoaded)
        DrawText("Niveau chargé.",550,600,35,BLACK);
    if(mLevelIsSaved)
        DrawText("Niveau sauvegardé.",550,600,35,BLACK);


    mBackButton.Draw();

    mSaveButton.Draw();
    DrawText("Sauvegardez",805, 350,20,BLACK);

    mLoadButton.Draw();
    DrawText("Chargez",856, 400,20,BLACK);


    DrawText("Entrez le nom de votre niveau puis : ",SCREEN_WIDTH/2-300,SCREEN_HEIGHT/2-100,20,BLACK);
    DrawText("Entrez le nom du niveau à charger puis : ",SCREEN_WIDTH/2-300,SCREEN_HEIGHT/2-50,20,BLACK);
    DrawText("Les niveaux sont stockés dans \"assets/levels/\"",SCREEN_WIDTH/2-300,SCREEN_HEIGHT/2,20,BLACK);


    int key = GetKeyPressed();
    Rectangle textBox = { SCREEN_WIDTH/2.0f - 200, 180, 450, 50 };

    if(key==KEY_BACKSPACE)
    {
        if(mLetterCount>0)
            mLetterCount--;
        newMap.name[mLetterCount]='\0';
    }
    else
    {
        key=GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (mLetterCount < MAX_LETTER_COUNT))
            {
                newMap.name[mLetterCount] = (char)key;
                newMap.name[mLetterCount+1] = '\0'; 
                mLetterCount++;
            }
            key = GetCharPressed(); 
        }
    }

    if(mBackButton.IsClicked())
    {
        mSaving=false;
        mLevelIsLoaded=false;
        mLevelIsSaved=false;
    }
    else if(mSaveButton.IsClicked())
    {
        SaveMap();
    }
    else if(mLoadButton.IsClicked())
    {
        LoadMap();
    }


    DrawRectangleRec(textBox, LIGHTGRAY);
    DrawText(newMap.name.c_str(), (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

}


void MapEditor::LoadMap()
{
    
    std::string levelInfo;
    std::string levelLoaded = "assets/levels/";
    levelLoaded.append(newMap.name);

    std::ifstream levelFile(levelLoaded);

    getline (levelFile, levelInfo);
    newMap.SetMap(levelInfo);

    getline (levelFile, levelInfo);
    sscanf(levelInfo.c_str(), "%d", &mStartingMoney);

    getline (levelFile, levelInfo);
    sscanf(levelInfo.c_str(), "%d", &mMaxEnemyByWave);

    levelFile.close();
    mLevelIsLoaded=true;
    mLevelIsSaved=false;

}



void MapEditor::SaveMap()
{
    std::string level = newMap.GetTiles();

    std::string outputLocation="assets/levels/";
    outputLocation.append(newMap.name);

    std::ofstream out(outputLocation, std::ios_base::binary);
    out << level << std::endl;
    out << mStartingMoney << std::endl;
    out << mMaxEnemyByWave << std::endl;
    out.close();

    mLevelIsLoaded=false;
    mLevelIsSaved=true;
}

void MapEditor::HelpMenu()
{
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height * 2, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);


    DrawText("Voici quelques conseils pour éviter tout problèmes avec vos niveaux:",50,50,30,BLACK);   

    DrawText("- Les ennemis ne changent de direction que s'ils se trouvent face à un obstacle. ",50,100,20,BLACK);   
    DrawText("- Plus vous ajoutez de camps moins le nombre d'ennemis par camp devrait être élevé.",50,150,20,BLACK);   
    DrawText("- Le nombre de vagues par niveau et les probabilités d'apparitions des ennemis en foncitons des vagues ne peuvent être changés",50,200,20,BLACK);   

    mBackButton.Draw();
    if(mBackButton.IsClicked())
        mHelp=false;

}

void MapEditor::LevelCreation()
{
    if(mSaving)
    {
        SaveMenu();
    }
    else if(mHelp)
    {
        HelpMenu();
    }
    else
    {
        DrawRightPanel();
        DrawLevelPanel();
        DrawBottomPanel();
        
        ChangeSelection();

        collision::Vec2 posMouse = {GetMousePosition()};

        ChangeTile(posMouse);


        if(mMenuButton.IsClicked())
            mSaving=true;
        if(mHelpButton.IsClicked())
            mHelp=true;


        UpdateStartingMoney();
        UpdateMaxEnemyByWave();

    }
 


}

void MapEditor::UpdateMaxEnemyByWave()
{
    if(mPlusMoneyButton.IsClicked() && mStartingMoney < 5000)
        mStartingMoney+=50;
    else if(mMinusMoneyButton.IsClicked() && mStartingMoney > 0)
        mStartingMoney-=50;

}

void MapEditor::UpdateStartingMoney()
{
    if(mPlusEnemyButton.IsClicked() && mMaxEnemyByWave < 50)
        mMaxEnemyByWave++;
    else if(mMinusEnemyButton.IsClicked() && mMaxEnemyByWave > 0)
        mMaxEnemyByWave--;


}