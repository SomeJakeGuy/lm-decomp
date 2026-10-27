#ifndef ENDING_SCENE_HPP
#define ENDING_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace EndingScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sEndingScene;
}

#endif
