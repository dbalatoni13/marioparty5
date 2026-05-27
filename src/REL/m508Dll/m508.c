#include "game/board/main.h"
#include "game/board/effect.h"
#include "game/board/audio.h"
#include "game/board/scroll.h"
#include "game/board/model.h"
#include "game/board/masu.h"
#include "game/board/opening.h"
#include "game/board/capsule.h"
#include "game/board/branch.h"
#include "game/board/camera.h"
#include "game/board/player.h"
#include "game/board/guide.h"
#include "game/board/window.h"
#include "game/board/coin.h"
#include "game/board/roulette.h"
#include "game/board/star.h"
#include "game/board/capsule.h"
#include "game/board/status.h"
#include "game/board/com.h"

#include "game/animdata.h"
#include "game/armem.h"
#include "game/audio.h"
#include "game/card.h"
#include "game/charman.h"
#include "game/data.h"
#include "game/disp.h"
#include "game/dvd.h"
#include "game/esprite.h"
#include "game/fault.h"
#include "game/flag.h"
#include "game/frand.h"
#include "game/gamemes.h"
#include "game/gamework.h"
#include "game/hsfex.h"
#include "game/hsfformat.h"
#include "game/hsfload.h"
#include "game/hu3d.h"
#include "game/init.h"
#include "game/jmp.h"
#include "game/main.h"
#include "game/memory.h"
#include "game/mgdata.h"
#include "game/objdll.h"
#include "game/object.h"
#include "game/pad.h"
#include "game/perf.h"
#include "game/printfunc.h"
#include "game/process.h"
#include "game/saveload.h"
#include "game/sprite.h"
#include "game/sreset.h"
#include "game/thpmain.h"
#include "game/window.h"
#include "game/wipe.h"

#include "game/mg/actman.h"
#include "game/mg/colman.h"
#include "game/mg/score.h"
#include "game/mg/seqman.h"
#include "game/mg/timer.h"

#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "math.h"

typedef void (*VoidFunc)(void);
extern const VoidFunc _ctors[];
extern const VoidFunc _dtors[];

typedef struct M508Vec2_s {
    float unk_0;
    float unk_4;
} M508Vec2;

typedef struct M508Circle_s {
    float unk_0;
    float unk_4;
    float unk_8;
} M508Circle;

typedef struct M508Rect_s {
    float unk_0;
    float unk_4;
    float unk_8;
    float unk_C;
} M508Rect;

typedef struct M508Polygon_s {
    s32 unk_0;
    M508Vec2 *unk_4;
} M508Polygon;

typedef struct M508Sphere_s {
    float unk_0;
    float unk_4;
    float unk_8;
    float unk_C;
} M508Sphere;

typedef struct M508State_s {
    s32 unk_0;
    s32 unk_4;
} M508State;

typedef struct M508AnimRange_s {
    float unk_0;
    float unk_4;
} M508AnimRange;

typedef struct M508AnimCmd_s {
    s32 unk_0;
    s32 unk_4;
} M508AnimCmd;

typedef void (*M508ModelFunc)();

typedef struct M508ModelObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad34[0x124];
    s32 unk_158;
    u8 pad15C[4];
    float unk_160;
    float unk_164;
    float unk_168;
    float unk_16C;
    float unk_170;
    float unk_174;
    float unk_178;
    float unk_17C;
    float unk_180;
    s16 unk_184;
    u8 pad186[2];
    s32 unk_188;
    s32 unk_18C;
    s16 *unk_190;
    u8 pad194[0x1C];
    float unk_1B0;
    float unk_1B4;
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    s32 unk_1C4;
    s32 unk_1C8;
} M508ModelObj;

typedef struct M508ScoreData_s {
    s16 unk_0;
    s16 unk_2[7];
    float unk_10;
    float unk_14;
    s32 unk_18;
    s16 unk_1C;
} M508ScoreData;

typedef struct M508ScoreObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    M508ScoreData unk_18;
} M508ScoreObj;

typedef struct M508StateObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    M508State unk_18;
} M508StateObj;

typedef struct M508LightData_s {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
} M508LightData;

typedef struct M508LightObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    M508LightData unk_18;
    u8 pad1E[0x13A];
    s32 unk_158;
    u8 pad15C[4];
    float unk_160;
    float unk_164;
    float unk_168;
    u8 pad16C[0x18];
    s16 unk_184;
} M508LightObj;

typedef struct M508MoveData_s {
    s32 unk_0;
    float unk_4;
    float unk_8;
    float unk_C;
} M508MoveData;

typedef struct M508MoveObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    M508MoveData unk_18;
} M508MoveObj;

typedef struct M508MainData_s {
    s32 unk_0;
    u8 pad4[0xC];
    s16 unk_10;
} M508MainData;

typedef struct M508MainObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    M508MainData unk_18;
    u8 pad2C[0x12C];
    s32 unk_158;
    u8 pad15C[0x28];
    s16 unk_184;
    u8 pad186[2];
    s32 unk_188;
    s32 unk_18C;
    s16 *unk_190;
} M508MainObj;

typedef struct M508Window_s {
    s16 unk_0;
    u8 pad2[2];
    float unk_4;
    float unk_8;
    s32 unk_C;
    HUPROCESS *unk_10;
} M508Window;

typedef struct M508CameraView_s {
    float unk_0;
    float unk_4;
    float unk_8;
    float unk_C;
    float unk_10;
    float unk_14;
    float unk_18;
    float unk_1C;
    float unk_20;
    float unk_24;
    float unk_28;
    float unk_2C;
    float unk_30;
} M508CameraView;

typedef struct M508Camera_s {
    s32 unk_0;
    s32 unk_4;
    s16 unk_8;
    u8 padA[2];
    HUPROCESS *unk_C;
    M508CameraView unk_10;
    M508CameraView unk_44;
    M508CameraView unk_78;
    s32 unk_AC;
} M508Camera;

typedef struct M508VecWords_s {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} M508VecWords;

typedef void (*M508CameraFunc)(M508Camera *, void *, s32);

typedef struct M508Bss114_s {
    s32 unk_0;
    float unk_4;
    float unk_8;
    float unk_C;
} M508Bss114;

#define M508_MODEL_ROT_GET(obj, x, y, z) \
    do { \
        if ((x) != NULL) { \
            *((float *)(x)) = (obj)->unk_16C; \
        } \
        if ((y) != NULL) { \
            *((float *)(y)) = (obj)->unk_170; \
        } \
        if ((z) != NULL) { \
            *((float *)(z)) = (obj)->unk_174; \
        } \
    } while (0)

s32 lbl_1_bss_0;
s32 lbl_1_bss_4;
M508ModelObj *lbl_1_bss_8[5];
M508ModelObj *lbl_1_bss_1C[6];
M508ScoreObj *lbl_1_bss_34[4];
M508ModelObj *lbl_1_bss_44[6][4];
M508ModelObj *lbl_1_bss_A4[4];
M508ModelObj *lbl_1_bss_B4[5];
M508ModelObj *lbl_1_bss_C8[5];
M508LightObj *lbl_1_bss_DC;
M508ModelObj *lbl_1_bss_E0;
M508ModelObj *lbl_1_bss_E4;
M508ModelObj *lbl_1_bss_E8;
M508ModelObj *lbl_1_bss_EC;
M508Camera *lbl_1_bss_F0;
s32 lbl_1_bss_F4[4];
s32 lbl_1_bss_104;
s32 lbl_1_bss_108;
s32 lbl_1_bss_10C;
s32 lbl_1_bss_110;
M508Bss114 lbl_1_bss_114[5];
M508Circle lbl_1_bss_164;
float lbl_1_bss_170;
float lbl_1_bss_174;
M508Vec2 lbl_1_bss_178;
M508Vec2 lbl_1_bss_180;
M508Vec2 lbl_1_bss_188;
M508Vec2 lbl_1_bss_190;
M508Vec2 lbl_1_bss_198;
M508Vec2 lbl_1_bss_1A0;
float lbl_1_bss_1A8;
float lbl_1_bss_1AC;
float lbl_1_bss_1B0;
float lbl_1_bss_1B4;
M508Polygon lbl_1_bss_1B8;
M508Vec2 lbl_1_bss_1C0[5];
float lbl_1_bss_1E8;
float lbl_1_bss_1EC;
M508Vec2 lbl_1_bss_1F0;
M508Vec2 lbl_1_bss_1F8;
M508Vec2 lbl_1_bss_200;
M508Vec2 lbl_1_bss_208;
M508Vec2 lbl_1_bss_210;
M508Vec2 lbl_1_bss_218;

void ObjectSetup(void);
void fn_1_79BC(void);
void fn_1_7A24(void);
void fn_1_8918(void);
void fn_1_897C(M508Camera *arg0);
void fn_1_8C70(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_8D30(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_926C(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_9578(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3,
               float farg4, float farg5);
void fn_1_95D8(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3);
void fn_1_9628(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3);
void fn_1_96BC();
void fn_1_9B38(M508Camera *arg0);
void fn_1_9EF8(void);
void fn_1_6FC(M508ModelObj *arg0);
void fn_1_A3C(M508ModelObj *arg0);
void fn_1_10D4(M508ModelObj *arg0);
void fn_1_15B4(M508ModelObj *arg0);
void fn_1_538(void);
M508ModelObj *fn_1_5B0(void);
void fn_1_1BB4(void);
M508LightObj *fn_1_1D88(void);
M508LightObj *fn_1_1E64(void);
M508ModelObj *fn_1_1F34(void);
void fn_1_1FD0(M508State *arg0);
void fn_1_2084(M508ModelObj *arg0, s32 arg1);
M508ModelObj *fn_1_2260(void);
void fn_1_22C0(M508ModelObj *arg0);
void fn_1_2388(M508State *arg0);
void fn_1_2394(M508ModelObj *arg0);
void fn_1_1FDC(void);
void fn_1_20A8(M508StateObj *arg0);
void fn_1_21C8(M508ModelObj *arg0, s32 arg1);
void fn_1_25B4(void);
M508MainObj *fn_1_24DC(void);
void fn_1_265C(M508MoveObj *arg0, s32 arg1, float farg0, float farg1, float farg2);
void fn_1_268C(M508ModelObj *arg0);
void fn_1_2838(M508State *arg0);
void fn_1_2844(M508ModelObj *arg0);
void fn_1_2C7C(M508State *arg0);
void fn_1_2C88(M508ModelObj *arg0);
void fn_1_2F80(M508State *arg0);
void fn_1_3090(M508ModelObj *arg0);
void fn_1_33D8(M508State *arg0);
void fn_1_33E4(M508ModelObj *arg0);
M508LightObj *fn_1_37E0(s32 arg0);
void fn_1_38CC(M508LightObj *arg0, float farg0, float farg1, float farg2);
M508ModelObj *fn_1_3958(s32 arg0);
void fn_1_3A44(M508ModelObj *arg0);
void fn_1_3B98(M508ModelObj *arg0);
void fn_1_4150(M508State *arg0);
void fn_1_415C(M508ModelObj *arg0);
void fn_1_4380(M508ModelObj *arg0);
s32 fn_1_4654(M508StateObj *arg0);
void fn_1_469C(M508State *arg0);
void fn_1_46A8(M508ModelObj *arg0);
void fn_1_4790(M508State *arg0);
void fn_1_479C(M508ModelObj *arg0);
void fn_1_4884(M508State *arg0);
void fn_1_4890(M508ModelObj *arg0);
void fn_1_49EC(M508State *arg0);
void fn_1_49F8(M508ModelObj *arg0);
M508ScoreObj *fn_1_4B54(s32 arg0);
void fn_1_4FA8(M508ScoreObj *arg0);
void fn_1_4F48(M508ScoreObj *arg0, const M508Vec2 *arg1, float farg0, float farg1);
void fn_1_5010(M508ScoreObj *arg0);
void fn_1_5C7C(s32 arg0, s32 arg1, s32 arg2);
void fn_1_5084(void);
void fn_1_512C(M508ModelObj *arg0);
void fn_1_5164(M508ScoreObj *arg0);
void fn_1_5470(void);
void fn_1_5518(M508State *arg0);
void fn_1_5524(M508ModelObj *arg0);
M508ModelObj *fn_1_5394(s32 arg0);
M508ModelObj *fn_1_5414(s32 arg0);
void fn_1_57D4(M508State *arg0);
void fn_1_57E0(M508ModelObj *arg0);
void fn_1_58B8(M508State *arg0);
void fn_1_58C4(M508ModelObj *arg0);
M508ModelObj *fn_1_5758(s32 arg0);
M508ModelObj *fn_1_7A3C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4,
                        s32 arg5, M508ModelFunc *arg6);
M508ModelObj *fn_1_8308(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4,
                        s32 arg5, M508ModelFunc *arg6, s16 arg7);

M508CameraFunc lbl_1_data_0[3] = { fn_1_8D30, fn_1_926C, fn_1_8C70 };
s32 lbl_1_data_C = -1;
M508ModelFunc lbl_1_data_10[5] = { NULL, fn_1_6FC, fn_1_A3C, fn_1_10D4, fn_1_15B4 };
M508ModelFunc lbl_1_data_24[1] = { NULL };
M508ModelFunc lbl_1_data_28[1] = { NULL };
M508ModelFunc lbl_1_data_2C[2] = { fn_1_1FDC, fn_1_20A8 };
M508ModelFunc lbl_1_data_34[2] = { fn_1_22C0, fn_1_2394 };
M508ModelFunc lbl_1_data_3C[6] = { fn_1_25B4, fn_1_268C, fn_1_2844, fn_1_2C88,
    fn_1_3090, fn_1_33E4 };
M508ModelFunc lbl_1_data_54[8] = { fn_1_3A44, fn_1_3B98, fn_1_415C, fn_1_4380,
    fn_1_46A8, fn_1_479C, fn_1_4890, fn_1_49F8 };
char lbl_1_data_74[0x19] = "test11_tex_we-itemhook-r";
M508ModelFunc lbl_1_data_90[2] = { fn_1_5084, fn_1_5164 };
M508ModelFunc lbl_1_data_98[2] = { fn_1_5470, fn_1_5524 };
M508ModelFunc lbl_1_data_A0[1] = { NULL };
M508ModelFunc lbl_1_data_A4[2] = { fn_1_57E0, fn_1_58C4 };

int _prolog(void)
{
    const VoidFunc *ctors = _ctors;

    while (*ctors != 0) {
        (**ctors)();
        ctors++;
    }
    ObjectSetup();
    return 0;
}

void _epilog(void)
{
    const VoidFunc *dtors = _dtors;

    while (*dtors != 0) {
        (**dtors)();
        dtors++;
    }
}

void ObjectSetup(void)
{
    s32 var_r31;
    M508Camera *var_r30;
    M508CameraView *var_r29;
    s32 var_r28;
    s32 var_r27;
    M508LightObj *var_r26;
    M508Camera *var_r25;
    M508Camera *var_r24;
    M508Camera *var_r23;
    M508Camera *var_r22;
    M508Camera *var_r21;
    OMOBJMAN *var_r20;
    M508Camera *var_r19;

    var_r20 = omInitObjMan(1, 0x2000);
    omGameSysInit(var_r20);
    var_r30 = HuMemDirectMallocNum(HEAP_HEAP, sizeof(M508Camera), HU_MEMNUM_OVL);
    var_r30->unk_8 = 1;
    for (var_r27 = 0; var_r27 < 3; var_r27++) {
        var_r29 = &var_r30->unk_10 + var_r27;
        var_r29->unk_18 = 0.0f;
        var_r29->unk_1C = 0.0f;
        var_r29->unk_20 = 0.0f;
        var_r29->unk_24 = 0.0f;
        var_r29->unk_28 = 0.0f;
        var_r29->unk_2C = 0.0f;
        var_r29->unk_30 = 0.0f;
    }
    var_r30->unk_C = HuPrcChildCreate(fn_1_8918, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r30->unk_C->property = var_r30;
    var_r30->unk_AC = 0;
    Hu3DCameraCreate(1);
    var_r23 = var_r30;
    Hu3DCameraPerspectiveSet(var_r23->unk_8, 30.0f, 10.0f, 8000.0f, 1.2f);
    var_r22 = var_r30;
    Hu3DCameraViewportSet(var_r22->unk_8, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    var_r21 = var_r30;
    Hu3DCameraScissorSet(var_r21->unk_8, 0, 0, 0x280, 0x1E0);
    var_r30->unk_0 = 2;
    var_r19 = var_r30;
    lbl_1_bss_F0 = var_r19;
    var_r25 = lbl_1_bss_F0;
    var_r25->unk_0 = 2;
    var_r24 = lbl_1_bss_F0;
    Hu3DCameraPerspectiveSet(var_r24->unk_8, 40.0f, 10.0f, 8000.0f, 1.2f);
    lbl_1_bss_E8 = fn_1_5414(0);
    lbl_1_bss_EC = fn_1_5B0();
    lbl_1_bss_EC->unk_4 = 1;
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        lbl_1_bss_F4[var_r31] = 0;
    }
    lbl_1_bss_E4 = (M508ModelObj *) fn_1_1D88();
    lbl_1_bss_E0 = fn_1_1F34();
    lbl_1_bss_DC = fn_1_1E64();
    var_r26 = lbl_1_bss_DC;
    var_r26->unk_158 = 1;
    Hu3DModelDispOn(var_r26->unk_184);
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        lbl_1_bss_C8[var_r31] = fn_1_2260();
    }
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        lbl_1_bss_B4[var_r31] = (M508ModelObj *) fn_1_37E0(var_r31);
    }
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        lbl_1_bss_A4[var_r31] = fn_1_3958(var_r31);
    }
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        lbl_1_bss_8[var_r31] = (M508ModelObj *) fn_1_24DC();
    }
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        for (var_r28 = 0; var_r28 < 6; var_r28++) {
            lbl_1_bss_44[var_r28][var_r31] = fn_1_5394(var_r28);
        }
    }
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        lbl_1_bss_34[var_r31] = fn_1_4B54(var_r31);
        fn_1_5010(lbl_1_bss_34[var_r31]);
    }
    for (var_r31 = 0; var_r31 < 6; var_r31++) {
        lbl_1_bss_1C[var_r31] = fn_1_5758(var_r31);
    }
    HuPrcChildCreate(fn_1_538, 0xFFF, 0x1000, 0, HuPrcCurrentGet());
}

