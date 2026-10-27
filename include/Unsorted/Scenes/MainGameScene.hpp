#ifndef MAIN_GAME_SCENE_HPP
#define MAIN_GAME_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace MainGameScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sMainGameScene;
}

#endif
