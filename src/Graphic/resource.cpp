#include "resource.hpp"

Resources* gRes = nullptr;


Resources::Resources()
{
    mTileSet = LoadTexture("assets/img/tileSheet.png");
    PlayButton2 = LoadTexture("assets/img/jouer2.png");
    SettingButton2 = LoadTexture("assets/img/Setting button.png");
    PauseButton2 = LoadTexture("assets/img/pause.png");
    CroixButton2 = LoadTexture("assets/img/croix.png");
    ParametreButton2 = LoadTexture("assets/img/parametre.png");
    Gameover2 = LoadTexture("assets/img/game over1.png");
    Resume2 = LoadTexture("assets/img/resume.png");
    Bg2 = LoadTexture("assets/img/title.png");    
    PauseImage2 = LoadTexture("assets/img/pauseImage.png");
    BgPause = LoadTexture("assets/img/BgPause.png");
    BgGameOver = LoadTexture("assets/img/BgGameOver.png");
    BgWood = LoadTexture("assets/img/Bgwood.png");
    BgWood2 = LoadTexture("assets/img/Bgwood2.png");
    SoundOn = LoadTexture("assets/img/soundOn.png");
    SoundOff = LoadTexture("assets/img/soundOff.png");
    MouseLeft = LoadTexture("assets/img/MouseLeft.png");
    MouseRight = LoadTexture("assets/img/MouseRight.png");
    King = LoadTexture("assets/img/king.png");
    Bubble = LoadTexture("assets/img/Bubble.png");
    CastleBg = LoadTexture("assets/img/CastleBg.png");
    KingFear = LoadTexture("assets/img/KingFear.png");
    MoneyBag = LoadTexture("assets/img/MoneyBag.png");
    Heart = LoadTexture("assets/img/Heart.png");
    KingAngry = LoadTexture("assets/img/KingAngry.png");
    KingHappy = LoadTexture("assets/img/KingHappy.png");
    Upgrade = LoadTexture("assets/img/upgrade.png");
    Acc = LoadTexture("assets/img/Acc.png");
    Dec = LoadTexture("assets/img/Dec.png");
    BgCredit = LoadTexture("assets/img/MenuCredit.png");
    Plus = LoadTexture("assets/img/plus.png");
    Moins = LoadTexture("assets/img/moins.png");
    Retour = LoadTexture("assets/img/retour.png");
    Explosion = LoadTexture("assets/img/explosion.png");

    MachineGun = LoadSound("assets/audio/ShootTower/MachineGun.wav");
    ImpactFreezingTower = LoadSound("assets/audio/ShootTower/impact freezingTower.wav");
    ShootFreezingTower = LoadSound("assets/audio/ShootTower/tire freezing Tower.wav");
    ShootExplosiveTower = LoadSound("assets/audio/ShootTower/tire ExplosiveTower.wav");
    ShootPoisonTower = LoadSound("assets/audio/ShootTower/tire PoisonTower.wav");
    ShootTower = LoadSound("assets/audio/ShootTower/tire tower.wav");
    ShootTower2 = LoadSound("assets/audio/ShootTower/tire tower2.wav");

    music = LoadMusicStream("assets/audio/bgm/ok.mp3");
}

Resources::~Resources()
{
    UnloadTexture(mTileSet);
    UnloadTexture(PlayButton2);
    UnloadTexture(SettingButton2);
    UnloadTexture(PauseButton2);
    UnloadTexture(CroixButton2);
    UnloadTexture(ParametreButton2);
    UnloadTexture(Gameover2);
    UnloadTexture(Resume2);
    UnloadTexture(Bg2);
    UnloadTexture(PauseImage2);
    UnloadTexture(BgPause);
    UnloadTexture(BgGameOver);
    UnloadTexture(BgWood);
    UnloadTexture(BgWood2);
    UnloadTexture(SoundOn);
    UnloadTexture(SoundOff);
    UnloadTexture(MouseLeft);
    UnloadTexture(MouseRight);
    UnloadTexture(King);
    UnloadTexture(Bubble);
    UnloadTexture(CastleBg);
    UnloadTexture(KingFear);
    UnloadTexture(MoneyBag);
    UnloadTexture(Heart);
    UnloadTexture(KingAngry);
    UnloadTexture(KingHappy);
    UnloadTexture(Upgrade);
    UnloadTexture(Acc);
    UnloadTexture(Dec);
    UnloadTexture(BgCredit);
    UnloadTexture(Plus);
    UnloadTexture(Moins);
    UnloadTexture(Retour);
    UnloadTexture(Explosion);

    UnloadSound(MachineGun);
    UnloadSound(ImpactFreezingTower);
    UnloadSound(ShootFreezingTower);
    UnloadSound(ShootExplosiveTower);
    UnloadSound(ShootPoisonTower);
    UnloadSound(ShootTower);
    UnloadSound(ShootTower2);

    UnloadMusicStream(music);


}