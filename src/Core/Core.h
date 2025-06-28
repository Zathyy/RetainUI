#pragma once

#include <memory>

namespace rui {
  template<typename T>
  using Ref = std::shared_ptr<T>;

  template<typename T, typename... Args>
  constexpr Ref<T> CreateRef(Args &&... args)
  {
    return std::make_shared<T>(std::forward<Args>(args)...);
  }
}

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

#define FORCE_INLINE __forceinline

#define NODISCARD [[nodiscard]]