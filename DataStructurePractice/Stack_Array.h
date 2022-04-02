#pragma once
#include "I_Stack.h"

namespace ch { namespace ds {
template<typename T, std::size_t sz>
class Stack_Array : public I_Stack<T> {
  
private:
  T arr_[sz];
  std::size_t size_ = 0;
public:
  Stack_Array();
  ~Stack_Array();
  void push_back(T t) override;
  T pop_back() override;
  T peek_back() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
  bool is_full() const;
};

template<typename T, std::size_t sz>
Stack_Array<T, sz>::Stack_Array() { }

template<typename T, std::size_t sz>
Stack_Array<T, sz>::~Stack_Array() { }

template<typename T, std::size_t sz>
void Stack_Array<T, sz>::push_back(T t) {
  if(!is_full()) {
    arr_[size_] = t;
    size_++;
  }
}

template<typename T, std::size_t sz>
T Stack_Array<T, sz>::pop_back() {
  if(!is_empty()) {
    size_--;
    return arr_[size_]; 
  } else {
    return arr_[0];
  }
}

template<typename T, std::size_t sz>
T Stack_Array<T, sz>::peek_back() const {
  if(!is_empty()) {
    return arr_[size_ - 1]; 
  } else {
    return arr_[0];
  }
}

template<typename T, std::size_t sz>
bool Stack_Array<T, sz>::is_empty() const {
  return size_ == 0;
}

template<typename T, std::size_t sz>
std::size_t Stack_Array<T, sz>::get_size() const {
  return size_;
}

template<typename T, std::size_t sz>
void Stack_Array<T, sz>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(size_));

  for(std::size_t i = 0; i != size_; i++) {
    std::cout << arr_[i];
    putchar('\n');
  }
  putchar('\n');
}

template<typename T, std::size_t sz>
bool Stack_Array<T, sz>::is_full() const {
  return size_ == sz;
}

}}