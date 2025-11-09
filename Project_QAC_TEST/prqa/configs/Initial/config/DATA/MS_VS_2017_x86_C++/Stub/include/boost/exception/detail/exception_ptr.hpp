#ifndef STUB_BOOST_TT_EXCEPTION_PTR_HPP_INCLUDED
#define STUB_BOOST_TT_EXCEPTION_PTR_HPP_INCLUDED

#ifdef BOOST_NO_EXCEPTIONS
  #pragma push_macro("BOOST_NO_EXCEPTIONS")
  #undef BOOST_NO_EXCEPTIONS

  #include_next "boost/exception/detail/exception_ptr.hpp"

  #pragma pop_macro("BOOST_NO_EXCEPTIONS")
#else
  #include_next "boost/exception/detail/exception_ptr.hpp"
#endif

#endif