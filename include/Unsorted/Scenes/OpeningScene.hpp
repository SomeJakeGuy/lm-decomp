#ifndef OPENING_SCENE_HPP
#define OPENING_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace OpeningScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sOpeningScene;
}

#endif
