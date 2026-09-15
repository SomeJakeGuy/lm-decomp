#include "Sato/EnemyTypicalStrategy.hpp"

dummy_float_data()
static float lbl_8035B0F0[8] = { 1.0f, 0.95f, 0.9f, 0.85f, 1.0f, 0.9f, 0.75f, 0.3f };

bool EnemyTypicalStrategy::onFishingBegin(Koga::CharacterEvent* msg) {
    EnemyStrategy* tsuri; // = fn_800E410C(unk_20, mpZako->0x808->0x3C)

    tsuri->mpZako = mpZako;
    tsuri->mpUserData = mpUserData;
    tsuri->setNextState(0);

    setTsuriStrategy(tsuri);

    return true;
}
