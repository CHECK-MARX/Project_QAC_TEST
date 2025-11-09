#ifndef STUB_BOOST_TT_DIAGNOSTIC_INFORMATION_HPP_INCLUDED
#define STUB_BOOST_TT_DIAGNOSTIC_INFORMATION_HPP_INCLUDED

#ifdef BOOST_NO_EXCEPTIONS
  #pragma push_macro("BOOST_NO_EXCEPTIONS")
  #undef BOOST_NO_EXCEPTIONS

  #include_next "boost/exception/diagnostic_information.hpp"

  #pragma pop_macro("BOOST_NO_EXCEPTIONS")
#else
  #include_next "boost/exception/diagnostic_information.hpp"
#endif

#endif