void fn_1_538(void)
{
    while (omSysExitReq == 0) {
        HuPrcVSleep();
    }
    HuAudFadeOut(1000);
    WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_WHITEFADE, 60);
    while (WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
    omOvlReturnEx(1, 1);
    HuPrcEnd();
}

M508ModelObj *fn_1_5B0(void)
{
    M508ModelObj *var_r31;
    s32 var_r30;
    M508ModelObj *var_r29;
    M508ModelObj *var_r28;

    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x158, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = 5;
    var_r31->unk_C = 0;
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, 0x14, HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < 5; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_7A24;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_79BC, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    if (lbl_1_data_10 != NULL) {
        for (var_r30 = 0; var_r30 < 5; var_r30++) {
            if (lbl_1_data_10[var_r30] != NULL) {
                var_r31->unk_10[var_r30] = lbl_1_data_10[var_r30];
            }
        }
    }
    var_r28 = var_r31;
    var_r29 = var_r28;
    return var_r29;
}

const s16 lbl_1_rodata_C4[4] = { 0x28, 0x38, 0x48, 0x58 };
const s32 lbl_1_rodata_CC[3] = { 0x43, 0x44, 0x42 };
const float lbl_1_rodata_D8[1] = { 40.0f };
const M508Vec2 lbl_1_rodata_DC[4] = {
    { 70.0f, 58.0f },
    { 190.0f, 58.0f },
    { 388.0f, 58.0f },
    { 508.0f, 58.0f }
};

void fn_1_6FC(M508ModelObj *arg0)
{
    s32 var_r31;
    M508ModelObj *var_r30;
    M508ModelObj *var_r29;
    M508ModelObj *var_r28;
    M508ModelObj *var_r27;

    var_r30 = lbl_1_bss_E4;
    Hu3DModelPosSet(var_r30->unk_184, var_r30->unk_160 = 0.0f,
        var_r30->unk_164 = 0.0f, var_r30->unk_168 = 0.0f);
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        var_r29 = lbl_1_bss_C8[var_r31];
        Hu3DModelPosSet(var_r29->unk_184,
            var_r29->unk_160 = -500.0f + (250.0f * var_r31),
            var_r29->unk_164 = 250.0f, var_r29->unk_168 = -450.0f);
    }
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        fn_1_38CC((M508LightObj *) lbl_1_bss_B4[var_r31],
            -500.0f + (250.0f * var_r31), 250.0f, -450.0f);
    }
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        var_r28 = lbl_1_bss_A4[var_r31];
        Hu3DModelPosSet(var_r28->unk_184,
            var_r28->unk_160 = -300.0f + (200.0f * var_r31),
            var_r28->unk_164 = 0.0f, var_r28->unk_168 = 0.0f);
        fn_1_4150((M508State *) lbl_1_bss_A4[var_r31]);
    }
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        var_r27 = lbl_1_bss_8[var_r31];
        Hu3DModelPosSet(var_r27->unk_184,
            var_r27->unk_160 = -500.0f + (250.0f * var_r31),
            var_r27->unk_164 = 0.0f, var_r27->unk_168 = -450.0f);
    }
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        fn_1_4F48(lbl_1_bss_34[var_r31], &lbl_1_rodata_DC[var_r31],
            lbl_1_rodata_DC[var_r31].unk_0, lbl_1_rodata_DC[var_r31].unk_4);
    }
    lbl_1_bss_EC->unk_4 = 2;
}

const HuVecF lbl_1_rodata_110 = { 0.0f, 500.0f, 1000.0f };
const HuVecF lbl_1_rodata_11C = { 0.0f, 0.0f, -300.0f };
const GXColor lbl_1_rodata_128 = { 0xFF, 0xFF, 0xFF, 0xFF };
const HuVecF lbl_1_rodata_12C = { 0.0f, 579.0f, -1070.7900390625f };
const HuVecF lbl_1_rodata_138 = { 11.6f, -0.1f, 7.0f };
const float lbl_1_rodata_144[1] = { 2202.3f };
const float lbl_1_rodata_148[1] = { 288.0f };
const float lbl_1_rodata_14C[1] = { 64.0f };

const s32 lbl_1_rodata_150[3][4] = {
    { 4, 6, 3, 6 },
    { 1, 2, 3, 4 },
    { 1, 5, 0, 4 }
};
const s32 lbl_1_rodata_180[3][2] = {
    { 0, 2 },
    { 3, 4 },
    { 1, 5 }
};
const float lbl_1_rodata_198[3][2] = {
    { 2.0f, -2.0f },
    { 1.0f, -1.0f },
    { 3.0f, -3.0f }
};
const float lbl_1_rodata_1B0[3] = { 1.0f, 0.4f, 2.0f };

void fn_1_A3C(M508ModelObj *var_r20)
{
    s32 temp_ret;
    M508CameraView *var_r31;
    M508CameraView *var_r30;
    M508Camera *var_r29;
    M508CameraView *var_r28;
    s32 var_r27;
    s32 var_r26;
    s16 var_r25;
    s32 var_r24;
    M508Camera *var_r23;
    M508CameraView *var_r22;
    s16 var_r21;
    double var_f31;

    var_r25 = Hu3DGLightCreate(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    Hu3DGLightPosAimSetV(var_r25, (HuVecF *) &lbl_1_rodata_110, (HuVecF *) &lbl_1_rodata_11C);
    Hu3DGLightColorSet(var_r25, lbl_1_rodata_128.r, lbl_1_rodata_128.g,
        lbl_1_rodata_128.b, lbl_1_rodata_128.a);
    Hu3DGLightStaticSet(var_r25, 1);
    var_r23 = lbl_1_bss_F0;
    var_r23->unk_0 = 2;
    fn_1_5518((M508State *) lbl_1_bss_E8);
    fn_1_58B8((M508State *) lbl_1_bss_1C[0]);
    fn_1_2084(lbl_1_bss_E0, 0);
    lbl_1_data_C = HuAudFXPlay(0x39A);
    WipeCreate(WIPE_MODE_IN, WIPE_TYPE_PREVTYPE, 60);
    while (WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x81);
    WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_CROSSCOPY, 60);
    var_r29 = lbl_1_bss_F0;
    var_r28 = &var_r29->unk_10;
    var_r22 = &var_r29->unk_44;
    var_r30 = &var_r29->unk_78;
    *var_r22 = *var_r28;
    *var_r30 = *var_r28;
    if (&lbl_1_rodata_12C != NULL) {
        *(u32 *) &var_r30->unk_18 = *(u32 *) &lbl_1_rodata_12C.x;
        *(u32 *) &var_r30->unk_1C = *(u32 *) &lbl_1_rodata_12C.y;
        *(u32 *) &var_r30->unk_20 = *(u32 *) &lbl_1_rodata_12C.z;
    }
    if (&lbl_1_rodata_138 != NULL) {
        *(u32 *) &var_r30->unk_24 = *(u32 *) &lbl_1_rodata_138.x;
        *(u32 *) &var_r30->unk_28 = *(u32 *) &lbl_1_rodata_138.y;
        *(u32 *) &var_r30->unk_2C = *(u32 *) &lbl_1_rodata_138.z;
    }
    if (&lbl_1_rodata_144 != NULL) {
        var_r30->unk_30 = lbl_1_rodata_144[0];
    }
    for (var_r26 = 0; var_r26 < 3; var_r26++) {
        var_r31 = &var_r29->unk_10 + var_r26;
        var_f31 = HuCos(var_r31->unk_24);
        var_r31->unk_0 = var_r31->unk_18 +
            (var_r31->unk_30 * (HuSin(var_r31->unk_28) * var_f31));
        var_r31->unk_4 = var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
        var_f31 = HuCos(var_r31->unk_24);
        var_r31->unk_8 = var_r31->unk_20 +
            (var_r31->unk_30 * (HuCos(var_r31->unk_28) * var_f31));
        var_f31 = HuSin(var_r31->unk_24);
        var_r31->unk_C = HuSin(var_r31->unk_28) * var_f31;
        var_r31->unk_10 = HuCos(var_r31->unk_24);
        var_f31 = HuSin(var_r31->unk_24);
        var_r31->unk_14 = HuCos(var_r31->unk_28) * var_f31;
    }
    var_r29->unk_4 = 0;
    *var_r28 = *var_r30;
    var_r29->unk_0 = 0;
    HuPrcSleep(0);
    WipeCreate(WIPE_MODE_IN, WIPE_TYPE_CROSSCOPY, 30);
    fn_1_2084(lbl_1_bss_E0, 5);
    temp_ret = HuAudSStreamPlay(lbl_1_rodata_CC[0]);
    lbl_1_bss_4 = temp_ret;
    var_r21 = GameMesCreate(2, 0);
    for (var_r24 = 0; var_r24 < 0x78; var_r24++) {
        HuPrcVSleep();
    }
    fn_1_1FD0((M508State *) lbl_1_bss_E0);
    for (var_r27 = 0; var_r27 < 5; var_r27++) {
        fn_1_2388((M508State *) lbl_1_bss_C8[var_r27]);
    }
    HuPrcSleep(0x13);
    HuAudFXStop(lbl_1_data_C);
    var_r20->unk_4 = 4;
}

void fn_1_10D4(M508ModelObj *arg0)
{
    s16 sp8[4];
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    s16 var_r25;
    s16 var_r24;
    s32 temp_r0;

    var_r27 = 0;
    fn_1_58B8((M508State *) lbl_1_bss_1C[1]);
    fn_1_2084(lbl_1_bss_E0, 4);
    HuAudFXStop(lbl_1_data_C);
    var_r24 = GameMesCreate(2, 1);
    while (GameMesStatGet(var_r24) != 0) {
        HuPrcVSleep();
    }
    var_r29 = 0;
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        if (var_r29 < lbl_1_bss_F4[var_r31]) {
            var_r29 = lbl_1_bss_F4[var_r31];
        }
    }
    var_r30 = 0;
    for (var_r31 = 0; var_r31 < 4; var_r31++) {
        if (var_r29 == lbl_1_bss_F4[var_r31]) {
            var_r30++;
        }
    }
    if ((var_r31 == var_r30) && (var_r29 == 0)) {
        HuAudJinglePlay(0x7B);
        HuPrcSleep(0);
        var_r25 = GameMesCreate(2, 2);
        CharLoseVoicePlay(lbl_1_bss_A4[0]->unk_1BC, lbl_1_bss_A4[1]->unk_1BC,
            lbl_1_bss_A4[2]->unk_1BC, lbl_1_bss_A4[3]->unk_1BC);
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            CharModelVoicePanSet(lbl_1_bss_A4[var_r31]->unk_1BC, lbl_1_rodata_C4[var_r31]);
            fn_1_49EC((M508State *) lbl_1_bss_A4[var_r31]);
        }
        for (var_r31 = 0; var_r31 < 5; var_r31++) {
            HuAudFXPlay(0x68E);
            fn_1_2C7C((M508State *) lbl_1_bss_8[var_r31]);
            HuPrcSleep(9);
        }
        HuPrcSleep(0xA9);
    } else {
        var_r30 = 0;
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            if (var_r29 == lbl_1_bss_F4[var_r31]) {
                temp_r0 = var_r30;
                var_r30++;
                sp8[temp_r0] = lbl_1_bss_A4[var_r31]->unk_1BC;
                GwPlayer[var_r31].mgCoinBonus = 0xA;
                fn_1_4884((M508State *) lbl_1_bss_A4[var_r31]);
            } else {
                fn_1_49EC((M508State *) lbl_1_bss_A4[var_r31]);
            }
        }
        while (var_r30 < var_r31) {
            sp8[var_r30] = -1;
            var_r30++;
        }
        HuAudJinglePlay(0x79);
        HuPrcSleep(0);
        var_r25 = GameMesCreate(4, 3, sp8[0], sp8[1], sp8[2], sp8[3]);
        lbl_1_data_C = HuAudFXPlay(0x39A);
        var_r27 = 0;
        for (var_r28 = 0; var_r28 < 4; var_r28++) {
            if (lbl_1_bss_F4[var_r28] == 3) {
                var_r30 = 0;
                for (var_r31 = 0; var_r31 < 4; var_r31++) {
                    if ((var_r31 != var_r28) && (lbl_1_bss_F4[var_r31] == 0)) {
                        var_r30++;
                    }
                }
                if (var_r30 == 3) {
                    var_r27 = 1;
                }
            }
        }
        if (var_r27 != 0) {
            for (var_r31 = 0; var_r31 < 5; var_r31++) {
                fn_1_33D8((M508State *) lbl_1_bss_8[var_r31]);
                HuPrcSleep(9);
            }
            HuPrcSleep(0xA9);
        } else {
            for (var_r31 = 0; var_r31 < 5; var_r31++) {
                fn_1_265C((M508MoveObj *) lbl_1_bss_8[var_r31],
                    lbl_1_bss_114[lbl_1_bss_110].unk_0, 0.0f, 0.0f, 1.0f);
            }
            HuPrcSleep(0xD1);
        }
    }
    HuAudFadeOut(0x3E8);
    WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_WHITEFADE, 60);
    while (WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
    omOvlReturnEx(1, 1);
    HuPrcEnd();
}

void fn_1_15B4(M508ModelObj *var_r26)
{
    float sp10;
    float spC;
    float sp8;
    s32 var_r31;
    MGTIMER *var_r30;
    s32 var_r29;
    M508ModelObj *var_r28;
    M508ModelObj *var_r27;
    float var_f31;
    float var_f30;
    float var_f29;

    var_r30 = MgTimerCreate(0);
    MgTimerPosSet(var_r30, 288.0f, 64.0f);
    var_r29 = 0;
    while (var_r29 < 3) {
        lbl_1_bss_104 = var_r29;
        if (var_r29 > 0) {
            for (var_r31 = 0; var_r31 < 4; var_r31++) {
                lbl_1_bss_A4[var_r31]->unk_4 = 2;
            }
        }
        fn_1_1BB4();
        HuAudFXPlay(0x688);
        for (var_r31 = 0; var_r31 < 5; var_r31++) {
            fn_1_2838((M508State *) lbl_1_bss_8[var_r31]);
        }
        HuPrcSleep(0x2D);
        for (var_r31 = 0; var_r31 < 5; var_r31++) {
            fn_1_265C((M508MoveObj *) lbl_1_bss_8[var_r31], lbl_1_bss_114[var_r31].unk_0,
                lbl_1_bss_114[var_r31].unk_4, lbl_1_bss_114[var_r31].unk_8,
                lbl_1_bss_114[var_r31].unk_C);
        }
        fn_1_2084(lbl_1_bss_E0, lbl_1_bss_104 + 1);
        fn_1_58B8((M508State *) lbl_1_bss_1C[var_r29 + 2]);
        MgTimerParamSet(var_r30, 0x12C, 0, 0);
        MgTimerModeOnSet(var_r30, 1);
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            fn_1_4FA8(lbl_1_bss_34[var_r31]);
        }
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            lbl_1_bss_A4[var_r31]->unk_4 = 1;
        }
        lbl_1_bss_0 = 0;
        while (1) {
            if (MgTimerDoneCheck(var_r30) != 0) {
                break;
            }
            if (lbl_1_bss_0 >= 4) {
                if (var_r30->stopF == 0) {
                    var_r30->stopF = 1;
                    var_r30->mode = 1;
                }
                break;
            }
            HuPrcSleep(0);
        }
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            lbl_1_bss_A4[var_r31]->unk_4 = 3;
        }
        HuPrcSleep(0x3B);
        for (var_r31 = 0; var_r31 < 5; var_r31++) {
            fn_1_2F80((M508State *) lbl_1_bss_8[var_r31]);
        }
        HuAudSStreamFadeOut(lbl_1_bss_4, 0x7D0);
        fn_1_2084(lbl_1_bss_E0, 5);
        HuPrcSleep(0x77);
        lbl_1_bss_1C[var_r29 + 2]->unk_4 = 0;
        fn_1_1FD0((M508State *) lbl_1_bss_E0);
        for (var_r31 = 0; var_r31 < 5; var_r31++) {
            fn_1_265C((M508MoveObj *) lbl_1_bss_8[var_r31],
                lbl_1_bss_114[var_r31].unk_0, 0.0f, 0.0f, 1.0f);
        }
        HuAudFXPlay(0x68D);
        var_r27 = lbl_1_bss_8[lbl_1_bss_110];
        if (&sp8 != NULL) {
            sp8 = var_r27->unk_160;
        }
        if (&spC != NULL) {
            spC = var_r27->unk_164;
        }
        if (&sp10 != NULL) {
            sp10 = var_r27->unk_168;
        }
        var_f29 = sp10;
        var_f30 = spC;
        var_f31 = sp8;
        var_r28 = lbl_1_bss_1C[5];
        Hu3DModelPosSet(var_r28->unk_184, var_r28->unk_160 = var_f31,
            var_r28->unk_164 = var_f30, var_r28->unk_168 = var_f29);
        fn_1_58B8((M508State *) lbl_1_bss_1C[5]);
        lbl_1_data_C = HuAudFXPlay(0x39A);
        for (var_r31 = 0; var_r31 < 4; var_r31++) {
            if (fn_1_4654((M508StateObj *) lbl_1_bss_A4[var_r31]) != 0) {
                fn_1_469C((M508State *) lbl_1_bss_A4[var_r31]);
                fn_1_512C((M508ModelObj *) lbl_1_bss_34[var_r31]);
                lbl_1_bss_F4[var_r31]++;
            } else {
                fn_1_4790((M508State *) lbl_1_bss_A4[var_r31]);
            }
        }
        HuPrcSleep(0x77);
        if (var_r29 != 2) {
            HuAudFXStop(lbl_1_data_C);
            fn_1_2084(lbl_1_bss_E0, 5);
            fn_1_57D4((M508State *) lbl_1_bss_1C[5]);
            HuAudFXPlay(0x68E);
            for (var_r31 = 0; var_r31 < 5; var_r31++) {
                fn_1_2C7C((M508State *) lbl_1_bss_8[var_r31]);
            }
            var_r29++;
            lbl_1_bss_4 = HuAudSStreamPlay(lbl_1_rodata_CC[var_r29]);
            HuPrcSleep(0x77);
        } else {
            break;
        }
    }
    MgTimerKill(var_r30);
    var_r26->unk_4 = 3;
}

