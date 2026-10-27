#ifndef _LM_DVD_FILE_BLOCK_H_
#define _LM_DVD_FILE_BLOCK_H_

#include <types.h>

class LMDvdFileInfoBlock {
public:
    void fn_800071D0(LMDvdFileInfoBlock*);
    s32 size();

    /* 0x0 */ void* _0; // Probably data stream?
    /* 0x4 */ u32 mLength;
};

#endif
