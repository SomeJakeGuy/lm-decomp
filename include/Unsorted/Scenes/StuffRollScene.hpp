#ifndef STUFF_ROLL_SCENE_HPP
#define STUFF_ROLL_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace StuffRollScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sStuffRollScene;
}

#endif
