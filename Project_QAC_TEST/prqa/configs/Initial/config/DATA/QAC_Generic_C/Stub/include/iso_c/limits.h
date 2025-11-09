#ifndef _LIMITS_H
#define _LIMITS_H

#define CHAR_BIT         8
#define SCHAR_MIN        (-127)
#define SCHAR_MAX        127
#define UCHAR_MAX        255

#ifdef _CHAR_IS_SIGNED
#define CHAR_MIN         SCHAR_MIN
#define CHAR_MAX         SCHAR_MAX
#else
#define CHAR_MIN         0
#define CHAR_MAX         UCHAR_MAX
#endif

#define MB_LEN_MAX       1
#define SHRT_MIN         (-32767)
#define SHRT_MAX         32767
#define USHRT_MAX        65535 /* no U */
#define INT_MIN          (-2147483647)
#define INT_MAX          2147483647
#define UINT_MAX         4294967295U
#define LONG_MIN         (-2147483647L)
#define LONG_MAX         2147483647L
#define ULONG_MAX        4294967295UL
#define LLONG_MIN        (-9223372036854775807LL)
#define LLONG_MAX        9223372036854775807LL
#define ULLONG_MAX       18446744073709551615ULL

#pragma PRQA_MACRO_MESSAGES_OFF "UINT_MAX" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "LONG_MIN" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "LONG_MAX" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "ULONG_MAX" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "LLONG_MIN" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "LLONG_MAX" 1278
#pragma PRQA_MACRO_MESSAGES_OFF "ULLONG_MAX" 1278

#endif
