#ifndef ENEMY_GEN_MANAGER_HPP
#define ENEMY_GEN_MANAGER_HPP

#include <types.h>
#include <JSystem/JORReflexible.hpp>

#include "Koga/Message.hpp"
#include "Koga/ToolData.hpp"
#include "Sato/IncludeStrategy.hpp"
#include "dolphin/types.h"


class unkEnemyGen1 {
public:
    unkEnemyGen1(); // fn_800C31F0
    ~unkEnemyGen1(); // fn_800C31FC
};

class EnemyGenerator : public JORReflexible, public IncludeStrategy {
public:
    EnemyGenerator();
    virtual ~EnemyGenerator();

    void fn_800C2500();
    void fn_800C2560();
    void fn_800C25F0(); // Need to validate arg / return type.
    void fn_800C2784(); // Need to validate arg / return type.
    Koga::ToolData* fn_800C2798(); // Need to validate arg / return type.
    u32 fn_800C2830(char*);

    /* 0x808 */ Koga::ToolData* _808;
    /* 0x80C */ u32 _80C;
    /* 0x810 */ u32 _810;
    /* 0x814 */ u32 _814;
    /* 0x818 */ Koga::ToolData mToolData;
    /* 0x820 */ unkEnemyGen1 _820; //Maybe 0x3C large?
    /* 0x824 */ u32 _824[0xE];
    /* 0x85C */ u32 _85C;
    /* 0x860 */ u32 _860;
    /* 0x864 */ u32 _864[0x3];
    /* 0x870 */ u16 _870;
};

namespace Koga {
    class EnemyGenManager : public JORReflexible, public MessageReceiver {
    public:
        EnemyGenManager();
        /* 0x08 */ virtual ~EnemyGenManager();
        /* 0x0C */ virtual BOOL vt_C(ToolDataRef*); // fn_800C2A30
        /* 0x10 */ virtual BOOL vt_10(ToolDataRef*);
        /* 0x14 */ virtual BOOL vt_14(ToolDataRef*, char*);

        void fn_800C2F44();

        inline void setUnk8(bool val) { _8 = val; }
    public:
        /* 0x4 */  EnemyGenerator* mEnemyGens;
        /* 0x8 */ bool _8;
    };

};

#endif
