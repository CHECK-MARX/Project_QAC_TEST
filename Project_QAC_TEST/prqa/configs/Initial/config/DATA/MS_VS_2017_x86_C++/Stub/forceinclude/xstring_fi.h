// vc2019_xstring.h
//

#ifndef INCLUDED_VC2019_XSTRING
#define INCLUDED_VC2019_XSTRING

// builtins used by iosfwd header

#if __QACPP_MAJOR__ < 45

#define __builtin_wmemchr std::wmemchr
#define __builtin_wmemcmp std::wmemcmp
#define __builtin_wcslen std::wcslen
#define __builtin_memcmp std::memcmp
#define __builtin_strlen std::strlen
#define __builtin_char_memchr(_T1,_T2,_T3) static_cast<const char *>(std::memchr(_T1,_T2,_T3))

#else // __QACPP_MAJOR__ < 45

// wmemchr
template <typename CharT> constexpr CharT * __qacpp_memchr_impl ( const CharT * s, const CharT c, PRQA_SIZE_T n )
{
  PRQA_SIZE_T i = 0;
  for ( ; s[ i ] != c && i < n; ++i ) ;
  return i == n ? nullptr : const_cast<CharT *> ( &s[ i ] );
}

constexpr wchar_t * __builtin_wmemchr ( const wchar_t * s, const wchar_t c, PRQA_SIZE_T n ) { return __qacpp_memchr_impl ( s, c, n ); }
constexpr const char * __builtin_char_memchr ( const char * s, const char c, PRQA_SIZE_T n ) { __qacpp_memchr_impl ( s, c, n ); }

// wmemcmp
template <typename CharT> constexpr int __qacpp_memcmp_impl ( const CharT * s1, const CharT * s2, PRQA_SIZE_T n )
{
  PRQA_SIZE_T i = 0;
  for ( ; i < n; ++i )
  {
    if ( s1[ i ] > s2[ i ] ) return 1;
    if ( s1[ i ] < s2[ i ] ) return -1;
  }
  return 0;
}

constexpr int __builtin_wmemcmp ( const wchar_t * s1, wchar_t const * s2, PRQA_SIZE_T n ) { return __qacpp_memcmp_impl ( s1, s2, n ); }
constexpr int __builtin_memcmp ( const char * s1, char const * s2, PRQA_SIZE_T n ) { return __qacpp_memcmp_impl ( s1, s2, n ); }

// wstrlen
template <typename CharT> constexpr PRQA_SIZE_T __qacpp_strlen_impl ( const CharT * s )
{
  PRQA_SIZE_T i = 0;
  for ( ; s[ i ] != '\0'; ++i ) ;
  return i;
}

constexpr int __builtin_wcslen ( const wchar_t * ws ) { return __qacpp_strlen_impl ( ws ); }
constexpr int __builtin_strlen ( const char * s ) { return __qacpp_strlen_impl ( s ); }

#endif

#endif
