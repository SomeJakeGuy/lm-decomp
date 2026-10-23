#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <types.h>
#include "Unsorted/Scenes/Scene.hpp"

class SceneManager {
    public:
        static u16 fn_8000B328();
        static void fn_8000B334(); // Unsure of return type/args
        static void fn_8000B370(); // Unsure of return type/args
        static void fn_8000B4A0(); // Unsure of return type/args
        static void fn_8000B610(); // Unsure of return type/args
        static void fn_8000B7F4(); // Looks to be the main game loop or something similar?

        static SceneID sCurrSceneId;

    private:
        static Scene* sCurrScene;
        static Scene* sSceneTable[SCENE_MAX];
};

extern s32 lbl_804D80B0; // Definitely not AppearPointSlot, will need to re-evaluate this.

// sinit(or maybe i think its an sinit?) of fn_8000B880() called here

#endif
