#ifndef LM_DVD_FILE_HPP
#define LM_DVD_FILE_HPP

#include <JSystem/JKernel/JKRMemArchive.hpp>
#include <dolphin.h>

class JKRMemArchive;
class LMDvdFileInfo;

typedef void (*LMDvdFileInfoCallback)(void* param_1, LMDvdFileInfo* param_2);

#define MAX_FILE_INFO_ARR 64

class LMDvdFileInfo : public DVDFileInfo {
public:
    s32 getUnk70();
    u8* getFileBuffer();
    u32 getLength();
    JKRMemArchive* getArchive();

public:
    /* 0x3C */ OSMessageQueue _3C;
    /* 0x5C */ s32 _5C;
    /* 0x60 */ s32 mAlignedFileSize;
    /* 0x64 */ u8* mFileBuffer;
    /* 0x68 */ u8* mDecompBuffer;
    /* 0x6C */ JKRMemArchive* mArchive;
    /* 0x70 */ s32 _70;
    /* 0x74 */ LMDvdFileInfoCallback mCallBack;
    /* 0x78 */ LMDvdFileInfoCallback mPostLoadFunc;
    /* 0x7C */ LMDvdFileInfo* _7C;
    /* 0x80 */ u8 mHeapGroupID;
    /* 0x84 */ JKRMemBreakFlag mBufferBreakFlag;
};

class LMDvdFile {
public:
    void init();
    bool open(const char*, u8*);
    void* open(const char*, LMDvdFileInfoCallback, u8*, s32);
    void checkDVDStatus();

    static LMDvdFileInfo* getFileInfoArray();
    static BOOL checkCurUnk0();
    static s32 getCurUnk4();
    static void checkCurDVDStatus();
    static void closeFile(void*, LMDvdFileInfo*);

    //TODO review these later to see if these can not be static?
    static void decompressFile(void*, LMDvdFileInfo*);
    static void mountFileFromArchive(void*, LMDvdFileInfo*);
    static void decompressAndMountArchive(void*, LMDvdFileInfo*);

    static LMDvdFileInfo sFileInfoArray[MAX_FILE_INFO_ARR];
    static LMDvdFile sCurDvdFile;
public:
    /* 0x00 */ s32 _0;
    /* 0x04 */ s32 _4;
    /* 0x08 */ LMDvdFileInfo* _8;
    /* 0x10 */ u8 _10[0x2C - 0x10];
};

void* LMDvdFileOpen(const char*, u8*);
void* LMDvdFileOpen(const char*, LMDvdFileInfoCallback, u8*, s32);
void* fn_80006930(const char*, u8*);
JKRMemArchive* LMOpenMemArchive(const char*, void*);
u8* fn_80006258(u32, int);

extern BOOL lbl_804D8028;

#endif
