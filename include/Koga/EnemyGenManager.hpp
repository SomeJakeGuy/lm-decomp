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

    void add(void**); //probably add member?
    void* remove(void**); //probably delete member;
};

class EnemyGenerator : public JORReflexible, public IncludeStrategy {
public:
    EnemyGenerator();
    virtual ~EnemyGenerator();

    void fn_800C2500();
    void fn_800C2560();
    void* fn_800C25F0(s32, s32); // Need to validate arg / return type.
    ToolDataRef fn_800C2784();
    Koga::ToolData* fn_800C2798();
    u32 fn_800C2830(const char*);
     // Need to validate arg / return type.
    void fn_800C287C(void*); // dynamic casts to EnZako and Koga::Observer<GeneratorEvent, void>

    /* 0x808 */ ToolDataRef _808; // Maybe some generator path? 
    /* 0x810 */ Koga::EnManager* _810;
    /* 0x814 */ s32 _814; // Generator type? See vt_C
    /* 0x818 */ Koga::ToolData _818;
    /* 0x820 */ unkEnemyGen1 _820;
    /* 0x860 */ s32 _860;
    /* 0x864 */ JGeometry::TVec3f mPos;
    /* 0x870 */ u16 _870;
};

namespace Koga {
    class EnemyGenManager : public JORReflexible, public MessageReceiver {
    public:
        EnemyGenManager();
        /* 0x04 */ virtual ~EnemyGenManager();
        /* 0x08 */ virtual BOOL vt_08(ToolDataRef*); // Checks to see if input is a generator, maybe something to do with adding/loading?
        /* 0x0C */ virtual BOOL vt_0C(ToolDataRef*); // Maybe something to do with removing / deleting
        /* 0x10 */ virtual BOOL vt_10(ToolDataRef*, char* message);

        void fn_800C2F44();
        void fn_800C2FE8(void*); // Need to validate arg / return type.
        void* fn_800C31DC(); // Something with IncludeStrategy?
        static ToolDataRef fn_800C31E4(Koga::ToolData*, s32);

        inline void setUnk8(bool val) { _8 = val; }
    public:
        /* 0x4 */  EnemyGenerator* mEnemyGens;
        /* 0x8 */ bool _8;
    };

};

#endif
