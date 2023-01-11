#include "sound.hpp"

void MySetVolume(float volume)
{
    SetSoundVolume(gRes->MachineGun, volume);
    SetSoundVolume(gRes->ImpactFreezingTower, volume);
    SetSoundVolume(gRes->ShootFreezingTower, volume);
    SetSoundVolume(gRes->ShootExplosiveTower, volume);
    SetSoundVolume(gRes->ShootPoisonTower, volume);
    SetSoundVolume(gRes->ShootTower, volume);
    SetSoundVolume(gRes->ShootTower2, volume);
}