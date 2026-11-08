#include "System/Scenes/MainGameScene.hpp"

namespace MainGameScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();

    Scene sMainGameScene = {
        "MAIN GAME",
        2,
        init,
        update,
        draw,
        destroy
    };

    
}
