#include "Unsorted/Scenes/EndingScene.hpp"
#include "Unsorted/LMDvdFile.hpp"
#include "Unsorted/Scenes/Scene.hpp"
#include "Unsorted/Scenes/SceneFunctionCalls.hpp"
#include "Unsorted/BackgroundMusic.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()

#define MAX_PLAYER_RANKS 7

namespace EndingScene {

    char sMansionBackgrounds[RANK_A + 1][20] = {
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

    char sMansionFramed[RANK_A + 1][20] = {
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

    char sRankNames[RANK_A + 1][32] = {
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
        fn_800061B8(2);
        fn_80057904(0x78, 0x1A4, 0xB4);
        fn_800061B8(6);
        lbl_804D8108 = 0; 

        sEndMsgImg.init();
        sMansionFrontImg.init();
        sEndMansionSizeImg.init();
        sEndRankMsgImg.init();
        sEndRankImg.init();
        sTheEndImg.init();
        sEndFrameImg.init();

        fn_800061B8(3);
        sEndMsgImg._0 = LMDvdFileOpen("Ending/ENGLISH/end_msE.bti", 0); // End Dialogue img, "And so the matter of the ghosts..."
        sEndMsgImg.set08To14(0, 0x2D0, 0xB4, 0xB4);

        sMansionFrontImg._0 = LMDvdFileOpen("Ending/house_00.bti", 0); // Normal Mansion img, could be the same from Title Screen?
        sMansionFrontImg.set08To14(0x168, 0x2D0, 0xB4, 0xB4);

        LMDvdFileOpen(sMansionBackgrounds[sPlayerRank], fn_8000D064, nullptr, &sEndMansionSizeImg._0); // Different House/Tent Sizes 
        fn_800061B8(5);

        sEndMansionSizeImg.set08To14(0x2D0, 0x528, 0xB4, 0xB4);
        sEndRankMsgImg.set08To14(0x348, 0x4B0, 0x78, 0x78);
        sEndRankImg.set08To14(0x3C0, 0x4EC, 0x78, 0x78);
        sTheEndImg.set08To14(0x5DC, 0x6CC, 0x78, 0x78);
        sEndFrameImg.set08To14(0x528, 0x9D8, 0xB4, 0xB4);

        fn_800061B8(2);

        switch (sPlayerRank) {
            case RANK_H:
                // The Mansion Disappeared without a trace...
                LMDvdFileOpen("Ending/ENGLISH/mes_bE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_BAD;
                break;
            case RANK_G:
                // Welcome to Luigi's NEW Mansion!
                LMDvdFileOpen("Ending/ENGLISH/mes_gE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_GOOD;
                break;
            case RANK_A:
                // Congratulations, Your Mansion is Complete!
                LMDvdFileOpen("Ending/ENGLISH/mes_VE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_EXCELLENT;
                break;
            default:
                // Welcome to Luigi's NEW Mansion!
                LMDvdFileOpen("Ending/ENGLISH/mes_gE.bti", fn_8000D064, nullptr, &sEndRankMsgImg._0);
                sBGMId = BGM_ENDING_GOOD;
                break;
        }

        LMDvdFileOpen(sRankNames[sPlayerRank], fn_8000D064, nullptr, &sEndRankImg._0); // Rank X img.
        LMDvdFileOpen("Ending/ENGLISH/me_kanE.bti", fn_8000D064, nullptr, &sTheEndImg._0); // The End img.
        LMDvdFileOpen(sMansionFramed[sPlayerRank], fn_8000D064, nullptr, &sEndFrameImg._0); // Same as Mansion Background but framed img.
    }

    SceneID update() {
        if (lbl_804D8108 < 0xA8C) {
            lbl_804D8108++;
        }

        if (lbl_804D8108 >= 0xA8C) {
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
