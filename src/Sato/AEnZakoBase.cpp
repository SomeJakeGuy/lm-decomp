#include "Sato/AEnZakoBase.hpp"

// From EnemyStrategy
void AEnZakoBase::init() {

}

void AEnZakoBase::doBehavior() {

}

void AEnZakoBase::doBehaviorInit() {

}

bool AEnZakoBase::vt_14() {
    return true;
}

// From this class
void AEnZakoBase::fn_800F5CB8() {}

void AEnZakoBase::vt_08() {
    return;
}

// From Koga::CharacterEventObserver
bool AEnZakoBase::onPlayerLeftRoom(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onCollideWithPlayer(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithWater(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithFire(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithIce(Koga::CharacterEvent* msg){
    return true;
}
