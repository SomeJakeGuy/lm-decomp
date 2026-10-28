#ifndef ENDING_SCENE_HPP
#define ENDING_SCENE_HPP

#include "Unsorted/Scenes/Scene.hpp"
#include "Unsorted/LMDvdFileBlock.hpp"
#include "Unsorted/80005EB8.hpp"
#include "types.h"

enum MansionRank {
    RANK_NONE,
    RANK_H,
    RANK_G,
    RANK_F,
    RANK_E,
    RANK_D,
    RANK_C,
    RANK_B,
    RANK_A,
};

struct EndingImage {
    /* 0x00 */ LMDvdFileInfoBlock* _0; // Probably data stream / size?
    /* 0x04 */ u32 _4;
    /* 0x08 */ u32 _8;
    /* 0x0C */ u32 _C;
    /* 0x10 */ u32 _10;
    /* 0x14 */ u32 _14;
    /* 0x18 */ u16 _18;

    inline void init() {
        _0 = nullptr;
        _4 = 0;
        _8 = 0;
        _10 = 0;
        _C = 0;
        _14 = 0;
        _18 = 0;
    }

    inline void update() {
        if (_4 >= _C) {
            if (_14 != 0) {
                f32 temp = (f32)(_4 - _C) / (f32)_14;
                if (temp > 1.0f) {
                    temp = 1.0f;
                }

                f32 temp2 = 255.0f * temp;
                _18 = 255 - (temp2 < 0.0f ? (s32)(temp2 - 0.5f) : (s32)(0.5f + temp2));
            }
        }
        else if (_4 >= _8) {
            if (_10 != 0) {
                f32 temp = (f32)(_4 - _8) / (f32)_10;
                if (temp > 1.0f) {
                    temp = 1.0f;
                }

                f32 temp2 = 255.0f * temp;
                _18 = (s16)(temp2 < 0.0f ? (s32)(temp2 - 0.5f) : (s32)(0.5f + temp2));
            }
        }

        if (_4 < -1) {
            _4++;
        }
    }

    inline void set08To14(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
        _8 = param_1;
        _10 = param_3;
        _C = param_2;
        _14 = param_4;
    }

    inline void destroy() {
        fn_80006138(_0);
    }
}; // size 0x1c

namespace EndingScene {
    void setPlayerRank(u32);
    u32 getPlayerRank();

    void init();
    SceneID update();
    void draw();
    void destroy();

    extern Scene sEndingScene;
}

static u32 sPlayerRank; // MansionRank
static u32 sBGMId;
static s32 lbl_804D8108;

#endif
