#include "Koga/EnemyGenManager.hpp"
#include "Koga/GameModeUtil.hpp"
#include "Koga/ToolData.hpp"
#include "types.h"

EnemyGenerator::EnemyGenerator() {
    fn_800C2500();
}

EnemyGenerator::~EnemyGenerator() {

}

void EnemyGenerator::fn_800C2500() {
   _808 = nullptr;
   _80C = 0;
   _810 = 0;
   mToolData.reset(); 
   _85C = 0;
   _870 = 0;
   destroyStrategy();
   fn_800C2560();
}

void EnemyGenerator::fn_800C2560() {
    _860 = 0;
}

Koga::ToolData* EnemyGenerator::fn_800C2798() {
    bool temp = false;
    const char* pathName;

    if (!mToolData.getJMapData()) {
        if (_808 != nullptr && -1 < _80C) {
            temp = true;
        }

        if (temp && _808->getValue(_80C, "path_name", &pathName) && pathName != nullptr) {
            Koga::ToolData::JMapData* jData = reinterpret_cast<Koga::ToolData::JMapData*>(Koga::GameModeUtil::getPathResource(pathName));
            mToolData.attach(jData);
        }
    }

    return &mToolData;
}

u32 EnemyGenerator::fn_800C2830(char* pKeyName) {
    u32* out;
    _808->getValue(_80C, pKeyName, out);
    return *out;
}

namespace Koga {

    EnemyGenManager::EnemyGenManager()  {
        mEnemyGens = new EnemyGenerator[0x14];
    }

}
