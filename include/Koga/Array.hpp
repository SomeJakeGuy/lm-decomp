#ifndef KOGA_ARRAY_H_
#define KOGA_ARRAY_H_

#include <types.h>

// TODO: This may not actually exist (ordering and the weird inline stuff).
// I want it to exist since if it doesn't then that means Koga wrote like 50 different variants of something that could've been written inside of a template.
// It also could exist because of the fact classes like MessageRecieverArray need to inherit something else in order to matchs
namespace Koga {
    template <typename T, s32 S>
    class Array {
    public:
        Array() { 
            FORCE_DONT_INLINE 
            mArraySize = 0; 
        }
        ~Array() { FORCE_DONT_INLINE }

        s32 getSize() const { return mArraySize; }
        void resetSize() { mArraySize = 0; }

        T& operator[](int idx) { return mArr[idx]; }
        const T& operator[](int idx) const { return mArr[idx]; }

        T* getArrayMember(s32 idx) const { return &mArr[idx]; }
        T* getArray() { return mArr; }
        
        T* getFirstMember() { return &mArr[0]; }
        T* getLastMember() { return &mArr[mArraySize]; }
        T* getMaxIter() { return &mArr[mArraySize - 1]; }
        
        void init(s32 num) {
            mArr = new T[num];
            mArraySize = num;
        }

        void addMember(T* member) {
            FORCE_DONT_INLINE
            mArr[mArraySize++] = *member;
        }

        T* eraseMember(T* pIter) {
            FORCE_DONT_INLINE
            if (getLastMember() - pIter - 1 > 0) {
                for (T* curr = pIter; (curr + 1) != getLastMember(); curr++) {
                    *curr = *(curr + 1);
                } 
            }
            
            mArraySize--;
            return pIter;
        }

    private:
        /* 0x00 */ T mArr[S];
        /* (0x4 * S) + 4 */ s32 mArraySize;
    };

};

#endif
