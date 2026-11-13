#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXCull.h>
#include <JSystem/JKernel/JKRExpHeap.hpp>

#include "System/Scenes/SceneManager.hpp"
#include "System/Scenes/MainGameScene.hpp"
#include "System/Scenes/MainGameSceneUtil2.hpp"
#include "System/Scenes/MainGameSceneUtil3.hpp"
#include "System/Scenes/SceneFunctionCalls.hpp"
#include "System/DataOnly.hpp"
#include "System/Memory.hpp"

#include "Unsorted/GamePad.hpp"
#include "Unsorted/80008418.hpp"
#include "Unsorted/80009B80.hpp"
#include "Unsorted/LMDisplayUtil.hpp"
#include "types.h"

namespace MainGameScene {
    s32 lbl_804D80E0;
    s32 lbl_804D80E4; // seems to be unused
    s32 lbl_804D80E8;
    s32 lbl_804D80EC;
    s32 lbl_804D80F0;
    s8 lbl_804D80F4;
    s32 lbl_804D80F8;
    s8 lbl_804D80FC;

    // requires fn_800AD39C to be more decompiled
    void fn_8000C90C() {
        if (lbl_804D80E0 != 0) {
            return;
        }

        if (fn_8000C8D8() && sGamePad->testTrigger(0x10) && SceneManager::lbl_804D8098 <= 2) {
            switch (MainGameScene::sCurMapNo) {
                case 6:
                case 2:
                    void* temp = fn_800AD39C(0); //checks against the 0x55 byte
                    lbl_804D80C4 = 3;
                    lbl_804D8438 = 0;
                    fn_80007E60(1);
                    fn_8018A678(1);
                    fn_8018A2A0(0x3804);
                    lbl_804D80E0 = 1;
                    fn_8007220C();
                    LMSetIntRenderModeVFilter(0x10);
                    fn_800531B8();
                    break;
            }
        }
    }

    void fn_8000C9EC() {
        if (lbl_804D80C4 == 0) {
            fn_8000C90C();
            return;
        }
        else if (lbl_804D80C4 == 3) {
            if (lbl_804D843C == 0 && lbl_804D80E0 == 1) {
                fn_80121944();
                lbl_804D80E0 = 2;
            }

            if (sGamePad->testTrigger(0x210)) {
                fn_8000CB78();
                return;
            }

            fn_80046864();
            
            switch (lbl_804D80E0) {
                case 1:
                    break;
                case 2:
                    if (fn_801219FC() == 0) {
                        lbl_804D80E0 = 3;
                    }
                    break;
                case 3:
                    fn_80053224();
                    break;
            }
        }
    }

    void fn_8000CAA0() {
        switch (lbl_804D80E0) {
            case 1:
                break;
            case 2:
                fn_80009B80();
                fn_80008654(&lbl_803A3820);
                GXSetViewportJitter(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, 1);
                GXSetScissor(0, 0, 640, 480);
                fn_80121AFC();
                break;
            case 3:
                fn_80008654(&lbl_803A3820);
                GXSetViewportJitter(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, 1);
                GXSetScissor(0, 0, 640, 480);
                fn_80121AFC();
                break;
        }

        fn_8005DF84();
        fn_8003E7B0(0);
    }
    
    void fn_8000CB78() {
        if (lbl_804D80E0 != 0 && lbl_804D80C4 == 3) {
            SceneManager::lbl_804D8088 = 0;
            lbl_804D80E0 = 0;
            lbl_804D80C4 = 0;
            lbl_804D8438 = 1;
            fn_8018A678(0);
            fn_8018A2A0(0x1037);
            fn_8018A2A0(0x3804);
            fn_8005332C();
            fn_801219C4();
            fn_80188760(lbl_804D8008 & 0xFF, 0);
            fn_8005DAFC();
            fn_80007E60(2);
            LMSetIntRenderModeVFilter(6);

            if (sUnusedHeap != nullptr) {
                sUnusedHeap->destroy();
            }
        }
    }
    
    void fn_8000CC18() {
        lbl_804D8438 = 0;
        fn_80007E60(1);
        fn_8018A2A0(0x3804);
        fn_8007220C();
        fn_80055114(lbl_804D80E8);
        lbl_804D80EC = 1;
    }

    void fn_8000CC60() {
        if (lbl_804D80C4 == 5) {
            if (lbl_804D80EC == 0) {
                lbl_804D8438 = 0;
                fn_80007E60(1);
                fn_8018A2A0(0x3804);
                fn_8007220C();
                fn_80055114(lbl_804D80E8);
                lbl_804D80EC = 1;
                return;
            }
            
            if (fn_80055270() != 0) {
                fn_8018A2A0(0x3804);
                fn_8000CD0C();
            }
        }
    }
    
    void fn_8000CCDC() {
        if (lbl_804D80EC != 0) {
            fn_8005DF84();
            fn_80055294();
        }
    }
    
    void fn_8000CD0C() {
        lbl_804D80C4 = 0;
        lbl_804D8438 = 1;
        fn_80055338();
        fn_80188760(lbl_804D8008 & 0xFF, nullptr);
        fn_80007E60(2);
        lbl_804D80EC = 0;
    }
    
    void fn_8000CD60() {
        if (!lbl_804D80F4) {
            lbl_804D80F0 = 0;
            lbl_804D80F4 = 1;
        }

        if (lbl_804D80C4 != 6) {
            return;
        }

        if (lbl_804D80F0 != 0) {
            lbl_804D80F0 = 0;
            lbl_804D80C4 = 0;
            fn_80187214();
            return;
        }

        if (sGamePad->testButton(0x200)) {
            lbl_804D80F0 = 1;
        }

        fn_80187218();
    }

    void fn_8000CDE0() {
        if (!lbl_804D80FC) {
            lbl_804D80F8 = 0;
            lbl_804D80FC = 1;
        }

        if (lbl_804D80C4 != 7) {
            return;
        }

        if (lbl_804D80F8 != 0) {
            lbl_804D80F8 = 0;
            lbl_804D80C4 = 0;
            fn_800518A0();
            return;
        }

        if (fn_800517D8() != 0) {
            lbl_804D80F8 = 1;
        }
    }
}
