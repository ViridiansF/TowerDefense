#pragma once
#include <raylib.h>

// Texture, sound, every raylib resources
class Resources
{
public:

    Texture2D mTileSet;                     
    Texture2D PlayButton2;
    Texture2D SettingButton2;
    Texture2D PauseButton2;
    Texture2D CroixButton2;
    Texture2D ParametreButton2;
    Texture2D Gameover2;
    Texture2D Resume2;
    Texture2D Bg2;
    Texture2D PauseImage2;
    Texture2D BgPause;
    Texture2D BgGameOver;
    Texture2D BgWood;
    Texture2D BgWood2;
    Texture2D SoundOn;
    Texture2D SoundOff;
    Texture2D MouseLeft;
    Texture2D MouseRight;
    Texture2D King;
    Texture2D Bubble;
    Texture2D CastleBg;
    Texture2D KingFear;
    Texture2D MoneyBag;
    Texture2D Heart;
    Texture2D KingAngry;
    Texture2D KingHappy;
    Texture2D Upgrade;
    Texture2D Acc;
    Texture2D Dec;
    Texture2D BgCredit;
    Texture2D Plus;
    Texture2D Moins;
    Texture2D Retour;
    Texture2D Explosion;

    Sound MachineGun;
    Sound ImpactFreezingTower;
    Sound ShootFreezingTower;
    Sound ShootExplosiveTower;
    Sound ShootPoisonTower;
    Sound ShootTower;
    Sound ShootTower2;

    Music music;
    Resources();
    ~Resources();
};

// Pointer for global access
extern Resources* gRes;
