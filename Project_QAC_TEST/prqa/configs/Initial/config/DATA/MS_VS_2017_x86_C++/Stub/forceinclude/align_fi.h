#ifndef STDCPP_ALIGN_CHECK
#define STDCPP_ALIGN_CHECK

#if defined(PRQA_STDCPP_DEFAULT_NEW_ALIGNMENT)
# if !defined(__cpp_aligned_new)
    // __cpp_aligned_new is only available if PRQA_STDCPP_DEFAULT_NEW_ALIGNMENT has
    // been declared implicitly. It would NOT be declared if -cpp14neon+ were used
    // for example.
#   define __cpp_aligned_new 201606L
# endif

# if (defined(__STDCPP_DEFAULT_NEW_ALIGNMENT__))

#   if __STDCPP_DEFAULT_NEW_ALIGNMENT__ != PRQA_STDCPP_DEFAULT_NEW_ALIGNMENT
#     error "__STDCPP_DEFAULT_NEW_ALIGNMENT__ does not match QACPP alignment from '-a default_new'."
#   endif

# else

#   define __STDCPP_DEFAULT_NEW_ALIGNMENT__ PRQA_STDCPP_DEFAULT_NEW_ALIGNMENT

# endif

#endif

#endif
