#pragma once
#include <cstddef>

//#define DEBUG_COUNT
#ifdef DEBUG_COUNT
  static int count = 0;
#endif

namespace ch { namespace ds {
template<typename T>
struct Node_Mono {
  Node_Mono(const T& t);
#ifdef DEBUG_COUNT
  ~Node_Mono();
#endif
  Node_Mono* next = nullptr;
  T t;
};

template<typename T>
Node_Mono<T>::Node_Mono(const T& tt) {
  t = tt;
#ifdef DEBUG_COUNT
  count++;
#endif
}

#ifdef DEBUG_COUNT
template<typename T>
Node_Mono<T>::~Node_Mono() {
  count--;
  printf("node : %d\n", count);
}
#endif

}}