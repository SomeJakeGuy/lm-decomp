#ifndef _80006258_H_
#define _80006258_H_

#include <dolphin.h>

#define MAX_FILE_INFO_ARR 64

class LMDvdFileInfo : public DVDFileInfo {
public:
    void fn_80006E18();

public:
    /* 0x3C */ OSMessageQueue _3C;
    /* 0x5C */ s32 _5C;
    /* 0x60 */ s32 _60;
    /* 0x64 */ s32 _64;
    /* 0x68 */ s32 _68;
    /* 0x6C */ s32 _6C;
    /* 0x70 */ s32 _70;
    /* 0x74 */ s32 _74;
    /* 0x78 */ s32 _78;
    /* 0x7C */ LMDvdFileInfo* _7C;
    /* 0x80 */ u8 _80;
    /* 0x84 */ s32 _84;
};

class LMDvdFile {
public:
    void fn_800063B8();
    bool open(const char* pFileName, s32);
    s32 open(const char* pFileName, s32, s32, s32);

    static LMDvdFileInfo* getFileInfoArray();

    static LMDvdFileInfo sFileInfoArray[MAX_FILE_INFO_ARR];
    static LMDvdFile sCurDvdFile;
public:
    /* 0x00 */ s32 _0;
    /* 0x04 */ s32 _4;
    /* 0x08 */ LMDvdFileInfo* _8;
    /* 0x10 */ u8 _10[0x2C - 0x10];
};

s32 LMDvdFileOpen(const char* pFIleName, s32);

//TODO: Is this apart of 80005EB8.cpp? I put it here since to prevent inlining issues
void* fn_80006258(u32 size, int align);

#endif
