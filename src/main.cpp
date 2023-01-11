#include <raylib.h>
#include "system/data.hpp"
#include "Graphic/resource.hpp"
#include "Game/game.hpp"
#include "time.h"


int main(void)
{
    InitAudioDevice();


    const int screenWidth  = 1440;
    const int screenHeight = 900;
    
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense");
    
    RenderTexture2D renderTarget = LoadRenderTexture(screenWidth, screenHeight);

    {
        Resources resources;
        gRes = &resources; // Init global access

        Game game = Game();
        PlayMusicStream(resources.music);
        gRes->music.looping = false;
        SetMusicVolume(gRes->music, game.pitch);
        
        while (!WindowShouldClose())
        {
            UpdateMusicStream(gRes->music);

            BeginDrawing();
        
            BeginTextureMode(renderTarget);
            EndTextureMode();
    
            DrawFPS(10, 10);
        
            ClearBackground(WHITE);
            game.GameLoop();


            EndDrawing();
        }

        for (long unsigned int i = 0; i < game.GetLevels().size(); i++)
        {
            game.GetLevels()[i]->GetSpawnEnemiesInGameSpace().clear();
            game.GetLevels()[i]->GetTowerInGameSpace().clear();
            game.GetLevels()[i]->GetEffectsInGameSpace().clear();
        }
        game.GetLevels().clear();
    }

    
    CloseAudioDevice();//=======================================
    CloseWindow();

    return 0;
}