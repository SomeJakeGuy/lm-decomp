#ifndef EN_THOUGHT_HPP
#define EN_THOUGHT_HPP

#include "Sato/IncludeStrategy.hpp"
#include <JSystem/JORReflexible.hpp>
#include "Koga/ValueControl.hpp"
#include "macros.h"

namespace Koga {
    class EnManager;
}

class MoveObjAlphaControl : public Koga::ValueControl<int> {
public:
    MoveObjAlphaControl();

    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0c */ f32 _0c;
    /* 0x10 */ void* _10;
    /* 0x14 */ void* _14;
    /* 0x18 */ void* _18; /* seems to be an object */
};

/**
 * 0x0 - IncludeStrategy
 * 0x808 - JORReflexible
 */
class EnThought : public IncludeStrategy, public JORReflexible  {
public:
    EnThought() { };
    virtual ~EnThought();
    virtual void vt_0C() = 0; // Did not check args/return type
    virtual void vt_10(); // Did not check args/return type

    /* 0x808 */ void* _808; //Unknown
    /* 0x80C */ Koga::EnManager* _80C;
    /* 0x810 - 0x824 */ void* _810[0x5]; // Unknown
    /* 0x828 - 0x888 */ void* _828[0x18]; // Maybe some Array?
    /* 0x88C */ u32 _88C;
    // There is some EnemyStrategy, TVec3F and some other ToolData probably.
};

#endif
