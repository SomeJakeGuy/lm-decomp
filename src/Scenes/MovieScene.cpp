#include "Scenes/MovieScene.hpp"

namespace MovieScene {    
    Scene sMovieScene = {
        "MOVIE", 
        2, 
        init, 
        update, 
        draw, 
        destroy
    };
}
