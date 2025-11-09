// qacpp_boost.h
//

#ifndef INCLUDED_QACPP_BOOST
#define INCLUDED_QACPP_BOOST

#if defined (_CPPUNWIND)
#  pragma push_macro("_CPPUNWIND")
#  undef _CPPUNWIND
#  define _QACPP_CPPUNWIND_UNDEF
#endif

#if __has_include("boost/config.hpp")
# include "boost/config.hpp"
#endif
#if defined (BOOST_CONFIG_HPP) && ! defined (BOOST_TYPEOF_EMULATION)
#  define BOOST_TYPEOF_NATIVE
   template<typename __type>
   struct __qacpp_remove_reference
   {
     typedef __type __result;
   };
   template<typename __type>
   struct __qacpp_remove_reference<__type &>
   {
     typedef __type __result;
   };
#  define __typeof__(__expr) __qacpp_remove_reference<decltype((__expr))>::__result
#  define BOOST_TYPEOF_KEYWORD __typeof__

#  define BOOST_TYPEOF_NATIVE_HPP_INCLUDED
#  define BOOST_TYPEOF_MSVC_TYPEOF_IMPL_HPP_INCLUDED
#  include <boost/typeof/typeof.hpp>
#  undef MSVC_TYPEOF_HACK
#  undef BOOST_TYPEOF_NATIVE_HPP_INCLUDED
#  include <boost/typeof/native.hpp>
#  if __has_include(<boost/typeof/decltype.hpp>)
#    include <boost/typeof/decltype.hpp>
#  endif
#endif

#define BOOST_COMPILER_CONFIG "boost/qacpp_boost_compiler.h"

#if defined(_QACPP_CPPUNWIND_UNDEF)
#  pragma pop_macro("_CPPUNWIND")\n
#  undef _QACPP_CPPUNWIND_UNDEF
#endif

#endif
