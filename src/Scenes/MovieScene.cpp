#include "Scenes/MovieScene.hpp"

namespace MovieScene {    
    Scene sMovieScene = {
        "MOVIE", 
        1, 
        init, 
        update, 
        draw, 
        destroy
    };
}
