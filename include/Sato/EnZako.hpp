#ifndef EN_ZAKO_HPP
#define EN_ZAKO_HPP

#include "Koga/ToolData.hpp"
#include "Sato/EnThought.hpp"
#include "macros.h"

dummy_float_data();
enemies_float_data();

class EnZako : public EnThought {
public:
    EnZako();
    /* 0x08 */ virtual ~EnZako();
    /* 0x0C */ virtual void vt_0C();
    /* 0x10 */ virtual void vt_10();

    void fn_800C1F38(const Koga::ToolData::JMapData*);
    bool fn_800C1F5C();
    Koga::ToolData* fn_800C1FF4();
    void fn_800C1FFC(); // Not sure about return type/args
    void* fn_800C211C(); // Not sure about return type/args, could be bool too?

    // Not sure if these do belong here or in Enthought, but _95C belongs here for sure.
    /* 0x94C */ u16 _94C;
    /* 0x94E */ u8 padding[0x2];
    /* 0x950 */ void* _950;
    /* 0x954 */ void* _954;
    /* 0x958 */ void* _958;
    /* 0x95C */ Koga::ToolData _95C;
};

#endif
