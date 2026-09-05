#ifndef ENEMY_GEN_MANAGER_HPP
#define ENEMY_GEN_MANAGER_HPP

#include <types.h>
#include <JSystem/JORReflexible.hpp>

#include "Koga/Array.hpp"
#include "Koga/Message.hpp"
#include "Koga/ToolData.hpp"
#include "Sato/IncludeStrategy.hpp"

namespace Koga {
    class EnManager;
}

namespace JGeometry {
    template<> class TVec3<f32>;
}

class unkEnemyGen1 : public Koga::Array<void*, 0xF> {
public:
    unkEnemyGen1() {}
    ~unkEnemyGen1() {}
};

class EnemyGenerator : public JORReflexible, public IncludeStrategy {
public:
    EnemyGenerator();
    virtual ~EnemyGenerator();

    void fn_800C2500();
    void fn_800C2560();
    void fn_800C25F0(int, int); // Need to validate arg / return type.
    void fn_800C2784(); // Need to validate arg / return type.
    Koga::ToolData* fn_800C2798(); // Need to validate arg / return type.
    u32 fn_800C2830(char*);

    /* 0x808 */ ToolDataRef _808; // Maybe some generator path? 
    /* 0x810 */ Koga::EnManager* _810;
    /* 0x814 */ s32 _814; // Generator type? See vt_C
    /* 0x818 */ Koga::ToolData _818;
    /* 0x820 */ unkEnemyGen1 _820;
    /* 0x860 */ u32 _860;
    /* 0x864 */ JGeometry::TVec3f mPos;
    /* 0x870 */ u16 _870;
};

namespace Koga {
    class EnemyGenManager : public JORReflexible, public MessageReceiver {
    public:
        EnemyGenManager();
        /* 0x08 */ virtual ~EnemyGenManager();
        /* 0x0C */ virtual BOOL vt_0C(ToolDataRef*);
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