void fn_1_1BB4(void)
{
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    u32 var_r28;

    var_r29 = lbl_1_rodata_180[lbl_1_bss_104][frandmod(2)];
    do {
        var_r30 = lbl_1_rodata_150[lbl_1_bss_104][frandmod(4)];
    } while (var_r29 == var_r30);
    lbl_1_bss_110 = frandmod(5);
    for (var_r31 = 0; var_r31 < 5; var_r31++) {
        lbl_1_bss_114[var_r31].unk_0 = var_r30;
        var_r28 = frandmod(2);
        lbl_1_bss_114[var_r31].unk_4 = lbl_1_rodata_198[lbl_1_bss_104][var_r28];
        lbl_1_bss_114[var_r31].unk_8 = (s32) frandmod(0x1E);
        lbl_1_bss_114[var_r31].unk_C = lbl_1_rodata_1B0[lbl_1_bss_104];
    }
    lbl_1_bss_114[lbl_1_bss_110].unk_0 = var_r29;
    lbl_1_bss_10C = var_r29;
    lbl_1_bss_108 = var_r30;
}

const HuVecF lbl_1_rodata_1BC = { 0.0f, 1000.0f, 800.0f };
const HuVecF lbl_1_rodata_1C8 = { 0.0f, 0.0f, -400.0f };
const GXColor lbl_1_rodata_1D4 = { 0xFF, 0xFF, 0xFF, 0xFF };
const HuVecF lbl_1_rodata_1D8 = { 0.0f, 1000.0f, 800.0f };
const HuVecF lbl_1_rodata_1E4 = { 0.0f, 0.0f, -600.0f };
const GXColor lbl_1_rodata_1F0[8] = {
    { 0xFF, 0xFF, 0xFF, 0xFF },
    { 0, 0, 0, 0 },
    { 0x44, 0x7A, 0, 0 },
    { 0x44, 0x48, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0xC4, 0x16, 0, 0 },
    { 0xFF, 0xFF, 0xFF, 0xFF }
};

M508LightObj *fn_1_1D88(void)
{
    M508LightObj *var_r31;
    M508LightData *var_r30;
    s16 var_r29;

    var_r31 = (M508LightObj *) fn_1_7A3C(0x1000, 0x2000, 0x42000B, 0, NULL, 1, lbl_1_data_24);
    var_r30 = &var_r31->unk_18;
    var_r30->unk_0 = Hu3DLLightCreateV(var_r31->unk_184, (HuVecF *) &lbl_1_rodata_1BC,
        (HuVecF *) &lbl_1_rodata_1C8, (GXColor *) &lbl_1_rodata_1D4);
    Hu3DLLightInfinitytSet(var_r31->unk_184, var_r30->unk_0);
    var_r31->unk_158 = 1;
    Hu3DModelDispOn(var_r31->unk_184);
    var_r29 = var_r31->unk_184;
    Hu3DModelAttrReset(var_r29, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrSet(var_r29, HU3D_MOTATTR_LOOP);
    return var_r31;
}

void fn_1_1E58(M508State *arg0)
{
    arg0->unk_4 = 0;
}

M508LightObj *fn_1_1E64(void)
{
    M508LightObj *var_r31;
    M508LightData *var_r30;
    s16 var_r29;

    var_r31 = (M508LightObj *) fn_1_7A3C(0x1000, 0x2000, 0x42001F, 0, NULL, 1, lbl_1_data_28);
    var_r30 = &var_r31->unk_18;
    var_r30->unk_0 = Hu3DLLightCreateV(var_r31->unk_184, (HuVecF *) &lbl_1_rodata_1D8,
        (HuVecF *) &lbl_1_rodata_1E4, (GXColor *) lbl_1_rodata_1F0);
    Hu3DLLightInfinitytSet(var_r31->unk_184, var_r30->unk_0);
    var_r31->unk_158 = 1;
    Hu3DModelDispOn(var_r31->unk_184);
    var_r29 = var_r31->unk_184;
    Hu3DModelAttrReset(var_r29, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrSet(var_r29, HU3D_MOTATTR_LOOP);
    return var_r31;
}

M508ModelObj *fn_1_1F34(void)
{
    M508ModelObj *var_r31;
    M508State *sp8;
    s16 var_r30;

    var_r31 = fn_1_7A3C(0x1000, 0x2000, 0x42000C, 0, NULL, 2, lbl_1_data_2C);
    sp8 = (M508State *) &var_r31->unk_18;
    var_r31->unk_158 = 1;
    Hu3DModelDispOn(var_r31->unk_184);
    var_r30 = var_r31->unk_184;
    Hu3DModelAttrReset(var_r30, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrSet(var_r30, HU3D_MOTATTR_LOOP);
    return var_r31;
}

void fn_1_1FD0(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_1FDC(void)
{
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    while (1) {
        var_r30 = 1;
        for (var_r31 = 0; var_r31 < var_r30;) {
            HuPrcVSleep();
            var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r29) {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                var_r31++;
            } else {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                return;
            }
        }
    }
}

void fn_1_2084(M508ModelObj *arg0, s32 arg1)
{
    arg0->unk_1C = arg1;
    arg0->unk_4 = 1;
}

const M508AnimCmd lbl_1_rodata_210[6][10] = {
    {
        { 1, 10 }, { 2, 10 }, { 3, 10 }, { 4, 10 }, { 0xFF, 10 },
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    },
    {
        { 1, 30 }, { 0, 4 }, { 2, 30 }, { 0, 4 }, { 0xFF, 10 },
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    },
    {
        { 2, 60 }, { 0, 30 }, { 3, 60 }, { 0, 30 }, { 0xFF, 10 },
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    },
    {
        { 1, 10 }, { 3, 10 }, { 1, 10 }, { 2, 10 }, { 0xFF, 10 },
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    },
    {
        { 0, 15 }, { 1, 15 }, { 2, 15 }, { 3, 15 }, { 4, 15 },
        { 0xFF, 10 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    },
    {
        { 0, 90 }, { 0xFF, 60 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
    }
};

void fn_1_20A8(M508StateObj *arg0)
{
    s32 var_r31;
    M508State *var_r30;
    s32 var_r29;
    s16 var_r28;
    s32 var_r27;
    s32 var_r26;
    M508StateObj *var_r25;
    s32 var_r24;

    var_r25 = arg0;
    var_r30 = &var_r25->unk_18;
    var_r31 = 0;
    var_r29 = 0;
    while (1) {
        if (var_r29 > 0) {
            var_r29--;
        } else {
            while (1) {
                var_r27 = lbl_1_rodata_210[var_r30->unk_4][var_r31].unk_0;
                var_r29 = lbl_1_rodata_210[var_r30->unk_4][var_r31].unk_4;
                if (var_r27 != 0xFF) {
                    break;
                }
                var_r31 = 0;
            }
            var_r31++;
            fn_1_21C8((M508ModelObj *) var_r25, var_r27);
        }
        var_r26 = 1;
        for (var_r28 = 0; var_r28 < var_r26;) {
            HuPrcVSleep();
            var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r24) {
                var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
                var_r28++;
            } else {
                var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
                return;
            }
        }
    }
}

const M508AnimRange lbl_1_rodata_3F0[5] = {
    { 0.0f, 1.0f },
    { 10.0f, 19.0f },
    { 20.0f, 29.0f },
    { 30.0f, 39.0f },
    { 40.0f, 49.0f }
};

void fn_1_21C8(M508ModelObj *arg0, s32 arg1)
{
    Hu3DModelAttrReset(arg0->unk_184, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrReset(arg0->unk_184, HU3D_MOTATTR_LOOP);
    Hu3DMotionStartEndSet(arg0->unk_184, lbl_1_rodata_3F0[arg1].unk_0,
        lbl_1_rodata_3F0[arg1].unk_4);
    Hu3DMotionTimeSet(arg0->unk_184, 0.0f);
}

void fn_1_22B4(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_22C0(M508ModelObj *arg0)
{
    s32 var_r31;
    s32 var_r29;
    s32 var_r28;

    arg0->unk_158 = 0;
    Hu3DModelDispOff(arg0->unk_184);
    while (1) {
        for (var_r31 = 0; var_r31 < 1;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                var_r31++;
            } else {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
        }
    }
}

M508ModelObj *fn_1_2260(void)
{
    M508ModelObj *var_r31;

    var_r31 = fn_1_7A3C(0x1000, 0x2000, 0x420020, 0, NULL, 2, lbl_1_data_34);
    return var_r31;
}

void fn_1_2388(M508State *arg0)
{
    arg0->unk_4 = 1;
}

void fn_1_2394(M508ModelObj *arg0)
{
    s32 var_r30;
    s32 var_r29;
    s16 var_r28;
    s32 var_r27;
    s32 var_r26;
    s32 var_r25;

    for (var_r30 = 0; var_r30 < 4; var_r30++) {
        fn_1_5C7C(var_r30, 2, 0x28);
    }
    HuAudFXPlay(0x687);
    arg0->unk_158 = 1;
    Hu3DModelDispOn(arg0->unk_184);
    var_r28 = arg0->unk_184;
    Hu3DModelAttrReset(var_r28, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrReset(var_r28, HU3D_MOTATTR_LOOP);
    Hu3DMotionTimeSet(arg0->unk_184, 0.0f);
    goto check_motion;
    do {
        var_r26 = 1;
        for (var_r29 = 0; var_r29 < var_r26;) {
            HuPrcVSleep();
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r25) {
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                return;
            }
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
            var_r29++;
        }
check_motion:
        if (Hu3DMotionEndCheck(arg0->unk_184) == 0) {
            var_r27 = 1;
        } else {
            var_r27 = 0;
        }
    } while (var_r27 != 0);
    arg0->unk_4 = 0;
}

const HuVecF lbl_1_rodata_418 = { 0.0f, 1000.0f, 800.0f };
const HuVecF lbl_1_rodata_424 = { 0.0f, 0.0f, -400.0f };
const GXColor lbl_1_rodata_430 = { 0xFF, 0xFF, 0xFF, 0xFF };
const s32 lbl_1_rodata_434[9] = {
    0x420001, 0x420002, 0x420003, 0x420004, 0x420005, 0x420006, 0x420007,
    0x420008, 0x420009
};

M508MainObj *fn_1_24DC(void)
{
    M508MainObj *var_r31;
    M508MainData *var_r30;

    var_r31 = (M508MainObj *) fn_1_7A3C(0x1000, 0x2000, 0x420000, 9,
        (s32 *) lbl_1_rodata_434, 6, lbl_1_data_3C);
    var_r30 = &var_r31->unk_18;
    var_r30->unk_0 = 0;
    var_r30->unk_10 = Hu3DLLightCreateV(var_r31->unk_184, (HuVecF *) &lbl_1_rodata_418,
        (HuVecF *) &lbl_1_rodata_424, (GXColor *) &lbl_1_rodata_430);
    Hu3DLLightInfinitytSet(var_r31->unk_184, var_r30->unk_10);
    var_r31->unk_188 = 0;
    Hu3DMotionShiftSet(var_r31->unk_184, *var_r31->unk_190, 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    return var_r31;
}

void fn_1_25A8(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_25B4(void)
{
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    while (1) {
        var_r30 = 1;
        for (var_r31 = 0; var_r31 < var_r30;) {
            HuPrcVSleep();
            var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r29) {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                var_r31++;
            } else {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                return;
            }
        }
    }
}

void fn_1_265C(M508MoveObj *arg0, s32 arg1, float farg0, float farg1, float farg2)
{
    M508MoveData *var_r31;

    var_r31 = &arg0->unk_18;
    var_r31->unk_0 = arg1;
    var_r31->unk_4 = farg0;
    var_r31->unk_8 = farg1;
    var_r31->unk_C = farg2;
    arg0->unk_4 = 1;
}

const s32 lbl_1_rodata_45C[7] = { 1, 2, 3, 4, 5, 6, 7 };

void fn_1_268C(M508ModelObj *var_r31)
{
    float sp10;
    float spC;
    float sp8;
    M508MoveData *var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    float var_f31;
    float var_f30;
    float var_f29;

    var_r30 = (M508MoveData *) &var_r31->unk_18;
    Hu3DMotionShiftSet(var_r31->unk_184,
        var_r31->unk_190[lbl_1_rodata_45C[var_r30->unk_0]], var_r30->unk_8, 16.0f,
        HU3D_MOTATTR_SHIFT_LOOP);
    Hu3DMotionShiftSpeedSet(var_r31->unk_184, var_r30->unk_C);
    if (&sp10 != NULL) {
        sp10 = var_r31->unk_16C;
    }
    if (&spC != NULL) {
        spC = var_r31->unk_170;
    }
    if (&sp8 != NULL) {
        sp8 = var_r31->unk_174;
    }
    while (1) {
        spC += var_r30->unk_4;
        var_f29 = sp8;
        var_f30 = spC;
        var_f31 = sp10;
        Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = var_f31,
            var_r31->unk_170 = var_f30, var_r31->unk_174 = var_f29);
        var_r28 = 1;
        for (var_r29 = 0; var_r29 < var_r28;) {
            HuPrcVSleep();
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r27) {
                var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
                return;
            }
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
            var_r29++;
        }
    }
}

void fn_1_2838(M508State *arg0)
{
    arg0->unk_4 = 2;
}

void fn_1_2844(M508ModelObj *var_r31)
{
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    float var_f31;
    float var_f30;
    float var_f29;
    float var_f28;
    float var_f27;
    float var_f26;
    float var_f25;
    float var_f24;
    float var_f23;
    float var_f22;
    float var_f21;

    var_r31->unk_188 = 8;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[8], 0.0f, 8.0f,
        HU3D_MOTATTR_SHIFT_REV);
    Hu3DMotionShiftStartEndSet(var_r31->unk_184, 0.0f, 45.0f);
    if (&sp14 != NULL) {
        sp14 = var_r31->unk_16C;
    }
    if (&sp18 != NULL) {
        sp18 = var_r31->unk_170;
    }
    if (&sp1C != NULL) {
        sp1C = var_r31->unk_174;
    }
    sp18 = 45.0f * (s32) frandmod(8);
    var_f26 = sp1C;
    var_f27 = sp18;
    var_f28 = sp14;
    Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = var_f28, var_r31->unk_170 = var_f27,
        var_r31->unk_174 = var_f26);
    if (&sp8 != NULL) {
        sp8 = var_r31->unk_160;
    }
    if (&spC != NULL) {
        spC = var_r31->unk_164;
    }
    if (&sp10 != NULL) {
        sp10 = var_r31->unk_168;
    }
    var_f29 = 410.0 + (410.0 - (410.0 * sin(1.5707963267948966)));
    for (var_r30 = 0; var_r30 < 45;) {
        var_f30 = 0.022222223f * (var_r30 + 1);
        var_f31 = HuSin(90.0f * var_f30);
        var_f31 *= var_f31 * var_f31;
        spC = var_f29 * var_f31;
        var_f23 = sp10;
        var_f24 = spC;
        var_f25 = sp8;
        Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f25,
            var_r31->unk_164 = var_f24, var_r31->unk_168 = var_f23);
        Hu3DModelScaleSet(var_r31->unk_184, var_r31->unk_178 = var_f30,
            var_r31->unk_17C = var_f30, var_r31->unk_180 = var_f30);
        var_r28 = 1;
        for (var_r29 = 0; var_r29 < var_r28;) {
            HuPrcVSleep();
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r27) {
                var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
                return;
            }
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
            var_r29++;
        }
        var_r30++;
    }
    Hu3DModelScaleSet(var_r31->unk_184, var_r31->unk_178 = 1.0f,
        var_r31->unk_17C = 1.0f, var_r31->unk_180 = 1.0f);
    var_f21 = sp10;
    var_f22 = sp8;
    Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f22,
        var_r31->unk_164 = 410.0f, var_r31->unk_168 = var_f21);
    var_r31->unk_4 = 0;
}

