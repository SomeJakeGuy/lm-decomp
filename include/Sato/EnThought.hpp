#ifndef EN_THOUGHT_HPP
#define EN_THOUGHT_HPP

#include "Sato/IncludeStrategy.hpp"
#include <JSystem/JORReflexible.hpp>

class EnThought : public JORReflexible, public IncludeStrategy {
    EnThought();
    virtual ~EnThought();
    virtual void vt_0C(); // Did not check args/return type
    virtual void vt_10(); // Did not check args/return type

    /* 0x808 */ void* _808; //Unknown
    /* 0x80C */ void* _80C; //Unknown
    /* 0x810 - 0x824 */ void* _810[0x5]; // Unknown
    /* 0x828 - 0x888 */ void* _828[0x18]; // Maybe some Array?
    /* 0x88C */ u32 _88C;
    // There is some EnemyStrategy, TVec3F and some other ToolData probably.
};

#endif
