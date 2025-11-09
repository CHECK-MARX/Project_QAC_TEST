#define CHAR_BIT      8
#define SCHAR_MIN   (-128)
#define SCHAR_MAX     127
#define UCHAR_MAX     0xff

#ifndef _CHAR_UNSIGNED
    #define CHAR_MIN    SCHAR_MIN
    #define CHAR_MAX    SCHAR_MAX
#else
    #define CHAR_MIN    0
    #define CHAR_MAX    UCHAR_MAX
#endif

#define MB_LEN_MAX    5
#define SHRT_MIN    (-32768)
#define SHRT_MAX      32767
#define USHRT_MAX     0xffff

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647
#define UINT_MAX      0xffffffff

#define LONG_MIN    (-2147483647L - 1)
#define LONG_MAX      2147483647L
#define ULONG_MAX     0xffffffffUL

#define LLONG_MIN   (-9223372036854775807LL-1LL)
#define LLONG_MAX     9223372036854775807LL
#define ULLONG_MAX    0xffffffffffffffffULL

#define _I8_MIN     (-128)
#define _I8_MAX       127
#define _UI8_MAX      0xff

#define _I16_MIN    (-32768)
#define _I16_MAX      32767
#define _UI16_MAX     0xffff

#define _I32_MIN    (-2147483647 - 1)
#define _I32_MAX      2147483647
#define _UI32_MAX     0xffffffffUL

#define _I64_MIN    (-9223372036854775807LL-1LL)
#define _I64_MAX      9223372036854775807LL
#define _UI64_MAX     0xffffffffffffffffULL

#if __QACPP_MAJOR__ < 64

#  define __builtin_nan nan
#  define __builtin_nanf nanf
#  define __builtin_nans nan
#  define __builtin_nansf nanf

#else

constexpr double      __builtin_nan   (const char *) { return __qacpp_nan(double);}
constexpr float       __builtin_nanf  (const char *) { return __qacpp_nan(float);}
constexpr double      __builtin_nans  (const char *) { return __qacpp_nan(double);}
constexpr float       __builtin_nansf (const char *) { return __qacpp_nan(float);}

#endif

// builtins used by limits header
#if ! defined (__QACPP_HUGE_ENUF)
#  define __QACPP_HUGE_ENUF 1e+300 // _HUGE_ENUF*_HUGE_ENUF must overflow
#endif
#define __QACPP_INFINITY ((float)(__QACPP_HUGE_ENUF * __QACPP_HUGE_ENUF))
#define __QACPP_HUGE_VAL ((double)__QACPP_INFINITY)
#define __QACPP_HUGE_VALF ((float)__QACPP_INFINITY)
constexpr double __builtin_huge_val () { return __QACPP_HUGE_VAL; }
constexpr float __builtin_huge_valf () { return __QACPP_HUGE_VALF; }
