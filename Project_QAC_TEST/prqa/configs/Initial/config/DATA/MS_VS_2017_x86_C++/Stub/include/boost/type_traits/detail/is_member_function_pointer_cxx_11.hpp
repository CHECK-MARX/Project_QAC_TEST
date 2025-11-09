#ifndef STUB_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_CXX_11_HPP_INCLUDED
#define STUB_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_CXX_11_HPP_INCLUDED

#if defined(PRL_006) && defined(_M_IX86)
  //Defining "ARM" eliminates the calling-convention overloads
  //
  #define _M_ARM 7

  #include_next "boost/type_traits/detail/is_member_function_pointer_cxx_11.hpp"

  #undef _M_ARM
#else
  #include_next "boost/type_traits/detail/is_member_function_pointer_cxx_11.hpp"
#endif

#endif
