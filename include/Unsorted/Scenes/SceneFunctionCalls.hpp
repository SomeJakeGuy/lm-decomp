#ifndef SCENE_UNK_FUNCTIONS_HPP
#define SCENE_UNK_FUNCTIONS_HPP

#include <types.h>
#include <dolphin/mtx.h>

class JKRMemArchive;
class J2DPicture;
class LMDvdFileInfo;

// externs
extern void fn_80066FAC(JKRMemArchive*);
extern void fn_80188594(void*, u32, u32);
extern void fn_8004D4C8();
extern void fn_80188714(void*);
extern void fn_80188638();
extern bool fn_80188740();
extern void fn_80009490();
extern void fn_8005FD80();
extern void fn_8003EB44();
extern void fn_80009B80();
extern void fn_8000A40C(f32, f32, f32, f32, f32, f32, Mtx, s32, s32, u32);

// SceneManager calls these, unsure of types/args
extern u8 fn_8018A8B4();
extern void fn_8018A8BC(s32);
extern void fn_80008394();
extern void fn_800083B4(s32);
extern bool fn_8018A860();
extern u32 fn_80185938();
extern void fn_8000AD48();
extern void fn_8000ADA0();
extern void fn_800081A8(void*); //Probable same TU as below
extern void fn_8000812C(void*);
extern void fn_800083A4(s32);
extern void fn_80009540(u16);
extern void fn_80185910();
extern void fn_80009580();
extern void fn_8000ADCC();
extern void fn_8018865C();
extern void fn_80188710();
extern void fn_80005E04();

// Definitely not from SceneManager's data
extern s32 lbl_804D7FF0;

// SelectScene calls these, unsure of types/args
extern void* fn_800739A4(s32);

#endif
