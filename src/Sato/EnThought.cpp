// Based on the previous decompilation effort: https://github.com/CoNesTra/zmansion/blob/main/src/Unsorted/IncludeStrategy.cpp
#include "Sato/EnThought.hpp"
#include "Koga/ToolData.hpp"
#include "Sato/EnemyStrategy.hpp"
#include "Unsorted/MoveObj.hpp"
#include "macros.h"
#include "types.h"


dummy_float_data();

static s32 lbl_804D2D6C = 0xff;
static s32 lbl_804D2D70 = 0x0;
static float lbl_804DB698 = 0.f;
static float lbl_804DB69C = 1.f;


IncludeStrategy::IncludeStrategy() : mpStrategy(nullptr) {
    destroyStrategy();
}

IncludeStrategy::~IncludeStrategy() {
    destroyStrategy();
}

void IncludeStrategy::setStrategy(int entityIdx) {
    void* buffer = mStrategyMemory;
    destroyStrategy();
    EnemyStrategyInitFn* initFunc = *EnemyStrategy::getInitFunction(entityIdx);
    mpStrategy = reinterpret_cast<EnemyStrategy*>(initFunc(buffer, sizeof(mStrategyMemory)));
}

void IncludeStrategy::destroyStrategy() {
    EnemyStrategy* strategy = mpStrategy;

    if (strategy != nullptr) {
        // This object was initialized via placement new, so we
        // can just call its destructor and invalidate its pointer.
        strategy->~EnemyStrategy();
        mpStrategy = nullptr;
    }
}


void MoveObjAlphaControl::vt_08() {
    void* obj = _18;
}



EnThought::EnThought() { }

void EnThought::reset() {
    float var1;
    EnemyStrategy* strategy;
    void* var3;

    _810 = 0;
    _814 = 0;
    _818 = 0;
    _928 = 0;
    _92c = 0;
    _930 = 0;
    _81c = 0;
    _820 = 0;
    _824 = 0;
    _934 = 0;
    _938 = 0;
    _89c = 0;
    _8a0 = 0;
    _890 = -1;
    _894 = 0;
    _898 = 0;
    array_828.resetSize();
    _8ac = lbl_804D2D6C;
    _8a8 = lbl_804D2D70;
    var1 = lbl_804DB69C;
    _8b4 = lbl_804DB69C;
    _8b8 = var1;
    _8bc = _808;
    _8c8 = -1;
    _8cc = 0;
    _8d0 = 0;
    _8d4 = 0;
    _8e4 = lbl_804DB698;
    _8e8 = 0;
    _8ea = 0;
    _900 = 0;
    _904 = 0;
    _905 = 0;
    _906 = 0;
    _908 = 0;
    _90c = 0;
    _910 = 0;
    _914 = 0;
    _918 = 0;
    _91c = 0;
    _920 = 0;
    _924 = 0;
    
    strategy = mpStrategy;
    var3 = nullptr;

    if (strategy != nullptr) {
        destroyStrategy();
    }

    void* var_this = _808;
    if (var_this != nullptr) {
        ToolDataRef ref = getToolDataRef();
        if (ref.isValid()) {
            u8 invisible = 0;
            ref.getToolData()->getValue(ref.getEntryIndex(), "invisible", &invisible);

            if (invisible != 0) {

            } else {

            }
        }
    }

    return;
}


EnThought::~EnThought() {
    
}


void EnThought::setToolDataRef(ToolDataRef ref) {
    mToolRef = ref;
}


ToolDataRef EnThought::getToolDataRef() {
    return mToolRef;
}
