#include <string.h>

#include "Koga/EnemyGenManager.hpp"
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

u32 EnemyGenerator::fn_800C2830(char* pKeyName) {
    u32 out = 0;
    _808.getToolData()->getValue(_808.getEntryIndex(), pKeyName, &out);
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
        
        if (localRef.getToolData()->getValue(localRef.getEntryIndex(), "name", &isGenerator)) {
            if (strcmp(isGenerator, "generator") == 0) {
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

                    localRef.getToolData()->getValue(localRef.getEntryIndex(), "pos_x", &curr->mPos.x);
                    localRef.getToolData()->getValue(localRef.getEntryIndex(), "pos_y", &curr->mPos.y);
                    localRef.getToolData()->getValue(localRef.getEntryIndex(), "pos_z", &curr->mPos.z);

                    curr->getStrategy()->init();
                }

                return true;
            }
        }

        return false;
    }

}
