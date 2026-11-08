#include "System/Scenes/StuffRollScene.hpp"

namespace StuffRollScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();
    
    Scene sStuffRollScene = {
        "STUFFROLL", 
        1, 
        init, 
        update, 
        draw, 
        destroy
    };
}
