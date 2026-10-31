#ifndef LM_DVD_THREAD_HPP
#define LM_DVD_THREAD_HPP

#include <types.h>

class LMDvdFileInfo;
struct LMDvdThread;

namespace LMDvdThreading {    
    void init();
    void sendDvdRequest(LMDvdFileInfo*);
    static void createDvdThreadCallback(LMDvdThread*);
    static void initDvdThread(LMDvdThread*);
}

#endif
