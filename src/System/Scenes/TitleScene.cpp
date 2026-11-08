#include "System/Scenes/TitleScene.hpp"

namespace TitleScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();

    Scene sTitleScene = {
        "TITLE",
        1,
        init,
        update,
        draw,
        destroy
    };
}
