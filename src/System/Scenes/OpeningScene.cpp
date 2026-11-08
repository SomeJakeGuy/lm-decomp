#include "System/Scenes/OpeningScene.hpp"

namespace OpeningScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();

    Scene sOpeningScene = {
        "OPENING",
        2,
        init,
        update,
        draw,
        destroy
    };
}
