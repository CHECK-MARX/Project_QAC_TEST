#pragma PRQA_MESSAGES_OFF 602,850,881,893,895,3410,3412,3429,3432,3435,3436,3443,3453,3456,3602,4601

#ifndef _TGMATH_H
#define _TGMATH_H

#include <math.h>
#include <complex.h>


#pragma PRQA_MACRO_MESSAGES_OFF "__TGM_SelectReal" 895,1082,1176
#pragma PRQA_MACRO_MESSAGES_OFF "__TGM_SelectComplex" 850,895,1082,1149,1176
#pragma PRQA_MACRO_MESSAGES_OFF "__TGM_SelectComplexManip" 895,1082,1149,1176


#define __TGM_Promoted(X, Y)                        \
  /* TODO add support for decimal types to this */  \
  ((X) + (Y))

#define __TGM_SelectReal(V, F)  \
  _Generic ((V)                 \
    , float       : F##f        \
    , double      : F           \
    , long double : F##l        \
/*  , _Decimal32  : F##d32  */  \
/*  , _Decimal64  : F##d64  */  \
/*  , _Decimal128 : F##d128 */  \
    , default     : F           )

#define __TGM_SelectComplexPfx(V, F           \
                             , FPfx, CPfx)    \
  _Generic ((V)                               \
    , float                : FPfx##F##f       \
    , double               : FPfx##F          \
    , long double          : FPfx##F##l       \
/*  , _Decimal32           : FPfx##F##d32  */ \
/*  , _Decimal64           : FPfx##F##d64  */ \
/*  , _Decimal128          : FPfx##F##d128 */ \
    , _Complex float       : CPfx##F##f       \
    , _Complex double      : CPfx##F          \
    , _Complex long double : CPfx##F##l       \
/*  , _Complex _Decimal32  : CPfx##F##d32  */ \
/*  , _Complex _Decimal64  : CPfx##F##d64  */ \
/*  , _Complex _Decimal128 : CPfx##F##d128 */ \
    , default              : FPfx##F          )

// default prefixes are: none for reals, c for complex
#define __TGM_SelectComplex(V, F)          \
  __TGM_SelectComplexPfx (V, F, /*none*/, c)

#define __TGM_SelectComplexManip(V, F)     \
  _Generic ((V)                            \
    , float                : F##f          \
    , double               : F             \
    , long double          : F##l          \
/*  , _Decimal32           : F##d32  */    \
/*  , _Decimal64           : F##d64  */    \
/*  , _Decimal128          : F##d128 */    \
    , _Complex float       : F##f          \
    , _Complex double      : F             \
    , _Complex long double : F##l          \
/*  , _Complex _Decimal32  : F##d32  */    \
/*  , _Complex _Decimal64  : F##d64  */    \
/*  , _Complex _Decimal128 : F##d128 */    \
    , default              : F             )


// complex not supported

#define acospi(X)              (__TGM_SelectReal(X,                     acospi)           (X))
#define asinpi(X)              (__TGM_SelectReal(X,                     asinpi)           (X))
#define atan2pi(X, Y)          (__TGM_SelectReal(__TGM_Promoted(X, Y),  atan2pi)          (X, Y))
#define atan2(X, Y)            (__TGM_SelectReal(__TGM_Promoted(X, Y),  atan2)            (X, Y))
#define atanpi(X)              (__TGM_SelectReal(X,                     atanpi)           (X))
#define cbrt(X)                (__TGM_SelectReal(X,                     cbrt)             (X))
#define ceil(X)                (__TGM_SelectReal(X,                     ceil)             (X))
#define compoundn(X, N)        (__TGM_SelectReal(X,                     compoundn)        (X, N))
#define copysign(X, Y)         (__TGM_SelectReal(__TGM_Promoted(X, Y),  copysign)         (X, Y))
#define cospi(X)               (__TGM_SelectReal(X,                     cospi)            (X))
#define erfc(X)                (__TGM_SelectReal(X,                     erfc)             (X))
#define erf(X)                 (__TGM_SelectReal(X,                     erf)              (X))
#define exp10m1(X)             (__TGM_SelectReal(X,                     exp10m1)          (X))
#define exp10(X)               (__TGM_SelectReal(X,                     exp10)            (X))
#define exp2m1(X)              (__TGM_SelectReal(X,                     exp2m1)           (X))
#define exp2(X)                (__TGM_SelectReal(X,                     exp2)             (X))
#define expm1(X)               (__TGM_SelectReal(X,                     expm1)            (X))
#define fdim(X, Y)             (__TGM_SelectReal(__TGM_Promoted(X, Y),  fdim)             (X, Y))
#define floor(X)               (__TGM_SelectReal(X,                     floor)            (X))
#define fmax(X, Y)             (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmax)             (X, Y))
#define fmaximum(X, Y)         (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmaximum)         (X, Y))
#define fmaximum_mag(X, Y)     (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmaximum_mag)     (X, Y))
#define fmaximum_num(X, Y)     (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmaximum_num)     (X, Y))
#define fmaximum_mag_num(X, Y) (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmaximum_mag_num) (X, Y))
#define fma(X, Y, Z)           (__TGM_SelectReal(__TGM_Promoted(X, \
                                                 __TGM_Promoted(Y, Z)), fma)              (X, Y, Z))
