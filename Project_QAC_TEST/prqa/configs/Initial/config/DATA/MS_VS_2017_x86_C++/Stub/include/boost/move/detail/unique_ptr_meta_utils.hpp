#ifndef STUB_BOOST_UNIQUE_PTR_META_UTILS_INCLUDED
#define STUB_BOOST_UNIQUE_PTR_META_UTILS_INCLUDED

#if defined(_M_IX86) && defined(_MSC_EXTENSIONS)
  // temporarily disable _MSC_EXTENSIONS so that BOOST_MOVE_TT_TEST_MSC_FUNC_SIGS is disabled
  // avoid duplicate definitions of is_unary_function_impl
  #pragma push_macro("_MSC_EXTENSIONS")
  #undef _MSC_EXTENSIONS

  #include_next "boost/move/detail/unique_ptr_meta_utils.hpp"

  #pragma pop_macro("_MSC_EXTENSIONS")
#else
  #include_next "boost/move/detail/unique_ptr_meta_utils.hpp"
#endif

#endif