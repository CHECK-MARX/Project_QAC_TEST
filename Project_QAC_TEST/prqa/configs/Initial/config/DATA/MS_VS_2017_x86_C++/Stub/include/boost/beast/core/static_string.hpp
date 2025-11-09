#ifndef BEAST_STATIC_STRING_STUB_DEFINED
#define BEAST_STATIC_STRING_STUB_DEFINED


#if defined(PRL_008) && BOOST_VERSION >= 107100
#  include "static_string_stub_107x.hpp"
#else
#  include_next <boost/beast/core/static_string.hpp>
#endif
#endif