#include "Unsorted/SaveData.hpp"
#include "dolphin/os.h"
#include "macros.h"
#include <dolphin/card.h>
#include <stdio.h>

static f32 card_float_data[5] =
{ 0.85f, 1.0f, 0.9f, 0.75f, 0.3f };

static char* sSaveDataFileName = "LUIGI_MANSION_SAVEDATA_v3";


void* lbl_803E7300[0x6060 / 4];

struct MemoryCard {
    /* 0x0000 */ s32 _0;
    /* 0x0004 */ s32 _4;
    /* 0x0008 */ u8 _8[0x2360 - 0x8];
    /* 0x2360 */ void* mWorkArea[CARD_WORKAREA_SIZE];
};

void initSaveData() {

}

void mountDetachCallback(s32 chan, s32 result) { }


bool mountMemoryCard(MemoryCard* pCard) {
    s32 err = CARDMount(0, pCard->mWorkArea, mountDetachCallback);

    switch (err) {
        case CARD_RESULT_IOERROR:
        case CARD_RESULT_FATAL_ERROR:
            pCard->_4 = 8;
            return false;
        case CARD_RESULT_ENCODING:
            pCard->_4 = 3;
            return false;
        case CARD_RESULT_NAMETOOLONG:
        case CARD_RESULT_LIMIT:
        case CARD_RESULT_NOPERM:
        case CARD_RESULT_INSSPACE:
        case CARD_RESULT_NOENT:
        case CARD_RESULT_EXIST:
        case CARD_RESULT_READY:
            if (CARDCheck(0) == CARD_RESULT_READY) {
                return true;
            }
            pCard->_4 = 4;
            return false;
        case CARD_RESULT_NOCARD:
            pCard->_4 = 4;
            return false;
        default:
            return false;
    }
}

static void readSaveData(CARDFileInfo* pInfo);

bool openSaveData() {
    CARDFileInfo fileInfo;

    if (CARDOpen(0, sSaveDataFileName, &fileInfo) == CARD_RESULT_READY) {
        readSaveData(&fileInfo);
        CARDClose(&fileInfo);
        return true;
    }

    return false;
}

s32 checkForFreeMemoryCardBlocks() {
    s32 byteNotUsed;
    s32 fileNotUsed;
    STACK_PAD_VAR(2); // TODO: Remove

    CARDFreeBlocks(0, &byteNotUsed, &fileNotUsed);

    if ((u32)byteNotUsed < SAVE_DATA_SIZE) {
        return 1;
    }

    if (fileNotUsed < 1) {
        return 2;
    }

    return 0;
}


void fn_801865A0(void* pStart) {
    memcpy(&lbl_803E7300, pStart, 0x1C00);
    OSCalendarTime time;
    OSTicksToCalendarTime(OSGetTime(), &time);
    strcpy((char*)&lbl_803E7300[0x700], "Luigi's Mansion");
    sprintf((char*)&lbl_803E7300[0x708], "Last saved on %d/%d", time.mon + 1, time.mday);
}

static void readSaveData(CARDFileInfo* pInfo) {

}
