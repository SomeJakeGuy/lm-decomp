#ifndef TITLE_SCENE_HPP
#define TITLE_SCENE_HPP

#include "Unsorted/Scene.hpp"

class TitleScene {
    public:
        static void init();
        static u32 update();
        static void draw();
        static void destroy();

        static Scene sTitleScene;
};


#endif
