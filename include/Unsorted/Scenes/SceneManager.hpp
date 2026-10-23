#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace SceneManager {
    u16 fn_8000B328();
    void fn_8000B334(); // Unsure of return type/args
    void fn_8000B370(); // Unsure of return type/args
    void fn_8000B4A0(); // Unsure of return type/args
    void fn_8000B610(); // Unsure of return type/args
    void fn_8000B7F4(); // Looks to be the main game loop or something similar?

    extern SceneID sCurrSceneId;
    extern Scene* sCurrScene;
    extern Scene* sSceneTable[SCENE_MAX];
};

extern s32 lbl_804D80B0; // Definitely not AppearPointSlot, will need to re-evaluate this.

// sinit(or maybe i think its an sinit?) of fn_8000B880() called here

#endif
