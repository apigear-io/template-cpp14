#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
  #define GOLDENMASTER_TESTBED2_EXPORT __attribute__ ((dllexport))
#else
  #define GOLDENMASTER_TESTBED2_EXPORT __declspec(dllexport)
#endif
#else
  #if __GNUC__ >= 4
    #define GOLDENMASTER_TESTBED2_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define GOLDENMASTER_TESTBED2_EXPORT
  #endif
#endif
