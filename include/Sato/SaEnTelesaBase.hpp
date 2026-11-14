#ifndef SA_EN_TELESA_BASE_HPP
#define SA_EN_TELESA_BASE_HPP

#include "JSystem/JORReflexible.hpp"
#include "Sato/SaEnGenUtility.hpp"

class SaEnTelesaBase : public SaEnZakoUtility, public JORReflexible {
public: 
    SaEnTelesaBase();
    virtual ~SaEnTelesaBase();

    virtual void SaEnTelesaBase_vt_0C() = 0;
    virtual void SaEnTelesaBase_vt_0F() = 0;
    virtual void SaEnTelesaBase_vt_14() = 0;
};

#endif
