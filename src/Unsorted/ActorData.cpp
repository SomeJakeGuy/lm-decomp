#include "Unsorted/ActorData.hpp"
#include "Koga/EnTypesManager.hpp"

ActorData cData[381] = {
    {0, 0, 0, 2, nullptr, -1, 0xFFFF, "luige"}
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
    return pData->_8 & param_2;
}

ActorData* ActorData::getActorData(s32 idx) {
    return &cData[idx];
}
