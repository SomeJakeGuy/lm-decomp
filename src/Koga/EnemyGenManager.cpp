#include <string.h>

#include "Koga/EnemyGenManager.hpp"
#include "Koga/EnManager.hpp"
#include "Koga/GameModeUtil.hpp"
#include "Koga/MissionMode.hpp"
#include "JSystem/JGeometry/JGVec3.hpp"
#include "Koga/ToolData.hpp"


EnemyGenerator::EnemyGenerator() {
    fn_800C2500();
}

void EnemyGenerator::fn_800C2500() {
   _808.setToolData(nullptr);
   _808.setEntryIndex(0);
   _810 = 0;
   _818.reset(); 
   _820.resetSize();
   _870 = 0;
   destroyStrategy();
   fn_800C2560();
}

void EnemyGenerator::fn_800C2560() {
    _860 = 0;
}

EnemyGenerator::~EnemyGenerator() {}

void* EnemyGenerator::fn_800C25F0(s32 param_1, s32 param_2) {
    s32 temp = fn_800C2830("max_enemy");
    if (temp <= _860) {
        return nullptr;
    }

    s32 temp2 = _820.getSize();
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

    if (_820.getSize() >= 0xF) {
        return nullptr;
    }

    if (Koga::EnManager::fn_800E4A04(param_1)) {
        return nullptr;
    }

    if (_810->fn_800E5868(param_1, param_2) < 0) {
        return nullptr;
    }

    unkEnCharacter* enChar = _810->fn_800E5A80(param_1);
    //EnZako* eZako = dynamic_cast<EnZako*>(enChar);
}

ToolDataRef EnemyGenerator::fn_800C2784() {
    ToolDataRef ref = _808;
    return ref;
}

Koga::ToolData* EnemyGenerator::fn_800C2798() {
    if (!_818.getJMapData()) {
        ToolDataRef ref = _808;
        Koga::ToolData* pData = ref.getToolData();
        s32 idx = ref.getEntryIndex();
        const char* pathName = nullptr;
        bool isValid = pData != nullptr && idx >= 0;

        if (isValid && pData->getValue(idx, "path_name", &pathName) && pathName != nullptr) {
            _818.attach(reinterpret_cast<Koga::ToolData::JMapData*>(Koga::GameModeUtil::getPathResource(pathName)));   
        }
    }

    return &_818;
}

u32 EnemyGenerator::fn_800C2830(const char* pKeyName) {
    u32 out = 0;
    ToolDataRef ref; 
    ref = _808;
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

    BOOL EnemyGenManager::vt_08(ToolDataRef* pRef) {
        const char* entryName;
        const char* genType;
        ToolDataRef localRef = *pRef;
        
        if (!localRef.getToolData()->getValue(localRef.getEntryIndex(), "name", &entryName)) {
            return false;
        }

        if (strcmp(entryName, "generator") != 0) {
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


    BOOL EnemyGenManager::vt_0C(ToolDataRef* pRef) {
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

        for (void** pIter = curr->_820.getArray(); pIter != curr->_820.getMaxMember(); pIter++) {
            //some call out to fn_800C0EBC?
            ToolDataRef temp = fn_800C31E4(curr->_808.getToolData(), curr->_808.getEntryIndex());

        }

        curr->_808.setToolData(nullptr);
        curr->_808.setEntryIndex(0);
        curr->_810 = nullptr;
        curr->_818.reset();
        curr->_820.resetSize();
        curr->_870 = 0;
        curr->destroyStrategy();
        curr->_860 = 0;

        return true;
    }

    BOOL EnemyGenManager::vt_10(ToolDataRef* pRef, char* message) {
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
        
        for(; curr != last; curr++) {
            ToolDataRef tRef = fn_800C31E4(curr->_808.getToolData(), curr->_808.getEntryIndex());

            if (tRef.getEntryIndex() == localRef.getEntryIndex() &&
                        tRef.getToolData() != nullptr &&
                        localRef.getToolData() != nullptr &&
                        tRef.getToolData()->getJMapData() != localRef.getToolData()->getJMapData()) {
                    break;
                }
        }
        
        if (curr == last) {
            return false;
        }

        if (strcmp(message, "start") == 0) {
            curr->getStrategy()->setNextState(0x104);
        } else if (strcmp(message, "stop") == 0) {
            curr->getStrategy()->setNextState(0x103);
        } else {
            return false;
        }

        return true;
    }

    ToolDataRef EnemyGenManager::fn_800C31E4(Koga::ToolData* pData, s32 entryIdx) {
        ToolDataRef ref;
        ref.setToolData(pData);
        ref.setEntryIndex(entryIdx);
        return ref;
    }
}

void unkEnemyGen1::add(void** pNew) {
    addMember(pNew);
}

void* unkEnemyGen1::remove(void** pIter) {
    return eraseMember(pIter);
}
