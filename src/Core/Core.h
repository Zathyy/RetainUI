#pragma once

#ifdef RUI_SHARED
  #ifdef _WIN32
    #ifdef RUI_BUILD
      #define RUI_API __declspec(dllexport)
    #else
      #define RUI_API __declspec(dllimport)
    #endif
  #else
    #ifdef RUI_BUILD
      #define RUI_API __attribute__((visibility("default")))
    #else
      #define RUI_API
    #endif
  #endif
#else
  #define RUI_API
#endif