void fn_1_2C7C(M508State *arg0)
{
    arg0->unk_4 = 3;
}

void fn_1_2C88(M508ModelObj *var_r31)
{
    float sp10;
    float spC;
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    float var_f31;
    float var_f30;
    float var_f29;
    float var_f28;
    float var_f27;
    float var_f26;
    float var_f25;

    Hu3DMotionSpeedSet(var_r31->unk_184, 1.0f);
    var_r31->unk_188 = 8;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[8], 0.0f, 16.0f,
        HU3D_ATTR_NONE);
    if (&sp8 != NULL) {
        sp8 = var_r31->unk_160;
    }
    if (&spC != NULL) {
        spC = var_r31->unk_164;
    }
    if (&sp10 != NULL) {
        sp10 = var_r31->unk_168;
    }
    for (var_r30 = 0; var_r30 < 0x2D; var_r30++) {
        var_f30 = 0.022222223f * (var_r30 + 1);
        var_f31 = HuSin(90.0f * var_f30);
        var_f31 *= var_f31 * var_f31;
        spC = 410.0f - (410.0f * var_f31);
        var_f27 = sp10;
        var_f28 = spC;
        var_f29 = sp8;
        Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f29,
            var_r31->unk_164 = var_f28, var_r31->unk_168 = var_f27);
        Hu3DModelScaleSet(var_r31->unk_184, var_r31->unk_178 = 1.0f - var_f30,
            var_r31->unk_17C = 1.0f - var_f30, var_r31->unk_180 = 1.0f - var_f30);
        var_r28 = 1;
        for (var_r29 = 0; var_r29 < var_r28;) {
            HuPrcVSleep();
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r27) {
                var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
                return;
            }
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
            var_r29++;
        }
    }
    var_f25 = sp10;
    var_f26 = sp8;
    Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f26, var_r31->unk_164 = 0.0f,
        var_r31->unk_168 = var_f25);
    var_r31->unk_4 = 0;
}

void fn_1_2F80(M508State *arg0)
{
    arg0->unk_4 = 4;
}

float fn_1_2F8C(float farg0, float farg1, float farg2)
{
    float var_f31;
    float var_f30;
    float var_f29;

    var_f29 = farg0;
    var_f31 = fmod(farg1 - var_f29, 360.0);
    if (var_f31 < 0.0f) {
        var_f31 += 360.0f;
    }
    if (var_f31 > 180.0f) {
        var_f31 -= 360.0f;
    }
    var_f30 = fmod(var_f29 + (var_f31 * farg2), 360.0);
    if (var_f30 < 0.0f) {
        var_f30 += 360.0f;
    }
    return var_f30;
}

void fn_1_3090(M508ModelObj *var_r31)
{
    float sp10;
    float spC;
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    float var_f31;
    float var_f30;
    float var_f29;
    float var_f28;
    float var_f27;
    float var_f26;
    float var_f25;
    float var_f24;

    var_r31->unk_188 = 0;
    Hu3DMotionShiftSet(var_r31->unk_184, *var_r31->unk_190, 9.0f, 9.0f, HU3D_MOTATTR_LOOP);
    if (&sp8 != NULL) {
        sp8 = var_r31->unk_16C;
    }
    if (&spC != NULL) {
        spC = var_r31->unk_170;
    }
    if (&sp10 != NULL) {
        sp10 = var_r31->unk_174;
    }

    while (1) {
        var_f27 = HuAtan(0.0, 2.0);
        var_f29 = spC;
        var_f31 = fmod(var_f27 - var_f29, 360.0);
        if (var_f31 < 0.0f) {
            var_f31 += 360.0f;
        }
        if (var_f31 > 180.0f) {
            var_f31 -= 360.0f;
        }
        var_f30 = fmod(var_f29 + (var_f31 * 0.1f), 360.0);
        if (var_f30 < 0.0f) {
            var_f30 += 360.0f;
        }
        var_f28 = var_f30;
        spC = var_f28;
        var_f24 = sp10;
        var_f25 = spC;
        var_f26 = sp8;
        Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = var_f26, var_r31->unk_170 = var_f25,
            var_r31->unk_174 = var_f24);
        if (!(spC < 1.0f) || !(spC > -1.0f)) {
            var_r29 = 1;
            for (var_r30 = 0; var_r30 < var_r29;) {
                HuPrcVSleep();
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r28) {
                    var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                    return;
                }
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                var_r30++;
            }
        } else {
            Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = 0.0f,
                var_r31->unk_170 = 0.0f, var_r31->unk_174 = 0.0f);
            var_r31->unk_4 = 0;
            return;
        }
    }
}

void fn_1_33D8(M508State *arg0)
{
    arg0->unk_4 = 5;
}

void fn_1_33E4(M508ModelObj *var_r31)
{
    float sp10;
    float spC;
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    s32 var_r26;
    s32 var_r25;
    float var_f31;
    float var_f30;
    float var_f29;
    float var_f28;
    float var_f27;
    float var_f26;
    float var_f25;
    float var_f24;
    float var_f23;

    var_r31->unk_188 = 0;
    Hu3DMotionShiftSet(var_r31->unk_184, *var_r31->unk_190, 0.0f, 8.0f, HU3D_MOTATTR_LOOP);
    while (1) {
        if (&sp8 != NULL) {
            sp8 = var_r31->unk_160;
        }
        if (&spC != NULL) {
            spC = var_r31->unk_164;
        }
        if (&sp10 != NULL) {
            sp10 = var_r31->unk_168;
        }
        var_r30 = 0;
        while (var_r30 < 10) {
            var_f31 = 0.1f * (var_r30 + 1);
            spC = 400.0 - (80.0 * HuSin(180.0f * var_f31));
            var_f28 = sp10;
            var_f29 = spC;
            var_f30 = sp8;
            Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f30,
                var_r31->unk_164 = var_f29, var_r31->unk_168 = var_f28);
            var_r27 = 1;
            for (var_r29 = 0; var_r29 < var_r27;) {
                HuPrcVSleep();
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r25) {
                    var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                    return;
                }
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                var_r29++;
            }
            var_r30++;
        }
        var_r30 = 0;
        while (var_r30 < 30) {
            var_f31 = 0.033333335f * (var_r30 + 1);
            spC = 400.0 + (200.0 * HuSin(180.0f * var_f31));
            var_f25 = sp10;
            var_f26 = spC;
            var_f27 = sp8;
            Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f27,
                var_r31->unk_164 = var_f26, var_r31->unk_168 = var_f25);
            var_r26 = 1;
            for (var_r28 = 0; var_r28 < var_r26;) {
                HuPrcVSleep();
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r25) {
                    var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                    return;
                }
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                var_r28++;
            }
            var_r30++;
        }
        var_f23 = sp10;
        var_f24 = sp8;
        Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f24,
            var_r31->unk_164 = 400.0f, var_r31->unk_168 = var_f23);
    }
}

const HuVecF lbl_1_rodata_4CC = { 0.0f, 1000.0f, 800.0f };
const HuVecF lbl_1_rodata_4D8 = { 0.0f, 0.0f, -600.0f };
const GXColor lbl_1_rodata_4E4 = { 0xFF, 0xFF, 0xFF, 0xFF };
const s32 lbl_1_rodata_4E8[5] = { 0x420015, 0x420014, 0x420017, 0x420016, 0x420018 };

M508LightObj *fn_1_37E0(s32 arg0)
{
    M508LightObj *var_r30;
    M508LightData *var_r31;

    var_r30 = (M508LightObj *) fn_1_7A3C(0x1000, 0x2000, lbl_1_rodata_4E8[arg0], 0, NULL, 1, NULL);
    var_r31 = &var_r30->unk_18;
    var_r31->unk_0 = Hu3DModelCreateData(0x420013);
    var_r31->unk_2 = Hu3DLLightCreateV(var_r30->unk_184, (HuVecF *) &lbl_1_rodata_4CC,
        (HuVecF *) &lbl_1_rodata_4D8, (GXColor *) &lbl_1_rodata_4E4);
    Hu3DLLightInfinitytSet(var_r30->unk_184, var_r31->unk_2);
    var_r31->unk_4 = Hu3DLLightCreateV(var_r31->unk_0, (HuVecF *) &lbl_1_rodata_4CC,
        (HuVecF *) &lbl_1_rodata_4D8, (GXColor *) &lbl_1_rodata_4E4);
    Hu3DLLightInfinitytSet(var_r31->unk_0, var_r31->unk_4);
    return var_r30;
}

void fn_1_38CC(M508LightObj *arg0, float farg0, float farg1, float farg2)
{
    M508LightData *var_r30;

    var_r30 = &arg0->unk_18;
    Hu3DModelPosSet(var_r30->unk_0, farg0, farg1, farg2);
    Hu3DModelPosSet(arg0->unk_184, arg0->unk_160 = farg0, arg0->unk_164 = farg1,
        arg0->unk_168 = farg2);
}

const s32 lbl_1_rodata_4FC[13][9] = {
    {
        0x008C0006, 0x008C0031, 0x008C003B, 0x008C003C, 0x008C003D,
        0x008C0046, 0x008C0047, 0x008C0048, 0x008C0049
    },
    {
        0x00330006, 0x00330031, 0x0033003B, 0x0033003C, 0x0033003D,
        0x00330046, 0x00330047, 0x00330048, 0x00330049
    },
    {
        0x00B70006, 0x00B70031, 0x00B7003B, 0x00B7003C, 0x00B7003D,
        0x00B70046, 0x00B70047, 0x00B70048, 0x00B70049
    },
    {
        0x00ED0006, 0x00ED0031, 0x00ED003B, 0x00ED003C, 0x00ED003D,
        0x00ED0046, 0x00ED0047, 0x00ED0048, 0x00ED0049
    },
    {
        0x00E60006, 0x00E60031, 0x00E6003B, 0x00E6003C, 0x00E6003D,
        0x00E60046, 0x00E60047, 0x00E60048, 0x00E60049
    },
    {
        0x00170006, 0x00170031, 0x0017003B, 0x0017003C, 0x0017003D,
        0x00170046, 0x00170047, 0x00170048, 0x00170049
    },
    {
        0x00E00006, 0x00E00031, 0x00E0003B, 0x00E0003C, 0x00E0003D,
        0x00E00046, 0x00E00047, 0x00E00048, 0x00E00049
    },
    {
        0x002D0006, 0x002D0031, 0x002D003B, 0x002D003C, 0x002D003D,
        0x002D0046, 0x002D0047, 0x002D0048, 0x002D0049
    },
    {
        0x00C90006, 0x00C90031, 0x00C9003B, 0x00C9003C, 0x00C9003D,
        0x00C90046, 0x00C90047, 0x00C90048, 0x00C90049
    },
    {
        0x00B00006, 0x00B00031, 0x00B0003B, 0x00B0003C, 0x00B0003D,
        0x00B00046, 0x00B00047, 0x00B00048, 0x00B00049
    },
    {
        0x00B00006, 0x00B00031, 0x00B0003B, 0x00B0003C, 0x00B0003D,
        0x00B00046, 0x00B00047, 0x00B00048, 0x00B00049
    },
    {
        0x00B00006, 0x00B00031, 0x00B0003B, 0x00B0003C, 0x00B0003D,
        0x00B00046, 0x00B00047, 0x00B00048, 0x00B00049
    },
    {
        0x00B00006, 0x00B00031, 0x00B0003B, 0x00B0003C, 0x00B0003D,
        0x00B00046, 0x00B00047, 0x00B00048, 0x00B00049
    }
};

const s32 lbl_1_rodata_6D0[4] = { 0xA, 0x28, 0x3C, 0x55 };

M508ModelObj *fn_1_3958(s32 var_r29)
{
    M508ModelObj *var_r31;
    M508State *var_r30;

    var_r31 = fn_1_8308(0x1000, 0x2800, var_r29, 9, (s32 *) lbl_1_rodata_4FC, 8,
        lbl_1_data_54, 2);
    var_r31->unk_188 = 5;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[5], 0.0f, 0.0f,
        HU3D_MOTATTR_LOOP);
    CharModelVoicePanSet(var_r29, lbl_1_rodata_C4[var_r29]);
    var_r30 = (M508State *) &var_r31->unk_18;
    var_r30->unk_0 = 0;
    var_r30->unk_4 = -1;
    var_r31->unk_4 = 0;
    return var_r31;
}

void fn_1_3A38(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_3A44(M508ModelObj *var_r31)
{
    M508ModelObj *var_r30;
    s32 var_r29;
    M508ModelObj *var_r28;
    s32 var_r27;
    char *var_r26;
    s32 var_r25;

    var_r31->unk_188 = 5;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[5], 0.0f, 8.0f,
        HU3D_MOTATTR_LOOP);
    var_r28 = lbl_1_bss_44[0][var_r31->unk_1C8];
    var_r26 = CharModelItemHookGet(var_r31->unk_1BC, 2, 0);
    Hu3DModelHookSet(var_r31->unk_184, var_r26, var_r28->unk_184);
    var_r30 = lbl_1_bss_44[0][var_r31->unk_1C8];
    var_r30->unk_158 = 1;
    Hu3DModelAttrReset(var_r30->unk_184, HU3D_ATTR_DISPOFF);
    while (1) {
        var_r27 = 1;
        for (var_r29 = 0; var_r29 < var_r27;) {
            HuPrcVSleep();
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r25) {
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                return;
            }
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
            var_r29++;
        }
    }
}

void fn_1_3B8C(M508State *arg0)
{
    arg0->unk_4 = 1;
}

void fn_1_3B98(M508ModelObj *var_r31)
{
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    char *sp8;
    s32 var_r30;
    M508State *var_r29;
    s16 var_r28;
    M508ModelObj *var_r27;
    M508ModelObj *var_r26;
    M508ModelObj *var_r25;
    M508ModelObj *var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 var_r21;
    s32 var_r20;
    M508ModelObj *var_r19;
    M508ModelObj *var_r18;
    s32 var_r17;
    s32 var_r16;

    var_r29 = (M508State *) &var_r31->unk_18;
    if (var_r29->unk_4 != -1) {
        Hu3DModelHookReset(var_r31->unk_184);
        var_r27 = lbl_1_bss_44[var_r29->unk_4][var_r31->unk_1C8];
        var_r27->unk_158 = 0;
        Hu3DModelDispOff(var_r27->unk_184);
    }
    var_r19 = lbl_1_bss_44[5][var_r31->unk_1C8];
    sp8 = CharModelItemHookGet(var_r31->unk_1BC, 2, 0);
    Hu3DModelHookSet(var_r31->unk_184, sp8, var_r19->unk_184);
    var_r26 = lbl_1_bss_44[5][var_r31->unk_1C8];
    var_r26->unk_158 = 1;
    Hu3DModelDispOn(var_r26->unk_184);
    var_r29->unk_0 = 0;
    var_r29->unk_4 = -1;
    if (var_r31->unk_1B8 != 0) {
        var_r30 = -1;
        while (var_r30 == -1) {
            var_r17 = frandmod(0x78) + 0x1E;
            sp18 = var_r17;
            for (var_r23 = 0; var_r23 < sp18;) {
                HuPrcVSleep();
                var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r16) {
                    var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
                    return;
                }
                var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
                var_r23++;
            }
            if ((s32) frandmod(0x64) < lbl_1_rodata_6D0[var_r31->unk_1C4]) {
                var_r30 = lbl_1_bss_110;
            } else {
                var_r30 = frandmod(5);
            }
        }
    } else {
        var_r28 = var_r31->unk_1C0;
        var_r30 = -1;
        while (var_r30 == -1) {
            if ((HuPadBtnDown[var_r28] & PAD_BUTTON_B) != 0) {
                var_r30 = 0;
            }
            if ((HuPadBtnDown[var_r28] & PAD_BUTTON_A) != 0) {
                var_r30 = 1;
            }
            if ((HuPadBtnDown[var_r28] & PAD_BUTTON_Y) != 0) {
                var_r30 = 2;
            }
            if ((HuPadBtnDown[var_r28] & PAD_BUTTON_X) != 0) {
                var_r30 = 3;
            }
            if ((HuPadBtnDown[var_r28] & PAD_TRIGGER_R) != 0) {
                var_r30 = 4;
            }
            sp14 = 1;
            for (var_r22 = 0; var_r22 < sp14;) {
                HuPrcVSleep();
                var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r16) {
                    var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
                    return;
                }
                var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
                var_r22++;
            }
        }
    }
    lbl_1_bss_0++;
    var_r29->unk_0 = 1;
    var_r29->unk_4 = var_r30;
    var_r25 = lbl_1_bss_44[5][var_r31->unk_1C8];
    var_r25->unk_158 = 0;
    Hu3DModelDispOff(var_r25->unk_184);
    Hu3DModelHookReset(var_r31->unk_184);
    var_r18 = lbl_1_bss_44[var_r30][var_r31->unk_1C8];
    Hu3DModelHookSet(var_r31->unk_184, lbl_1_data_74, var_r18->unk_184);
    var_r24 = lbl_1_bss_44[var_r30][var_r31->unk_1C8];
    var_r24->unk_158 = 1;
    Hu3DModelDispOn(var_r24->unk_184);
    switch (var_r31->unk_1C8) {
        case 0:
            HuAudFXPlay(0x689);
            break;
        case 1:
            HuAudFXPlay(0x68A);
            break;
        case 2:
            HuAudFXPlay(0x68B);
            break;
        case 3:
            HuAudFXPlay(0x68C);
            break;
    }
    var_r31->unk_188 = 2;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[2], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    sp10 = 0x14;
    for (var_r21 = 0; var_r21 < sp10;) {
        HuPrcVSleep();
        var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r16) {
            var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
            return;
        }
        var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
        var_r21++;
    }
    var_r31->unk_188 = 3;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[3], 0.0f, 8.0f,
        HU3D_MOTATTR_LOOP);
    while (1) {
        spC = 1;
        for (var_r20 = 0; var_r20 < spC;) {
            HuPrcVSleep();
            var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r16) {
                var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
                return;
            }
            var_r16 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r16;
            var_r20++;
        }
    }
}

