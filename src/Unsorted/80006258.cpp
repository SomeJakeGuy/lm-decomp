#include "Unsorted/80006258.hpp"
#include "Unsorted/80005EB8.hpp"
#include "dolphin/macros.h"
#include "dolphin/os/OSMessage.h"

#include <dolphin.h>
#include <JSystem/JUtility/JUTGamePad.hpp>

extern JUTGamePad* sGamePad;
extern void fn_800473F8(s16);
extern void fn_80006DF0();

BOOL lbl_804D8028;
s32 lbl_804D80AC;

LMDvdFileInfo LMDvdFile::sFileInfoArray[MAX_FILE_INFO_ARR];
LMDvdFile LMDvdFile::sCurDvdFile;

void* fn_80006258(u32 size, int align) {
    return fn_80006080(size, align);
}

LMDvdFileInfo* LMDvdFile::getFileInfoArray() {
    return &sFileInfoArray[0];
}

void fn_80006284() {
    s32 driveStatus = DVDGetDriveStatus();

    if (lbl_804D8028 != FALSE) {
        driveStatus = DVD_STATE_FATAL_ERROR;
    }

    switch (driveStatus) {
    case DVD_STATE_FATAL_ERROR:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    case DVD_STATE_END:
        lbl_804D80AC = 0;
        break;
    case DVD_STATE_BUSY:
        if (DVDCheckDisk() != FALSE) {
            lbl_804D80AC = 0;
        } else {
            driveStatus = 3;
            sGamePad->stopMotor();
            lbl_804D80AC = 1;
        }
        break;
    case DVD_STATE_COVER_CLOSED:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    case DVD_STATE_NO_DISK:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    case DVD_STATE_COVER_OPEN:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    case DVD_STATE_WRONG_DISK:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    case DVD_STATE_RETRY:
        sGamePad->stopMotor();
        lbl_804D80AC = 1;
        break;
    }
    fn_800473F8(driveStatus);
}

void LMDvdFile::fn_800063B8() {
    //TODO: Remove this
    FORCE_DONT_INLINE

    LMDvdFileInfo* block = _8->_7C;
    while (true) {
        s32 blockStatus;
        blockStatus = DVDGetCommandBlockStatus(&block->cb);
        if (blockStatus != 1) break;
    }
    _8 = block;
    _8->_64 = 0;
    _8->_68 = 0;
    _8->_6C = 0;
    _8->_78 = 0;
    _8->_74 = 0;
    _8->_80 = getCurHeapGroupId();

    OSReceiveMessage(&_8->_3C, nullptr, 0);
}

bool LMDvdFile::open(const char* pFileName, s32 param_2) {
    //TODO: Remove this
    FORCE_DONT_INLINE

    LMDvdFileInfo* block = _8;
    while (true) {
        s32 blockStatus;
        blockStatus = DVDGetCommandBlockStatus(&block->cb);
        if (blockStatus != 1) break;
    }

    DVDOpen((char*)pFileName, block);

    _8->_60 =  block->length + 0x1F & 0xFFFFFFE0;
    _8->_84 = 0;
    _8->_64 = param_2;

    _8->fn_80006E18();
    return true;
}

s32 LMDvdFile::open(const char* pFileName, s32 param_2, s32 param_3, s32 param_4) {
    _8->_74 = param_2;
    _8->_70 = param_4;

    LMDvdFileInfo* block = _8;

    while (true) {
        s32 blockStatus;
        blockStatus = DVDGetCommandBlockStatus(&block->cb);
        if (blockStatus != 1) break;
    }

    DVDOpen((char*)pFileName, block);
    _8->_60 =  block->length + 0x1F & 0xFFFFFFE0;
    _8->_84 = 0;
    _8->_64 = param_3;

    _8->fn_80006E18();
    _0++;

    return _8->_64;
}

void fn_800065A8() {
    fn_80006DF0();

    LMDvdFileInfo* curIndex = LMDvdFile::getFileInfoArray();

    LMDvdFile::sCurDvdFile._4 = 1;
    LMDvdFile::sCurDvdFile._0 = 0;
    LMDvdFile::sCurDvdFile._8 = LMDvdFile::getFileInfoArray();

    for (s32 i = 0; i < MAX_FILE_INFO_ARR; i++) {
        curIndex->_7C = &LMDvdFile::sFileInfoArray[i + 1];
        OSInitMessageQueue(&curIndex->_3C, &curIndex->_5C, 1);
        curIndex++;
    }

    LMDvdFile::sFileInfoArray[MAX_FILE_INFO_ARR - 1]._7C = LMDvdFile::getFileInfoArray();
}

s32 LMDvdFileOpen(const char* pFileName, s32 param_2) {
    LMDvdFile::sCurDvdFile.fn_800063B8();
    LMDvdFile::sCurDvdFile._8->_74 = 0;
    LMDvdFile::sCurDvdFile._8->_70 = 0;

    if (LMDvdFile::sCurDvdFile.open(pFileName, param_2)) {
        LMDvdFile::sCurDvdFile._0++;
    }

    u32 msg;

    OSReceiveMessage(&LMDvdFile::sCurDvdFile._8->_3C, &msg, 1);

    return LMDvdFile::sCurDvdFile._8->_64;
}
