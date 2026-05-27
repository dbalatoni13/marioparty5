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

typedef void (*M508ModelFunc)();

typedef struct M508ModelObj_s {
    HUPROCESS *unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    M508ModelFunc *unk_10;
    s32 unk_14;
    u8 pad18[0x140];
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

typedef struct M508VecWords_s {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} M508VecWords;

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

typedef void (*M508CameraFunc)(M508Camera *, void *, s32);

void fn_1_BDF0(void);
void fn_1_BE58(void);
void fn_1_CD4C(void);
void fn_1_D0A4(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_D164(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_D6A0(M508Camera *arg0, void *arg1, s32 arg2);
void fn_1_D9AC(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3,
               float farg4, float farg5);
void fn_1_DA0C(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3);
void fn_1_DA5C(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3);
void fn_1_DAF0(M508Camera *arg0);
void fn_1_DF6C(M508Camera *arg0);
void fn_1_E32C(void);

M508CameraFunc lbl_1_data_B0[3] = { fn_1_D164, fn_1_D6A0, fn_1_D0A4 };

M508Circle lbl_1_bss_220;
float lbl_1_bss_22C;
float lbl_1_bss_230;
M508Vec2 lbl_1_bss_234;
M508Vec2 lbl_1_bss_23C;
M508Vec2 lbl_1_bss_244;
M508Vec2 lbl_1_bss_24C;
M508Vec2 lbl_1_bss_254;
M508Vec2 lbl_1_bss_25C;
float lbl_1_bss_264;
float lbl_1_bss_268;
float lbl_1_bss_26C;
float lbl_1_bss_270;
M508Polygon lbl_1_bss_274;
M508Vec2 lbl_1_bss_27C[5];
float lbl_1_bss_2A4;
float lbl_1_bss_2A8;
M508Vec2 lbl_1_bss_2AC;
M508Vec2 lbl_1_bss_2B4;
M508Vec2 lbl_1_bss_2BC;
M508Vec2 lbl_1_bss_2C4;
M508Vec2 lbl_1_bss_2CC;
M508Vec2 lbl_1_bss_2D4;

float fn_1_A194(M508Vec2 *arg0)
{
    float var_f30;

    var_f30 = (arg0->unk_0 * arg0->unk_0) + (arg0->unk_4 * arg0->unk_4);
    return sqrt(var_f30);
}

void fn_1_A314(M508Vec2 *arg0, M508Vec2 *arg1)
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

s32 fn_1_A4DC(M508Vec2 *arg0, M508Circle *arg1)
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
    }
    else {
        var_r31 = 1;
    }
    return var_r31;
}

s32 fn_1_A564(M508Circle *arg0, M508Circle *arg1)
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
    }
    else {
        var_r31 = 0;
    }
    return var_r31;
}

s32 fn_1_A5F4(M508Rect *arg0, M508Rect *arg1)
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

s32 fn_1_A65C(M508Vec2 *arg0, M508Polygon *arg1, s32 arg2)
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
    }
    else {
        var_r24 = 0;
    }
    return var_r24;
}

s32 fn_1_A74C(M508Circle *arg0, M508Rect *arg1)
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
    lbl_1_bss_2D4.unk_0 = arg1->unk_8 - arg1->unk_0;
    lbl_1_bss_2D4.unk_4 = arg1->unk_C - arg1->unk_4;
    lbl_1_bss_2CC.unk_0 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_2CC.unk_4 = arg0->unk_4 - arg1->unk_4;
    var_f20 = (lbl_1_bss_2D4.unk_0 * lbl_1_bss_2CC.unk_4) -
        (lbl_1_bss_2D4.unk_4 * lbl_1_bss_2CC.unk_0);
    lbl_1_bss_2A8 = var_f20;
    if (lbl_1_bss_2A8 == 0.0f) {
        lbl_1_bss_2AC = *(M508Vec2 *)arg0;
        goto block_22;
    }
    lbl_1_bss_2C4.unk_0 = lbl_1_bss_2D4.unk_4 * lbl_1_bss_2A8;
    lbl_1_bss_2C4.unk_4 = -(lbl_1_bss_2D4.unk_0 * lbl_1_bss_2A8);
    var_f30 = (lbl_1_bss_2C4.unk_0 * lbl_1_bss_2C4.unk_0) +
        (lbl_1_bss_2C4.unk_4 * lbl_1_bss_2C4.unk_4);
    var_f21 = sqrt(var_f30);
    var_f22 = 1.0f / var_f21;
    lbl_1_bss_2BC.unk_0 = lbl_1_bss_2C4.unk_0 * var_f22;
    lbl_1_bss_2BC.unk_4 = lbl_1_bss_2C4.unk_4 * var_f22;
    lbl_1_bss_2B4.unk_0 = arg1->unk_0 - arg0->unk_0;
    lbl_1_bss_2B4.unk_4 = arg1->unk_4 - arg0->unk_4;
    var_f19 = (lbl_1_bss_2BC.unk_0 * lbl_1_bss_2B4.unk_0) +
        (lbl_1_bss_2BC.unk_4 * lbl_1_bss_2B4.unk_4);
    lbl_1_bss_2A4 = var_f19;
    if (lbl_1_bss_2A4 > arg0->unk_8) {
        return 0;
    }
    lbl_1_bss_2AC.unk_0 = arg0->unk_0 + (lbl_1_bss_2BC.unk_0 * lbl_1_bss_2A4);
    lbl_1_bss_2AC.unk_4 = arg0->unk_4 + (lbl_1_bss_2BC.unk_4 * lbl_1_bss_2A4);

block_22:
    if ((arg1->unk_0 < lbl_1_bss_2AC.unk_0) && (lbl_1_bss_2AC.unk_0 < arg1->unk_8)) {
        return 1;
    }
    if ((arg1->unk_8 < lbl_1_bss_2AC.unk_0) && (lbl_1_bss_2AC.unk_0 < arg1->unk_0)) {
        return 1;
    }
    if ((arg1->unk_4 < lbl_1_bss_2AC.unk_4) && (lbl_1_bss_2AC.unk_4 < arg1->unk_C)) {
        return 1;
    }
    if ((arg1->unk_C < lbl_1_bss_2AC.unk_4) && (lbl_1_bss_2AC.unk_4 < arg1->unk_4)) {
        return 1;
    }
    return 0;
}

s32 fn_1_AD98(M508Circle *arg0, M508Polygon *arg1, s32 arg2)
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
        if (fn_1_A74C(arg0, (M508Rect *)sp8) != 0) {
            return 1;
        }
        var_r29++;
    }
    return 0;
}

s32 fn_1_AF28(M508Rect *arg0, M508Circle *arg1, s32 arg2)
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

    lbl_1_bss_27C[0].unk_0 = arg0->unk_0;
    lbl_1_bss_27C[0].unk_4 = arg0->unk_4;
    lbl_1_bss_27C[1].unk_0 = arg0->unk_8;
    lbl_1_bss_27C[1].unk_4 = arg0->unk_4;
    lbl_1_bss_27C[2].unk_0 = arg0->unk_8;
    lbl_1_bss_27C[2].unk_4 = arg0->unk_C;
    lbl_1_bss_27C[3].unk_0 = arg0->unk_0;
    lbl_1_bss_27C[3].unk_4 = arg0->unk_C;
    lbl_1_bss_27C[4].unk_0 = arg0->unk_0;
    lbl_1_bss_27C[4].unk_4 = arg0->unk_4;
    lbl_1_bss_274.unk_0 = 5;
    lbl_1_bss_274.unk_4 = lbl_1_bss_27C;
    var_r25 = 0;
    var_r23 = 0;
    var_r22 = lbl_1_bss_274.unk_0 - 1;
    for (var_r28 = 0; var_r28 < var_r22; var_r28++) {
        var_r26 = &lbl_1_bss_274.unk_4[var_r28];
        var_r27 = &lbl_1_bss_274.unk_4[var_r28 + 1];
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
        var_r19 = lbl_1_bss_274.unk_0 - 1;
        var_r29 = 0;
        goto loop_17_check;
    loop_17:
        sp8[0] = lbl_1_bss_274.unk_4[var_r29].unk_0;
        sp8[1] = lbl_1_bss_274.unk_4[var_r29].unk_4;
        sp8[2] = lbl_1_bss_274.unk_4[var_r29 + 1].unk_0;
        sp8[2] = lbl_1_bss_274.unk_4[var_r29 + 1].unk_4;
        if (fn_1_A74C(arg1, (M508Rect *)sp8) != 0) {
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

s32 fn_1_B1C0(M508Sphere *arg0, M508Sphere *arg1)
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
    }
    else {
        var_r31 = 0;
    }
    return var_r31;
}

s32 fn_1_B274(M508Circle *arg0, M508Circle *arg1)
{
    float var_f30;

    lbl_1_bss_270 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_26C = arg0->unk_4 - arg1->unk_4;
    lbl_1_bss_268 = arg0->unk_8 + arg1->unk_8;
    var_f30 = (lbl_1_bss_270 * lbl_1_bss_270) + (lbl_1_bss_26C * lbl_1_bss_26C);
    lbl_1_bss_264 = sqrtf(var_f30);
    if (lbl_1_bss_264 < lbl_1_bss_268) {
        if (lbl_1_bss_264 == 0.0f) {
            lbl_1_bss_270 = 0.0f;
            lbl_1_bss_26C = -1.0f;
        } else {
            lbl_1_bss_270 /= lbl_1_bss_264;
            lbl_1_bss_26C /= lbl_1_bss_264;
        }
        arg0->unk_0 = arg1->unk_0 + (lbl_1_bss_270 * lbl_1_bss_268);
        arg0->unk_4 = arg1->unk_4 + (lbl_1_bss_26C * lbl_1_bss_268);
        return 1;
    }
    return 0;
}

