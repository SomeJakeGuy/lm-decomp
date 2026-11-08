#include "System/Scenes/EndingScene.hpp"
#include "System/Scenes/Scene.hpp"
#include "System/Scenes/SceneFunctionCalls.hpp"

#include "System/DiscFile.hpp"
#include "System/Memory.hpp"

#include "Unsorted/BackgroundMusic.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()

#define MAX_PLAYER_RANKS 7
#define ENDING_SCENE_RESET_FRAME_COUNT 2700

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
    /* 0x00 */ u8* _0; // Probably data stream / size?
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
        freeMem(_0);
    }
}; // size 0x1c

namespace EndingScene {
    static void init();
    static SceneID update();
    static void draw();
    static void destroy();

    static char sMansionBackgrounds[RANK_A + 1][20] = {
        "Ending/h_P00.bti",
        "Ending/h_P00.bti",
        "Ending/h_P01.bti",
        "Ending/h_P02.bti",
        "Ending/h_P03.bti",
        "Ending/h_P04.bti",
        "Ending/h_P05.bti",
        "Ending/h_P06.bti",
        "Ending/h_P07.bti",
    };

    static char sMansionFramed[RANK_A + 1][20] = {
        "Ending/h_P00G.bti",
        "Ending/h_P00G.bti",
        "Ending/h_P01G.bti",
        "Ending/h_P02G.bti",
        "Ending/h_P03G.bti",
        "Ending/h_P04G.bti",
        "Ending/h_P05G.bti",
        "Ending/h_P06G.bti",
        "Ending/h_P07G.bti",
    };

    static char sRankNames[RANK_A + 1][32] = {
        "Ending/ENGLISH/ra_HE.bti",
        "Ending/ENGLISH/ra_HE.bti",
        "Ending/ENGLISH/ra_GE.bti",
        "Ending/ENGLISH/ra_FE.bti",
        "Ending/ENGLISH/ra_EE.bti",
        "Ending/ENGLISH/ra_DE.bti",
        "Ending/ENGLISH/ra_CE.bti",
        "Ending/ENGLISH/ra_BE.bti",
        "Ending/ENGLISH/ra_AE.bti",
    };

    Scene sEndingScene = {
        "ENDING", 
        1, 
        init, 
        update, 
        draw, 
        destroy
    };

    static u32 sPlayerRank;
    static u32 sBGMId;
    static s32 endingSceneFrameCount;

    static EndingImage sEndMsgImg;
    static EndingImage sMansionFrontImg;
    static EndingImage sEndMansionSizeImg;
    static EndingImage sEndRankMsgImg;
    static EndingImage sTheEndImg;
    static EndingImage sEndFrameImg;
    static EndingImage sEndRankImg;

    void setPlayerRank(u32 playerMoney) {
        u32 ranks[MAX_PLAYER_RANKS] = {5000000, 20000000, 40000000, 50000000, 60000000, 70000000, 100000000};
        sPlayerRank = MAX_PLAYER_RANKS;

        for (s32 i = 0; i < MAX_PLAYER_RANKS; i++) {
            if (playerMoney < ranks[i]) {
                sPlayerRank = i;
                break;
            }
        }
        
        sPlayerRank++;
        if (playerMoney == 0)  {
            sPlayerRank = RANK_NONE;
        }
    }

    u32 getPlayerRank() {
        return sPlayerRank;
    }

    void init() {
        setCurHeapGroupId(2);
        fn_80057904(0x78, 0x1A4, 0xB4);
        setCurHeapGroupId(6);
        endingSceneFrameCount = 0; 

        sEndMsgImg.init();
        sMansionFrontImg.init();
        sEndMansionSizeImg.init();
        sEndRankMsgImg.init();
        sEndRankImg.init();
        sTheEndImg.init();
        sEndFrameImg.init();

        setCurHeapGroupId(3);
        sEndMsgImg._0 = openDiscFile("Ending/ENGLISH/end_msE.bti", nullptr); // End Dialogue img, "And so the matter of the ghosts..."
        sEndMsgImg.set08To14(0, 0x2D0, 0xB4, 0xB4);

        sMansionFrontImg._0 = openDiscFile("Ending/house_00.bti", nullptr); // Normal Mansion img, could be the same from Title Screen?
        sMansionFrontImg.set08To14(0x168, 0x2D0, 0xB4, 0xB4);

        openDiscFileAsync(sMansionBackgrounds[sPlayerRank], fn_8000D064, nullptr, &sEndMansionSizeImg._0); // Different House/Tent Sizes 
        setCurHeapGroupId(5);

        sEndMansionSizeImg.set08To14(0x2D0, 0x528, 0xB4, 0xB4);
        sEndRankMsgImg.set08To14(0x348, 0x4B0, 0x78, 0x78);
        sEndRankImg.set08To14(0x3C0, 0x4EC, 0x78, 0x78);
        sTheEndImg.set08To14(0x5DC, 0x6CC, 0x78, 0x78);
        sEndFrameImg.set08To14(0x528, 0x9D8, 0xB4, 0xB4);

        setCurHeapGroupId(2);

        switch (sPlayerRank) {
            case RANK_H:
                // The Mansion Disappeared without a trace...
                openDiscFileAsync("Ending/ENGLISH/mes_bE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_BAD;
                break;
            case RANK_G:
                // Welcome to Luigi's NEW Mansion!
                openDiscFileAsync("Ending/ENGLISH/mes_gE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_GOOD;
                break;
            case RANK_A:
                // Congratulations, Your Mansion is Complete!
                openDiscFileAsync("Ending/ENGLISH/mes_VE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_EXCELLENT;
                break;
            default:
                // Welcome to Luigi's NEW Mansion!
                openDiscFileAsync("Ending/ENGLISH/mes_gE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_GOOD;
                break;
        }

        openDiscFileAsync(sRankNames[sPlayerRank], fn_8000D064, nullptr, &sEndRankImg._0); // Rank X img.
        openDiscFileAsync("Ending/ENGLISH/me_kanE.bti", fn_8000D064, nullptr, &sTheEndImg._0); // The End img.
        openDiscFileAsync(sMansionFramed[sPlayerRank], fn_8000D064, nullptr, &sEndFrameImg._0); // Same as Mansion Background but framed img.
    }

    SceneID update() {
        if (endingSceneFrameCount < ENDING_SCENE_RESET_FRAME_COUNT) {
            endingSceneFrameCount++;
        }

        if (endingSceneFrameCount >= ENDING_SCENE_RESET_FRAME_COUNT) {
            return SCENE_TITLE;
        }

        sEndMsgImg.update();
        sMansionFrontImg.update();
        sEndMansionSizeImg.update();
        if (sEndMansionSizeImg._4 == 0x384) {
            fn_80188760(sBGMId, 0);
        }

        sEndRankMsgImg.update();
        sEndRankImg.update();
        sTheEndImg.update();
        sEndFrameImg.update();

        return SCENE_ENDING;
    }

    void draw() {

    }

    void destroy() {
        sEndMsgImg.destroy();
        sMansionFrontImg.destroy();
        sEndMansionSizeImg.destroy();
        sEndRankMsgImg.destroy();
        sTheEndImg.destroy();
        sEndFrameImg.destroy();
        sEndRankImg.destroy();
        fn_80057A8C();
    }
}
