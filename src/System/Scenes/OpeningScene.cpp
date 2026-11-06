#include "System/Scenes/OpeningScene.hpp"

namespace OpeningScene {
    Scene sOpeningScene = {
        "OPENING",
        2,
        init,
        update,
        draw,
        destroy
    };
}