#define fmin(X, Y)             (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmin)             (X, Y))
#define fminimum(X, Y)         (__TGM_SelectReal(__TGM_Promoted(X, Y),  fminimum)         (X, Y))
#define fminimum_mag(X, Y)     (__TGM_SelectReal(__TGM_Promoted(X, Y),  fminimum_mag)     (X, Y))
#define fminimum_num(X, Y)     (__TGM_SelectReal(__TGM_Promoted(X, Y),  fminimum_num)     (X, Y))
#define fminimum_mag_num(X, Y) (__TGM_SelectReal(__TGM_Promoted(X, Y),  fminimum_mag_num) (X, Y))
#define fmod(X, Y)             (__TGM_SelectReal(__TGM_Promoted(X, Y),  fmod)             (X, Y))
#define frexp(X, P)            (__TGM_SelectReal(X,                     frexp)            (X, P))
#define fromfpx(X, N, U)       (__TGM_SelectReal(X,                     fromfpx)          (X, N, U))
#define fromfp(X, N, U)        (__TGM_SelectReal(X,                     fromfp)           (X, N, U))
#define hypot(X, Y)            (__TGM_SelectReal(__TGM_Promoted(X, Y),  hypot)            (X, Y))
#define ilogb(X)               (__TGM_SelectReal(X,                     ilogb)            (X))
#define ldexp(X, N)            (__TGM_SelectReal(X,                     ldexp)            (X, N))
#define lgamma(X)              (__TGM_SelectReal(X,                     lgamma)           (X))
#define llogb(X)               (__TGM_SelectReal(X,                     llogb)            (X))
#define llrint(X)              (__TGM_SelectReal(X,                     llrint)           (X))
#define llround(X)             (__TGM_SelectReal(X,                     llround)          (X))
#define log10p1(X)             (__TGM_SelectReal(X,                     log10p1)          (X))
#define log10(X)               (__TGM_SelectReal(X,                     log10)            (X))
#define log1p(X)               (__TGM_SelectReal(X,                     log1p)            (X))
#define log2p1(X)              (__TGM_SelectReal(X,                     log2p1)           (X))
#define log2(X)                (__TGM_SelectReal(X,                     log2)             (X))
#define logb(X)                (__TGM_SelectReal(X,                     logb)             (X))
#define logp1(X)               (__TGM_SelectReal(X,                     logp1)            (X))
#define lrint(X)               (__TGM_SelectReal(X,                     lrint)            (X))
#define lround(X)              (__TGM_SelectReal(X,                     lround)           (X))
#define nearbyint(X)           (__TGM_SelectReal(X,                     nearbyint)        (X))
#define nextafter(X, Y)        (__TGM_SelectReal(__TGM_Promoted(X, Y),  nextafter)        (X, Y))
#define nextdown(X)            (__TGM_SelectReal(X,                     nextdown)         (X))
#define nexttoward(X, LD)      (__TGM_SelectReal(X,                     nexttoward)       (X, LD))
#define nextup(X)              (__TGM_SelectReal(X,                     nextup)           (X))
#define pown(X, N)             (__TGM_SelectReal(X,                     pown)             (X, N))
#define powr(X, Y)             (__TGM_SelectReal(__TGM_Promoted(X, Y),  powr)             (X, Y))
#define remainder(X, Y)        (__TGM_SelectReal(__TGM_Promoted(X, Y),  remainder)        (X, Y))
#define remquo(X, Y, P)        (__TGM_SelectReal(__TGM_Promoted(X, Y),  remquo)           (X, Y, P))
#define rint(X)                (__TGM_SelectReal(X,                     rint)             (X))
#define rootn(X, N)            (__TGM_SelectReal(X,                     rootn)            (X, N))
#define roundeven(X)           (__TGM_SelectReal(X,                     roundeven)        (X))
#define round(X)               (__TGM_SelectReal(X,                     round)            (X))
#define rsqrt(X)               (__TGM_SelectReal(X,                     rsqrt)            (X))
#define scalbln(X, N)          (__TGM_SelectReal(X,                     scalbln)          (X, N))
#define scalbn(X, N)           (__TGM_SelectReal(X,                     scalbn)           (X, N))
#define sinpi(X)               (__TGM_SelectReal(X,                     sinpi)            (X))
#define tanpi(X)               (__TGM_SelectReal(X,                     tanpi)            (X))
#define tgamma(X)              (__TGM_SelectReal(X,                     tgamma)           (X))
#define trunc(X)               (__TGM_SelectReal(X,                     trunc)            (X))
#define ufromfpx(X, N, U)      (__TGM_SelectReal(X,                     ufromfpx)         (X, N, U))
#define ufromfp(X, N, U)       (__TGM_SelectReal(X,                     ufromfp)          (X, N, U))

