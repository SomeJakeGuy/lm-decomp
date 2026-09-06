#include <string.h>

#include "Koga/EnemyGenManager.hpp"
#include "Koga/EnManager.hpp"
#include "Koga/GameModeUtil.hpp"
#include "Koga/MissionMode.hpp"
#include "JSystem/JGeometry/JGVec3.hpp"


EnemyGenerator::EnemyGenerator() {
    fn_800C2500();
}

void EnemyGenerator::fn_800C2500() {
   _808.setToolData(nullptr);
   _808.setEntryIndex(0);
   _810 = 0;
   _818.reset(); 
   _820.mArraySize = 0;
   _870 = 0;
   destroyStrategy();
   fn_800C2560();
}

void EnemyGenerator::fn_800C2560() {
    _860 = 0;
}

EnemyGenerator::~EnemyGenerator() {}

void* EnemyGenerator::fn_800C25F0(s32 param_1, s32 param_2) {
    const char* maxEnemyKey = "max_enemy";
    s32 temp = fn_800C2830(maxEnemyKey);
    if (temp <= _860) {
        return nullptr;
    }

    s32 temp2 = _820.mArraySize;
    if (fn_800C2830("max_enemy_once") <= temp2) {
        return nullptr;
    }

    if (!(_870 & 0x2)) {
        JGeometry::TVec3f pos = mPos;
        // Does something with with mPos
    }

    if (!(_870 & 0x1)) {
        if (!fn_800E7174(&mPos, -1)) {
            return nullptr;
        }
    }

    if (_820.mArraySize >= 0xF) {
        return nullptr;
    }

    if (Koga::EnManager::fn_800E4A04(param_1)) {
        return nullptr;
    }

    if (_810->fn_800E5868(param_1, param_2) < 0) {
        return nullptr;
    }

    unkEnCharacter* enChar = _810->fn_800E5A80(param_1);
    // some dynamic cast stuff
}

Koga::ToolData* EnemyGenerator::fn_800C2798() {
    if (!_818.getJMapData()) {
        Koga::ToolData* tData = _808.getToolData();
        const char* pathName = nullptr;

        if (_808.isValid() && tData->getValue(_808.getEntryIndex(), "path_name", &pathName) && pathName != nullptr) {
            Koga::ToolData::JMapData* jData = reinterpret_cast<Koga::ToolData::JMapData*>(Koga::GameModeUtil::getPathResource(pathName));
            _818.attach(jData);
        }
    }

    return &_818;
}

u32 EnemyGenerator::fn_800C2830(const char* pKeyName) {
    u32 out = 0;
    ToolDataRef ref = _808;
    ref.getToolData()->getValue(ref.getEntryIndex(), pKeyName, &out);
    return out;
}

namespace Koga {

    EnemyGenManager::EnemyGenManager()  {
        _8 = true;
        mEnemyGens = new EnemyGenerator[0x14];
    }

    EnemyGenManager::~EnemyGenManager() {
        delete [] mEnemyGens;
    }

    BOOL EnemyGenManager::vt_0C(ToolDataRef* pRef) {
        ToolDataRef localRef = *pRef;
        const char* isGenerator;
        const char* genType;
        
        if (!localRef.getToolData()->getValue(localRef.getEntryIndex(), "name", &isGenerator)) {
            return false;
        }

        if (strcmp(isGenerator, "generator") != 0) {
            return false;
        }

        EnemyGenerator* curr = mEnemyGens;
        EnemyGenerator* last = curr + 14;

        while(curr != last && curr->getStrategy() != nullptr) {
            curr++;
        }

        if (curr != last) {
            genType = 0;
            localRef.getToolData()->getValue(localRef.getEntryIndex(), "type", &genType);
            //int uVar1 = fn_800DAB18(genType);
            //void* pcVar3 = fn_800DAC54();
            curr->_808 = localRef;
            curr->_814 = 0; //uVar1
            curr->_810 = MissionMode::sMissionMode->getEnManager();
            // some call on pcVar3 / localRef?

            curr->destroyStrategy();
            curr->setStrategy(0); // maybe uses pcVar3 here
            // fn_800C1BAC(curr)

            Koga::ToolData* tData = curr->_808.getToolData();
            s32 currIdx = curr->_808.getEntryIndex();
            tData->getValue(currIdx, "pos_x", &curr->mPos.x);
            tData->getValue(currIdx, "pos_y", &curr->mPos.y);
            tData->getValue(currIdx, "pos_z", &curr->mPos.z);

            curr->getStrategy()->init();
        }

        return true;
    }


    BOOL EnemyGenManager::vt_10(ToolDataRef* pRef) {
        ToolDataRef localRef = *pRef;
        const char* isGenerator;

        if (!localRef.getToolData()->getValue(localRef.getEntryIndex(), "name", &isGenerator)) {
            return false;
        }
        
        if (strcmp(isGenerator, "generator") != 0) {
            return false;
        }

        EnemyGenerator* curr = mEnemyGens;
        EnemyGenerator* last = curr + 0x14;

        while(curr != last && curr->getStrategy() != nullptr) {
            curr++;
        }

        if (curr == last) {
            return false;
        }

        void** p = curr->_820.getArray();
        while (p != curr->_820.getMaxMember()) {
            // some call out to fn_800C0EBC?
            p++;
        }

        curr->_808.setToolData(nullptr);
        curr->_808.setEntryIndex(0);
        curr->_810 = nullptr;
        curr->_818.reset();
        curr->_820.mArraySize = 0;
        curr->_870 = 0;
        curr->destroyStrategy();
        curr->_860 = 0;

        return true;
    }
}
