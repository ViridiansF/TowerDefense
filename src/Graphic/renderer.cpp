 #include "renderer.hpp"
 #include "resource.hpp"
 #include "../Graphic/drawAsset.hpp"
 #include "../Game/level.hpp"

void DrawOption()
{
    DrawBgOption();

    DrawTexture(gRes->CroixButton2, 1380, 10, WHITE);
    
    // Big rectangle for sound
    DrawRectangle(370, 260, 690, 120, YELLOW);
    DrawRectangleLinesEx({370, 260, 690, 120}, 5, BLACK);
    
    // Upper rectangle for sound
    DrawRectangle(620, 220, 200, 50, YELLOW);
    DrawRectangleLinesEx({620, 220, 200, 50}, 5, BLACK);
    DrawText("Audio", 680, 232, 30, BLACK);
    
    
    DrawRectangle(475, 300, 550, 50, LIGHTGRAY);

    // Big rectangle for commands
    DrawRectangle(100, 500, SCREEN_WIDTH - 200, SCREEN_HEIGHT - 600, YELLOW);
    DrawRectangleLinesEx({100, 500, SCREEN_WIDTH - 200, SCREEN_HEIGHT - 600}, 5, BLACK);
    
    // Upper rectangle for commands
    DrawRectangle(560, 430, 300, 80, YELLOW);
    DrawRectangleLinesEx({560, 430, 300, 80}, 5, BLACK);
    DrawText("Commandes", 630, 460, 30, BLACK);

    DrawLeftOption();
    DrawRightOption();
}

void DrawBgOption()
{
    // Background
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height * 2, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
}

void DrawLeftOption()
{
    // Left mouse button command
    DrawTexturePro(gRes->MouseLeft, {0, 0, (float)gRes->MouseLeft.width, (float)gRes->MouseLeft.height}, {400, 630, (float)gRes->MouseLeft.width / 2, (float)gRes->MouseLeft.height / 2}, {(float)gRes->MouseLeft.width / 2, (float)gRes->MouseLeft.height / 2}, 0, WHITE);
    DrawText("Selectionner, placer et améliorer des tours", 630, 590, 25, BLACK);
}

void DrawRightOption()
{
    // Right mouse button command
    DrawTexturePro(gRes->MouseRight, {0, 0, (float)gRes->MouseRight.width, (float)gRes->MouseRight.height}, {400, 730, (float)gRes->MouseRight.width / 2, (float)gRes->MouseRight.height / 2}, {(float)gRes->MouseRight.width / 2, (float)gRes->MouseRight.height / 2}, 0, WHITE);
    DrawText("Déselectionner un type de tour", 630, 690, 25, BLACK);
}

