#ifndef TITLE_SCENE_HPP
#define TITLE_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace TitleScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sTitleScene;
};


#endif