s32 fn_1_B514(M508Circle *arg0, M508Rect *arg1)
{
    s32 var_r31;
    float var_f29;
    float var_f28;
    float var_f26;
    float var_f24;
    float var_f23;
    float var_f22;

    lbl_1_bss_25C.unk_0 = arg1->unk_8 - arg1->unk_0;
    lbl_1_bss_25C.unk_4 = arg1->unk_C - arg1->unk_4;
    lbl_1_bss_254.unk_0 = arg0->unk_0 - arg1->unk_0;
    lbl_1_bss_254.unk_4 = arg0->unk_4 - arg1->unk_4;
    var_f23 = (lbl_1_bss_25C.unk_0 * lbl_1_bss_254.unk_4) -
        (lbl_1_bss_25C.unk_4 * lbl_1_bss_254.unk_0);
    lbl_1_bss_230 = var_f23;
    if (lbl_1_bss_230 == 0.0f) {
        lbl_1_bss_234 = *(M508Vec2 *)arg0;
        goto block_12;
    }
    lbl_1_bss_24C.unk_0 = lbl_1_bss_25C.unk_4 * lbl_1_bss_230;
    lbl_1_bss_24C.unk_4 = -(lbl_1_bss_25C.unk_0 * lbl_1_bss_230);
    var_f29 = (lbl_1_bss_24C.unk_0 * lbl_1_bss_24C.unk_0) +
        (lbl_1_bss_24C.unk_4 * lbl_1_bss_24C.unk_4);
    var_f24 = sqrt(var_f29);
    var_f26 = 1.0f / var_f24;
    lbl_1_bss_244.unk_0 = lbl_1_bss_24C.unk_0 * var_f26;
    lbl_1_bss_244.unk_4 = lbl_1_bss_24C.unk_4 * var_f26;
    lbl_1_bss_23C.unk_0 = arg1->unk_0 - arg0->unk_0;
    lbl_1_bss_23C.unk_4 = arg1->unk_4 - arg0->unk_4;
    var_f22 = (lbl_1_bss_244.unk_0 * lbl_1_bss_23C.unk_0) +
        (lbl_1_bss_244.unk_4 * lbl_1_bss_23C.unk_4);
    lbl_1_bss_22C = var_f22;
    if (lbl_1_bss_22C > arg0->unk_8) {
        return 0;
    }
    lbl_1_bss_234.unk_0 = arg0->unk_0 + (lbl_1_bss_244.unk_0 * lbl_1_bss_22C);
    lbl_1_bss_234.unk_4 = arg0->unk_4 + (lbl_1_bss_244.unk_4 * lbl_1_bss_22C);

block_12:
    lbl_1_bss_220.unk_0 = lbl_1_bss_234.unk_0;
    lbl_1_bss_220.unk_4 = lbl_1_bss_234.unk_4;
    lbl_1_bss_220.unk_8 = 1.0f;
    lbl_1_bss_270 = arg0->unk_0 - lbl_1_bss_220.unk_0;
    lbl_1_bss_26C = arg0->unk_4 - lbl_1_bss_220.unk_4;
    lbl_1_bss_268 = arg0->unk_8 + lbl_1_bss_220.unk_8;
    var_f28 = (lbl_1_bss_270 * lbl_1_bss_270) + (lbl_1_bss_26C * lbl_1_bss_26C);
    lbl_1_bss_264 = sqrtf(var_f28);
    if (lbl_1_bss_264 < lbl_1_bss_268) {
        if (lbl_1_bss_264 == 0.0f) {
            lbl_1_bss_270 = 0.0f;
            lbl_1_bss_26C = -1.0f;
        } else {
            lbl_1_bss_270 /= lbl_1_bss_264;
            lbl_1_bss_26C /= lbl_1_bss_264;
        }
        arg0->unk_0 = lbl_1_bss_220.unk_0 + (lbl_1_bss_270 * lbl_1_bss_268);
        arg0->unk_4 = lbl_1_bss_220.unk_4 + (lbl_1_bss_26C * lbl_1_bss_268);
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    return var_r31;
}

M508ModelObj *fn_1_BC7C(s32 arg0, u32 arg1, s32 arg2, M508ModelFunc *arg3)
{
    M508ModelObj *var_r31;
    s32 var_r30;
    M508ModelFunc *var_r29;
    s32 var_r28;
    u32 spC;
    s32 sp8;

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
        var_r31->unk_10[var_r30] = fn_1_BE58;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
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

void fn_1_BDB0(M508ModelObj *arg0)
{
    HuMemDirectFree(arg0->unk_10);
    HuPrcKill(arg0->unk_0);
    HuMemDirectFree(arg0);
}

void fn_1_BDF0(void)
{
    M508ModelObj *var_r31;

    var_r31 = HuPrcCurrentGet()->property;
    while (var_r31->unk_4 < var_r31->unk_14) {
        var_r31->unk_10[var_r31->unk_4](var_r31, var_r31->unk_10);
        var_r31->unk_8 = var_r31->unk_4;
    }
    HuPrcEnd();
}

void fn_1_BE58(void)
{
    while (1) {
        HuPrcSleep(0);
    }
}

M508ModelObj *fn_1_BE70(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5,
                        M508ModelFunc *arg6)
{
    u32 spC;
    s32 sp8;
    M508ModelObj *var_r31;
    s32 var_r30;

    sp8 = arg0;
    spC = arg1;
    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x1B8, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = arg5;
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
    var_r31->unk_18C = arg3;
    var_r31->unk_190 = HuMemDirectMallocNum(HEAP_HEAP, arg3 * sizeof(s16), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < arg3; var_r30++) {
        var_r31->unk_190[var_r30] = -1;
    }
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, arg5 * sizeof(M508ModelFunc), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < arg5; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_BE58;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    if ((arg2 + 0x10000) != -1) {
        var_r31->unk_184 = Hu3DModelCreateData(arg2);
    }
    for (var_r30 = 0; var_r30 < arg3; var_r30++) {
        if ((arg4[var_r30] + 0x10000) != -1) {
            var_r31->unk_190[var_r30] = Hu3DJointMotionData(var_r31->unk_184, arg4[var_r30]);
        }
    }
    if (arg6 != NULL) {
        for (var_r30 = 0; var_r30 < arg5; var_r30++) {
            if (arg6[var_r30] != NULL) {
                var_r31->unk_10[var_r30] = arg6[var_r30];
            }
        }
    }
    return var_r31;
}

void fn_1_C0F4(M508ModelObj *arg0)
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

void fn_1_C194(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    arg0->unk_160 = farg0;
    arg0->unk_164 = farg1;
    arg0->unk_168 = farg2;
    Hu3DModelPosSet(arg0->unk_184, farg0, farg1, farg2);
}

void fn_1_C1E8(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
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

void fn_1_C228(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    arg0->unk_16C = farg0;
    arg0->unk_170 = farg1;
    arg0->unk_174 = farg2;
    Hu3DModelRotSet(arg0->unk_184, farg0, farg1, farg2);
}

void fn_1_C27C(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
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

void fn_1_C2BC(M508ModelObj *arg0, float farg0, float farg1, float farg2)
{
    arg0->unk_178 = farg0;
    arg0->unk_17C = farg1;
    arg0->unk_180 = farg2;
    Hu3DModelScaleSet(arg0->unk_184, farg0, farg1, farg2);
}

void fn_1_C310(M508ModelObj *arg0, float *arg1, float *arg2, float *arg3)
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

void fn_1_C350(M508ModelObj *arg0, float farg0)
{
    arg0->unk_1B0 = farg0;
    Hu3DModelTPLvlSet(arg0->unk_184, farg0);
}

float fn_1_C38C(M508ModelObj *arg0)
{
    return arg0->unk_1B0;
}

void fn_1_C394(M508ModelObj *arg0)
{
    arg0->unk_158 = 1;
    Hu3DModelDispOn(arg0->unk_184);
}

void fn_1_C3D0(M508ModelObj *arg0)
{
    arg0->unk_158 = 0;
    Hu3DModelDispOff(arg0->unk_184);
}

s32 fn_1_C40C(M508ModelObj *arg0)
{
    return arg0->unk_158;
}

void fn_1_C414(M508ModelObj *arg0, s32 arg1)
{
    Hu3DMotionTimeSet(arg0->unk_184, arg1);
}

void fn_1_C470(M508ModelObj *arg0, s32 arg1)
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

void fn_1_C4E8(M508ModelObj *arg0)
{
    Hu3DModelAttrSet(arg0->unk_184, HU3D_MOTATTR_PAUSE);
}

s32 fn_1_C520(M508ModelObj *arg0)
{
    s32 var_r31;

    if (Hu3DMotionEndCheck(arg0->unk_184) == 0) {
        var_r31 = 1;
    }
    else {
        var_r31 = 0;
    }
    return var_r31;
}

void fn_1_C570(M508ModelObj *arg0, s32 arg1, float farg0, float farg1, u32 arg2)
{
    arg0->unk_188 = arg1;
    if (arg1 == -1) {
        Hu3DMotionSet(arg0->unk_184, -1);
        return;
    }
    Hu3DMotionShiftSet(arg0->unk_184, arg0->unk_190[arg1], farg0, farg1, arg2);
}

s32 fn_1_C5EC(M508ModelObj *arg0)
{
    return arg0->unk_188;
}

void fn_1_C5F4(M508ModelObj *arg0, float farg0)
{
    arg0->unk_1B4 = farg0;
    Hu3DMotionSpeedSet(arg0->unk_184, farg0);
}

void fn_1_C630(M508ModelObj *arg0)
{
    Hu3DModelShadowSet(arg0->unk_184);
}

void fn_1_C660(M508ModelObj *arg0)
{
    Hu3DModelShadowReset(arg0->unk_184);
}

void fn_1_C690(M508ModelObj *arg0)
{
    Hu3DModelShadowMapSet(arg0->unk_184);
}

void fn_1_C6C0(void)
{
}

void fn_1_C6C4(M508ModelObj *arg0, char *arg1, M508ModelObj *arg2)
{
    Hu3DModelHookSet(arg0->unk_184, arg1, arg2->unk_184);
}

void fn_1_C70C(M508ModelObj *arg0)
{
    Hu3DModelHookReset(arg0->unk_184);
}

M508ModelObj *fn_1_C73C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5,
                        M508ModelFunc *arg6, s16 arg7)
{
    s16 sp10;
    u32 spC;
    s32 sp8;
    M508ModelObj *var_r31;
    s32 var_r30;
    s32 var_r24;
    s32 var_r23;

    sp8 = arg0;
    spC = arg1;
    sp10 = arg7;
    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x1CC, HU_MEMNUM_OVL);
    var_r31->unk_4 = 0;
    var_r31->unk_8 = 0;
    var_r31->unk_14 = arg5;
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
    if (GwPlayerConf[arg2].type != 0) {
        var_r24 = 1;
    }
    else {
        var_r24 = 0;
    }
    var_r31->unk_1B8 = var_r24;
    var_r31->unk_1BC = GwPlayerConf[arg2].charNo;
    var_r31->unk_1C0 = GwPlayerConf[arg2].padNo;
    var_r31->unk_1C4 = GwPlayerConf[arg2].dif;
    var_r31->unk_1C8 = arg2;
    var_r31->unk_C = 0;
    var_r31->unk_18C = arg3;
    var_r31->unk_190 = HuMemDirectMallocNum(HEAP_HEAP, arg3 * sizeof(s16), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < arg3; var_r30++) {
        var_r31->unk_190[var_r30] = -1;
    }
    var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, arg5 * sizeof(M508ModelFunc), HU_MEMNUM_OVL);
    for (var_r30 = 0; var_r30 < arg5; var_r30++) {
        var_r31->unk_10[var_r30] = fn_1_BE58;
    }
    var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
    var_r31->unk_0->property = var_r31;
    var_r31->unk_184 = CharModelCreate(var_r31->unk_1BC, sp10);
    for (var_r30 = 0; var_r30 < arg3; var_r30++) {
        var_r23 = var_r30 + (var_r31->unk_1BC * 0xD);
        if ((arg4[var_r23] + 0x10000) != -1) {
            var_r31->unk_190[var_r30] = CharMotionCreate(var_r31->unk_1BC, arg4[var_r30]);
        }
    }
    CharMotionDataClose(var_r31->unk_1BC);
    for (var_r30 = 0; var_r30 < arg5; var_r30++) {
        if (arg6[var_r30] != NULL) {
            var_r31->unk_10[var_r30] = arg6[var_r30];
        }
    }
    return var_r31;
}

void fn_1_CA2C(M508ModelObj *arg0)
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

void fn_1_CACC(M508ModelObj *arg0, char *arg1)
{
    if ((arg0->unk_1BC = 0) != 0) {
        CharModelHookDustCreate(arg0->unk_1BC, arg1);
        return;
    }
    Hu3DModelHookReset(arg0->unk_184);
}

M508Camera *fn_1_CB24(s16 arg0)
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
    var_r31->unk_C = HuPrcChildCreate(fn_1_CD4C, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_C->property = var_r31;
    var_r31->unk_AC = 0;
    Hu3DCameraCreate(arg0);
    fn_1_DA0C(var_r31, 30.0f, 10.0f, 8000.0f, 1.2f);
    fn_1_D9AC(var_r31, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    fn_1_DA5C(var_r31, 0.0f, 0.0f, 640.0f, 480.0f);
    var_r31->unk_0 = 2;
    return var_r31;
}

void fn_1_CD14(M508Camera *arg0)
{
    HuPrcKill(arg0->unk_C);
    HuMemDirectFree(arg0);
}

void fn_1_CD4C(void)
{
    M508Camera *var_r31;

    var_r31 = HuPrcCurrentGet()->property;
    while (var_r31->unk_0 != 3) {
        lbl_1_data_B0[var_r31->unk_0](var_r31, &lbl_1_data_B0[var_r31->unk_0],
            var_r31->unk_0 * sizeof(M508CameraFunc));
    }
    HuPrcEnd();
}

void fn_1_CDB0(M508Camera *arg0)
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

void fn_1_D028(M508Camera *arg0)
{
    M508CameraView *var_r31;

    if (arg0->unk_0 != 2) {
        var_r31 = &arg0->unk_10;
        Hu3DCameraPosSet(arg0->unk_8, var_r31->unk_0, var_r31->unk_4, var_r31->unk_8,
            var_r31->unk_C, var_r31->unk_10, var_r31->unk_14, var_r31->unk_18,
            var_r31->unk_1C, var_r31->unk_20);
    }
}

void fn_1_D098(s32 *arg0)
{
    *arg0 = 2;
}

void fn_1_D0A4(M508Camera *arg0, void *arg1, s32 arg2)
{
    M508Camera *var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;

    while (1) {
        var_r27 = 1;
        for (var_r29 = 0; var_r29 < var_r27; var_r29++) {
            var_r28 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
            var_r30 = HuPrcCurrentGet()->property;
            fn_1_D028(var_r30);
            HuPrcVSleep();
            if (var_r28 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                return;
            }
        }
    }
}

void fn_1_D158(s32 *arg0)
{
    *arg0 = 0;
}

void fn_1_D164(M508Camera *arg0, void *arg1, s32 arg2)
{
    M508Camera *var_r30;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;

    while (1) {
        fn_1_DAF0(arg0);
        fn_1_DF6C(arg0);
        var_r27 = 1;
        for (var_r29 = 0; var_r29 < var_r27; var_r29++) {
            var_r28 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
            var_r30 = HuPrcCurrentGet()->property;
            fn_1_D028(var_r30);
            HuPrcVSleep();
            if (var_r28 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                return;
            }
        }
    }
}

s32 fn_1_D22C(s32 *arg0)
{
    s32 var_r31;

    if (*arg0 != 0) {
        var_r31 = 1;
    }
    else {
        var_r31 = 0;
    }
    return var_r31;
}

void fn_1_D25C(M508Camera *arg0, M508VecWords *arg1, M508VecWords *arg2, float *arg3, s32 arg4)
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
    fn_1_CDB0(var_r29);
    var_r29->unk_4 = arg4;
    if (arg4 > 0) {
        var_r29->unk_0 = 1;
        return;
    }
    *var_r28 = *var_r30;
    var_r29->unk_0 = 0;
}

void fn_1_D6A0(M508Camera *arg0, void *arg1, s32 arg2)
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

    var_r30 = &arg0->unk_10;
    var_r31 = &arg0->unk_44;
    var_r29 = &arg0->unk_78;
    var_f29 = 1.0f / arg0->unk_4;
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
        fn_1_DAF0(arg0);
        fn_1_DF6C(arg0);
        var_f30 += var_f29;
        if (!(var_f30 >= 1.0f)) {
            var_r23 = 1;
            for (var_r25 = 0; var_r25 < var_r23; var_r25++) {
                var_r24 = ((M508Camera *) HuPrcCurrentGet()->property)->unk_0;
                var_r26 = HuPrcCurrentGet()->property;
                fn_1_D028(var_r26);
                HuPrcVSleep();
                if (var_r24 != ((M508Camera *) HuPrcCurrentGet()->property)->unk_0) {
                    return;
                }
            }
        }
        else {
            *var_r30 = *var_r29;
            arg0->unk_0 = 0;
            return;
        }
    }
}

