#ifndef LM_DVD_THREAD_HPP
#define LM_DVD_THREAD_HPP

#include <types.h>

class LMDvdFileInfo;

void initDvdThread();
void sendDvdRequest(LMDvdFileInfo*);

#endif
