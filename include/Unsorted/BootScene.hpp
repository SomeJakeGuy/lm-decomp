#ifndef BOOT_SCENE_H
#define BOOT_SCENE_H

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

class BootScene {
    public:
        static void init();
        static void destroy();
        static u32 update();
        static void draw();

        static Scene sBootScene;

    private:
        static void loadStaticData();
        static void loadStaticDataArchives() ;
        static void dvdFileOpenCallback(void*, LMDvdFileInfo*);
        u8* getStaticDataArr();
        

        static s32 lbl_804D8110;
        static BootSceneState sCurBootSceneState;
        static u16 lbl_804D8118;
        static f32 lbl_804D811C;
        static J2DPicture* sNintendoLogoPicture;
        static JKRMemArchive* sStaticDataArchive;
};

#endif
