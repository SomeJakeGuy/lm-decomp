#ifndef _LM_DVD_FILE_H_
#define _LM_DVD_FILE_H_

#include <dolphin.h>

class JKRMemArchive;

#define MAX_FILE_INFO_ARR 64

class LMDvdFileInfo;

typedef void (*LMDvdFileInfoCallback)(void* param_1, LMDvdFileInfo* param_2);

class LMDvdFileInfoBlock {
public:
    void fn_800071D0(u32);
    s32 fn_800071C0();
public:
    /* 0x0 */ u32 _0;
};

class LMDvdFileInfo : public DVDFileInfo {
public:
    void fn_80006E18();

    s32 getUnk70();
    LMDvdFileInfoBlock* getUnk64();
    u32 getLength();
    JKRMemArchive* getArchive();

public:
    /* 0x3C */ OSMessageQueue _3C;
    /* 0x5C */ s32 _5C;
    /* 0x60 */ s32 _60;
    /* 0x64 */ LMDvdFileInfoBlock* _64;
    /* 0x68 */ LMDvdFileInfoBlock* _68;
    /* 0x6C */ JKRMemArchive* mArchive;
    /* 0x70 */ s32 _70;
    /* 0x74 */ LMDvdFileInfoCallback _74;
    /* 0x78 */ LMDvdFileInfoCallback _78;
    /* 0x7C */ LMDvdFileInfo* _7C;
    /* 0x80 */ u8 _80;
    /* 0x84 */ s32 _84;
};

class LMDvdFile {
public:
    void init();
    bool open(const char* pFileName, s32);
    s32 open(const char* pFileName, LMDvdFileInfoCallback, LMDvdFileInfoBlock*, s32);
    void checkDVDStatus();

    static LMDvdFileInfo* getFileInfoArray();
    static BOOL checkCurUnk0();
    static s32 getCurUnk4();
    static void checkCurDVDStatus();
    static void closeFile(void *pMsg, LMDvdFileInfo* pInfo);

    static LMDvdFileInfo sFileInfoArray[MAX_FILE_INFO_ARR];
    static LMDvdFile sCurDvdFile;
public:
    /* 0x00 */ s32 _0;
    /* 0x04 */ s32 _4;
    /* 0x08 */ LMDvdFileInfo* _8;
    /* 0x10 */ u8 _10[0x2C - 0x10];
};

s32 LMDvdFileOpen(const char* pFIleName, s32);
s32 LMDvdFileOpen(const char *pFileName, LMDvdFileInfoCallback param_2, s32 param_3, s32 param_4);
void* fn_80006930(const char*, LMDvdFileInfoBlock*);
JKRMemArchive* LMOpenMemArchive(const char* pFileName, void*);

void* fn_80006258(u32 size, int align);

#endif