void fn_1_4150(M508State *arg0)
{
    arg0->unk_4 = 2;
}

void fn_1_415C(M508ModelObj *var_r31)
{
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    float var_f31;
    float var_f30;

    var_r31->unk_188 = 6;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[6], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    M508_MODEL_ROT_GET(var_r31, NULL, &sp8, NULL);
    for (var_r30 = 0; var_r30 < 0x2E; var_r30++) {
        var_f31 = 0.02173913f * (var_r30 + 1);
        var_f30 = sp8 + ((-180.0f - sp8) * var_f31);
        Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = 0.0f,
            var_r31->unk_170 = var_f30, var_r31->unk_174 = 0.0f);
        var_r28 = 1;
        for (var_r29 = 0; var_r29 < var_r28;) {
            HuPrcVSleep();
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r27) {
                var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
                return;
            }
            var_r27 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r27;
            var_r29++;
        }
    }
    Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = 0.0f,
        var_r31->unk_170 = -180.0f, var_r31->unk_174 = 0.0f);
    var_r31->unk_4 = 0;
}

void fn_1_4374(M508State *arg0)
{
    arg0->unk_4 = 3;
}

void fn_1_4380(M508ModelObj *var_r31)
{
    float sp8;
    M508State *var_r27;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r26;
    s32 var_r25;
    s32 var_r24;
    float var_f31;
    float var_f30;

    var_r27 = (M508State *) &var_r31->unk_18;
    HuPrcSleep(0x3B);
    if (var_r27->unk_0 != 0) {
        var_r31->unk_188 = 4;
        Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[4], 0.0f, 8.0f,
            HU3D_ATTR_NONE);
    } else {
        var_r31->unk_188 = 6;
        Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[6], 0.0f, 8.0f,
            HU3D_ATTR_NONE);
    }
    M508_MODEL_ROT_GET(var_r31, NULL, &sp8, NULL);
    for (var_r30 = 0; var_r30 < 0x3C; var_r30++) {
        var_f31 = 0.016666668f * (var_r30 + 1);
        var_f30 = sp8 + ((-360.0f - sp8) * var_f31);
        Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = 0.0f,
            var_r31->unk_170 = var_f30, var_r31->unk_174 = 0.0f);
        var_r26 = 1;
        for (var_r29 = 0; var_r29 < var_r26;) {
            HuPrcVSleep();
            var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r24) {
                var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
                return;
            }
            var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
            var_r29++;
        }
    }
    Hu3DModelRotSet(var_r31->unk_184, var_r31->unk_16C = 0.0f,
        var_r31->unk_170 = 0.0f, var_r31->unk_174 = 0.0f);
    while (1) {
        var_r25 = 1;
        for (var_r28 = 0; var_r28 < var_r25;) {
            HuPrcVSleep();
            var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r24) {
                var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
                return;
            }
            var_r24 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r24;
            var_r28++;
        }
    }
}

s32 fn_1_4654(M508StateObj *arg0)
{
    M508State *var_r31;
    s32 var_r30;

    var_r31 = &arg0->unk_18;
    if (lbl_1_bss_110 == var_r31->unk_4) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    return var_r30;
}

void fn_1_469C(M508State *arg0)
{
    arg0->unk_4 = 4;
}

void fn_1_46A8(M508ModelObj *var_r30)
{
    s32 var_r31;
    s32 var_r29;
    s32 var_r28;

    var_r30->unk_188 = 7;
    Hu3DMotionShiftSet(var_r30->unk_184, var_r30->unk_190[7], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    while (1) {
        var_r29 = 1;
        for (var_r31 = 0; var_r31 < var_r29;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
            var_r31++;
        }
    }
}

void fn_1_4790(M508State *arg0)
{
    arg0->unk_4 = 5;
}

void fn_1_479C(M508ModelObj *var_r30)
{
    s32 var_r31;
    s32 var_r29;
    s32 var_r28;

    var_r30->unk_188 = 8;
    Hu3DMotionShiftSet(var_r30->unk_184, var_r30->unk_190[8], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    while (1) {
        var_r29 = 1;
        for (var_r31 = 0; var_r31 < var_r29;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
            var_r31++;
        }
    }
}

void fn_1_4884(M508State *arg0)
{
    arg0->unk_4 = 6;
}

void fn_1_4890(M508ModelObj *var_r31)
{
    Mtx sp18;
    HuVecF spC;
    M508State *sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;

    sp8 = (M508State *) &var_r31->unk_18;
    CharModelHookDustCreate(var_r31->unk_1BC, CharModelItemHookGet(var_r31->unk_1BC, 2, 0));
    Hu3DModelObjMtxGet(var_r31->unk_184, CharModelItemHookGet(var_r31->unk_1BC, 2, 0),
        sp18);
    spC.x = sp18[0][3];
    spC.y = sp18[1][3];
    spC.z = sp18[2][3];
    CharEffectSmokeCreate(1, &spC);
    var_r31->unk_188 = 0;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[0], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    while (1) {
        var_r29 = 1;
        for (var_r30 = 0; var_r30 < var_r29;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
            var_r30++;
        }
    }
}

void fn_1_49EC(M508State *arg0)
{
    arg0->unk_4 = 7;
}

void fn_1_49F8(M508ModelObj *var_r31)
{
    Mtx sp18;
    HuVecF spC;
    M508State *sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;

    sp8 = (M508State *) &var_r31->unk_18;
    CharModelHookDustCreate(var_r31->unk_1BC, CharModelItemHookGet(var_r31->unk_1BC, 2, 0));
    Hu3DModelObjMtxGet(var_r31->unk_184, CharModelItemHookGet(var_r31->unk_1BC, 2, 0),
        sp18);
    spC.x = sp18[0][3];
    spC.y = sp18[1][3];
    spC.z = sp18[2][3];
    CharEffectSmokeCreate(1, &spC);
    var_r31->unk_188 = 1;
    Hu3DMotionShiftSet(var_r31->unk_184, var_r31->unk_190[1], 0.0f, 8.0f,
        HU3D_ATTR_NONE);
    while (1) {
        var_r29 = 1;
        for (var_r30 = 0; var_r30 < var_r29;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
            var_r30++;
        }
    }
}

const s32 lbl_1_rodata_6F0[13] = {
    0x960000, 0x960001, 0x960002, 0x960003, 0x960004, 0x960006, 0x960007,
    0x960008, 0x960009, 0x96000A, 0x96000B, 0x96000C, 0x96000D
};

M508ScoreObj *fn_1_4B54(s32 arg0)
{
    M508ScoreData *var_r31;
    M508ScoreObj *var_r30;
    s32 var_r29;
    s16 var_r28;
    s32 var_r27;
    M508ScoreObj *var_r26;
    M508ScoreObj *var_r25;

    var_r30 = HuMemDirectMallocNum(HEAP_HEAP, 0x158, HU_MEMNUM_OVL);
    var_r30->unk_4 = 0;
    var_r30->unk_8 = 0;
    var_r30->unk_14 = 2;
    var_r30->unk_C = 0;
    var_r30->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, 8, HU_MEMNUM_OVL);
    for (var_r29 = 0; var_r29 < 2; var_r29++) {
        var_r30->unk_10[var_r29] = fn_1_7A24;
    }
    var_r30->unk_0 = HuPrcChildCreate(fn_1_79BC, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r30->unk_0->property = var_r30;
    if (lbl_1_data_90 != NULL) {
        for (var_r29 = 0; var_r29 < 2; var_r29++) {
            if (lbl_1_data_90[var_r29] != NULL) {
                var_r30->unk_10[var_r29] = lbl_1_data_90[var_r29];
            }
        }
    }
    var_r25 = var_r30;
    var_r26 = var_r25;
    var_r31 = &var_r26->unk_18;
    var_r31->unk_0 = HuSprGrpCreate(7);
    var_r31->unk_1C = MgScoreWinCreate(0x70, 0x28);
    for (var_r28 = 0; var_r28 < 7; var_r28++) {
        if (var_r28 < 4) {
            if (var_r28 != 0) {
                var_r27 = 0x420030;
            } else {
                var_r27 = lbl_1_rodata_6F0[GwPlayerConf[arg0].charNo];
            }
        } else if (var_r28 < 7) {
            var_r27 = 0x420031;
        }
        var_r31->unk_2[var_r28] = HuSprCreate(HuSprAnimRead(
            HuDataSelHeapReadNum(var_r27, HU_MEMNUM_OVL, HEAP_MODEL)), 0, 0);
        HuSprGrpMemberSet(var_r31->unk_0, var_r28, var_r31->unk_2[var_r28]);
    }
    MgScoreWinPosSet(var_r31->unk_1C, 0.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 0, -36.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 1, -8.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 2, 14.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 3, 36.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 4, -8.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 5, 14.0f, 0.0f);
    HuSprPosSet(var_r31->unk_0, 6, 36.0f, 0.0f);
    HuSprPriSet(var_r31->unk_0, 0, 0xB);
    HuSprPriSet(var_r31->unk_0, 1, 0xB);
    HuSprPriSet(var_r31->unk_0, 2, 0xB);
    HuSprPriSet(var_r31->unk_0, 3, 0xB);
    HuSprPriSet(var_r31->unk_0, 4, 0xA);
    HuSprPriSet(var_r31->unk_0, 5, 0xA);
    HuSprPriSet(var_r31->unk_0, 6, 0xA);
    MgScoreWinDispSet(var_r31->unk_1C, 0);
    HuSprDispOff(var_r31->unk_0, 4);
    HuSprDispOff(var_r31->unk_0, 5);
    HuSprDispOff(var_r31->unk_0, 6);
    var_r31->unk_18 = 0;
    return var_r26;
}

void fn_1_4F48(M508ScoreObj *arg0, const M508Vec2 *arg1, float farg0, float farg1)
{
    M508ScoreData *var_r31;

    var_r31 = &arg0->unk_18;
    HuSprGrpPosSet(var_r31->unk_0, var_r31->unk_10 = farg0, var_r31->unk_14 = farg1);
    MgScoreWinPosSet(var_r31->unk_1C, var_r31->unk_10, var_r31->unk_14);
}

void fn_1_4FA8(M508ScoreObj *arg0)
{
    M508ScoreData *var_r31;
    s32 var_r30;

    var_r31 = &arg0->unk_18;
    for (var_r30 = 0; var_r30 < 4; var_r30++) {
        HuSprAttrReset(var_r31->unk_0, var_r30, 4);
    }
    MgScoreWinDispSet(var_r31->unk_1C, 1);
}

void fn_1_5010(M508ScoreObj *arg0)
{
    M508ScoreData *var_r31;
    s32 var_r30;

    var_r31 = &arg0->unk_18;
    for (var_r30 = 0; var_r30 < 7; var_r30++) {
        HuSprAttrSet(var_r31->unk_0, var_r30, 4);
    }
    MgScoreWinDispSet(var_r31->unk_1C, 0);
}

void fn_1_5078(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_5084(void)
{
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    while (1) {
        var_r30 = 1;
        for (var_r31 = 0; var_r31 < var_r30;) {
            HuPrcVSleep();
            var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r29) {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                var_r31++;
            } else {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                return;
            }
        }
    }
}

void fn_1_512C(M508ModelObj *arg0)
{
    if (arg0->unk_30 < 3) {
        arg0->unk_30++;
    }
    arg0->unk_4 = 1;
}

void fn_1_5164(M508ScoreObj *arg0)
{
    M508ScoreData *var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    M508ScoreObj *var_r27;
    s32 var_r26;
    s32 var_r25;
    float var_f31;
    float var_f30;

    var_r27 = arg0;
    var_r31 = &var_r27->unk_18;
    var_r30 = var_r31->unk_18;
    HuSprAttrReset(var_r31->unk_0, var_r30 + 3, 4);
    for (var_r29 = 0; var_r29 < 0x3C; var_r29++) {
        var_f30 = 0.016666668f * (var_r29 + 1);
        var_f31 = HuSin(90.0f * var_f30);
        HuSprScaleSet(var_r31->unk_0, var_r30 + 3, 1.0f + (2.0f - (2.0f * var_f31)),
            1.0f + (2.0f - (2.0f * var_f31)));
        HuSprTPLvlSet(var_r31->unk_0, var_r30 + 3, var_f31);
        var_r26 = 1;
        for (var_r28 = 0; var_r28 < var_r26;) {
            HuPrcVSleep();
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r25) {
                var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
                return;
            }
            var_r25 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r25;
            var_r28++;
        }
    }
    HuSprScaleSet(var_r31->unk_0, var_r30 + 3, 1.0f, 1.0f);
    HuSprTPLvlSet(var_r31->unk_0, var_r30 + 3, 1.0f);
    var_r27->unk_4 = 0;
}

const s32 lbl_1_rodata_738[7] = {
    0x42001A, 0x420019, 0x42001C, 0x42001B, 0x42001D, 0x42001E, 0x42000A
};

M508ModelObj *fn_1_5394(s32 arg0)
{
    M508ModelObj *var_r31;

    var_r31 = fn_1_7A3C(0x1000, 0x2000, lbl_1_rodata_738[arg0], 0, NULL, 1, NULL);
    var_r31->unk_158 = 0;
    Hu3DModelDispOff(var_r31->unk_184);
    return var_r31;
}

M508ModelObj *fn_1_5414(s32 arg0)
{
    M508ModelObj *var_r31;

    var_r31 = fn_1_7A3C(0x1000, 0x2000, -1, 0, NULL, 2, lbl_1_data_98);
    return var_r31;
}

void fn_1_5464(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_5470(void)
{
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    while (1) {
        var_r30 = 1;
        for (var_r31 = 0; var_r31 < var_r30;) {
            HuPrcVSleep();
            var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r29) {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                var_r31++;
            } else {
                var_r29 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r29;
                return;
            }
        }
    }
}

void fn_1_5518(M508State *arg0)
{
    arg0->unk_4 = 1;
}

void fn_1_5524(M508ModelObj *arg0)
{
    s32 var_r31;
    s16 var_r30;
    s16 var_r29;
    s32 var_r28;
    s32 var_r26;

    var_r29 = Hu3DMotionCreateData(0x42000A);
    var_r30 = Hu3DModelCameraCreate(var_r29, 1);
    Hu3DCameraMotionStart(var_r30, 1);
    var_r28 = 0xB4;
    for (var_r31 = 0; var_r31 < var_r28; var_r31++) {
        HuPrcVSleep();
        var_r26 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r26) {
            var_r26 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r26;
            return;
        }
        var_r26 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r26;
    }
    Hu3DModelKill(var_r30);
    arg0->unk_4 = 0;
}

M508ModelObj *fn_1_560C(void)
{
    M508ModelObj *var_r31;
    s32 var_r30;
    M508ModelObj *var_r29;
    M508ModelObj *var_r28;

    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x158, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = 1;
    var_r31->unk_C = 0;
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, 4, HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < 1; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_7A24;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_79BC, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    if (lbl_1_data_A0 != NULL) {
        for (var_r30 = 0; var_r30 < 1; var_r30++) {
            if (lbl_1_data_A0[var_r30] != NULL) {
                var_r31->unk_10[var_r30] = lbl_1_data_A0[var_r30];
            }
        }
    }
    var_r28 = var_r31;
    var_r29 = var_r28;
    return var_r29;
}

const s32 lbl_1_rodata_754[6] = {
    0x42000D, 0x420011, 0x42000E, 0x42000F, 0x420010, 0x420012
};

M508ModelObj *fn_1_5758(s32 var_r29)
{
    M508StateObj *var_r31;
    M508State *var_r30;

    var_r31 = (M508StateObj *) fn_1_7A3C(0x1000, 0x2000, lbl_1_rodata_754[var_r29],
        0, NULL, 2, lbl_1_data_A4);
    var_r30 = &var_r31->unk_18;
    var_r30->unk_0 = var_r29;
    return (M508ModelObj *) var_r31;
}

void fn_1_57D4(M508State *arg0)
{
    arg0->unk_4 = 0;
}

void fn_1_57E0(M508ModelObj *arg0)
{
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;

    arg0->unk_158 = 0;
    Hu3DModelDispOff(arg0->unk_184);
    Hu3DModelAttrSet(arg0->unk_184, HU3D_MOTATTR_PAUSE);
    while (1) {
        for (var_r30 = 0; var_r30 < 1;) {
            HuPrcVSleep();
            var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 == var_r28) {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                var_r30++;
            } else {
                var_r28 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r28;
                return;
            }
        }
    }
}

void fn_1_58B8(M508State *arg0)
{
    arg0->unk_4 = 1;
}

