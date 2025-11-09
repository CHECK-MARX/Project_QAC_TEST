// stub to provide limited __has_cpp_attribute support
//

#if ! defined (__has_cpp_attribute)

// Implementation of __has_cpp_attribute using the preprocessor
#  define __qacpp_has_cpp_attribute_helper_1(_) 0
#  define __qacpp_has_cpp_attribute_helper_2(_,value) value

#  define __qacpp_get_has_cpp_attribute_helper(_0,_1,_2,NAME,...) NAME
#  define __qacpp_has_cpp_attribute_helper(...) __qacpp_get_has_cpp_attribute_helper( 0, \
                                                                                      __VA_ARGS__, \
                                                                                      __qacpp_has_cpp_attribute_helper_2, \
                                                                                      __qacpp_has_cpp_attribute_helper_1, \
                                                                                      __qacpp_has_cpp_attribute_helper_0 )(__VA_ARGS__)

#  define __has_cpp_attribute(x) __qacpp_has_cpp_attribute_helper( PRQA_HAS_##x##_CPP_ATTRIBUTE )

// Attributes that are provided by QAC++
#  define PRQA_HAS_noreturn_CPP_ATTRIBUTE       noreturn, 1
#  define PRQA_HAS_nodiscard_CPP_ATTRIBUTE      nodiscard, 1
#  define PRQA_HAS_maybe_unused_CPP_ATTRIBUTE   maybe_unused, 1

#endif // if ! defined (__has_cpp_attribute)
