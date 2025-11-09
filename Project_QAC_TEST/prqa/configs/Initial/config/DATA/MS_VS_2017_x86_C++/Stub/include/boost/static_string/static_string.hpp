#ifndef STATIC_STRING_STUB_DEFINED
#define STATIC_STRING_STUB_DEFINED


#if defined(PRL_008) && BOOST_VERSION >= 107300
#  include "static_string_stub_107x.hpp"
#else
#  include_next "boost/static_string/static_string.hpp"
#endif
#endif