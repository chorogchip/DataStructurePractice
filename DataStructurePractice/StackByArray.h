#pragma once
#include "IStack.h"

namespace ch { namespace ds {
template<typename T, std::size_t sz>
class StackByArray : public IStack<T> {
  
private:
  T arr_[sz];
  std::size_t size_ = 0;
public:
  StackByArray();
  ~StackByArray();
  void push_back(T data) override;
  T pop_back() override;
  T peek_back() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
  bool is_full() const;
};

template<typename T, std::size_t sz>
StackByArray<T, sz>::StackByArray() { }

template<typename T, std::size_t sz>
StackByArray<T, sz>::~StackByArray() { }

template<typename T, std::size_t sz>
void StackByArray<T, sz>::push_back(T data) {
  if(!is_full()) {
    arr_[size_] = data;
    size_++;
  }
  // else error
}

template<typename T, std::size_t sz>
T StackByArray<T, sz>::pop_back() {
  if(!is_empty()) {
    size_--;
    return arr_[size_]; 
  } else {
    return arr_[0];  // error
  }
}

template<typename T, std::size_t sz>
T StackByArray<T, sz>::peek_back() const {
  return arr_[size_ - 1]; 
}

template<typename T, std::size_t sz>
bool StackByArray<T, sz>::is_empty() const {
  return size_ == 0;
}

template<typename T, std::size_t sz>
std::size_t StackByArray<T, sz>::get_size() const {
  return size_;
}

template<typename T, std::size_t sz>
void StackByArray<T, sz>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(size_));

  for(std::size_t i = 0; i != size_; i++) {
    std::cout << arr_[i];
    putchar('\n');
  }
  putchar('\n');
}

template<typename T, std::size_t sz>
bool StackByArray<T, sz>::is_full() const {
  return size_ == sz;
}

}}