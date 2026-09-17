#ifndef SA_EN_GEN_UTILITY_HPP
#define SA_EN_GEN_UTILITY_HPP

#include "JSystem/JORReflexible.hpp"
#include "Koga/Observer.hpp"
#include "Sato/EnemyStrategy.hpp"

static float lbl_804D5FE8 = 0.73;
static float lbl_804D5FEC = 2500;
static char lbl_804D5FF0[] = "pnt0_x";
static char lbl_804D5FF8[] = "pnt0_y";
static char lbl_804D6000[] = "pnt0_z";

// The first void is GeneratorEvent
class SaEnGenUtility: public EnemyStrategy, public Koga::Observer<void, void> {
public:
    SaEnGenUtility();
    virtual ~SaEnGenUtility();

};

class SaEnZakoUtility {
public:
    SaEnZakoUtility();

    virtual void vt_08() = 0;
    virtual ~SaEnZakoUtility();

    /* probably a setter */ void fn_80143810(void* param1, void* param2);

private:
    /* 0x04 */ void* _04;
    /* 0x08 */ void* _08;
    /* 0x0c */ bool _0c;
    /* 0x0d - 0x41 */ u8 _0d[0x41-0xd];
    /* 0x41 */ u8 _41;
}; 


#endif
