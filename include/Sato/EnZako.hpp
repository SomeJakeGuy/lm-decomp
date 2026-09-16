#ifndef EN_ZAKO_HPP
#define EN_ZAKO_HPP

#include "Sato/EnThought.hpp"
#include "macros.h"

dummy_float_data();
enemies_float_data();


char path_name[] = "path_name";

class EnZako : public EnThought {
public:
    /* 0x08 */ virtual ~EnZako();
    /* 0x0C */ virtual void vt_0C();
    /* 0x10 */ virtual void vt_10();
};

#endif
