#include "Sato/EnZako.hpp"

EnZako::~EnZako() {

}


void EnZako::vt_0C() {
    mpStrategy->update();
}


void EnZako::vt_10() {
    mpStrategy->mpZako = 0;
}
