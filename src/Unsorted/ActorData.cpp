#include "Unsorted/ActorData.hpp"
#include "Koga/EnTypesManager.hpp"

ActorData cData[381] = {
    {0, 0, 0, 2, 0, -1, -1, "luige"},
    {0, 0, 0, 0xA, 0x800, -1, -1, "waluige"},
    {0x14, 3, 0, 2, 0x800, -1, -1, "dluige01"},
    {0x15, 3, 0, 2, 0x800, -1, -1, "dluige02"},
    {0x16, 0, 0, 2, 0x800, -1, -1, "dluige03"},
    {3, 1, 0, 6, 0x800, -1, -1, "vbody"},
    {1, 1, 0, 2, 0x800, -1, -1, "vhead"},
    {2, 1, 0, 2, 0x800, -1, -1, "wplight"},
    {0x12, 1, 0, 2, 0x800, -1, -1, "wpwater"},
    {0x13, 1, 0, 2, 0x800, -1, -1, "wpair"},
    {4, 1, 0, 2, 0x800, -1, -1, "gameboy"},
    {0x19, 2, 0, 0xE, 0, 0, 2, "yapoo1"},
    {0x19, 2, 0, 0xE, 0, 1, 2, "yapoo2"},
    {0x1F, 2, 0, 0xE, 0, -1, 2, "skul"},
    {0x22, 2, 0, 0xF, 0, -1, 3, "situji"},
    {0x94, 4, 0, 1, 0, -1, 2, "candle"},
    {0x1A, 2, 0, 0xE, 0, 0, 2, "mapoo1"},
    {0x1A, 2, 0, 0xE, 0, 1, 2, "mapoo2"},
    {0x1B, 2, 0, 0xE, 0, 0, 2, "mopoo1"},
    {0x1B, 2, 0, 0xE, 0, 1, 2, "mopoo2"},
    {0x1D, 2, 0, 0xE, 0, 0, 2, "topoo1"},
    {0x1D, 2, 0, 0xE, 0, 1, 2, "topoo2"},
    {0x1D, 2, 0, 0xE, 0, 2, 2, "topoo3"},
    {0x1D, 2, 0, 0xE, 0, 3, 2, "topoo4"},
    {0x1C, 2, 0, 0xE, 0, -1, 2, "putcher1"},
    {0x21, 2, 0, 0xE, 0, 0, 2, "heypo1"},
    {0x21, 2, 0, 0xE, 0, 2, 2, "heypo2"},
    {0x21, 2, 0, 0xE, 0, 3, 2, "heypo3"},
    {0x21, 2, 0, 0xE, 0, 4, 2, "heypo4"},
    {0x21, 2, 0, 0xE, 0, 5, 2, "heypo5"},
    {0x21, 2, 0, 0xE, 0, 6, 2, "heypo6"},
    {0x21, 2, 0, 0xE, 0, 7, 2, "heypo7"},
    {0x21, 2, 0, 0xE, 0, 8, 2, "heypo8"},
    {0x29, 2, 0, 0xE, 0, 0, 2, "tenjyo"},
    {0x29, 2, 0, 0xE, 0, 1, 2, "tenjyo2"},
    {0x2A, 2, 0, 0xE, 0, -1, 2, "banaoba"},
    {0x20, 3, 0, 0xE, 0, -1, 3, "tubone"},
    {0x20, 3, 0, 0xF, 0, 0, 3, "htubone"},
    {0x23, 3, 0, 0xF, 0, 0, 3, "pianist"},
    {0x48, 5, 0, 2, 0, -1, -1, "lohakase"},
    {0x17, 3, 0, 2, 0, -1, -1, "dhakase"},
    {0x18, 3, 0, 2, 0, -1, -1, "dhakase2"},
    {0x49, 3, 0, 2, 0, 0, -1, "kinopio"},
    {0x49, 3, 0, 2, 0, 1, -1, "kinopio2"},
    {0x2F, 3, 0, 0xE, 0, -1, 3, "eater"},
    {0x30, 3, 0, 0xF, 0, -1, 3, "fat"},
    {0x2C, 2, 0, 0xF, 0, -1, 3, "father"},
    {0x2D, 2, 0, 0xF, 0, -1, 3, "mother"},
    {0x2E, 2, 0, 0xF, 0x800, -1, 3, "obaasan"},
    {0x32, 2, 0, 0xF, 0, 0, 3, "boy"},
    {0x32, 2, 0, 0xF, 0, 0, 3, "boy2"},
};

u32 ActorData::fn_8006A354(s32 idx) {
    return cData[idx]._0;
}

u16 ActorData::fn_8006A36C(s32 idx) {
    return cData[idx]._4;
}

u32 ActorData::getEnemyBrightColor(s32 idx) {
    return Koga::EnTypesManager::getEnemyBrightColor(idx);
}

const char* ActorData::getActorName(s32 idx) {
    return cData[idx].mActorName;
}

u16 ActorData::fn_8006A3BC(s32 idx, s32 param_2) {
    ActorData* pData = &cData[idx];
    return pData->mFlags & param_2;
}

ActorData* ActorData::getActorData(s32 idx) {
    return &cData[idx];
}