void fn_1_D9AC(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3,
               float farg4, float farg5)
{
    Hu3DCameraViewportSet(arg0->unk_8, farg0, farg1, farg2, farg3, farg4, farg5);
}

void fn_1_DA0C(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3)
{
    Hu3DCameraPerspectiveSet(arg0->unk_8, farg0, farg1, farg2, farg3);
}

void fn_1_DA5C(M508Camera *arg0, float farg0, float farg1, float farg2, float farg3)
{
    Hu3DCameraScissorSet(arg0->unk_8, farg0, farg1, farg2, farg3);
}

void fn_1_DAF0(M508Camera *arg0)
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
        fn_1_CDB0(arg0);
    }
}

void fn_1_DF6C(M508Camera *arg0)
{
}

void fn_1_DF70(s32 arg0, s32 arg1)
{
    WipeCreate(WIPE_MODE_IN, WIPE_TYPE_PREVTYPE, arg0);
    while (arg1 != 0 && WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
}

void fn_1_DFCC(s32 arg0, s32 arg1)
{
    WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_WHITEFADE, arg0);
    while (arg1 != 0 && WipeCheckEnd() != 0) {
        HuPrcVSleep();
    }
}

void fn_1_E028(s32 arg0)
{
    s32 var_r29;
    s16 var_r30;
    s32 var_r31;

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

void fn_1_E0B4(s32 arg0)
{
    s32 var_r29;
    s16 var_r30;
    s32 var_r31;

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

float fn_1_E140(float farg0, float farg1, float farg2)
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

M508Window *fn_1_E244(s32 arg0, s32 arg1)
{
    M508Window *var_r31;

    var_r31 = HuMemDirectMallocNum(HEAP_HEAP, sizeof(M508Window), HU_MEMNUM_OVL);
    var_r31->unk_10 = HuPrcChildCreate(fn_1_E32C, 0x1000, 0x2000, 0, HuPrcCurrentGet());
    var_r31->unk_10->property = var_r31;
    var_r31->unk_0 = HuWinExCreateFrame(0.0f, 0.0f, arg0, arg1, -1, 1);
    return var_r31;
}

void fn_1_E2EC(M508Window *arg0)
{
    HuWinKill(arg0->unk_0);
    HuPrcKill(arg0->unk_10);
    HuMemDirectFree(arg0);
}

void fn_1_E32C(void)
{
    while (1) {
        HuPrcVSleep();
    }
}

void fn_1_E340(M508Window *arg0, float farg0, float farg1)
{
    arg0->unk_4 = farg0;
    arg0->unk_8 = farg1;
    HuWinPosSet(arg0->unk_0, farg0, farg1);
}

void fn_1_E388(M508Window *arg0, float *arg1, float *arg2)
{
    *arg1 = arg0->unk_4;
    *arg2 = arg0->unk_8;
}

void fn_1_E39C(s16 *arg0, u32 arg1)
{
    HuWinMesSet(*arg0, arg1);
}

void fn_1_E3D4(M508Window *arg0)
{
    HuWinDispOn(arg0->unk_0);
    arg0->unk_C = 1;
}

void fn_1_E40C(M508Window *arg0)
{
    HuWinDispOff(arg0->unk_0);
    arg0->unk_C = 0;
}

void fn_1_E444(s16 *arg0, s32 arg1)
{
    HuWinMesColSet(*arg0, arg1);
}

void fn_1_E480(s16 *arg0, s16 arg1)
{
    HuWinMesSpeedSet(*arg0, arg1);
}

void fn_1_E4B8(s16 *arg0)
{
    HuWinMesWait(*arg0);
}

void fn_1_E4E8(s16 *arg0)
{
    HuWinExOpen(*arg0);
}

void fn_1_E518(s16 *arg0)
{
    HuWinExClose(*arg0);
}

void fn_1_E548(s16 *arg0, float farg0, float farg1)
{
    HuWinScaleSet(*arg0, farg0, farg1);
}

//void fn_1_BDF0();
//void fn_1_BE58();
//void fn_1_CD4C();
//void fn_1_D0A4(s32 *arg_sp0, ? **arg_sp0, s32);
//void fn_1_D164(s32 *arg_sp0, ? **arg_sp0, s32);
//void fn_1_D6A0(s32 *arg_sp0, ? **arg_sp0, s32);
//void fn_1_D9AC(void *arg0, ? *farg0, float farg1, float farg2, float farg3, float farg4, float farg5, float);
//void fn_1_DA0C(void *arg0, ? *farg0, float farg1, float farg2, float farg3, float);
//void fn_1_DA5C(void *arg0, ? *farg0, float farg1, float farg2, float farg3, float);
//void fn_1_DAF0(s32 *arg0, float, float);
//void fn_1_DF6C(s32 *);
//void fn_1_E32C();
//static ? lbl_1_bss_2D4;
//static ? lbl_1_bss_2CC;
//static ? lbl_1_bss_2C4;
//static ? lbl_1_bss_2BC;
//static ? lbl_1_bss_2B4;
//static ? lbl_1_bss_2AC;
//static float lbl_1_bss_2A8;
//static float lbl_1_bss_2A4;
//static ? lbl_1_bss_27C;
//static ? lbl_1_bss_274;
//static float lbl_1_bss_270;
//static float lbl_1_bss_26C;
//static float lbl_1_bss_268;
//static float lbl_1_bss_264;
//static ? lbl_1_bss_25C;
//static ? lbl_1_bss_254;
//static ? lbl_1_bss_24C;
//static ? lbl_1_bss_244;
//static ? lbl_1_bss_23C;
//static ? lbl_1_bss_234;
//static float lbl_1_bss_230;
//static float lbl_1_bss_22C;
//static ? lbl_1_bss_220;
//static void (*lbl_1_data_B0[3])(s32 *, ? *, s32) = { fn_1_D164, fn_1_D6A0, fn_1_D0A4 };
//static ? lbl_1_rodata_798; /* unable to generate initializer: unknown type;
//                              const */
//
//float fn_1_A194(void *arg0) {
//  double var_f31;
//  float var_f30;
//  double var_f29;
//  float temp_f1;
//
//  var_f30 = (arg0->unk_0 * arg0->unk_0) + (arg0->unk_4 * arg0->unk_4);
//  if (var_f30 > 0.0) {
//    var_f31 = __frsqrte(var_f30);
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f29 = var_f30 * var_f31;
//  } else if (0.0 == var_f30) {
//    var_f29 = 0.0;
//  } else if (var_f30 != 0.0) {
//    var_f29 = *__float_nan;
//  } else {
//    var_f29 = *__float_huge;
//  }
//  temp_f1 = var_f29;
//  return temp_f1;
//}
//
//void fn_1_A314(void *arg0, void *arg1) {
//  double var_f31;
//  float var_f30;
//  double var_f29;
//  float var_f28;
//  float var_f27;
//
//  var_f30 = (arg1->unk_0 * arg1->unk_0) + (arg1->unk_4 * arg1->unk_4);
//  if (var_f30 > 0.0) {
//    var_f31 = __frsqrte(var_f30);
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f29 = var_f30 * var_f31;
//  } else if (0.0 == var_f30) {
//    var_f29 = 0.0;
//  } else if (var_f30 != 0.0) {
//    var_f29 = *__float_nan;
//  } else {
//    var_f29 = *__float_huge;
//  }
//  var_f27 = var_f29;
//  var_f28 = 1.0f / var_f27;
//  arg0->unk_0 = arg1->unk_0 * var_f28;
//  arg0->unk_4 = arg1->unk_4 * var_f28;
//}
//
//s32 fn_1_A4DC(void *arg0, void *arg1) {
//  s32 var_r31;
//  float var_f31;
//  float var_f30;
//  float var_f29;
//
//  var_f31 = arg0->unk_0 - arg1->unk_0;
//  var_f30 = arg0->unk_4 - arg1->unk_4;
//  var_f29 = arg1->unk_8;
//  if (((var_f31 * var_f31) + (var_f30 * var_f30)) > (var_f29 * var_f29)) {
//    var_r31 = 0;
//  } else {
//    var_r31 = 1;
//  }
//  return var_r31;
//}
//
//s32 fn_1_A564(void *arg0, void *arg1) {
//  s32 var_r31;
//  float var_f31;
//  float var_f30;
//  float var_f29;
//
//  var_f31 = arg0->unk_0 - arg1->unk_0;
//  var_f30 = arg0->unk_4 - arg1->unk_4;
//  var_f29 = arg0->unk_8 + arg1->unk_8;
//  if (((var_f31 * var_f31) + (var_f30 * var_f30)) < (var_f29 * var_f29)) {
//    var_r31 = 1;
//  } else {
//    var_r31 = 0;
//  }
//  return var_r31;
//}
//
//s32 fn_1_A5F4(void *arg0, void *arg1) {
//  if (arg0->unk_0 > arg1->unk_8) {
//    return 0;
//  }
//  if (arg0->unk_8 < arg1->unk_0) {
//    return 0;
//  }
//  if (arg0->unk_4 > arg1->unk_C) {
//    return 0;
//  }
//  if (arg0->unk_C < arg1->unk_4) {
//    return 0;
//  }
//  return 1;
//}
//
//s32 fn_1_A65C(void *arg0, void *arg1, ? arg_sp0)
//{
//  s32 var_r31;
//  s32 var_r30;
//  void *var_r29;
//  void *var_r28;
//  s32 var_r27;
//  s32 var_r26;
//  s32 var_r25;
//  s32 var_r24;
//
//  var_r30 = 0;
//  var_r26 = 0;
//  var_r27 = arg1->unk_0 - 1;
//  for (var_r31 = 0; var_r31 < var_r27; var_r31++) {
//    var_r29 = arg1->unk_4 + (var_r31 * 8);
//    var_r28 = arg1->unk_4 + ((var_r31 + 1) * 8);
//    var_r26 =
//        ((arg0->unk_0 - var_r29->unk_0) * (arg0->unk_4 - var_r28->unk_4)) -
//        ((arg0->unk_4 - var_r29->unk_4) * (arg0->unk_0 - var_r28->unk_0));
//    if (var_r26 < 0) {
//      var_r30++;
//    }
//  }
//  var_r25 = 1;
//  if ((var_r30 != 0) && (var_r30 != var_r27)) {
//    var_r25 = 0;
//  }
//  if (var_r25 != 0) {
//    var_r24 = 1;
//  } else {
//    var_r24 = 0;
//  }
//  return var_r24;
//}
//
//s32 fn_1_A74C(void *arg0, float *arg1) {
//  s32 var_r31;
//  s32 var_r30;
//  double var_f31;
//  float var_f30;
//  double var_f29;
//  float var_f28;
//  float var_f27;
//  float var_f26;
//  float var_f25;
//  float var_f24;
//  float var_f23;
//  float var_f22;
//  float var_f21;
//  float var_f20;
//  float var_f19;
//
//  var_f26 = arg1->unk_0 - arg0->unk_0;
//  var_f27 = arg1->unk_4 - arg0->unk_4;
//  var_f28 = arg0->unk_8;
//  if (((var_f26 * var_f26) + (var_f27 * var_f27)) > (var_f28 * var_f28)) {
//    var_r31 = 0;
//  } else {
//    var_r31 = 1;
//  }
//  if (var_r31 != 0) {
//    return 1;
//  }
//  var_f23 = arg1->unk_8 - arg0->unk_0;
//  var_f24 = arg1->unk_C - arg0->unk_4;
//  var_f25 = arg0->unk_8;
//  if (((var_f23 * var_f23) + (var_f24 * var_f24)) > (var_f25 * var_f25)) {
//    var_r30 = 0;
//  } else {
//    var_r30 = 1;
//  }
//  if (var_r30 != 0) {
//    return 1;
//  }
//  lbl_1_bss_2D4.unk_0 = arg1->unk_8 - arg1->unk_0;
//  lbl_1_bss_2D4.unk_4 = arg1->unk_C - arg1->unk_4;
//  lbl_1_bss_2CC.unk_0 = arg0->unk_0 - arg1->unk_0;
//  lbl_1_bss_2CC.unk_4 = arg0->unk_4 - arg1->unk_4;
//  var_f20 = (lbl_1_bss_2D4.unk_0 * lbl_1_bss_2CC.unk_4) -
//            (lbl_1_bss_2D4.unk_4 * lbl_1_bss_2CC.unk_0);
//  lbl_1_bss_2A8 = var_f20;
//  if (lbl_1_bss_2A8 == 0.0f) {
//    M2C_STRUCT_COPY(&lbl_1_bss_2AC, arg0, 8);
//    goto block_22;
//  }
//  lbl_1_bss_2C4.unk_0 = lbl_1_bss_2D4.unk_4 * lbl_1_bss_2A8;
//  lbl_1_bss_2C4.unk_4 = -(lbl_1_bss_2D4.unk_0 * lbl_1_bss_2A8);
//  var_f30 = (lbl_1_bss_2C4.unk_0 * lbl_1_bss_2C4.unk_0) +
//            (lbl_1_bss_2C4.unk_4 * lbl_1_bss_2C4.unk_4);
//  if (var_f30 > 0.0) {
//    var_f31 = __frsqrte(var_f30);
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f29 = var_f30 * var_f31;
//  } else if (0.0 == var_f30) {
//    var_f29 = 0.0;
//  } else if (var_f30 != 0.0) {
//    var_f29 = *__float_nan;
//  } else {
//    var_f29 = *__float_huge;
//  }
//  var_f21 = var_f29;
//  var_f22 = 1.0f / var_f21;
//  lbl_1_bss_2BC.unk_0 = lbl_1_bss_2C4.unk_0 * var_f22;
//  lbl_1_bss_2BC.unk_4 = lbl_1_bss_2C4.unk_4 * var_f22;
//  lbl_1_bss_2B4.unk_0 = arg1->unk_0 - arg0->unk_0;
//  lbl_1_bss_2B4.unk_4 = arg1->unk_4 - arg0->unk_4;
//  var_f19 = (lbl_1_bss_2BC.unk_0 * lbl_1_bss_2B4.unk_0) +
//            (lbl_1_bss_2BC.unk_4 * lbl_1_bss_2B4.unk_4);
//  lbl_1_bss_2A4 = var_f19;
//  if (lbl_1_bss_2A4 > arg0->unk_8) {
//    return 0;
//  }
//  lbl_1_bss_2AC.unk_0 = arg0->unk_0 + (lbl_1_bss_2BC.unk_0 * lbl_1_bss_2A4);
//  lbl_1_bss_2AC.unk_4 = arg0->unk_4 + (lbl_1_bss_2BC.unk_4 * lbl_1_bss_2A4);
//block_22:
//  if ((arg1->unk_0 < lbl_1_bss_2AC.unk_0) &&
//      (lbl_1_bss_2AC.unk_0 < arg1->unk_8)) {
//    return 1;
//  }
//  if ((arg1->unk_8 < lbl_1_bss_2AC.unk_0) &&
//      (lbl_1_bss_2AC.unk_0 < arg1->unk_0)) {
//    return 1;
//  }
//  if ((arg1->unk_4 < lbl_1_bss_2AC.unk_4) &&
//      (lbl_1_bss_2AC.unk_4 < arg1->unk_C)) {
//    return 1;
//  }
//  if ((arg1->unk_C < lbl_1_bss_2AC.unk_4) &&
//      (lbl_1_bss_2AC.unk_4 < arg1->unk_4)) {
//    return 1;
//  }
//  return 0;
//}
//
//s32 fn_1_AD98(void *arg0, void *arg1, ? arg_sp0)
//{
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s32 var_r28;
//  void *var_r27;
//  void *var_r26;
//  s32 var_r25;
//  s32 var_r24;
//  s32 var_r23;
//  s32 var_r22;
//  s32 var_r21;
//  s32 var_r20;
//
//  var_r30 = arg0;
//  var_r31 = arg1;
//  var_r25 = 0;
//  var_r24 = 0;
//  var_r23 = var_r31->unk_0 - 1;
//  for (var_r28 = 0; var_r28 < var_r23; var_r28++) {
//    var_r26 = var_r31->unk_4 + (var_r28 * 8);
//    var_r27 = var_r31->unk_4 + ((var_r28 + 1) * 8);
//    var_r24 =
//        ((var_r30->unk_0 - var_r26->unk_0) *
//         (var_r30->unk_4 - var_r27->unk_4)) -
//        ((var_r30->unk_4 - var_r26->unk_4) * (var_r30->unk_0 - var_r27->unk_0));
//    if (var_r24 < 0) {
//      var_r25++;
//    }
//  }
//  var_r22 = 1;
//  if ((var_r25 != 0) && (var_r25 != var_r23)) {
//    var_r22 = 0;
//  }
//  if (var_r22 != 0) {
//    var_r21 = 1;
//  } else {
//    var_r21 = 0;
//  }
//  if (var_r21 != 0) {
//    return 1;
//  }
//  var_r20 = var_r31->unk_0 - 1;
//  var_r29 = 0;
//loop_17:
//  if (var_r29 >= var_r20) {
//    return 0;
//  }
//  sp8 = *(var_r31->unk_4 + (var_r29 * 8));
//  spC = *(var_r31->unk_4 + ((var_r29 * 8) + 4));
//  sp10 = *(var_r31->unk_4 + ((var_r29 + 1) * 8));
//  sp10 = *(var_r31->unk_4 + (((var_r29 + 1) * 8) + 4));
//  if (fn_1_A74C(var_r30, &sp8) != 0) {
//    return 1;
//  }
//  var_r29++;
//  goto loop_17;
//}
//
//s32 fn_1_AF28(void *arg0, void *arg1, ? arg_sp0)
//{
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s32 var_r28;
//  void *var_r27;
//  void *var_r26;
//  s32 var_r25;
//  s32 var_r24;
//  s32 var_r23;
//  s32 var_r22;
//  s32 var_r21;
//  s32 var_r20;
//  s32 var_r19;
//
//  var_r31 = arg0;
//  var_r30 = arg1;
//  lbl_1_bss_27C.unk_0 = var_r31->unk_0;
//  lbl_1_bss_27C.unk_4 = var_r31->unk_4;
//  lbl_1_bss_27C.unk_8 = var_r31->unk_8;
//  lbl_1_bss_27C.unk_C = var_r31->unk_4;
//  lbl_1_bss_27C.unk_10 = var_r31->unk_8;
//  lbl_1_bss_27C.unk_14 = var_r31->unk_C;
//  lbl_1_bss_27C.unk_18 = var_r31->unk_0;
//  lbl_1_bss_27C.unk_1C = var_r31->unk_C;
//  lbl_1_bss_27C.unk_20 = var_r31->unk_0;
//  lbl_1_bss_27C.unk_24 = var_r31->unk_4;
//  lbl_1_bss_274.unk_0 = 5;
//  lbl_1_bss_274.unk_4 = &lbl_1_bss_27C;
//  var_r25 = 0;
//  var_r23 = 0;
//  var_r22 = lbl_1_bss_274.unk_0 - 1;
//  for (var_r28 = 0; var_r28 < var_r22; var_r28++) {
//    var_r26 = lbl_1_bss_274.unk_4 + (var_r28 * 8);
//    var_r27 = lbl_1_bss_274.unk_4 + ((var_r28 + 1) * 8);
//    var_r23 =
//        ((var_r30->unk_0 - var_r26->unk_0) *
//         (var_r30->unk_4 - var_r27->unk_4)) -
//        ((var_r30->unk_4 - var_r26->unk_4) * (var_r30->unk_0 - var_r27->unk_0));
//    if (var_r23 < 0) {
//      var_r25++;
//    }
//  }
//  var_r21 = 1;
//  if ((var_r25 != 0) && (var_r25 != var_r22)) {
//    var_r21 = 0;
//  }
//  if (var_r21 != 0) {
//    var_r20 = 1;
//  } else {
//    var_r20 = 0;
//  }
//  if (var_r20 != 0) {
//    var_r24 = 1;
//  } else {
//    var_r19 = lbl_1_bss_274.unk_0 - 1;
//    var_r29 = 0;
//  loop_17:
//    if (var_r29 >= var_r19) {
//      var_r24 = 0;
//    } else {
//      sp8 = *(lbl_1_bss_274.unk_4 + (var_r29 * 8));
//      spC = *(lbl_1_bss_274.unk_4 + ((var_r29 * 8) + 4));
//      sp10 = *(lbl_1_bss_274.unk_4 + ((var_r29 + 1) * 8));
//      sp10 = *(lbl_1_bss_274.unk_4 + (((var_r29 + 1) * 8) + 4));
//      if (fn_1_A74C(var_r30, &sp8) != 0) {
//        var_r24 = 1;
//      } else {
//        var_r29++;
//        goto loop_17;
//      }
//    }
//  }
//  return var_r24;
//}
//
//s32 fn_1_B1C0(void *arg0, void *arg1) {
//  s32 var_r31;
//  float var_f31;
//  float var_f30;
//  float var_f29;
//  float var_f28;
//
//  var_f31 = arg0->unk_0 - arg1->unk_0;
//  var_f30 = arg0->unk_4 - arg1->unk_4;
//  var_f29 = arg0->unk_8 - arg1->unk_8;
//  var_f28 = arg0->unk_C + arg1->unk_C;
//  if (((var_f29 * var_f29) + ((var_f31 * var_f31) + (var_f30 * var_f30))) <
//      (var_f28 * var_f28)) {
//    var_r31 = 1;
//  } else {
//    var_r31 = 0;
//  }
//  return var_r31;
//}
//
//s32 fn_1_B274(void *arg0, void *arg1) {
//  float sp8;
//  double var_f31;
//  float var_f30;
//  float var_f29;
//
//  lbl_1_bss_270 = arg0->unk_0 - arg1->unk_0;
//  lbl_1_bss_26C = arg0->unk_4 - arg1->unk_4;
//  lbl_1_bss_268 = arg0->unk_8 + arg1->unk_8;
//  var_f30 = (lbl_1_bss_270 * lbl_1_bss_270) + (lbl_1_bss_26C * lbl_1_bss_26C);
//  if (var_f30 > 0.0f) {
//    var_f31 = __frsqrte(var_f30);
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f30 * (var_f31 * var_f31)));
//    sp8 = var_f30 * var_f31;
//    var_f29 = sp8;
//  } else {
//    var_f29 = var_f30;
//  }
//  lbl_1_bss_264 = var_f29;
//  if (lbl_1_bss_264 < lbl_1_bss_268) {
//    if (lbl_1_bss_264 == 0.0f) {
//      lbl_1_bss_270 = 0.0f;
//      lbl_1_bss_26C = -1.0f;
//    } else {
//      lbl_1_bss_270 /= lbl_1_bss_264;
//      lbl_1_bss_26C /= lbl_1_bss_264;
//    }
//    arg0->unk_0 = arg1->unk_0 + (lbl_1_bss_270 * lbl_1_bss_268);
//    arg0->unk_4 = arg1->unk_4 + (lbl_1_bss_26C * lbl_1_bss_268);
//    return 1;
//  }
//  return 0;
//}
//
//s32 fn_1_B514(void *arg0, void *arg1) {
//  float sp8;
//  s32 var_r31;
//  double var_f31;
//  double var_f30;
//  float var_f29;
//  float var_f28;
//  double var_f27;
//  float var_f26;
//  float var_f25;
//  float var_f24;
//  float var_f23;
//  float var_f22;
//
//  lbl_1_bss_25C.unk_0 = arg1->unk_8 - arg1->unk_0;
//  lbl_1_bss_25C.unk_4 = arg1->unk_C - arg1->unk_4;
//  lbl_1_bss_254.unk_0 = arg0->unk_0 - arg1->unk_0;
//  lbl_1_bss_254.unk_4 = arg0->unk_4 - arg1->unk_4;
//  var_f23 = (lbl_1_bss_25C.unk_0 * lbl_1_bss_254.unk_4) -
//            (lbl_1_bss_25C.unk_4 * lbl_1_bss_254.unk_0);
//  lbl_1_bss_230 = var_f23;
//  if (lbl_1_bss_230 == 0.0f) {
//    M2C_STRUCT_COPY(&lbl_1_bss_234, arg0, 8);
//    goto block_12;
//  }
//  lbl_1_bss_24C.unk_0 = lbl_1_bss_25C.unk_4 * lbl_1_bss_230;
//  lbl_1_bss_24C.unk_4 = -(lbl_1_bss_25C.unk_0 * lbl_1_bss_230);
//  var_f29 = (lbl_1_bss_24C.unk_0 * lbl_1_bss_24C.unk_0) +
//            (lbl_1_bss_24C.unk_4 * lbl_1_bss_24C.unk_4);
//  if (var_f29 > 0.0) {
//    var_f31 = __frsqrte(var_f29);
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f29 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f29 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f29 * (var_f31 * var_f31)));
//    var_f31 = 0.5 * var_f31 * (3.0 - (var_f29 * (var_f31 * var_f31)));
//    var_f27 = var_f29 * var_f31;
//  } else if (0.0 == var_f29) {
//    var_f27 = 0.0;
//  } else if (var_f29 != 0.0) {
//    var_f27 = *__float_nan;
//  } else {
//    var_f27 = *__float_huge;
//  }
//  var_f24 = var_f27;
//  var_f26 = 1.0f / var_f24;
//  lbl_1_bss_244.unk_0 = lbl_1_bss_24C.unk_0 * var_f26;
//  lbl_1_bss_244.unk_4 = lbl_1_bss_24C.unk_4 * var_f26;
//  lbl_1_bss_23C.unk_0 = arg1->unk_0 - arg0->unk_0;
//  lbl_1_bss_23C.unk_4 = arg1->unk_4 - arg0->unk_4;
//  var_f22 = (lbl_1_bss_244.unk_0 * lbl_1_bss_23C.unk_0) +
//            (lbl_1_bss_244.unk_4 * lbl_1_bss_23C.unk_4);
//  lbl_1_bss_22C = var_f22;
//  if (lbl_1_bss_22C > arg0->unk_8) {
//    return 0;
//  }
//  lbl_1_bss_234.unk_0 = arg0->unk_0 + (lbl_1_bss_244.unk_0 * lbl_1_bss_22C);
//  lbl_1_bss_234.unk_4 = arg0->unk_4 + (lbl_1_bss_244.unk_4 * lbl_1_bss_22C);
//block_12:
//  lbl_1_bss_220.unk_0 = lbl_1_bss_234.unk_0;
//  lbl_1_bss_220.unk_4 = lbl_1_bss_234.unk_4;
//  lbl_1_bss_220.unk_8 = 1.0f;
//  lbl_1_bss_270 = arg0->unk_0 - lbl_1_bss_220.unk_0;
//  lbl_1_bss_26C = arg0->unk_4 - lbl_1_bss_220.unk_4;
//  lbl_1_bss_268 = arg0->unk_8 + lbl_1_bss_220.unk_8;
//  var_f28 = (lbl_1_bss_270 * lbl_1_bss_270) + (lbl_1_bss_26C * lbl_1_bss_26C);
//  if (var_f28 > 0.0f) {
//    var_f30 = __frsqrte(var_f28);
//    var_f30 = 0.5 * var_f30 * (3.0 - (var_f28 * (var_f30 * var_f30)));
//    var_f30 = 0.5 * var_f30 * (3.0 - (var_f28 * (var_f30 * var_f30)));
//    var_f30 = 0.5 * var_f30 * (3.0 - (var_f28 * (var_f30 * var_f30)));
//    sp8 = var_f28 * var_f30;
//    var_f25 = sp8;
//  } else {
//    var_f25 = var_f28;
//  }
//  lbl_1_bss_264 = var_f25;
//  if (lbl_1_bss_264 < lbl_1_bss_268) {
//    if (lbl_1_bss_264 == 0.0f) {
//      lbl_1_bss_270 = 0.0f;
//      lbl_1_bss_26C = -1.0f;
//    } else {
//      lbl_1_bss_270 /= lbl_1_bss_264;
//      lbl_1_bss_26C /= lbl_1_bss_264;
//    }
//    arg0->unk_0 = lbl_1_bss_220.unk_0 + (lbl_1_bss_270 * lbl_1_bss_268);
//    arg0->unk_4 = lbl_1_bss_220.unk_4 + (lbl_1_bss_26C * lbl_1_bss_268);
//    var_r31 = 1;
//  } else {
//    var_r31 = 0;
//  }
//  return var_r31;
//}
//
//void *fn_1_BC7C(s32 arg0, u32 arg1, s32 arg2, u32 arg3) {
//  u32 spC;
//  s32 sp8;
//  void *var_r31;
//  s32 var_r30;
//  u32 var_r29;
//  s32 var_r28;
//
//  sp8 = arg0;
//  spC = arg1;
//  var_r28 = arg2;
//  var_r29 = arg3;
//  var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x158, HU_MEMNUM_OVL);
//  var_r31->unk_4 = 0;
//  var_r31->unk_8 = 0;
//  var_r31->unk_14 = var_r28;
//  var_r31->unk_C = 0;
//  var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r28 * 4, HU_MEMNUM_OVL);
//  for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
//    *(var_r31->unk_10 + (var_r30 * 4)) = fn_1_BE58;
//  }
//  var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
//  var_r31->unk_0->property = var_r31;
//  if (var_r29 != 0) {
//    for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
//      if (*(var_r29 + (var_r30 * 4)) != 0) {
//        *(var_r31->unk_10 + (var_r30 * 4)) = *(var_r29 + (var_r30 * 4));
//      }
//    }
//  }
//  return var_r31;
//}
//
//void fn_1_BDB0(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  HuMemDirectFree(var_r31->unk_10);
//  HuPrcKill(var_r31->unk_0);
//  HuMemDirectFree(var_r31);
//}
//
//void fn_1_BDF0(void) {
//  s32 temp_r4;
//  void *var_r31;
//
//  var_r31 = HuPrcCurrentGet()->property;
//loop_2:
//  if (var_r31->unk_4 < var_r31->unk_14) {
//    temp_r4 = var_r31->unk_10;
//    *(temp_r4 + (var_r31->unk_4 * 4))(var_r31, temp_r4);
//    var_r31->unk_8 = var_r31->unk_4;
//    goto loop_2;
//  }
//  HuPrcEnd();
//}
//
//void fn_1_BE58(void) {
//loop_1:
//  HuPrcSleep(0);
//  goto loop_1;
//}
//
//void *fn_1_BE70(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u32 arg6, ? arg_sp0)
//{
//  u32 spC;
//  s32 sp8;
//  void *var_r31;
//  s32 var_r30;
//  u32 var_r29;
//  s32 var_r28;
//  s32 var_r27;
//  s32 var_r26;
//  s32 var_r25;
//
//  sp8 = arg0;
//  spC = arg1;
//  var_r25 = arg2;
//  var_r26 = arg3;
//  var_r27 = arg4;
//  var_r28 = arg5;
//  var_r29 = arg6;
//  var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x1B8, HU_MEMNUM_OVL);
//  var_r31->unk_4 = 0;
//  var_r31->unk_8 = 0;
//  var_r31->unk_14 = var_r28;
//  var_r31->unk_158 = 1;
//  var_r31->unk_160 = 0.0f;
//  var_r31->unk_164 = 0.0f;
//  var_r31->unk_168 = 0.0f;
//  var_r31->unk_16C = 0.0f;
//  var_r31->unk_170 = 0.0f;
//  var_r31->unk_174 = 0.0f;
//  var_r31->unk_178 = 1.0f;
//  var_r31->unk_17C = 1.0f;
//  var_r31->unk_180 = 1.0f;
//  var_r31->unk_184 = -1;
//  var_r31->unk_C = 0;
//  var_r31->unk_18C = var_r26;
//  var_r31->unk_190 =
//      HuMemDirectMallocNum(HEAP_HEAP, var_r26 * 2, HU_MEMNUM_OVL);
//  for (var_r30 = 0; var_r30 < var_r26; var_r30++) {
//    *(var_r31->unk_190 + (var_r30 * 2)) = -1;
//  }
//  var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r28 * 4, HU_MEMNUM_OVL);
//  for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
//    *(var_r31->unk_10 + (var_r30 * 4)) = fn_1_BE58;
//  }
//  var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
//  var_r31->unk_0->property = var_r31;
//  if ((var_r25 + 0x10000) != -1) {
//    var_r31->unk_184 = Hu3DModelCreateData(var_r25);
//  }
//  for (var_r30 = 0; var_r30 < var_r26; var_r30++) {
//    if ((*(var_r27 + (var_r30 * 4)) + 0x10000) != -1) {
//      *(var_r31->unk_190 + (var_r30 * 2)) =
//          Hu3DJointMotionData(var_r31->unk_184, *(var_r27 + (var_r30 * 4)));
//    }
//  }
//  if (var_r29 != 0) {
//    for (var_r30 = 0; var_r30 < var_r28; var_r30++) {
//      if (*(var_r29 + (var_r30 * 4)) != 0) {
//        *(var_r31->unk_10 + (var_r30 * 4)) = *(var_r29 + (var_r30 * 4));
//      }
//    }
//  }
//  return var_r31;
//}
//
//void fn_1_C0F4(void *arg0) {
//  void *var_r31;
//  s32 var_r30;
//
//  var_r31 = arg0;
//  for (var_r30 = 0; var_r30 < var_r31->unk_18C; var_r30++) {
//    if (*(var_r31->unk_190 + (var_r30 * 2)) != -1) {
//      Hu3DMotionKill(*(var_r31->unk_190 + (var_r30 * 2)));
//    }
//  }
//  HuMemDirectFree(var_r31->unk_190);
//  if (var_r31->unk_184 != -1) {
//    Hu3DModelKill(var_r31->unk_184);
//  }
//  HuMemDirectFree(var_r31->unk_10);
//  HuPrcKill(var_r31->unk_0);
//  HuMemDirectFree(var_r31);
//}
//
//void fn_1_C194(void *arg0, float farg0, float farg1, float farg2) {
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  var_r31->unk_160 = sp8;
//  var_r31->unk_164 = spC;
//  var_r31->unk_168 = sp10;
//  Hu3DModelPosSet(var_r31->unk_184, sp8, spC, sp10);
//}
//
//void fn_1_C1E8(void *arg0, float *arg1, float *arg2, float *arg3) {
//  if (arg1 != NULL) {
//    *arg1 = arg0->unk_160;
//  }
//  if (arg2 != NULL) {
//    *arg2 = arg0->unk_164;
//  }
//  if (arg3 != NULL) {
//    *arg3 = arg0->unk_168;
//  }
//}
//
//void fn_1_C228(void *arg0, float farg0, float farg1, float farg2) {
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  var_r31->unk_16C = sp8;
//  var_r31->unk_170 = spC;
//  var_r31->unk_174 = sp10;
//  Hu3DModelRotSet(var_r31->unk_184, sp8, spC, sp10);
//}
//
//void fn_1_C27C(void *arg0, float *arg1, float *arg2, float *arg3) {
//  if (arg1 != NULL) {
//    *arg1 = arg0->unk_16C;
//  }
//  if (arg2 != NULL) {
//    *arg2 = arg0->unk_170;
//  }
//  if (arg3 != NULL) {
//    *arg3 = arg0->unk_174;
//  }
//}
//
//void fn_1_C2BC(void *arg0, float farg0, float farg1, float farg2) {
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  var_r31->unk_178 = sp8;
//  var_r31->unk_17C = spC;
//  var_r31->unk_180 = sp10;
//  Hu3DModelScaleSet(var_r31->unk_184, sp8, spC, sp10);
//}
//
//void fn_1_C310(void *arg0, float *arg1, float *arg2, float *arg3) {
//  if (arg1 != NULL) {
//    *arg1 = arg0->unk_178;
//  }
//  if (arg2 != NULL) {
//    *arg2 = arg0->unk_17C;
//  }
//  if (arg3 != NULL) {
//    *arg3 = arg0->unk_180;
//  }
//}
//
//void fn_1_C350(void *arg0, float farg0) {
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  var_r31->unk_1B0 = sp8;
//  Hu3DModelTPLvlSet(var_r31->unk_184, sp8);
//}
//
//float fn_1_C38C(void *arg0) { return arg0->unk_1B0; }
//
//void fn_1_C394(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  var_r31->unk_158 = 1;
//  Hu3DModelDispOn(var_r31->unk_184);
//}
//
//void fn_1_C3D0(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  var_r31->unk_158 = 0;
//  Hu3DModelDispOff(var_r31->unk_184);
//}
//
//s32 fn_1_C40C(void *arg0) { return arg0->unk_158; }
//
//void fn_1_C414(void *arg0, s32 arg1) {
//  s32 sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = arg1;
//  Hu3DMotionTimeSet(var_r31->unk_184, sp8);
//}
//
//void fn_1_C470(void *arg0, s32 arg1) {
//  s32 sp8;
//  s16 var_r31;
//  void *var_r30;
//
//  var_r30 = arg0;
//  sp8 = arg1;
//  var_r31 = var_r30->unk_184;
//  Hu3DModelAttrReset(var_r31, HU3D_MOTATTR_PAUSE);
//  if (sp8 != 0) {
//    Hu3DModelAttrSet(var_r31, HU3D_MOTATTR_LOOP);
//    return;
//  }
//  Hu3DModelAttrReset(var_r31, HU3D_MOTATTR_LOOP);
//}
//
//void fn_1_C4E8(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  Hu3DModelAttrSet(var_r31->unk_184, HU3D_MOTATTR_PAUSE);
//}
//
//s32 fn_1_C520(void *arg0) {
//  s32 var_r31;
//  void *var_r30;
//
//  var_r30 = arg0;
//  if (Hu3DMotionEndCheck(var_r30->unk_184) == 0) {
//    var_r31 = 1;
//  } else {
//    var_r31 = 0;
//  }
//  return var_r31;
//}
//
//void fn_1_C570(void *arg0, s32 arg1, u32 arg2, float farg0, float farg1) {
//  u32 sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//  s32 var_r30;
//
//  var_r31 = arg0;
//  var_r30 = arg1;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = arg2;
//  var_r31->unk_188 = var_r30;
//  if (var_r30 == -1) {
//    Hu3DMotionSet(var_r31->unk_184, -1);
//    return;
//  }
//  Hu3DMotionShiftSet(var_r31->unk_184, *(var_r31->unk_190 + (var_r30 * 2)), sp8,
//                     spC, sp10);
//}
//
//s32 fn_1_C5EC(void *arg0) { return arg0->unk_188; }
//
//void fn_1_C5F4(void *arg0, float farg0) {
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  var_r31->unk_1B4 = sp8;
//  Hu3DMotionSpeedSet(var_r31->unk_184, sp8);
//}
//
//void fn_1_C630(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  Hu3DModelShadowSet(var_r31->unk_184);
//}
//
//void fn_1_C660(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  Hu3DModelShadowReset(var_r31->unk_184);
//}
//
//void fn_1_C690(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  Hu3DModelShadowMapSet(var_r31->unk_184);
//}
//
//void fn_1_C6C0(void) {}
//
//void fn_1_C6C4(void *arg0, s8 *arg1, void *arg2) {
//  s8 *sp8;
//  void *var_r31;
//  void *var_r30;
//
//  var_r30 = arg0;
//  sp8 = arg1;
//  var_r31 = arg2;
//  Hu3DModelHookSet(var_r30->unk_184, sp8, var_r31->unk_184);
//}
//
//void fn_1_C70C(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  Hu3DModelHookReset(var_r31->unk_184);
//}
//
//void *fn_1_C73C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, ? arg_sp0)
//{
//  s16 sp10;
//  u32 spC;
//  s32 sp8;
//  void *var_r31;
//  s32 var_r30;
//  s32 var_r29;
//  s32 var_r28;
//  s32 var_r27;
//  s32 var_r26;
//  s32 var_r25;
//  s32 var_r24;
//  s32 var_r23;
//
//  sp8 = arg0;
//  spC = arg1;
//  var_r29 = arg2;
//  var_r25 = arg3;
//  var_r26 = arg4;
//  var_r27 = arg5;
//  var_r28 = arg6;
//  sp10 = arg7;
//  var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x1CC, HU_MEMNUM_OVL);
//  var_r31->unk_4 = 0;
//  var_r31->unk_8 = 0;
//  var_r31->unk_14 = var_r27;
//  var_r31->unk_158 = 1;
//  var_r31->unk_160 = 0.0f;
//  var_r31->unk_164 = 0.0f;
//  var_r31->unk_168 = 0.0f;
//  var_r31->unk_16C = 0.0f;
//  var_r31->unk_170 = 0.0f;
//  var_r31->unk_174 = 0.0f;
//  var_r31->unk_178 = 1.0f;
//  var_r31->unk_17C = 1.0f;
//  var_r31->unk_180 = 1.0f;
//  var_r31->unk_184 = -1;
//  if (GwPlayerConf[var_r29].type != 0) {
//    var_r24 = 1;
//  } else {
//    var_r24 = 0;
//  }
//  var_r31->unk_1B8 = var_r24;
//  var_r31->unk_1BC = GwPlayerConf[var_r29].charNo;
//  var_r31->unk_1C0 = GwPlayerConf[var_r29].padNo;
//  var_r31->unk_1C4 = GwPlayerConf[var_r29].dif;
//  var_r31->unk_1C8 = var_r29;
//  var_r31->unk_C = 0;
//  var_r31->unk_18C = var_r25;
//  var_r31->unk_190 =
//      HuMemDirectMallocNum(HEAP_HEAP, var_r25 * 2, HU_MEMNUM_OVL);
//  for (var_r30 = 0; var_r30 < var_r25; var_r30++) {
//    *(var_r31->unk_190 + (var_r30 * 2)) = -1;
//  }
//  var_r31->unk_10 = HuMemDirectMallocNum(HEAP_HEAP, var_r27 * 4, HU_MEMNUM_OVL);
//  for (var_r30 = 0; var_r30 < var_r27; var_r30++) {
//    *(var_r31->unk_10 + (var_r30 * 4)) = fn_1_BE58;
//  }
//  var_r31->unk_0 = HuPrcChildCreate(fn_1_BDF0, sp8, spC, 0, HuPrcCurrentGet());
//  var_r31->unk_0->property = var_r31;
//  var_r31->unk_184 = CharModelCreate(var_r31->unk_1BC, sp10);
//  for (var_r30 = 0; var_r30 < var_r25; var_r30++) {
//    var_r23 = var_r30 + (var_r31->unk_1BC * 0xD);
//    if ((*(var_r26 + (var_r23 * 4)) + 0x10000) != -1) {
//      *(var_r31->unk_190 + (var_r30 * 2)) =
//          CharMotionCreate(var_r31->unk_1BC, *(var_r26 + (var_r30 * 4)));
//    }
//  }
//  CharMotionDataClose(var_r31->unk_1BC);
//  for (var_r30 = 0; var_r30 < var_r27; var_r30++) {
//    if (*(var_r28 + (var_r30 * 4)) != 0) {
//      *(var_r31->unk_10 + (var_r30 * 4)) = *(var_r28 + (var_r30 * 4));
//    }
//  }
//  return var_r31;
//}
//
//void fn_1_CA2C(void *arg0) {
//  void *var_r31;
//  s32 var_r30;
//
//  var_r31 = arg0;
//  for (var_r30 = 0; var_r30 < var_r31->unk_18C; var_r30++) {
//    if (*(var_r31->unk_190 + (var_r30 * 2)) != -1) {
//      Hu3DMotionKill(*(var_r31->unk_190 + (var_r30 * 2)));
//    }
//  }
//  HuMemDirectFree(var_r31->unk_190);
//  if (var_r31->unk_184 != -1) {
//    Hu3DModelKill(var_r31->unk_184);
//  }
//  HuMemDirectFree(var_r31->unk_10);
//  HuPrcKill(var_r31->unk_0);
//  HuMemDirectFree(var_r31);
//}
//
//void fn_1_CACC(void *arg0, s8 *arg1) {
//  s8 *sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = arg1;
//  var_r31->unk_1BC = 0;
//  if (0 != 0) {
//    CharModelHookDustCreate(var_r31->unk_1BC, sp8);
//    return;
//  }
//  Hu3DModelHookReset(var_r31->unk_184);
//}
//
//void *fn_1_CB24(s16 arg0) {
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s16 var_r28;
//
//  var_r28 = arg0;
//  var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0xB0, HU_MEMNUM_OVL);
//  var_r31->unk_8 = var_r28;
//  for (var_r29 = 0; var_r29 < 3; var_r29++) {
//    var_r30 = (var_r29 * 0x34) + 0x10;
//    var_r30 += var_r31;
//    var_r30->unk_18 = 0.0f;
//    var_r30->unk_1C = 0.0f;
//    var_r30->unk_20 = 0.0f;
//    var_r30->unk_24 = 0.0f;
//    var_r30->unk_28 = 0.0f;
//    var_r30->unk_2C = 0.0f;
//    var_r30->unk_30 = 0.0f;
//  }
//  var_r31->unk_C =
//      HuPrcChildCreate(fn_1_CD4C, 0x1000, 0x2000, 0, HuPrcCurrentGet());
//  var_r31->unk_C->property = var_r31;
//  var_r31->unk_AC = 0;
//  Hu3DCameraCreate(var_r28);
//  fn_1_DA0C(var_r31, &lbl_1_rodata_7AC, 30.0f, 10.0f, 8000.0f, 1.2f);
//  fn_1_D9AC(var_r31, &lbl_1_rodata_788, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
//  fn_1_DA5C(var_r31, &lbl_1_rodata_7B4, 0.0f, 0.0f, 640.0f, 480.0f);
//  var_r31->unk_0 = 2;
//  return var_r31;
//}
//
//void fn_1_CD14(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  HuPrcKill(var_r31->unk_C);
//  HuMemDirectFree(var_r31);
//}
//
//void fn_1_CD4C(void) {
//    void (**temp_r4)(s32 *, ?, s32);
//    s32 *var_r31;
//    s32 temp_r0;
//
//    var_r31 = HuPrcCurrentGet()->property;
//loop_2:
//  if (*var_r31 != 3) {
//    temp_r0 = *var_r31;
//    temp_r4 = &lbl_1_data_B0[temp_r0];
//    *temp_r4(var_r31, temp_r4, temp_r0 * 4);
//    goto loop_2;
//  }
//  HuPrcEnd();
//}
//
//void fn_1_CDB0(s32 arg0) {
//  s32 sp8;
//  void *var_r31;
//  s32 var_r30;
//  double var_f31;
//
//  sp8 = arg0;
//  for (var_r30 = 0; var_r30 < 3; var_r30++) {
//    var_r31 = (var_r30 * 0x34) + 0x10;
//    var_r31 += sp8;
//    var_f31 = HuCos(var_r31->unk_24);
//    var_r31->unk_0 = var_r31->unk_18 +
//                     (var_r31->unk_30 * (HuSin(var_r31->unk_28) * var_f31));
//    var_r31->unk_4 =
//        var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
//    var_f31 = HuCos(var_r31->unk_24);
//    var_r31->unk_8 = var_r31->unk_20 +
//                     (var_r31->unk_30 * (HuCos(var_r31->unk_28) * var_f31));
//    var_f31 = HuSin(var_r31->unk_24);
//    var_r31->unk_C = HuSin(var_r31->unk_28) * var_f31;
//    var_r31->unk_10 = HuCos(var_r31->unk_24);
//    var_f31 = HuSin(var_r31->unk_24);
//    var_r31->unk_14 = HuCos(var_r31->unk_28) * var_f31;
//  }
//}
//
//void fn_1_D028(void *arg0, float farg8) {
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//
//  var_r30 = arg0;
//  if (var_r30->unk_0 != 2) {
//    var_r31 = var_r30 + 0x10;
//    sp8 = var_r31->unk_20;
//    Hu3DCameraPosSet(var_r30->unk_8, var_r30->unk_10, var_r31->unk_4,
//                     var_r31->unk_8, var_r31->unk_C, var_r31->unk_10,
//                     var_r31->unk_14, var_r31->unk_18, var_r31->unk_1C, farg8);
//  }
//}
//
//void fn_1_D098(s32 *arg0) { *arg0 = 2; }
//
//void fn_1_D0A4(s32 *arg_sp0) {
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s32 var_r28;
//  s32 var_r27;
//
//loop_1:
//  var_r27 = 1;
//  var_r29 = 0;
//loop_6:
//  if (var_r29 >= 1) {
//    goto loop_1;
//  }
//  var_r28 = *HuPrcCurrentGet()->property;
//  var_r30 = HuPrcCurrentGet()->property;
//  if (var_r30->unk_0 != 2) {
//    var_r31 = var_r30 + 0x10;
//    sp8 = var_r31->unk_20;
//    Hu3DCameraPosSet(var_r30->unk_8, var_r30->unk_10, var_r31->unk_4,
//                     var_r31->unk_8, var_r31->unk_C, var_r31->unk_10,
//                     var_r31->unk_14, var_r31->unk_18, var_r31->unk_1C,
//                     M2C_ERROR(/* Read from unset reg $f9 */));
//  }
//  HuPrcVSleep();
//  if (var_r28 == *HuPrcCurrentGet()->property) {
//    var_r29++;
//    goto loop_6;
//  }
//}
//
//void fn_1_D158(s32 *arg0) { *arg0 = 0; }
//
//void fn_1_D164(s32 *arg0, void (**arg_sp0)(s32 *, ?, s32))
//{
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s32 var_r28;
//  s32 var_r27;
//  s32 *var_r26;
//
//  var_r26 = arg0;
//loop_1:
//  fn_1_DAF0(var_r26);
//  fn_1_DF6C(var_r26);
//  var_r27 = 1;
//  var_r29 = 0;
//loop_6:
//  if (var_r29 >= 1) {
//    goto loop_1;
//  }
//  var_r28 = *HuPrcCurrentGet()->property;
//  var_r30 = HuPrcCurrentGet()->property;
//  if (var_r30->unk_0 != 2) {
//    var_r31 = var_r30 + 0x10;
//    sp8 = var_r31->unk_20;
//    Hu3DCameraPosSet(var_r30->unk_8, var_r30->unk_10, var_r31->unk_4,
//                     var_r31->unk_8, var_r31->unk_C, var_r31->unk_10,
//                     var_r31->unk_14, var_r31->unk_18, var_r31->unk_1C,
//                     M2C_ERROR(/* Read from unset reg $f9 */));
//  }
//  HuPrcVSleep();
//  if (var_r28 == *HuPrcCurrentGet()->property) {
//    var_r29++;
//    goto loop_6;
//  }
//}
//
//s32 fn_1_D22C(s32 *arg0) {
//  s32 var_r31;
//
//  if (*arg0 != 0) {
//    var_r31 = 1;
//  } else {
//    var_r31 = 0;
//  }
//  return var_r31;
//}
//
//void fn_1_D25C(void *arg0, void *arg1, void *arg2, float *arg3, s32 arg4) {
//  void *var_r31;
//  void *var_r30;
//  void *var_r29;
//  s32 var_r28;
//  s32 var_r27;
//  s32 var_r26;
//  float *var_r25;
//  void *var_r24;
//  void *var_r23;
//  s32 var_r22;
//  double var_f31;
//
//  var_r29 = arg0;
//  var_r23 = arg1;
//  var_r24 = arg2;
//  var_r25 = arg3;
//  var_r22 = arg4;
//  var_r28 = var_r29 + 0x10;
//  var_r26 = var_r29 + 0x44;
//  var_r30 = var_r29 + 0x78;
//  M2C_STRUCT_COPY(var_r26, var_r28, 0x34);
//  M2C_STRUCT_COPY(var_r30, var_r28, 0x34);
//  if (var_r23 != NULL) {
//    var_r30->unk_18 = var_r23->unk_0;
//    var_r30->unk_1C = var_r23->unk_4;
//    var_r30->unk_20 = var_r23->unk_8;
//  }
//  if (var_r24 != NULL) {
//    var_r30->unk_24 = var_r24->unk_0;
//    var_r30->unk_28 = var_r24->unk_4;
//    var_r30->unk_2C = var_r24->unk_8;
//  }
//  if (var_r25 != NULL) {
//    var_r30->unk_30 = *var_r25;
//  }
//  for (var_r27 = 0; var_r27 < 3; var_r27++) {
//    var_r31 = (var_r27 * 0x34) + 0x10;
//    var_r31 += var_r29;
//    var_f31 = HuCos(var_r31->unk_24);
//    var_r31->unk_0 = var_r31->unk_18 +
//                     (var_r31->unk_30 * (HuSin(var_r31->unk_28) * var_f31));
//    var_r31->unk_4 =
//        var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
//    var_f31 = HuCos(var_r31->unk_24);
//    var_r31->unk_8 = var_r31->unk_20 +
//                     (var_r31->unk_30 * (HuCos(var_r31->unk_28) * var_f31));
//    var_f31 = HuSin(var_r31->unk_24);
//    var_r31->unk_C = HuSin(var_r31->unk_28) * var_f31;
//    var_r31->unk_10 = HuCos(var_r31->unk_24);
//    var_f31 = HuSin(var_r31->unk_24);
//    var_r31->unk_14 = HuCos(var_r31->unk_28) * var_f31;
//  }
//  var_r29->unk_4 = var_r22;
//  if (var_r22 > 0) {
//    var_r29->unk_0 = 1;
//    return;
//  }
//  M2C_STRUCT_COPY(var_r28, var_r30, 0x34);
//  var_r29->unk_0 = 0;
//}
//
//void fn_1_D6A0(s32 *arg0) {
//  float sp8;
//  void *var_r31;
//  void *var_r30;
//  void *var_r29;
//  void *var_r28;
//  s32 *var_r27;
//  void *var_r26;
//  s32 var_r25;
//  s32 var_r24;
//  s32 var_r23;
//  float var_f31;
//  float var_f30;
//  float temp_f2;
//  float var_f29;
//  float temp_f1;
//
//  var_r27 = arg0;
//  var_r30 = var_r27 + 0x10;
//  var_r31 = var_r27 + 0x44;
//  var_r29 = var_r27 + 0x78;
//  var_f29 = 1.0f / var_r27->unk_4;
//  var_f30 = 0.0f;
//loop_1:
//  var_f31 = HuSin((90.0f * var_f30));
//  var_f31 *= var_f31;
//  var_r30->unk_18 =
//      var_r31->unk_18 + (var_f31 * (var_r29->unk_18 - var_r31->unk_18));
//  var_r30->unk_1C =
//      var_r31->unk_1C + (var_f31 * (var_r29->unk_1C - var_r31->unk_1C));
//  var_r30->unk_20 =
//      var_r31->unk_20 + (var_f31 * (var_r29->unk_20 - var_r31->unk_20));
//  var_r27->unk_10 =
//      var_r27->unk_44 + (var_f31 * (var_r27->unk_78 - var_r27->unk_44));
//  var_r30->unk_4 =
//      var_r31->unk_4 + (var_f31 * (var_r29->unk_4 - var_r31->unk_4));
//  var_r30->unk_8 =
//      var_r31->unk_8 + (var_f31 * (var_r29->unk_8 - var_r31->unk_8));
//  var_r30->unk_C =
//      var_r31->unk_C + (var_f31 * (var_r29->unk_C - var_r31->unk_C));
//  var_r30->unk_10 =
//      var_r31->unk_10 + (var_f31 * (var_r29->unk_10 - var_r31->unk_10));
//  temp_f2 = var_r31->unk_14;
//  temp_f1 = var_r29->unk_14;
//  var_r30->unk_14 = temp_f2 + (var_f31 * (temp_f1 - var_r31->unk_14));
//  fn_1_DAF0(var_r27, temp_f1, temp_f2);
//  fn_1_DF6C(var_r27);
//  var_f30 += var_f29;
//  if (!(var_f30 >= 1.0f)) {
//    var_r23 = 1;
//    var_r25 = 0;
//  loop_7:
//    if (var_r25 >= 1) {
//      goto loop_1;
//    }
//    var_r24 = *HuPrcCurrentGet()->property;
//    var_r26 = HuPrcCurrentGet()->property;
//    if (var_r26->unk_0 != 2) {
//      var_r28 = var_r26 + 0x10;
//      sp8 = var_r28->unk_20;
//      Hu3DCameraPosSet(var_r26->unk_8, var_r26->unk_10, var_r28->unk_4,
//                       var_r28->unk_8, var_r28->unk_C, var_r28->unk_10,
//                       var_r28->unk_14, var_r28->unk_18, var_r28->unk_1C,
//                       M2C_ERROR(/* Read from unset reg $f9 */));
//    }
//    HuPrcVSleep();
//    if (var_r24 == *HuPrcCurrentGet()->property) {
//      var_r25++;
//      goto loop_7;
//    }
//  } else {
//    M2C_STRUCT_COPY(var_r30, var_r29, 0x34);
//    var_r27->unk_0 = 0;
//  }
//}
//
//void fn_1_D9AC(void *arg0, float farg0, float farg1, float farg2, float farg3,
//               float farg4, float farg5) {
//  float sp1C;
//  float sp18;
//  float sp14;
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  sp14 = farg3;
//  sp18 = farg4;
//  sp1C = farg5;
//  Hu3DCameraViewportSet(var_r31->unk_8, sp8, spC, sp10, sp14, sp18, sp1C);
//}
//
//void fn_1_DA0C(void *arg0, float farg0, float farg1, float farg2, float farg3) {
//  float sp14;
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  sp14 = farg3;
//  Hu3DCameraPerspectiveSet(var_r31->unk_8, sp8, spC, sp10, sp14);
//}
//
//void fn_1_DA5C(void *arg0, float farg0, float farg1, float farg2, float farg3) {
//  float sp14;
//  float sp10;
//  float spC;
//  float sp8;
//  void *var_r31;
//  u32 var_r30;
//  u32 var_r29;
//  u32 var_r28;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  sp10 = farg2;
//  sp14 = farg3;
//  var_r28 = sp14;
//  var_r29 = sp10;
//  var_r30 = spC;
//  Hu3DCameraScissorSet(var_r31->unk_8, sp8, var_r30, var_r29, var_r28);
//}
//
//void fn_1_DAF0(s32 *arg0) {
//  void *var_r31;
//  void *var_r30;
//  s32 var_r29;
//  s32 *var_r28;
//  double var_f31;
//
//  var_r28 = arg0;
//  if ((var_r28->unk_AC != 0) && ((*HuPadBtn & 0x800) != 0)) {
//    var_r30 = var_r28 + 0x10;
//    var_r30->unk_18 = var_r30->unk_18 + (0.1f * *HuPadSubStkX);
//    var_r30->unk_20 = var_r30->unk_20 - (0.02f * *HuPadSubStkY);
//    var_r30->unk_28 = var_r30->unk_28 - (0.1f * *HuPadStkX);
//    var_r30->unk_24 = var_r30->unk_24 + (0.1f * *HuPadStkY);
//    var_r30->unk_30 = var_r30->unk_30 + (0.1f * *HuPadTrigL);
//    var_r30->unk_30 = var_r30->unk_30 - (0.1f * *HuPadTrigR);
//    for (var_r29 = 0; var_r29 < 3; var_r29++) {
//      var_r31 = (var_r29 * 0x34) + 0x10;
//      var_r31 += var_r28;
//      var_f31 = HuCos(var_r31->unk_24);
//      var_r31->unk_0 = var_r31->unk_18 +
//                       (var_r31->unk_30 * (HuSin(var_r31->unk_28) * var_f31));
//      var_r31->unk_4 =
//          var_r31->unk_1C + (var_r31->unk_30 * -HuSin(var_r31->unk_24));
//      var_f31 = HuCos(var_r31->unk_24);
//      var_r31->unk_8 = var_r31->unk_20 +
//                       (var_r31->unk_30 * (HuCos(var_r31->unk_28) * var_f31));
//      var_f31 = HuSin(var_r31->unk_24);
//      var_r31->unk_C = HuSin(var_r31->unk_28) * var_f31;
//      var_r31->unk_10 = HuCos(var_r31->unk_24);
//      var_f31 = HuSin(var_r31->unk_24);
//      var_r31->unk_14 = HuCos(var_r31->unk_28) * var_f31;
//    }
//  }
//}
//
//void fn_1_DF6C(void) {}
//
//void fn_1_DF70(s32 arg0, s32 arg1) {
//  s32 spC;
//  s32 sp8;
//
//  sp8 = arg0;
//  spC = arg1;
//  WipeCreate(WIPE_MODE_IN, WIPE_TYPE_PREVTYPE, sp8);
//loop_2:
//  if ((spC != 0) && (WipeCheckEnd() != 0)) {
//    HuPrcVSleep();
//    goto loop_2;
//  }
//}
//
//void fn_1_DFCC(s32 arg0, s32 arg1) {
//  s32 spC;
//  s32 sp8;
//
//  sp8 = arg0;
//  spC = arg1;
//  WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_WHITEFADE, sp8);
//loop_2:
//  if ((spC != 0) && (WipeCheckEnd() != 0)) {
//    HuPrcVSleep();
//    goto loop_2;
//  }
//}
//
//void fn_1_E028(s32 arg0) {
//  s32 var_r31;
//  s16 var_r30;
//  s32 var_r29;
//
//  var_r29 = arg0;
//  var_r30 = GameMesCreate(2, 0);
//  if (var_r29 == -1) {
//  loop_3:
//    if (GameMesStatGet(var_r30) != 0) {
//      HuPrcVSleep();
//      goto loop_3;
//    }
//    return;
//  }
//  for (var_r31 = 0; var_r31 < var_r29; var_r31++) {
//    HuPrcVSleep();
//  }
//}
//
//void fn_1_E0B4(s32 arg0) {
//  s32 var_r31;
//  s16 var_r30;
//  s32 var_r29;
//
//  var_r29 = arg0;
//  var_r30 = GameMesCreate(2, 1);
//  if (var_r29 == -1) {
//  loop_3:
//    if (GameMesStatGet(var_r30) != 0) {
//      HuPrcVSleep();
//      goto loop_3;
//    }
//    return;
//  }
//  for (var_r31 = 0; var_r31 < var_r29; var_r31++) {
//    HuPrcVSleep();
//  }
//}
//
//float fn_1_E140(float farg0, float farg1, float farg2) {
//  float spC;
//  float sp8;
//  float var_f31;
//  float var_f30;
//  float var_f29;
//  float temp_f1;
//
//  var_f29 = farg0;
//  sp8 = farg1;
//  spC = farg2;
//  var_f31 = fmod(sp8 - var_f29, 360.0);
//  if (var_f31 < 0.0f) {
//    var_f31 += 360.0f;
//  }
//  if (var_f31 > 180.0f) {
//    var_f31 -= 360.0f;
//  }
//  var_f30 = fmod(var_f29 + (var_f31 * spC), 360.0);
//  if (var_f30 < 0.0f) {
//    var_f30 += 360.0f;
//  }
//  temp_f1 = var_f30;
//  return temp_f1;
//}
//
//void *fn_1_E244(s32 arg0, s32 arg1) {
//  s32 spC;
//  s32 sp8;
//  void *var_r31;
//
//  sp8 = arg0;
//  spC = arg1;
//  var_r31 = HuMemDirectMallocNum(HEAP_HEAP, 0x14, HU_MEMNUM_OVL);
//  var_r31->unk_10 =
//      HuPrcChildCreate(fn_1_E32C, 0x1000, 0x2000, 0, HuPrcCurrentGet());
//  var_r31->unk_10->property = var_r31;
//  var_r31->unk_0 = HuWinExCreateFrame(0.0f, 0.0f, sp8, spC, -1, 1);
//  return var_r31;
//}
//
//void fn_1_E2EC(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  HuWinKill(var_r31->unk_0);
//  HuPrcKill(var_r31->unk_10);
//  HuMemDirectFree(var_r31);
//}
//
//void fn_1_E32C(void) {
//loop_1:
//  HuPrcVSleep();
//  goto loop_1;
//}
//
//void fn_1_E340(void *arg0, float farg0, float farg1) {
//  float spC;
//  float sp8;
//  void *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  var_r31->unk_4 = sp8;
//  var_r31->unk_8 = spC;
//  HuWinPosSet(var_r31->unk_0, sp8, spC);
//}
//
//void fn_1_E388(void *arg0, float *arg1, float *arg2) {
//  *arg1 = arg0->unk_4;
//  *arg2 = arg0->unk_8;
//}
//
//void fn_1_E39C(s16 *arg0, u32 arg1) {
//  u32 sp8;
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  sp8 = arg1;
//  HuWinMesSet(*var_r31, sp8);
//}
//
//void fn_1_E3D4(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  HuWinDispOn(var_r31->unk_0);
//  var_r31->unk_C = 1;
//}
//
//void fn_1_E40C(void *arg0) {
//  void *var_r31;
//
//  var_r31 = arg0;
//  HuWinDispOff(var_r31->unk_0);
//  var_r31->unk_C = 0;
//}
//
//void fn_1_E444(s16 *arg0, s32 arg1) {
//  s32 sp8;
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  sp8 = arg1;
//  HuWinMesColSet(*var_r31, sp8);
//}
//
//void fn_1_E480(s16 *arg0, s16 arg1) {
//  s16 sp8;
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  sp8 = arg1;
//  HuWinMesSpeedSet(*var_r31, sp8);
//}
//
//void fn_1_E4B8(s16 *arg0) {
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  HuWinMesWait(*var_r31);
//}
//
//void fn_1_E4E8(s16 *arg0) {
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  HuWinExOpen(*var_r31);
//}
//
//void fn_1_E518(s16 *arg0) {
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  HuWinExClose(*var_r31);
//}
//
//void fn_1_E548(s16 *arg0, float farg0, float farg1) {
//  float spC;
//  float sp8;
//  s16 *var_r31;
//
//  var_r31 = arg0;
//  sp8 = farg0;
//  spC = farg1;
//  HuWinScaleSet(*var_r31, sp8, spC);
//}
