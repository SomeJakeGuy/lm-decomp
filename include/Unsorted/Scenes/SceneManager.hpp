#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <dolphin/os/OSMessage.h>

#include "Unsorted/Scenes/Scene.hpp"

enum SceneManagerState {
    SM_STATE_0,
    SM_STATE_1,
    SM_STATE_2
};

struct SceneManagerHelper {
    SceneManagerHelper();
    
    /* 0x00 */ SceneManagerState mState;
    /* 0x00 */ SceneID _4;
    /* 0x08 */ OSMessageQueue mOSMsgQueue;
    /* 0x28 */ OSMessage mMsgs;
}; // size 0x2C

namespace SceneManager {
    u16 fn_8000B328();
    void fn_8000B334(s32); // Unsure of return type/args
    void fn_8000B370(); // Unsure of return type/args
    void fn_8000B4A0(); // Unsure of return type/args
    void fn_8000B610(); // Unsure of return type/args
    void fn_8000B7F4(); // Looks to be the main game loop or something similar?

    extern SceneID sCurrSceneId;
    extern SceneManagerHelper sSceneMgr;
}

extern s32 lbl_804D80B0; // Definitely not AppearPointSlot, will need to re-evaluate this.
extern s32 lbl_804D8088;
extern s64 lbl_804D8098;
extern s64 lbl_804D8090;
extern s32 lbl_804D80AC;
extern s32 lbl_804D80A8;
extern s32 lbl_803A3AE4;
extern s32 lbl_803A3B08;
extern s32 lbl_804D80B4;

// sinit(or maybe i think its an sinit?) of fn_8000B880() called here

#endif