void fn_1_58C4(M508ModelObj *var_r31)
{
    float sp10;
    float spC;
    float sp8;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    s16 var_r27;
    s16 var_r26;
    s16 var_r25;
    M508State *var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 var_r21;
    s32 var_r20;
    s32 var_r19;
    s32 var_r18;
    float var_f31;
    float var_f30;
    float var_f29;

    var_r24 = (M508State *) &var_r31->unk_18;
    var_r23 = var_r24->unk_0;
    if (var_r23 != 1) {
        if (var_r23 < 1) {
            if (var_r23 < 0) {
                goto done;
            }
            goto normal_motion;
        }
        if (var_r23 != 5) {
            if (var_r23 < 5) {
normal_motion:
                var_r31->unk_158 = 1;
                Hu3DModelDispOn(var_r31->unk_184);
                var_r27 = var_r31->unk_184;
                Hu3DModelAttrReset(var_r27, HU3D_MOTATTR_PAUSE);
                Hu3DModelAttrReset(var_r27, HU3D_MOTATTR_LOOP);
                Hu3DMotionTimeSet(var_r31->unk_184, 0.0f);
                goto normal_check;
normal_loop:
                var_r21 = 1;
                for (var_r30 = 0; var_r30 < var_r21;) {
                    HuPrcVSleep();
                    var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r18) {
                        var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                        ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
                        return;
                    }
                    var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
                    ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
                    var_r30++;
                }
normal_check:
                if (Hu3DMotionEndCheck(var_r31->unk_184) == 0) {
                    var_r23 = 1;
                } else {
                    var_r23 = 0;
                }
                if (var_r23 != 0) {
                    goto normal_loop;
                }
                goto done;
            }
            goto done;
        }
        goto state5;
    }
    var_r31->unk_158 = 1;
    Hu3DModelDispOn(var_r31->unk_184);
    var_r26 = var_r31->unk_184;
    Hu3DModelAttrReset(var_r26, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrSet(var_r26, HU3D_MOTATTR_LOOP);
    Hu3DMotionTimeSet(var_r31->unk_184, 0.0f);
    goto state1_check;
state1_loop:
    var_r20 = 1;
    for (var_r29 = 0; var_r29 < var_r20;) {
        HuPrcVSleep();
        var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r18) {
            var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
            return;
        }
        var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
        var_r29++;
    }
state1_check:
    if (Hu3DMotionEndCheck(var_r31->unk_184) == 0) {
        var_r22 = 1;
    } else {
        var_r22 = 0;
    }
    if (var_r22 != 0) {
        goto state1_loop;
    }
    goto done;
