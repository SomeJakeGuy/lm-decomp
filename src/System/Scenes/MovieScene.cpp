#include "System/Scenes/MovieScene.hpp"

namespace MovieScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();

    Scene sMovieScene = {
        "MOVIE", 
        2, 
        init, 
        update, 
        draw, 
        destroy
    };
}
