#ifndef SELECT_SCENE_HPP
#define SELECT_SCENE_HPP

#include <dolphin/os/OSMessage.h>

#include "Unsorted/Scenes/Scene.hpp"

struct SelectSceneHelper {
    SelectSceneHelper();
    
    /* 0x00 */ s32 _0;
    /* 0x04 */ OSMessageQueue mOSMsgQueue;
    /* 0x24 */ OSMessage mMsgs[1];
};

namespace SelectScene {
    void fn_8000B8D8(void*);
    void fn_8000B910();
    void fn_8000B978();

    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sSelectScene;
}

extern s32 lbl_804D80C0;

#endif