state5:
    if (&sp8 != NULL) {
        sp8 = var_r31->unk_160;
    }
    if (&spC != NULL) {
        spC = var_r31->unk_164;
    }
    if (&sp10 != NULL) {
        sp10 = var_r31->unk_168;
    }
    spC = -20.0f;
    var_f29 = sp10;
    var_f30 = spC;
    var_f31 = sp8;
    Hu3DModelPosSet(var_r31->unk_184, var_r31->unk_160 = var_f31,
        var_r31->unk_164 = var_f30, var_r31->unk_168 = var_f29);
    Hu3DModelAttrReset(var_r31->unk_184, HU3D_MOTATTR_REV);
    var_r31->unk_158 = 1;
    Hu3DModelDispOn(var_r31->unk_184);
    var_r25 = var_r31->unk_184;
    Hu3DModelAttrReset(var_r25, HU3D_MOTATTR_PAUSE);
    Hu3DModelAttrReset(var_r25, HU3D_MOTATTR_LOOP);
    Hu3DMotionTimeSet(var_r31->unk_184, 0.0f);
    var_r19 = 0x6E;
    for (var_r28 = 0; var_r28 < var_r19;) {
        HuPrcVSleep();
        var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        if (((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 != var_r18) {
            var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
            ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
            return;
        }
        var_r18 = ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_4;
        ((M508ModelObj *) HuPrcCurrentGet()->property)->unk_8 = var_r18;
        var_r28++;
    }
done:
    var_r31->unk_4 = 0;
}

void fn_1_5C7C(s32 arg0, s32 arg1, s32 arg2)
{
    switch (arg1) {
    case 0:
        omVibrate(arg0, arg2, 6, 6);
        return;
    case 1:
        omVibrate(arg0, arg2, 4, 2);
        return;
    case 2:
        omVibrate(arg0, arg2, 0xC, 0);
    }
}

float fn_1_5D20(M508Vec2 *arg0, M508Vec2 *arg1)
{
    return (arg0->unk_0 * arg1->unk_0) + (arg0->unk_4 * arg1->unk_4);
}

float fn_1_5D40(M508Vec2 *arg0, M508Vec2 *arg1)
{
    return (arg0->unk_0 * arg1->unk_4) - (arg0->unk_4 * arg1->unk_0);
}

float fn_1_5D60(M508Vec2 *arg0)
{
    float var_f30;

    var_f30 = (arg0->unk_0 * arg0->unk_0) + (arg0->unk_4 * arg0->unk_4);
    return sqrt(var_f30);
}

void fn_1_5EE0(M508Vec2 *arg0, M508Vec2 *arg1)
{
    float var_f30;
    float var_f28;
    float var_f27;

    var_f30 = (arg1->unk_0 * arg1->unk_0) + (arg1->unk_4 * arg1->unk_4);
    var_f27 = sqrt(var_f30);
    var_f28 = 1.0f / var_f27;
    arg0->unk_0 = arg1->unk_0 * var_f28;
    arg0->unk_4 = arg1->unk_4 * var_f28;
}

s32 fn_1_60A8(M508Vec2 *arg0, M508Circle *arg1)
{
    s32 var_r31;
    float var_f31;
    float var_f30;
    float var_f29;

    var_f31 = arg0->unk_0 - arg1->unk_0;
    var_f30 = arg0->unk_4 - arg1->unk_4;
    var_f29 = arg1->unk_8;
    if (((var_f31 * var_f31) + (var_f30 * var_f30)) > (var_f29 * var_f29)) {
        var_r31 = 0;
    } else {
        var_r31 = 1;
    }
    return var_r31;
}

s32 fn_1_6130(M508Circle *arg0, M508Circle *arg1)
{
    s32 var_r31;
    float var_f31;
    float var_f30;
    float var_f29;

    var_f31 = arg0->unk_0 - arg1->unk_0;
    var_f30 = arg0->unk_4 - arg1->unk_4;
    var_f29 = arg0->unk_8 + arg1->unk_8;
    if (((var_f31 * var_f31) + (var_f30 * var_f30)) < (var_f29 * var_f29)) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

s32 fn_1_61C0(M508Rect *arg0, M508Rect *arg1)
{
    if (arg0->unk_0 > arg1->unk_8) {
        return 0;
    }
    if (arg0->unk_8 < arg1->unk_0) {
        return 0;
    }
    if (arg0->unk_4 > arg1->unk_C) {
        return 0;
    }
    if (arg0->unk_C < arg1->unk_4) {
        return 0;
    }
    return 1;
}

s32 fn_1_6228(M508Vec2 *arg0, M508Polygon *arg1, s32 arg2)
{
    s32 var_r31;
    s32 var_r30;
    M508Vec2 *var_r29;
    M508Vec2 *var_r28;
    s32 var_r27;
    s32 var_r26;
    s32 var_r25;
    s32 var_r24;

    var_r30 = 0;
    var_r26 = 0;
    var_r27 = arg1->unk_0 - 1;
    for (var_r31 = 0; var_r31 < var_r27; var_r31++) {
        var_r29 = &arg1->unk_4[var_r31];
        var_r28 = &arg1->unk_4[var_r31 + 1];
        var_r26 = ((arg0->unk_0 - var_r29->unk_0) * (arg0->unk_4 - var_r28->unk_4)) -
            ((arg0->unk_4 - var_r29->unk_4) * (arg0->unk_0 - var_r28->unk_0));
        if (var_r26 < 0) {
            var_r30++;
        }
    }
    var_r25 = 1;
    if ((var_r30 != 0) && (var_r30 != var_r27)) {
        var_r25 = 0;
    }
    if (var_r25 != 0) {
        var_r24 = 1;
    } else {
        var_r24 = 0;
    }
    return var_r24;
}

s32 fn_1_6318(M508Circle *arg0, M508Rect *arg1)
{
    s32 var_r31;
    s32 var_r30;
    float var_f30;
    float var_f28;
    float var_f27;
    float var_f26;
    float var_f25;
    float var_f24;
    float var_f23;
    float var_f22;
    float var_f21;
    float var_f20;
    float var_f19;

    var_f26 = arg1->unk_0 - arg0->unk_0;
    var_f27 = arg1->unk_4 - arg0->unk_4;
    var_f28 = arg0->unk_8;
    if (((var_f26 * var_f26) + (var_f27 * var_f27)) > (var_f28 * var_f28)) {
        var_r31 = 0;
    } else {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        return 1;
    }
    var_f23 = arg1->unk_8 - arg0->unk_0;
    var_f24 = arg1->unk_C - arg0->unk_4;
    var_f25 = arg0->unk_8;
    if (((var_f23 * var_f23) + (var_f24 * var_f24)) > (var_f25 * var_f25)) {
        var_r30 = 0;
    } else {
        var_r30 = 1;
    }
    if (var_r30 != 0) {
        return 1;
    }
    lbl_1_bss_218.unk_0 = arg1->unk_8 - arg1->unk_0;
    lbl_1_bss_218.unk_4 = arg1->unk_C - arg1->unk_4;
    lbl_1_bss_210.unk_0 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_210.unk_4 = arg0->unk_4 - arg1->unk_4;
    var_f20 = (lbl_1_bss_218.unk_0 * lbl_1_bss_210.unk_4) -
        (lbl_1_bss_218.unk_4 * lbl_1_bss_210.unk_0);
    lbl_1_bss_1EC = var_f20;
    if (lbl_1_bss_1EC == 0.0f) {
        lbl_1_bss_1F0 = *(M508Vec2 *)arg0;
        goto block_22;
    }
    lbl_1_bss_208.unk_0 = lbl_1_bss_218.unk_4 * lbl_1_bss_1EC;
    lbl_1_bss_208.unk_4 = -(lbl_1_bss_218.unk_0 * lbl_1_bss_1EC);
    var_f30 = (lbl_1_bss_208.unk_0 * lbl_1_bss_208.unk_0) +
        (lbl_1_bss_208.unk_4 * lbl_1_bss_208.unk_4);
    var_f21 = sqrt(var_f30);
    var_f22 = 1.0f / var_f21;
    lbl_1_bss_200.unk_0 = lbl_1_bss_208.unk_0 * var_f22;
    lbl_1_bss_200.unk_4 = lbl_1_bss_208.unk_4 * var_f22;
    lbl_1_bss_1F8.unk_0 = arg1->unk_0 - arg0->unk_0;
    lbl_1_bss_1F8.unk_4 = arg1->unk_4 - arg0->unk_4;
    var_f19 = (lbl_1_bss_200.unk_0 * lbl_1_bss_1F8.unk_0) +
        (lbl_1_bss_200.unk_4 * lbl_1_bss_1F8.unk_4);
    lbl_1_bss_1E8 = var_f19;
    if (lbl_1_bss_1E8 > arg0->unk_8) {
        return 0;
    }
    lbl_1_bss_1F0.unk_0 = arg0->unk_0 + (lbl_1_bss_200.unk_0 * lbl_1_bss_1E8);
    lbl_1_bss_1F0.unk_4 = arg0->unk_4 + (lbl_1_bss_200.unk_4 * lbl_1_bss_1E8);

block_22:
    if ((arg1->unk_0 < lbl_1_bss_1F0.unk_0) && (lbl_1_bss_1F0.unk_0 < arg1->unk_8)) {
        return 1;
    }
    if ((arg1->unk_8 < lbl_1_bss_1F0.unk_0) && (lbl_1_bss_1F0.unk_0 < arg1->unk_0)) {
        return 1;
    }
    if ((arg1->unk_4 < lbl_1_bss_1F0.unk_4) && (lbl_1_bss_1F0.unk_4 < arg1->unk_C)) {
        return 1;
    }
    if ((arg1->unk_C < lbl_1_bss_1F0.unk_4) && (lbl_1_bss_1F0.unk_4 < arg1->unk_4)) {
        return 1;
    }
    return 0;
}

s32 fn_1_6964(M508Circle *arg0, M508Polygon *arg1, s32 arg2)
{
    float sp8[3];
    s32 var_r29;
    s32 var_r28;
    M508Vec2 *var_r27;
    M508Vec2 *var_r26;
    s32 var_r25;
    s32 var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 var_r21;
    s32 var_r20;

    var_r25 = 0;
    var_r24 = 0;
    var_r23 = arg1->unk_0 - 1;
    for (var_r28 = 0; var_r28 < var_r23; var_r28++) {
        var_r26 = &arg1->unk_4[var_r28];
        var_r27 = &arg1->unk_4[var_r28 + 1];
        var_r24 = ((arg0->unk_0 - var_r26->unk_0) * (arg0->unk_4 - var_r27->unk_4)) -
            ((arg0->unk_4 - var_r26->unk_4) * (arg0->unk_0 - var_r27->unk_0));
        if (var_r24 < 0) {
            var_r25++;
        }
    }
    var_r22 = 1;
    if ((var_r25 != 0) && (var_r25 != var_r23)) {
        var_r22 = 0;
    }
    if (var_r22 != 0) {
        var_r21 = 1;
    } else {
        var_r21 = 0;
    }
    if (var_r21 != 0) {
        return 1;
    }
    var_r20 = arg1->unk_0 - 1;
    var_r29 = 0;
    while (var_r29 < var_r20) {
        sp8[0] = arg1->unk_4[var_r29].unk_0;
        sp8[1] = arg1->unk_4[var_r29].unk_4;
        sp8[2] = arg1->unk_4[var_r29 + 1].unk_0;
        sp8[2] = arg1->unk_4[var_r29 + 1].unk_4;
        if (fn_1_6318(arg0, (M508Rect *)sp8) != 0) {
            return 1;
        }
        var_r29++;
    }
    return 0;
}

s32 fn_1_6AF4(M508Rect *arg0, M508Circle *arg1, s32 arg2)
{
    float sp8[3];
    s32 var_r29;
    s32 var_r28;
    M508Vec2 *var_r27;
    M508Vec2 *var_r26;
    s32 var_r25;
    s32 var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 var_r21;
    s32 var_r20;
    s32 var_r19;

    lbl_1_bss_1C0[0].unk_0 = arg0->unk_0;
    lbl_1_bss_1C0[0].unk_4 = arg0->unk_4;
    lbl_1_bss_1C0[1].unk_0 = arg0->unk_8;
    lbl_1_bss_1C0[1].unk_4 = arg0->unk_4;
    lbl_1_bss_1C0[2].unk_0 = arg0->unk_8;
    lbl_1_bss_1C0[2].unk_4 = arg0->unk_C;
    lbl_1_bss_1C0[3].unk_0 = arg0->unk_0;
    lbl_1_bss_1C0[3].unk_4 = arg0->unk_C;
    lbl_1_bss_1C0[4].unk_0 = arg0->unk_0;
    lbl_1_bss_1C0[4].unk_4 = arg0->unk_4;
    lbl_1_bss_1B8.unk_0 = 5;
    lbl_1_bss_1B8.unk_4 = lbl_1_bss_1C0;
    var_r25 = 0;
    var_r23 = 0;
    var_r22 = lbl_1_bss_1B8.unk_0 - 1;
    for (var_r28 = 0; var_r28 < var_r22; var_r28++) {
        var_r26 = &lbl_1_bss_1B8.unk_4[var_r28];
        var_r27 = &lbl_1_bss_1B8.unk_4[var_r28 + 1];
        var_r23 = ((arg1->unk_0 - var_r26->unk_0) * (arg1->unk_4 - var_r27->unk_4)) -
            ((arg1->unk_4 - var_r26->unk_4) * (arg1->unk_0 - var_r27->unk_0));
        if (var_r23 < 0) {
            var_r25++;
        }
    }
    var_r21 = 1;
    if ((var_r25 != 0) && (var_r25 != var_r22)) {
        var_r21 = 0;
    }
    if (var_r21 != 0) {
        var_r20 = 1;
    } else {
        var_r20 = 0;
    }
    if (var_r20 != 0) {
        var_r24 = 1;
    } else {
        var_r19 = lbl_1_bss_1B8.unk_0 - 1;
        var_r29 = 0;
        goto loop_17_check;
    loop_17:
        sp8[0] = lbl_1_bss_1B8.unk_4[var_r29].unk_0;
        sp8[1] = lbl_1_bss_1B8.unk_4[var_r29].unk_4;
        sp8[2] = lbl_1_bss_1B8.unk_4[var_r29 + 1].unk_0;
        sp8[2] = lbl_1_bss_1B8.unk_4[var_r29 + 1].unk_4;
        if (fn_1_6318(arg1, (M508Rect *)sp8) != 0) {
            var_r24 = 1;
            goto loop_17_done;
        }
        var_r29++;
    loop_17_check:
        if (var_r29 < var_r19) {
            goto loop_17;
        }
        var_r24 = 0;
    loop_17_done:;
    }
    return var_r24;
}

s32 fn_1_6D8C(M508Sphere *arg0, M508Sphere *arg1)
{
    s32 var_r31;
    float var_f31;
    float var_f30;
    float var_f29;
    float var_f28;

    var_f31 = arg0->unk_0 - arg1->unk_0;
    var_f30 = arg0->unk_4 - arg1->unk_4;
    var_f29 = arg0->unk_8 - arg1->unk_8;
    var_f28 = arg0->unk_C + arg1->unk_C;
    if (((var_f29 * var_f29) + ((var_f31 * var_f31) + (var_f30 * var_f30))) < (var_f28 * var_f28)) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

s32 fn_1_6E40(M508Circle *arg0, M508Circle *arg1)
{
    float var_f30;

    lbl_1_bss_1B4 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_1B0 = arg0->unk_4 - arg1->unk_4;
    lbl_1_bss_1AC = arg0->unk_8 + arg1->unk_8;
    var_f30 = (lbl_1_bss_1B4 * lbl_1_bss_1B4) + (lbl_1_bss_1B0 * lbl_1_bss_1B0);
    lbl_1_bss_1A8 = sqrtf(var_f30);
    if (lbl_1_bss_1A8 < lbl_1_bss_1AC) {
        if (lbl_1_bss_1A8 == 0.0f) {
            lbl_1_bss_1B4 = 0.0f;
            lbl_1_bss_1B0 = -1.0f;
        } else {
            lbl_1_bss_1B4 /= lbl_1_bss_1A8;
            lbl_1_bss_1B0 /= lbl_1_bss_1A8;
        }
        arg0->unk_0 = arg1->unk_0 + (lbl_1_bss_1B4 * lbl_1_bss_1AC);
        arg0->unk_4 = arg1->unk_4 + (lbl_1_bss_1B0 * lbl_1_bss_1AC);
        return 1;
    }
    return 0;
}

s32 fn_1_70E0(M508Circle *arg0, M508Rect *arg1)
{
    s32 var_r31;
    float var_f29;
    float var_f28;
    float var_f26;
    float var_f24;
    float var_f23;
    float var_f22;

    lbl_1_bss_1A0.unk_0 = arg1->unk_8 - arg1->unk_0;
    lbl_1_bss_1A0.unk_4 = arg1->unk_C - arg1->unk_4;
    lbl_1_bss_198.unk_0 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_198.unk_4 = arg0->unk_4 - arg1->unk_4;
    var_f23 = (lbl_1_bss_1A0.unk_0 * lbl_1_bss_198.unk_4) -
        (lbl_1_bss_1A0.unk_4 * lbl_1_bss_198.unk_0);
    lbl_1_bss_174 = var_f23;
    if (lbl_1_bss_174 == 0.0f) {
        lbl_1_bss_178 = *(M508Vec2 *)arg0;
        goto block_12;
    }
    lbl_1_bss_190.unk_0 = lbl_1_bss_1A0.unk_4 * lbl_1_bss_174;
    lbl_1_bss_190.unk_4 = -(lbl_1_bss_1A0.unk_0 * lbl_1_bss_174);
    var_f29 = (lbl_1_bss_190.unk_0 * lbl_1_bss_190.unk_0) +
        (lbl_1_bss_190.unk_4 * lbl_1_bss_190.unk_4);
    var_f24 = sqrt(var_f29);
    var_f26 = 1.0f / var_f24;
    lbl_1_bss_188.unk_0 = lbl_1_bss_190.unk_0 * var_f26;
    lbl_1_bss_188.unk_4 = lbl_1_bss_190.unk_4 * var_f26;
    lbl_1_bss_180.unk_0 = arg1->unk_0 - arg0->unk_0;
    lbl_1_bss_180.unk_4 = arg1->unk_4 - arg0->unk_4;
    var_f22 = (lbl_1_bss_188.unk_0 * lbl_1_bss_180.unk_0) +
        (lbl_1_bss_188.unk_4 * lbl_1_bss_180.unk_4);
    lbl_1_bss_170 = var_f22;
    if (lbl_1_bss_170 > arg0->unk_8) {
        return 0;
    }
    lbl_1_bss_178.unk_0 = arg0->unk_0 + (lbl_1_bss_188.unk_0 * lbl_1_bss_170);
    lbl_1_bss_178.unk_4 = arg0->unk_4 + (lbl_1_bss_188.unk_4 * lbl_1_bss_170);

block_12:
    lbl_1_bss_164.unk_0 = lbl_1_bss_178.unk_0;
    lbl_1_bss_164.unk_4 = lbl_1_bss_178.unk_4;
    lbl_1_bss_164.unk_8 = 1.0f;
    lbl_1_bss_1B4 = arg0->unk_0 - lbl_1_bss_164.unk_0;
    lbl_1_bss_1B0 = arg0->unk_4 - lbl_1_bss_164.unk_4;
    lbl_1_bss_1AC = arg0->unk_8 + lbl_1_bss_164.unk_8;
    var_f28 = (lbl_1_bss_1B4 * lbl_1_bss_1B4) + (lbl_1_bss_1B0 * lbl_1_bss_1B0);
    lbl_1_bss_1A8 = sqrtf(var_f28);
    if (lbl_1_bss_1A8 < lbl_1_bss_1AC) {
        if (lbl_1_bss_1A8 == 0.0f) {
            lbl_1_bss_1B4 = 0.0f;
            lbl_1_bss_1B0 = -1.0f;
        } else {
            lbl_1_bss_1B4 /= lbl_1_bss_1A8;
            lbl_1_bss_1B0 /= lbl_1_bss_1A8;
        }
        arg0->unk_0 = lbl_1_bss_164.unk_0 + (lbl_1_bss_1B4 * lbl_1_bss_1AC);
        arg0->unk_4 = lbl_1_bss_164.unk_4 + (lbl_1_bss_1B0 * lbl_1_bss_1AC);
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

M508ModelObj *fn_1_7848(s32 arg0, u32 arg1, s32 arg2, M508ModelFunc *arg3)
{
    u32 spC;
    s32 sp8;
    M508ModelObj *var_r31;
    s32 var_r30;
    M508ModelFunc *var_r29;
    s32 var_r28;

    sp8 = arg0;
    spC = arg1;
    var_r28 = arg2;
    var_r29 = arg3;
    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x158, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = var_r28;
    var_r31->unk_C = 0;
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r28 * sizeof(M508ModelFunc), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_7A24;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_79BC, sp8, spC, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    if (var_r29 != NULL) {
        for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
            if (var_r29[var_r30] != NULL) {
                var_r31->unk_10[var_r30] = var_r29[var_r30];
            }
        }
    }
    return var_r31;
}

void fn_1_797C(M508ModelObj *arg0)
{
    HuMemDirectFree(arg0->unk_10);
    HuPrcKill(arg0->unk_0);
    HuMemDirectFree(arg0);
}

void fn_1_79BC(void)
{
    M508ModelObj *var_r31;

    var_r31 = HuPrcCurrentGet()->property;
    while (var_r31->unk_4 < var_r31->unk_14) {
        var_r31->unk_10[var_r31->unk_4](var_r31, var_r31->unk_10);
        var_r31->unk_8 = var_r31->unk_4;
    }
    HuPrcEnd();
}

void fn_1_7A24(void)
{
    while (1) {
        HuPrcSleep(0);
    }
}

M508ModelObj *fn_1_7A3C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4,
                        s32 arg5, M508ModelFunc *arg6)
{
    u32 spC;
    s32 sp8;
    M508ModelObj *var_r31;
    s32 var_r30;
    M508ModelFunc *var_r29;
    s32 var_r28;
    s32 *var_r27;
    s32 var_r26;
    s32 var_r25;

    sp8 = arg0;
    spC = arg1;
    var_r25 = arg2;
    var_r26 = arg3;
    var_r27 = arg4;
    var_r28 = arg5;
    var_r29 = arg6;
    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x1B8, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = var_r28;
    var_r31->unk_158 = 1;
    var_r31->unk_160 = 0.0f;
    var_r31->unk_164 = 0.0f;
    var_r31->unk_168 = 0.0f;
    var_r31->unk_16C = 0.0f;
    var_r31->unk_170 = 0.0f;
    var_r31->unk_174 = 0.0f;
    var_r31->unk_178 = 1.0f;
    var_r31->unk_17C = 1.0f;
    var_r31->unk_180 = 1.0f;
    var_r31->unk_184 = -1;
    var_r31->unk_C = 0;
    var_r31->unk_18C = var_r26;
    var_r31->unk_190 = HuMemDirectMallocNum(HEAP_HEAP, var_r26 * sizeof(s16), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < var_r26; var_r30++) {
        var_r31->unk_190[var_r30] = -1;
    }
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r28 * sizeof(M508ModelFunc), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_7A24;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_79BC, sp8, spC, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    if ((var_r25 + 0x10000) != -1) {
        var_r31->unk_184 = Hu3DModelCreateData(var_r25);
    }
    for (var_r30 = 0; var_r30 < var_r26; var_r30++) {
        if ((var_r27[var_r30] + 0x10000) != -1) {
            var_r31->unk_190[var_r30] = Hu3DJointMotionData(var_r31->unk_184, var_r27[var_r30]);
        }
    }
    if (var_r29 != NULL) {
        for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
            if (var_r29[var_r30] != NULL) {
                var_r31->unk_10[var_r30] = var_r29[var_r30];
            }
        }
    }
    return var_r31;
}

void fn_1_7CC0(M508ModelObj *arg0)
{
    s32 var_r30;

    for (var_r30 = 0; var_r30 < arg0->unk_18C; var_r30++) {
        if (arg0->unk_190[var_r30] != -1) {
            Hu3DMotionKill(arg0->unk_190[var_r30]);
        }
    }
    HuMemDirectFree(arg0->unk_190);
    if (arg0->unk_184 != -1) {
        Hu3DModelKill(arg0->unk_184);
    }
    HuMemDirectFree(arg0->unk_10);
    HuPrcKill(arg0->unk_0);
    HuMemDirectFree(arg0);
}

void fn_1_7D60(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    float sp10;
    float spC;
    float sp8;

    sp8 = farg0;
    spC = farg1;
    sp10 = farg2;
    arg0->unk_160 = sp8;
    arg0->unk_164 = spC;
    arg0->unk_168 = sp10;
    Hu3DModelPosSet(arg0->unk_184, sp8, spC, sp10);
}

void fn_1_7DB4(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
{
    if (arg1 != NULL) {
        *arg1 = arg0->unk_160;
    }
    if (arg2 != NULL) {
        *arg2 = arg0->unk_164;
    }
    if (arg3 != NULL) {
        *arg3 = arg0->unk_168;
    }
}

void fn_1_7DF4(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    float sp10;
    float spC;
    float sp8;

    sp8 = farg0;
    spC = farg1;
    sp10 = farg2;
    arg0->unk_16C = sp8;
    arg0->unk_170 = spC;
    arg0->unk_174 = sp10;
    Hu3DModelRotSet(arg0->unk_184, sp8, spC, sp10);
}

void fn_1_7E48(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
{
    if (arg1 != NULL) {
        *arg1 = arg0->unk_16C;
    }
    if (arg2 != NULL) {
        *arg2 = arg0->unk_170;
    }
    if (arg3 != NULL) {
        *arg3 = arg0->unk_174;
    }
}

void fn_1_7E88(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    float sp10;
    float spC;
    float sp8;

    sp8 = farg0;
    spC = farg1;
    sp10 = farg2;
    arg0->unk_178 = sp8;
    arg0->unk_17C = spC;
    arg0->unk_180 = sp10;
    Hu3DModelScaleSet(arg0->unk_184, sp8, spC, sp10);
}

void fn_1_7EDC(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
{
    if (arg1 != NULL) {
        *arg1 = arg0->unk_178;
    }
    if (arg2 != NULL) {
        *arg2 = arg0->unk_17C;
    }
    if (arg3 != NULL) {
        *arg3 = arg0->unk_180;
    }
}

void fn_1_7F1C(M508ModelObj *arg0, float farg0)
{
    arg0->unk_1B0 = farg0;
    Hu3DModelTPLvlSet(arg0->unk_184, farg0);
}

float fn_1_7F58(M508ModelObj *arg0)
{
    return arg0->unk_1B0;
}

void fn_1_7F60(M508ModelObj *arg0)
{
    arg0->unk_158 = 1;
    Hu3DModelDispOn(arg0->unk_184);
}

void fn_1_7F9C(M508ModelObj *arg0)
{
    arg0->unk_158 = 0;
    Hu3DModelDispOff(arg0->unk_184);
}

s32 fn_1_7FD8(M508ModelObj *arg0)
{
    return arg0->unk_158;
}

void fn_1_7FE0(M508ModelObj *arg0, s32 arg1)
{
    Hu3DMotionTimeSet(arg0->unk_184, arg1);
}

void fn_1_803C(M508ModelObj *arg0, s32 arg1)
{
    s16 var_r31;
    M508ModelObj *var_r30;

    var_r30 = arg0;
    var_r31 = var_r30->unk_184;
    Hu3DModelAttrReset(var_r31, HU3D_MOTATTR_PAUSE);
    if (arg1 != 0) {
        Hu3DModelAttrSet(var_r31, HU3D_MOTATTR_LOOP);
        return;
    }
    Hu3DModelAttrReset(var_r31, HU3D_MOTATTR_LOOP);
}

void fn_1_80B4(M508ModelObj *arg0)
{
    Hu3DModelAttrSet(arg0->unk_184, HU3D_MOTATTR_PAUSE);
}

s32 fn_1_80EC(M508ModelObj *arg0)
{
    s32 var_r31;

    if (Hu3DMotionEndCheck(arg0->unk_184) == 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

void fn_1_813C(M508ModelObj *arg0, s32 arg1, u32 arg2, float farg0, float farg1)
{
    arg0->unk_188 = arg1;
    if (arg1 == -1) {
        Hu3DMotionSet(arg0->unk_184, -1);
        return;
    }
    Hu3DMotionShiftSet(arg0->unk_184, arg0->unk_190[arg1], farg0, farg1, arg2);
}

s32 fn_1_81B8(M508ModelObj *arg0)
{
    return arg0->unk_188;
}

void fn_1_81C0(M508ModelObj *arg0, float farg0)
{
    arg0->unk_1B4 = farg0;
    Hu3DMotionSpeedSet(arg0->unk_184, farg0);
}

void fn_1_81FC(M508ModelObj *arg0)
{
    Hu3DModelShadowSet(arg0->unk_184);
}

void fn_1_822C(M508ModelObj *arg0)
{
    Hu3DModelShadowReset(arg0->unk_184);
}

void fn_1_825C(M508ModelObj *arg0)
{
    Hu3DModelShadowMapSet(arg0->unk_184);
}

void fn_1_828C(void)
{
}

void fn_1_8290(M508ModelObj *arg0, char *arg1, M508ModelObj *arg2)
{
    Hu3DModelHookSet(arg0->unk_184, arg1, arg2->unk_184);
}

void fn_1_82D8(M508ModelObj *arg0)
{
    Hu3DModelHookReset(arg0->unk_184);
}

M508ModelObj *fn_1_8308(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4,
                        s32 arg5, M508ModelFunc *arg6, s16 arg7)
{
    s16 sp10;
    u32 spC;
    s32 sp8;
    M508ModelObj *var_r31;
    s32 var_r30;
    s32 var_r29;
    M508ModelFunc *var_r28;
    s32 var_r27;
    s32 *var_r26;
    s32 var_r25;
    s32 var_r24;
    s32 var_r23;

    sp8 = arg0;
    spC = arg1;
    var_r29 = arg2;
    var_r25 = arg3;
    var_r26 = arg4;
    var_r27 = arg5;
    var_r28 = arg6;
    sp10 = arg7;
    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, sizeof(M508ModelObj), HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = var_r27;
    var_r31->unk_158 = 1;
    var_r31->unk_160 = 0.0f;
    var_r31->unk_164 = 0.0f;
    var_r31->unk_168 = 0.0f;
    var_r31->unk_16C = 0.0f;
    var_r31->unk_170 = 0.0f;
    var_r31->unk_174 = 0.0f;
    var_r31->unk_178 = 1.0f;
    var_r31->unk_17C = 1.0f;
    var_r31->unk_180 = 1.0f;
    var_r31->unk_184 = -1;
    if (GwPlayerConf[var_r29].type != 0) {
        var_r24 = 1;
    } else {
        var_r24 = 0;
    }
    var_r31->unk_1B8 = var_r24;
    var_r31->unk_1BC = GwPlayerConf[var_r29].charNo;
    var_r31->unk_1C0 = GwPlayerConf[var_r29].padNo;
    var_r31->unk_1C4 = GwPlayerConf[var_r29].dif;
    var_r31->unk_1C8 = var_r29;
    var_r31->unk_C = 0;
    var_r31->unk_18C = var_r25;
    var_r31->unk_190 = HuMemDirectMallocNum(HEAP_HEAP, var_r25 * sizeof(s16), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < var_r25; var_r30++) {
        var_r31->unk_190[var_r30] = -1;
    }
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r27 * sizeof(M508ModelFunc), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < var_r27; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_7A24;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_79BC, sp8, spC, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    var_r31->unk_184 = CharModelCreate(var_r31->unk_1BC, sp10);
    for (var_r30 = 0; var_r30 < var_r25; var_r30++) {
        var_r23 = var_r30 + (var_r31->unk_1BC * 0xD);
        if ((var_r26[var_r23] + 0x10000) != -1) {
            var_r31->unk_190[var_r30] = CharMotionCreate(var_r31->unk_1BC, var_r26[var_r30]);
        }
    }
    CharMotionDataClose(var_r31->unk_1BC);
    for (var_r30 = 0; var_r30 < var_r27; var_r30++) {
        if (var_r28[var_r30] != NULL) {
            var_r31->unk_10[var_r30] = var_r28[var_r30];
        }
    }
    return var_r31;
}

void fn_1_85F8(M508ModelObj *arg0)
{
    s32 var_r30;

    for (var_r30 = 0; var_r30 < arg0->unk_18C; var_r30++) {
        if (arg0->unk_190[var_r30] != -1) {
            Hu3DMotionKill(arg0->unk_190[var_r30]);
        }
    }
    HuMemDirectFree(arg0->unk_190);
    if (arg0->unk_184 != -1) {
        Hu3DModelKill(arg0->unk_184);
    }
    HuMemDirectFree(arg0->unk_10);
    HuPrcKill(arg0->unk_0);
    HuMemDirectFree(arg0);
}

void fn_1_8698(M508ModelObj *arg0, char *arg1)
{
    if ((arg0->unk_1BC = 0) != 0) {
        CharModelHookDustCreate(arg0->unk_1BC, arg1);
        return;
    }
    Hu3DModelHookReset(arg0->unk_184);
}

M508Camera *fn_1_86F0(s16 arg0)
{
    M508Camera *var_r31;
    M508CameraView *var_r30;
    s32 var_r29;

    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, sizeof(M508Camera), HU_MEMNUM_OVL);
    var_r31->unk_8 = arg0;
    for (var_r29 = 0; var_r29 < 3; var_r29++) {
        var_r30 = &var_r31->unk_10 + var_r29;
        var_r30->unk_18 = 0.0f;
        var_r30->unk_1C = 0.0f;
        var_r30->unk_20 = 0.0f;
        var_r30->unk_24 = 0.0f;
        var_r30->unk_28 = 0.0f;
        var_r30->unk_2C = 0.0f;
        var_r30->unk_30 = 0.0f;
    }
    var_r31->unk_C = HuPrcChildCreate(fn_1_8918, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_C->property = var_r31;
    var_r31->unk_AC = 0;
    Hu3DCameraCreate(arg0);
    fn_1_95D8(var_r31, 30.0f, 10.0f, 8000.0f, 1.2f);
    fn_1_9578(var_r31, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    fn_1_9628(var_r31, 0.0f, 0.0f, 640.0f, 480.0f);
    var_r31->unk_0 = 2;
    return var_r31;
}

void fn_1_88E0(M508Camera *arg0)
{
    HuPrcKill(arg0->unk_C);
    HuMemDirectFree(arg0);
}

void fn_1_8918(void)
{
    M508Camera *var_r31;

    var_r31 = HuPrcCurrentGet()->property;
    while (var_r31->unk_0 != 3) {
        lbl_1_data_0[var_r31->unk_0](var_r31, &lbl_1_data_0[var_r31->unk_0],
            var_r31->unk_0 * sizeof(M508CameraFunc));
    }
    HuPrcEnd();
}

void fn_1_897C(M508Camera *arg0)
{
    M508CameraView *var_r31;
    s32 var_r30;
    double var_f31;

    for (var_r30 = 0; var_r30 < 3; var_r30++) {
        var_r31 = &arg0->unk_10 + var_r30;
        var_f31 = HuCos(var_r31->unk_24);
        var_r31->unk_0 = var_r31->unk_18 + (var_r31->unk_30 * (HuSin(var_r31->unk_28) * var_f31));
        var_r31->unk_4 = var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
        var_f31 = HuCos(var_r31->unk_24);
        var_r31->unk_8 = var_r31->unk_20 + (var_r31->unk_30 * (HuCos(var_r31->unk_28) * var_f31));
        var_f31 = HuSin(var_r31->unk_24);
        var_r31->unk_C = HuSin(var_r31->unk_28) * var_f31;
        var_r31->unk_10 = HuCos(var_r31->unk_24);
        var_f31 = HuSin(var_r31->unk_24);
        var_r31->unk_14 = HuCos(var_r31->unk_28) * var_f31;
    }
}

void fn_1_8BF4(M508Camera *arg0, float farg8)
{
    M508CameraView *var_r31;

    if (arg0->unk_0 != 2) {
        var_r31 = &arg0->unk_10;
        Hu3DCameraPosSet(arg0->unk_8, var_r31->unk_0, var_r31->unk_4, var_r31->unk_8,
            var_r31->unk_C, var_r31->unk_10, var_r31->unk_14, var_r31->unk_18,
            var_r31->unk_1C, farg8);
    }
}

void fn_1_8C64(s32 *arg0)
{
    *arg0 = 2;
}

void fn_1_8C70(M508Camera *arg0, void *arg1, s32 arg2)
{
    float sp8;
    M508CameraView *var_r31;
    M508Camera *var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;

    while (1) {
        var_r27 = 1;
        for (var_r29 = 0; var_r29 < var_r27; var_r29++) {
            var_r28 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
            var_r30 = HuPrcCurrentGet()->property;
            if (var_r30->unk_0 != 2) {
                var_r31 = &var_r30->unk_10;
                sp8 = var_r31->unk_20;
                Hu3DCameraPosSet(var_r30->unk_8, var_r31->unk_0, var_r31->unk_4,
                    var_r31->unk_8, var_r31->unk_C, var_r31->unk_10, var_r31->unk_14,
                    var_r31->unk_18, var_r31->unk_1C, sp8);
            }
            HuPrcVSleep();
            if (var_r28 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                return;
            }
        }
    }
}

void fn_1_8D24(s32 *arg0)
{
    *arg0 = 0;
}

void fn_1_8D30(M508Camera *arg0, void *arg1, s32 arg2)
{
    float sp8;
    M508CameraView *var_r31;
    M508Camera *var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    M508Camera *var_r26;

    var_r26 = arg0;
    while (1) {
        fn_1_96BC(var_r26);
        fn_1_9B38(var_r26);
        var_r27 = 1;
        for (var_r29 = 0; var_r29 < var_r27; var_r29++) {
            var_r28 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
            var_r30 = HuPrcCurrentGet()->property;
            if (var_r30->unk_0 != 2) {
                var_r31 = &var_r30->unk_10;
                sp8 = var_r31->unk_20;
                Hu3DCameraPosSet(var_r30->unk_8, var_r31->unk_0, var_r31->unk_4,
                    var_r31->unk_8, var_r31->unk_C, var_r31->unk_10, var_r31->unk_14,
                    var_r31->unk_18, var_r31->unk_1C, sp8);
            }
            HuPrcVSleep();
            if (var_r28 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                return;
            }
        }
    }
}

s32 fn_1_8DF8(s32 *arg0)
{
    s32 var_r31;

    if (*arg0 != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

void fn_1_8E28(M508Camera *arg0, M508VecWords *arg1, M508VecWords *arg2, float *arg3, s32 arg4)
{
    M508CameraView *var_r31;
    M508CameraView *var_r30;
    M508Camera *var_r29;
    M508CameraView *var_r28;
    s32 var_r27;
    M508CameraView *var_r26;

    var_r29 = arg0;
    var_r28 = &var_r29->unk_10;
    var_r26 = &var_r29->unk_44;
    var_r30 = &var_r29->unk_78;
    *var_r26 = *var_r28;
    *var_r30 = *var_r28;
    if (arg1) {
        *(u32 *)&var_r30->unk_18 = arg1->unk_0;
        *(u32 *)&var_r30->unk_1C = arg1->unk_4;
        *(u32 *)&var_r30->unk_20 = arg1->unk_8;
    }
    if (arg2) {
        *(u32 *)&var_r30->unk_24 = arg2->unk_0;
        *(u32 *)&var_r30->unk_28 = arg2->unk_4;
        *(u32 *)&var_r30->unk_2C = arg2->unk_8;
    }
    if (arg3) {
        var_r30->unk_30 = *arg3;
    }
    for (var_r27 = 0; var_r27 < 3; var_r27++) {
        var_r31 = &var_r29->unk_10 + var_r27;
        var_r31->unk_0 = var_r31->unk_18 +
            (var_r31->unk_30 * (HuSin(var_r31->unk_28) * HuCos(var_r31->unk_24)));
        var_r31->unk_4 = var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
        var_r31->unk_8 = var_r31->unk_20 +
            (var_r31->unk_30 * (HuCos(var_r31->unk_28) * HuCos(var_r31->unk_24)));
        var_r31->unk_C = HuSin(var_r31->unk_28) * HuSin(var_r31->unk_24);
        var_r31->unk_10 = HuCos(var_r31->unk_24);
        var_r31->unk_14 = HuCos(var_r31->unk_28) * HuSin(var_r31->unk_24);
    }
    var_r29->unk_4 = arg4;
    if (arg4 > 0) {
        var_r29->unk_0 = 1;
        return;
    }
    *var_r28 = *var_r30;
    var_r29->unk_0 = 0;
}

void fn_1_926C(M508Camera *var_r27, void *arg1, s32 arg2)
{
    M508CameraView *var_r31;
    M508CameraView *var_r30;
    M508CameraView *var_r29;
    M508CameraView *var_r28;
    M508Camera *var_r26;
    s32 var_r25;
    s32 var_r24;
    s32 var_r23;
    float var_f31;
    float var_f30;
    float var_f29;

    var_r30 = &var_r27->unk_10;
    var_r31 = &var_r27->unk_44;
    var_r29 = &var_r27->unk_78;
    var_f29 = 1.0f / var_r27->unk_4;
    var_f30 = 0.0f;
    while (1) {
        var_f31 = HuSin(90.0f * var_f30);
        var_f31 *= var_f31;
        var_r30->unk_18 = var_r31->unk_18 + (var_f31 * (var_r29->unk_18 - var_r31->unk_18));
        var_r30->unk_1C = var_r31->unk_1C + (var_f31 * (var_r29->unk_1C - var_r31->unk_1C));
        var_r30->unk_20 = var_r31->unk_20 + (var_f31 * (var_r29->unk_20 - var_r31->unk_20));
        var_r30->unk_0 = var_r31->unk_0 + (var_f31 * (var_r29->unk_0 - var_r31->unk_0));
        var_r30->unk_4 = var_r31->unk_4 + (var_f31 * (var_r29->unk_4 - var_r31->unk_4));
        var_r30->unk_8 = var_r31->unk_8 + (var_f31 * (var_r29->unk_8 - var_r31->unk_8));
        var_r30->unk_C = var_r31->unk_C + (var_f31 * (var_r29->unk_C - var_r31->unk_C));
        var_r30->unk_10 = var_r31->unk_10 + (var_f31 * (var_r29->unk_10 - var_r31->unk_10));
        var_r30->unk_14 = var_r31->unk_14 + (var_f31 * (var_r29->unk_14 - var_r31->unk_14));
        fn_1_96BC(var_r27, var_r29->unk_14, var_r31->unk_14);
        fn_1_9B38(var_r27);
        var_f30 += var_f29;
        if (!(var_f30 >= 1.0f)) {
            var_r23 = 1;
            for (var_r25 = 0; var_r25 < var_r23; var_r25++) {
                var_r24 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
                var_r26 = HuPrcCurrentGet()->property;
                if (var_r26->unk_0 != 2) {
                    var_r28 = &var_r26->unk_10;
                    Hu3DCameraPosSet(var_r26->unk_8, var_r28->unk_0, var_r28->unk_4,
                        var_r28->unk_8, var_r28->unk_C, var_r28->unk_10,
                        var_r28->unk_14, var_r28->unk_18, var_r28->unk_1C, var_r28->unk_20);
                }
                HuPrcVSleep();
                if (var_r24 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                    return;
                }
            }
        } else {
            *var_r30 = *var_r29;
            var_r27->unk_0 = 0;
            return;
        }
    }
}

void fn_1_9578(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3,
               float farg4, float farg5)
{
    Hu3DCameraViewportSet(arg0->unk_8, farg0, farg1, farg2, farg3, farg4, farg5);
}

void fn_1_95D8(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3)
{
    Hu3DCameraPerspectiveSet(arg0->unk_8, farg0, farg1, farg2, farg3);
}

void fn_1_9628(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3)
{
    Hu3DCameraScissorSet(arg0->unk_8, farg0, farg1, farg2, farg3);
}

void fn_1_96BC(M508Camera *arg0)
{
    M508CameraView *var_r30;

    if ((arg0->unk_AC != 0) && ((HuPadBtn[0] & PAD_BUTTON_Y) != 0)) {
        var_r30 = &arg0->unk_10;
        var_r30->unk_18 += 0.1f * HuPadSubStkX[0];
        var_r30->unk_20 -= 0.02f * HuPadSubStkY[0];
        var_r30->unk_28 -= 0.1f * HuPadStkX[0];
        var_r30->unk_24 += 0.1f * HuPadStkY[0];
        var_r30->unk_30 += 0.1f * HuPadTrigL[0];
        var_r30->unk_30 -= 0.1f * HuPadTrigR[0];
        fn_1_897C(arg0);
    }
}

void fn_1_9B38(M508Camera *arg0)
{
}

void fn_1_9B3C(s32 arg0, s32 arg1)
{
    WipeCreate(WIPE_MODE_IN, WIPE_TYPE_PREVTYPE, arg0);
    while (arg1 != 0 && WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
}

void fn_1_9B98(s32 arg0, s32 arg1)
{
    WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_WHITEFADE, arg0);
    while (arg1 != 0 && WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
}

void fn_1_9BF4(s32 arg0)
{
    s32 var_r31;
    s16 var_r30;
    s32 var_r29;

    var_r29 = arg0;
    var_r30 = GameMesCreate(2, 0);
    if (var_r29 == -1) {
        while (GameMesStatGet(var_r30) != 0) {
            HuPrcVSleep();
        }
        return;
    }
    for (var_r31 = 0; var_r31 < var_r29; var_r31++) {
        HuPrcVSleep();
    }
}

void fn_1_9C80(s32 arg0)
{
    s32 var_r31;
    s16 var_r30;
    s32 var_r29;

    var_r29 = arg0;
    var_r30 = GameMesCreate(2, 1);
    if (var_r29 == -1) {
        while (GameMesStatGet(var_r30) != 0) {
            HuPrcVSleep();
        }
        return;
    }
    for (var_r31 = 0; var_r31 < var_r29; var_r31++) {
        HuPrcVSleep();
    }
}

float fn_1_9D0C(float farg0, float farg1, float farg2)
{
    float var_f31;
    float var_f30;
    float var_f29;

    var_f29 = farg0;
    var_f31 = fmod(farg1 - var_f29, 360.0);
    if (var_f31 < 0.0f) {
        var_f31 += 360.0f;
    }
    if (var_f31 > 180.0f) {
        var_f31 -= 360.0f;
    }
    var_f30 = fmod(var_f29 + (var_f31 * farg2), 360.0);
    if (var_f30 < 0.0f) {
        var_f30 += 360.0f;
    }
    return var_f30;
}

M508Window *fn_1_9E10(s32 arg0, s32 arg1)
{
    M508Window *var_r31;

    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, sizeof(M508Window), HU_MEMNUM_OVL);
    var_r31->unk_10 = HuPrcChildCreate(fn_1_9EF8, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_10->property = var_r31;
    var_r31->unk_0 = HuWinExCreateFrame(0.0f, 0.0f, arg0, arg1, -1, 1);
    return var_r31;
}

void fn_1_9EB8(M508Window *arg0)
{
    HuWinKill(arg0->unk_0);
    HuPrcKill(arg0->unk_10);
    HuMemDirectFree(arg0);
}

void fn_1_9EF8(void)
{
    while (1) {
        HuPrcVSleep();
    }
}

void fn_1_9F0C(M508Window *arg0, float farg0, float farg1)
{
    arg0->unk_4 = farg0;
    arg0->unk_8 = farg1;
    HuWinPosSet(arg0->unk_0, farg0, farg1);
}

void fn_1_9F54(M508Window *arg0, float *arg1, float *arg2)
{
    *arg1 = arg0->unk_4;
    *arg2 = arg0->unk_8;
}

void fn_1_9F68(s16 *arg0, u32 arg1)
{
    HuWinMesSet(*arg0, arg1);
}

void fn_1_9FA0(M508Window *arg0)
{
    HuWinDispOn(arg0->unk_0);
    arg0->unk_C = 1;
}

void fn_1_9FD8(M508Window *arg0)
{
    HuWinDispOff(arg0->unk_0);
    arg0->unk_C = 0;
}

void fn_1_A010(s16 *arg0, s32 arg1)
{
    HuWinMesColSet(*arg0, arg1);
}

void fn_1_A04C(s16 *arg0, s16 arg1)
{
    HuWinMesSpeedSet(*arg0, arg1);
}

void fn_1_A084(s16 *arg0)
{
    HuWinMesWait(*arg0);
}

void fn_1_A0B4(s16 *arg0)
{
    HuWinExOpen(*arg0);
}

void fn_1_A0E4(s16 *arg0)
{
    HuWinExClose(*arg0);
}

void fn_1_A114(s16 *arg0, float farg0, float farg1)
{
    HuWinScaleSet(*arg0, farg0, farg1);
}

float fn_1_A154(M508Vec2 *arg0, M508Vec2 *arg1)
{
    return (arg0->unk_0 * arg1->unk_0) + (arg0->unk_4 * arg1->unk_4);
}

float fn_1_A174(M508Vec2 *arg0, M508Vec2 *arg1)
{
    return (arg0->unk_0 * arg1->unk_4) - (arg0->unk_4 * arg1->unk_0);
}
