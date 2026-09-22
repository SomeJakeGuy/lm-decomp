#include "Sato/EnZako.hpp"

EnZako::EnZako() {
    
}

EnZako::~EnZako() {
    
}


void EnZako::vt_0C() {
    getStrategy()->update();
}


void EnZako::vt_10() {
    getStrategy()->mpZako = 0;
}
