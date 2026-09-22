#include "Sato/EnZako.hpp"
#include "Koga/GameModeUtil.hpp"
#include "Koga/ToolData.hpp"
#include "types.h"

EnZako::EnZako() {

}

EnZako::~EnZako() {
    
}


void EnZako::vt_0C() {
    _958 = _954;
    getStrategy()->update();
}


void EnZako::vt_10() {
    getStrategy()->mpZako = 0;
    _954 = nullptr;
}


void EnZako::fn_800C1F38(const Koga::ToolData::JMapData* pMapData) {
    _95C.attach(pMapData);
}


bool EnZako::fn_800C1F5C() {
    ToolDataRef temp = getToolDataRef();
    const char* pathName;

    if (temp.getToolData() == nullptr) {
        return true;
    }
    else if (!(temp.getToolData()->getValue(temp.getEntryIndex(), "path_name", &pathName))) {
        return false;
    }
    else {
        _95C.attach(reinterpret_cast<Koga::ToolData::JMapData*>(Koga::GameModeUtil::getPathResource(pathName)));
    }

    return true;
}

Koga::ToolData* EnZako::fn_800C1FF4() {
    return &_95C;
}