// complex supported

#define acos(X)   (__TGM_SelectComplex(X, acos)  (X))
#define asin(X)   (__TGM_SelectComplex(X, asin)  (X))
#define atan(X)   (__TGM_SelectComplex(X, atan)  (X))
#define acosh(X)  (__TGM_SelectComplex(X, acosh) (X))
#define asinh(X)  (__TGM_SelectComplex(X, asinh) (X))
#define atanh(X)  (__TGM_SelectComplex(X, atanh) (X))
#define cos(X)    (__TGM_SelectComplex(X, cos)   (X))
#define sin(X)    (__TGM_SelectComplex(X, sin)   (X))
#define tan(X)    (__TGM_SelectComplex(X, tan)   (X))
#define cosh(X)   (__TGM_SelectComplex(X, cosh)  (X))
#define sinh(X)   (__TGM_SelectComplex(X, sinh)  (X))
#define tanh(X)   (__TGM_SelectComplex(X, tanh)  (X))
#define exp(X)    (__TGM_SelectComplex(X, exp)   (X))
#define log(X)    (__TGM_SelectComplex(X, log)   (X))
#define pow(X, Y) (__TGM_SelectComplex(__TGM_Promoted(X, Y), pow) (X, Y))
#define sqrt(X)   (__TGM_SelectComplex(X, sqrt)  (X))
#define fabs(X)   (__TGM_SelectComplexPfx(X, abs, f, c) (X)) // irregular conjugation

// complex only

#define carg(X)  (__TGM_SelectComplexManip(X, carg)  (X))
#define cimag(X) (__TGM_SelectComplexManip(X, cimag) (X))
#define conj(X)  (__TGM_SelectComplexManip(X, conj)  (X))
#define cproj(X) (__TGM_SelectComplexManip(X, cproj) (X))
#define creal(X) (__TGM_SelectComplexManip(X, creal) (X))

// narrowing result

#define fadd(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), fadd)   (X, Y))
#define dadd(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), dadd)   (X, Y))
#define fsub(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), fsub)   (X, Y))
#define dsub(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), dsub)   (X, Y))
#define fmul(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), fmul)   (X, Y))
#define dmul(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), dmul)   (X, Y))
#define fdiv(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), fdiv)   (X, Y))
#define ddiv(X, Y)   (__TGM_SelectReal(__TGM_Promoted (X, Y), fdiv)   (X, Y))
#define d32add(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d32add) (X, Y))
#define d64add(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d64add) (X, Y))
#define d32sub(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d32sub) (X, Y))
#define d64sub(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d64sub) (X, Y))
#define d32mul(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d32mul) (X, Y))
#define d64mul(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d64mul) (X, Y))
#define d32div(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d32div) (X, Y))
#define d64div(X, Y) (__TGM_SelectReal(__TGM_Promoted (X, Y), d64div) (X, Y))

#define ffma(X, Y, Z)   (__TGM_SelectReal(__TGM_PRomoted (X, __TGM_Promoted (Y, Z)), ddivffma) (X, Y, Z))
#define dfma(X, Y, Z)   (__TGM_SelectReal(__TGM_PRomoted (X, __TGM_Promoted (Y, Z)), ddivffma) (X, Y, Z))
#define d32fma(X, Y, Z) (__TGM_SelectReal(__TGM_PRomoted (X, __TGM_Promoted (Y, Z)), d32fma)   (X, Y, Z))
#define d64fma(X, Y, Z) (__TGM_SelectReal(__TGM_PRomoted (X, __TGM_Promoted (Y, Z)), d64fma)   (X, Y, Z))

