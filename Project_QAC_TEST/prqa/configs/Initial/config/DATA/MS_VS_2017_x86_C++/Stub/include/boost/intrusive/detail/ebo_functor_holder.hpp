#ifndef STUB_BOOST_EBO_FUNCTOR_HOLDER_INCLUDED
#define STUB_BOOST_EBO_FUNCTOR_HOLDER_INCLUDED

#if defined(_M_IX86) && defined(_MSC_EXTENSIONS)
  // temporarily disable _MSC_EXTENSIONS so that BOOST_TT_TEST_MSC_FUNC_SIGS is disabled
  // see boost ticket #4094
  // avoid duplicate definitions of is_unary_or_binary_function_impl
  #pragma push_macro("_MSC_EXTENSIONS")
  #undef _MSC_EXTENSIONS

  #include_next "boost/intrusive/detail/ebo_functor_holder.hpp"

  #pragma pop_macro("_MSC_EXTENSIONS")
#else
  #include_next "boost/intrusive/detail/ebo_functor_holder.hpp"
#endif

#endif