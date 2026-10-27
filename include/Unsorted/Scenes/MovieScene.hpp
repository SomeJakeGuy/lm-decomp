#ifndef MOVIE_SCENE_HPP
#define MOVIE_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"

namespace MovieScene {
    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sMovieScene;
}

#endif
