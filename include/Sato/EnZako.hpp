#ifndef EN_ZAKO_HPP
#define EN_ZAKO_HPP

#include "Sato/EnThought.hpp"
#include "macros.h"

dummy_float_data()
static float lbl_8035A390[8] = { 1.0f, 0.95f, 0.9f, 0.85f, 1.0f, 0.9f, 0.75f, 0.3f };
char path_name[] = "path_name";

class EnZako : public EnThought {
public:
    /* 0x08 */ virtual ~EnZako();
    /* 0x0C */ virtual void vt_0C();
    /* 0x10 */ virtual void vt_10();
};

#endif
