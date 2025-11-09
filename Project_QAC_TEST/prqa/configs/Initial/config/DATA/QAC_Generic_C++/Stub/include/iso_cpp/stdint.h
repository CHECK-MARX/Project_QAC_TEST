/* "stdint.h"
 */

#ifndef __QAC_INCLUDE_stdint_h__
#define __QAC_INCLUDE_stdint_h__

// types

typedef   signed char      int8_t;
typedef   signed short     int16_t;
typedef   signed int       int32_t;
typedef   signed long long int64_t;

typedef   signed char      int_fast8_t;
typedef   signed short     int_fast16_t;
typedef   signed int       int_fast32_t;
typedef   signed long long int_fast64_t;

typedef   signed char      int_least8_t;
typedef   signed short     int_least16_t;
typedef   signed int       int_least32_t;
typedef   signed long long int_least64_t;

typedef   signed long long intmax_t;
typedef   signed long      intptr_t;

typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef unsigned char      uint_fast8_t;
typedef unsigned short     uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned long long uint_least64_t;

typedef unsigned long long uintmax_t;
typedef unsigned long      uintptr_t;

// literal macros

#define INT8_C(c)  c
#define INT16_C(c) c
#define INT32_C(c) c
#define INT64_C(c) c ## LL

#define UINT8_C(c)  c
#define UINT16_C(c) c
#define UINT32_C(c) c ## U
#define UINT64_C(c) c ## ULL

#define INTMAX_C(c) c ## LL
#define UINTMAX_C(c)  c ## ULL

#endif // __QAC_INCLUDE_stdint_h__
