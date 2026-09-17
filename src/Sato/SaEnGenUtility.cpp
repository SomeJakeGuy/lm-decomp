#include "Sato/SaEnGenUtility.hpp"


/**
 * Construct this vtable in 0x60 (the only diff match), same in dt
 */
SaEnZakoUtility::SaEnZakoUtility() {
    _04 = 0;
    _08 = 0;
    _0c = true;
    _41 = 0xff;
}


SaEnZakoUtility::~SaEnZakoUtility() {}

void SaEnZakoUtility::fn_80143810(void* param1, void* param2) {
    _04 = param1;
    _08 = param2;
}
