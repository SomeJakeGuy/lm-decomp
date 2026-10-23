#ifndef BOOT_SCENE_HPP
#define BOOT_SCENE_HPP

#include <version.h>

#include "Unsorted/Scene.hpp"

class JKRMemArchive;
class J2DPicture;
class LMDvdFileInfo;

enum BootSceneState {
    STATE_0,
    STATE_1,
    STATE_2,
};

namespace BootScene {
    void init();
    void destroy();
    u32 update();
    void draw();

    void loadStaticData();
    void loadStaticDataArchives() ;
    void dvdFileOpenCallback(void*, LMDvdFileInfo*);
    u8* getStaticDataArr();

    extern Scene sBootScene;
    extern s32 lbl_804D8110;
    extern BootSceneState sCurBootSceneState;
    extern u16 lbl_804D8118;
    extern f32 lbl_804D811C;
    extern J2DPicture* sNintendoLogoPicture;
    extern JKRMemArchive* sStaticDataArchive;
};

#endif