void DrawTitleScreen(int& decal, int& decal2, int& decal3)
{
    DrawTexture(gRes->Bg2, 0, 0, WHITE);

    DrawRectangle(0, 720, SCREEN_WIDTH, 60, YELLOW);
    DrawRectangleLinesEx({-4, 720, SCREEN_WIDTH + 8, 60}, 3, BLACK);
    DrawAssetTexture(19, 8, (-SCREEN_WIDTH / 6 * 5) + decal, 750, 0, 1.0f, WHITE);
    DrawAssetTexture(19, 10, (-SCREEN_WIDTH / 6 * 4) + decal, 743, 0, 1.0f, WHITE);
    DrawAssetTexture(22, 8, (-SCREEN_WIDTH / 6 * 3) + decal, 753, 0, 1.0f, WHITE);
    DrawAssetTexture(15, 12, (-SCREEN_WIDTH / 6 * 2) + decal, 750, 0, 1.0f, WHITE);
    DrawAssetTexture(22, 9, (-SCREEN_WIDTH / 6) + decal, 750, 0, 1.0f, WHITE);
    DrawAssetTexture(16, 12, decal, 750, 0, 1.0f, WHITE);
    decal++;
    if (decal == SCREEN_WIDTH *2 - 200)
        decal = 0;

    DrawRectangle(0, 570, SCREEN_WIDTH, 80, YELLOW);
    DrawRectangleLinesEx({-4, 570, SCREEN_WIDTH + 8, 80}, 3, BLACK);
    DrawAssetTexture(15, 10, decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(16, 10, (-SCREEN_WIDTH / 6) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(17, 10, (-SCREEN_WIDTH / 6 * 2) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(18, 10, (-SCREEN_WIDTH / 6 * 3) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(15, 8, (-SCREEN_WIDTH / 6 * 4) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(17, 11, (-SCREEN_WIDTH / 6 * 5) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(15, 11, (-SCREEN_WIDTH) + decal2, 610, 0, 1.0f, WHITE);
    DrawAssetTexture(15, 12, (-SCREEN_WIDTH) + decal2, 610, 0, 1.0f, WHITE);
    decal2++;
    if( decal2 == SCREEN_WIDTH * 2 + 80)
        decal2 = 0;

    DrawText("TOWER DEFENSE", decal3 = decal3 + 2, 100, 70, YELLOW);
    if (decal3 >= SCREEN_WIDTH)
        decal3 =  -600;

    DrawRectangleRounded({540, 270, 360, 70}, 0.8f, 5, YELLOW);
    DrawRectangleRoundedLines({540, 270, 360, 70}, 0.8f, 5, 3, BLACK);
    DrawText("JOUER", 660, 290, 40, BLACK);

    DrawRectangleRounded({590, 377, 270, 60}, 0.8f, 5, YELLOW);
    DrawRectangleRoundedLines({590, 377, 270, 60}, 0.8f, 5, 3, BLACK);
    DrawText("OPTIONS", 635, 390, 40, BLACK);

    DrawRectangleRounded({990, 380, 270, 60}, 0.8, 5, YELLOW);
    DrawRectangleRoundedLines({990, 380, 270, 60}, 0.8, 5, 3, BLACK);
    DrawText("CREDITS", 1040, 395, 40, BLACK);

    DrawRectangleRounded({190, 380, 270, 60}, 0.8, 5, YELLOW);
    DrawRectangleRoundedLines({190, 380, 270, 60}, 0.8, 5, 3, BLACK);
    DrawText("EDITEUR DE MAP", 200, 400, 29, BLACK);
}

void DrawPause()
{
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->BgWood2, {0, 0, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, (float)gRes->BgWood2.height * 2, (float)gRes->BgWood2.width, (float)gRes->BgWood2.height}, {0, 0}, 0, WHITE);


    DrawTexture(gRes->Resume2, 680, 330, WHITE);

    DrawTexture(gRes->PauseImage2, 570, 20, WHITE);

    DrawRectangleRounded({5, 125, 550, 500}, 0.8, 5, YELLOW);
    DrawRectangleRoundedLines({5, 125, 550, 500}, 0.8, 5, 3, BLACK);


    DrawText("Liste des effets:",50,200,35,BLACK);

    DrawText("- Ralentissement : réduit la vitesse de la",50,260,20,BLACK);
    DrawText("                       cible de moitié.",50,280,20,BLACK);

    DrawText("- Poison : inflige une bonne quantité",50,325,20,BLACK); 
    DrawText("            de dégâts sur une certaine durée.",50,345,20,BLACK);
    
    
    DrawText("- Combo : inflige les effets de la cible aux",50,390,20,BLACK);
    DrawText("           autres ennemis dans un certain rayon.",50,410,20,BLACK);
    DrawText("           Si la cible en a au moins deux",50,430,20,BLACK);
    DrawText("           inflige également une explosion.",50,450,20,BLACK);

    DrawText("- Explosion : inflige des dégâts dans une zone.",50,495,20,BLACK);
}

void DrawCredit()
{
    DrawTexture(gRes->BgCredit, 0, 0, WHITE);
    DrawText("   Mael JAMMET\n   Aran HIBLOT\n Tangui SAMSON", 550, 250, 50, BLACK);
    DrawText("Jeu réalisé par :", 680, 200, 20, BLACK);
    DrawTexture(gRes->CroixButton2, 1380, 10, WHITE);
}

void DrawRunningGame()
{
    // Draw wood 
    DrawTexture(gRes->BgWood, 1300, 0, WHITE);
    DrawRectangle(1300, 0, 10, 900, DARKBROWN);
    DrawTexture(gRes->BgWood2, 0, 800, WHITE);
    DrawRectangle(0, 800, 1440, 10, DARKBROWN);

    // Money and life draw
    DrawTexturePro(gRes->MoneyBag, {0, 0, (float)gRes->MoneyBag.width, (float)gRes->MoneyBag.height}, {130, 20, (float)gRes->MoneyBag.width / 8, (float)gRes->MoneyBag.height / 8}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->Heart, {0, 0, (float)gRes->Heart.width, (float)gRes->Heart.height}, {10, 110, (float)gRes->Heart.width / 9, (float)gRes->Heart.height / 9}, {0, 0}, 0, WHITE);
    
    // Info rectangle
    DrawRectangleRounded({60, 815, 1150, 60}, 0.8, 5, YELLOW);
    DrawRectangleRoundedLines({60, 815, 1150, 60}, 0.8, 5, 3, BLACK);

    // Draw buttons
    DrawTexture(gRes->PauseButton2, 1255, 840, WHITE);
    DrawTexture(gRes->ParametreButton2, 1317, 837, WHITE);
    DrawTexture(gRes->CroixButton2, 1382, 837, WHITE);
    DrawTexturePro(gRes->Acc, {0, 0, (float)gRes->Acc.width, (float)gRes->Acc.height}, {1390, 10, (float)gRes->Acc.width / 5, (float)gRes->Acc.height / 5}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->Dec, {0, 0, (float)gRes->Dec.width, (float)gRes->Dec.height}, {1320, 10, (float)gRes->Dec.width / 5, (float)gRes->Dec.height / 5}, {0, 0}, 0, WHITE);

}

void DrawLevelSelection()
{
    DrawBgOption();
    
    DrawText("Choisissez un niveau depuis lequel commencer votre aventure.",50,50,30,BLACK);
    DrawText("Les niveaux s'enchainent ensuite jusqu'à la fin.",150,80,20,BLACK);

    DrawTexture(gRes->CroixButton2, 1382, 12, WHITE);
}

void DrawGameOver(int level)
{
    DrawTexturePro(gRes->CastleBg, {0, 0, (float)gRes->CastleBg.width, (float)gRes->CastleBg.height}, {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->KingAngry, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {150, 650, (float)gRes->King.width, (float)gRes->King.height}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    DrawRectangleLinesEx({150 - (float)gRes->King.width / 2, 650 - (float)gRes->King.height / 2, (float)gRes->King.width, (float)gRes->King.height}, 3, BLACK);
    DrawTexturePro(gRes->Bubble, {0, 0, (float)gRes->Bubble.width, (float)gRes->Bubble.height}, {1270, 850, (float)gRes->Bubble.width / 2.3f, (float)gRes->Bubble.height / 2.3f}, {(float)gRes->Bubble.width / 2, (float)gRes->Bubble.height / 2}, 0, WHITE);

    DrawText("J'avais confiance en vous !", 510, 275, 30, BLACK);
    if (level == 0)
        DrawText(TextFormat("Vous avez échoué à repousser %d invasion !", level +1), 400, 345, 30, BLACK);
    else
        DrawText(TextFormat("Vous avez échoué à repousser %d invasions !", level +1), 400, 345, 30, BLACK);
    DrawText("Vous êtes un traître à la nation !", 480, 415, 30, BLACK);
    DrawText("Vous serez emprisonné !", 550, 475, 30, BLACK);

    DrawRectangle(530, 750, 180, 100, YELLOW);
    DrawRectangleLinesEx({530, 750, 180, 100}, 3, BLACK);
    DrawText("REJOUER", 548, 790, 30, BLACK);

    DrawRectangle(730, 750, 180, 100, YELLOW);
    DrawRectangleLinesEx({730, 750, 180, 100}, 3, BLACK);
    DrawText("MENU", 778, 790, 30, BLACK);
}

void DrawVictory(int level)
{
    DrawTexturePro(gRes->CastleBg, {0, 0, (float)gRes->CastleBg.width, (float)gRes->CastleBg.height}, {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->KingHappy, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {150, 650, (float)gRes->King.width, (float)gRes->King.height}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    DrawRectangleLinesEx({150 - (float)gRes->King.width / 2, 650 - (float)gRes->King.height / 2, (float)gRes->King.width, (float)gRes->King.height}, 3, BLACK);
    DrawTexturePro(gRes->Bubble, {0, 0, (float)gRes->Bubble.width, (float)gRes->Bubble.height}, {1270, 850, (float)gRes->Bubble.width / 2.5f, (float)gRes->Bubble.height / 2.5f}, {(float)gRes->Bubble.width / 2, (float)gRes->Bubble.height / 2}, 0, WHITE);  
    DrawText("Félicitations ! Vous avez gagné !", 455, 255, 30, BLACK);
    if (level == 0)
        DrawText(TextFormat("Vous avez repoussé %d invasion !", level +1), 470, 325, 30, BLACK);
    else
        DrawText(TextFormat("Vous avez repoussé %d invasions !", level +1), 470, 325, 30, BLACK);
    DrawText("Vous êtes un héros !", 540, 395, 30, BLACK);
    DrawText("Vous serez anobli !", 550, 455, 30, BLACK);

    DrawRectangle(530, 750, 180, 100, YELLOW);
    DrawRectangleLinesEx({530, 750, 180, 100}, 3, BLACK);
    DrawText("REJOUER", 548, 790, 30, BLACK);

    DrawRectangle(730, 750, 180, 100, YELLOW);
    DrawRectangleLinesEx({730, 750, 180, 100}, 3, BLACK);
    DrawText("MENU", 778, 790, 30, BLACK);
}

void DrawAnimation1()
{
    DrawTexturePro(gRes->CastleBg, {0, 0, (float)gRes->CastleBg.width, (float)gRes->CastleBg.height}, {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->King, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {150, 650, (float)gRes->King.width, (float)gRes->King.height}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    DrawRectangleLinesEx({150 - (float)gRes->King.width / 2, 650 - (float)gRes->King.height / 2, (float)gRes->King.width, (float)gRes->King.height}, 3, BLACK);
    DrawTexturePro(gRes->Bubble, {0, 0, (float)gRes->Bubble.width, (float)gRes->Bubble.height}, {1300, 865, (float)gRes->Bubble.width / 2.65f, (float)gRes->Bubble.height / 2.65f}, {(float)gRes->Bubble.width / 2, (float)gRes->Bubble.height / 2}, 0, WHITE);
}

void DrawAnimation2()
{
    DrawTexturePro(gRes->CastleBg, {0, 0, (float)gRes->CastleBg.width, (float)gRes->CastleBg.height}, {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, {0, 0}, 0, WHITE);
    DrawTexturePro(gRes->King, {0, 0, (float)gRes->King.width, (float)gRes->King.height}, {150, 650, (float)gRes->King.width, (float)gRes->King.height}, {(float)gRes->King.width / 2, (float)gRes->King.height / 2}, 0, WHITE);
    DrawRectangleLinesEx({150 - (float)gRes->King.width / 2, 650 - (float)gRes->King.height / 2, (float)gRes->King.width, (float)gRes->King.height}, 3, BLACK);
    DrawTexturePro(gRes->Bubble, {0, 0, (float)gRes->Bubble.width, (float)gRes->Bubble.height}, {1300, 860, (float)gRes->Bubble.width / 2.65f, (float)gRes->Bubble.height / 2.65f}, {(float)gRes->Bubble.width / 2, (float)gRes->Bubble.height / 2}, 0, WHITE);
}