#define fsqrt(X)   (__TGM_SelectReal(X, dfmafsqrt) (X))
#define dsqrt(X)   (__TGM_SelectReal(X, dsqrt)     (X))
#define d32sqrt(X) (__TGM_SelectReal(X, d32sqrt)   (X))
#define d64sqrt(X) (__TGM_SelectReal(X, d64sqrt)   (X))


#pragma PRQA_MACRO_MESSAGES_OFF "acospi"           893
#pragma PRQA_MACRO_MESSAGES_OFF "asinpi"           893
#pragma PRQA_MACRO_MESSAGES_OFF "atan2pi"          893
#pragma PRQA_MACRO_MESSAGES_OFF "atan2"            893
#pragma PRQA_MACRO_MESSAGES_OFF "atanpi"           893
#pragma PRQA_MACRO_MESSAGES_OFF "cbrt"             893
#pragma PRQA_MACRO_MESSAGES_OFF "ceil"             893
#pragma PRQA_MACRO_MESSAGES_OFF "compoundn"        893
#pragma PRQA_MACRO_MESSAGES_OFF "copysign"         893
#pragma PRQA_MACRO_MESSAGES_OFF "cospi"            893
#pragma PRQA_MACRO_MESSAGES_OFF "erfc"             893
#pragma PRQA_MACRO_MESSAGES_OFF "erf"              893
#pragma PRQA_MACRO_MESSAGES_OFF "exp10m1"          893
#pragma PRQA_MACRO_MESSAGES_OFF "exp10"            893
#pragma PRQA_MACRO_MESSAGES_OFF "exp2m1"           893
#pragma PRQA_MACRO_MESSAGES_OFF "exp2"             893
#pragma PRQA_MACRO_MESSAGES_OFF "expm1"            893
#pragma PRQA_MACRO_MESSAGES_OFF "fdim"             893
#pragma PRQA_MACRO_MESSAGES_OFF "floor"            893
#pragma PRQA_MACRO_MESSAGES_OFF "fmax"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fmaximum"         893
#pragma PRQA_MACRO_MESSAGES_OFF "fmaximum_mag"     893
#pragma PRQA_MACRO_MESSAGES_OFF "fmaximum_num"     893
#pragma PRQA_MACRO_MESSAGES_OFF "fmaximum_mag_num" 893
#pragma PRQA_MACRO_MESSAGES_OFF "fma"              893
#pragma PRQA_MACRO_MESSAGES_OFF "fmin"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fminimum"         893
#pragma PRQA_MACRO_MESSAGES_OFF "fminimum_mag"     893
#pragma PRQA_MACRO_MESSAGES_OFF "fminimum_num"     893
#pragma PRQA_MACRO_MESSAGES_OFF "fminimum_mag_num" 893
#pragma PRQA_MACRO_MESSAGES_OFF "fmod"             893
#pragma PRQA_MACRO_MESSAGES_OFF "frexp"            893
#pragma PRQA_MACRO_MESSAGES_OFF "fromfpx"          893
#pragma PRQA_MACRO_MESSAGES_OFF "fromfp"           893
#pragma PRQA_MACRO_MESSAGES_OFF "hypot"            893
#pragma PRQA_MACRO_MESSAGES_OFF "ilogb"            893
#pragma PRQA_MACRO_MESSAGES_OFF "ldexp"            893
#pragma PRQA_MACRO_MESSAGES_OFF "lgamma"           893
#pragma PRQA_MACRO_MESSAGES_OFF "llogb"            893
#pragma PRQA_MACRO_MESSAGES_OFF "llrint"           893
#pragma PRQA_MACRO_MESSAGES_OFF "llround"          893
#pragma PRQA_MACRO_MESSAGES_OFF "log10p1"          893
#pragma PRQA_MACRO_MESSAGES_OFF "log10"            893
#pragma PRQA_MACRO_MESSAGES_OFF "log1p"            893
#pragma PRQA_MACRO_MESSAGES_OFF "log2p1"           893
#pragma PRQA_MACRO_MESSAGES_OFF "log2"             893
#pragma PRQA_MACRO_MESSAGES_OFF "logb"             893
#pragma PRQA_MACRO_MESSAGES_OFF "logp1"            893
#pragma PRQA_MACRO_MESSAGES_OFF "lrint"            893
#pragma PRQA_MACRO_MESSAGES_OFF "lround"           893
#pragma PRQA_MACRO_MESSAGES_OFF "nearbyint"        893
#pragma PRQA_MACRO_MESSAGES_OFF "nextafter"        893
#pragma PRQA_MACRO_MESSAGES_OFF "nextdown"         893
#pragma PRQA_MACRO_MESSAGES_OFF "nexttoward"       893
#pragma PRQA_MACRO_MESSAGES_OFF "nextup"           893
#pragma PRQA_MACRO_MESSAGES_OFF "pown"             893
#pragma PRQA_MACRO_MESSAGES_OFF "powr"             893
#pragma PRQA_MACRO_MESSAGES_OFF "remainder"        893
#pragma PRQA_MACRO_MESSAGES_OFF "remquo"           893
#pragma PRQA_MACRO_MESSAGES_OFF "rint"             893
#pragma PRQA_MACRO_MESSAGES_OFF "rootn"            893
#pragma PRQA_MACRO_MESSAGES_OFF "roundeven"        893
#pragma PRQA_MACRO_MESSAGES_OFF "round"            893
#pragma PRQA_MACRO_MESSAGES_OFF "rsqrt"            893
#pragma PRQA_MACRO_MESSAGES_OFF "scalbln"          893
#pragma PRQA_MACRO_MESSAGES_OFF "scalbn"           893
#pragma PRQA_MACRO_MESSAGES_OFF "sinpi"            893
#pragma PRQA_MACRO_MESSAGES_OFF "tanpi"            893
#pragma PRQA_MACRO_MESSAGES_OFF "tgamma"           893
#pragma PRQA_MACRO_MESSAGES_OFF "trunc"            893
#pragma PRQA_MACRO_MESSAGES_OFF "ufromfpx"         893
#pragma PRQA_MACRO_MESSAGES_OFF "ufromfp"          893
#pragma PRQA_MACRO_MESSAGES_OFF "acos"             893
#pragma PRQA_MACRO_MESSAGES_OFF "asin"             893
#pragma PRQA_MACRO_MESSAGES_OFF "atan"             893
#pragma PRQA_MACRO_MESSAGES_OFF "acosh"            893
#pragma PRQA_MACRO_MESSAGES_OFF "asinh"            893
#pragma PRQA_MACRO_MESSAGES_OFF "atanh"            893
#pragma PRQA_MACRO_MESSAGES_OFF "cos"              893
#pragma PRQA_MACRO_MESSAGES_OFF "sin"              893
#pragma PRQA_MACRO_MESSAGES_OFF "tan"              893
#pragma PRQA_MACRO_MESSAGES_OFF "cosh"             893
#pragma PRQA_MACRO_MESSAGES_OFF "sinh"             893
#pragma PRQA_MACRO_MESSAGES_OFF "tanh"             893
#pragma PRQA_MACRO_MESSAGES_OFF "exp"              893
#pragma PRQA_MACRO_MESSAGES_OFF "log"              893
#pragma PRQA_MACRO_MESSAGES_OFF "pow"              893
#pragma PRQA_MACRO_MESSAGES_OFF "sqrt"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fabs"         850,893
#pragma PRQA_MACRO_MESSAGES_OFF "carg"             893
#pragma PRQA_MACRO_MESSAGES_OFF "cimag"            893
#pragma PRQA_MACRO_MESSAGES_OFF "conj"             893
#pragma PRQA_MACRO_MESSAGES_OFF "cproj"            893
#pragma PRQA_MACRO_MESSAGES_OFF "creal"            893
#pragma PRQA_MACRO_MESSAGES_OFF "fadd"             893
#pragma PRQA_MACRO_MESSAGES_OFF "dadd"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fsub"             893
#pragma PRQA_MACRO_MESSAGES_OFF "dsub"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fmul"             893
#pragma PRQA_MACRO_MESSAGES_OFF "dmul"             893
#pragma PRQA_MACRO_MESSAGES_OFF "fdiv"             893
#pragma PRQA_MACRO_MESSAGES_OFF "ddiv"             893
#pragma PRQA_MACRO_MESSAGES_OFF "d32add"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d64add"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d32sub"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d64sub"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d32mul"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d64mul"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d32div"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d64div"           893
#pragma PRQA_MACRO_MESSAGES_OFF "ffma"             893
#pragma PRQA_MACRO_MESSAGES_OFF "dfma"             893
#pragma PRQA_MACRO_MESSAGES_OFF "d32fma"           893
#pragma PRQA_MACRO_MESSAGES_OFF "d64fma"           893
#pragma PRQA_MACRO_MESSAGES_OFF "fsqrt"            893
#pragma PRQA_MACRO_MESSAGES_OFF "dsqrt"            893
#pragma PRQA_MACRO_MESSAGES_OFF "d32sqrt"          893
#pragma PRQA_MACRO_MESSAGES_OFF "d64sqrt"          893


#endif
