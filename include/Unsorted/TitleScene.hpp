#ifndef TITLE_SCENE_HPP
#define TITLE_SCENE_HPP

#include "Unsorted/Scene.hpp"

namespace TitleScene {
    void init();
    u32 update();
    void draw();
    void destroy();

    extern Scene sTitleScene;
};


#endif
