#pragma once
#include "IDeque.h"

namespace ch { namespace ds {
template<typename T, std::size_t sz>
class DequeByArray : public IDeque<T> {

private:
  T arr_[sz];
  std::size_t front_ = (sz >> 1) - 1;
  std::size_t back_ = (sz >> 1);
public:
  DequeByArray();
  ~DequeByArray();
  void push_back(T data);
  void push_front(T data);
  T pop_back();
  T pop_front();
  T peek_back() const;
  T peek_front() const;
  bool is_empty() const;
  std::size_t get_size() const;
  void display() const;
};  // class DequeByArray


template<typename T, std::size_t sz>
DequeByArray<T, sz>::DequeByArray() { }

template<typename T, std::size_t sz>
DequeByArray<T, sz>::~DequeByArray() { }

template<typename T, std::size_t sz>
void DequeByArray<T, sz>::push_back(T data) {
  arr_[back_] = data;
  back_++;
}

template<typename T, std::size_t sz>
void DequeByArray<T, sz>::push_front(T data) {
  arr_[front_] = data;
  front_--;
}

template<typename T, std::size_t sz>
T DequeByArray<T, sz>::pop_back() {
  if(front_ + 1 == back_) {
    // error
    back_--;
    return arr_[back_];
  }
  back_--;
  return arr_[back_];
}

template<typename T, std::size_t sz>
T DequeByArray<T, sz>::pop_front() {
  if(front_ + 1 == back_) {
    // error
    front_++;
    return arr_[front_];
  }
  front_++;
  return arr_[front_];
}

template<typename T, std::size_t sz>
T DequeByArray<T, sz>::peek_back() const {
  if(front_ + 1 == back_) {
    // error
    return arr_[front_ + 1];
  }
  return arr_[front_ + 1];
}

template<typename T, std::size_t sz>
T DequeByArray<T, sz>::peek_front() const {
  if(front_ + 1 == back_) {
    // error
    return arr_[back_ - 1];
  }
  return arr_[back_ - 1];
}

template<typename T, std::size_t sz>
bool DequeByArray<T, sz>::is_empty() const {
  return front_ + 1 == back_;
}

template<typename T, std::size_t sz>
std::size_t DequeByArray<T, sz>::get_size() const {
  return static_cast<std::size_t>(back_ - (front_ + 1));
}

template<typename T, std::size_t sz>
void DequeByArray<T, sz>::display() const {
  printf("size : %u\n", static_cast<unsigned int>(get_size()));
  for(std::size_t i = front_ + 1; i != back_; i++) {
    std::cout << arr_[i];
    putchar('\n');
  }
  putchar('\n');
}

}}  // namespace ch::da