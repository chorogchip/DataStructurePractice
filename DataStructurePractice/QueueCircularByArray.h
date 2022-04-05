#pragma once
#include "IQueue.h"

namespace ch { namespace ds {
template<typename T, std::size_t sz>
class QueueCircularByArray : public I_Queue<T> {

private:
  T arr_[sz];
  std::size_t start_ = 0;
  std::size_t size_ = 0;
public:
  QueueCircularByArray();
  ~QueueCircularByArray();
  void push_back(T data) override;
  T pop_front() override;
  T peek_front() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
  bool is_full() const;

};

template<typename T, std::size_t sz>
QueueCircularByArray<T, sz>::QueueCircularByArray() { }

template<typename T, std::size_t sz>
QueueCircularByArray<T, sz>::~QueueCircularByArray() { }

template<typename T, std::size_t sz>
void QueueCircularByArray<T, sz>::push_back(T data) {
  if(!is_full()) {
    std::size_t ind = start_ + size_;
    if(ind >= sz) {
      ind -= sz;
    }
    arr_[ind] = data;
    size_++;
  }
}

template<typename T, std::size_t sz>
T QueueCircularByArray<T, sz>::pop_front() {
  if(!is_empty()) {
    T tt = arr_[start_];
    start_++;
    if(start_ >= sz) {
      start_ -= sz;
    }
    size_--;
    return tt;
  } else {
    return arr_[0];
  }
}

template<typename T, std::size_t sz>
T QueueCircularByArray<T, sz>::peek_front() const {
  if(!is_empty()) {
    return arr_[start_];
  } else {
    return arr_[0];
  }
}

template<typename T, std::size_t sz>
bool QueueCircularByArray<T, sz>::is_empty() const {
  return size_ == 0;
}

template<typename T, std::size_t sz>
std::size_t QueueCircularByArray<T, sz>::get_size() const {
  return size_;
}

template<typename T, std::size_t sz>
void QueueCircularByArray<T, sz>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(size_));

  std::size_t ind = start_ + size_;
  if(ind >= sz) {
    ind -= sz;
  }
  for(std::size_t i = 0; i != size_; i++) {
    std::cout << arr_[ind];
    putchar('\n');
    ind++;
    if(ind >= sz) {
      ind -= sz;
    }
  }
  putchar('\n');
}

template<typename T, std::size_t sz>
bool QueueCircularByArray<T, sz>::is_full() const {
  return size_ == sz;
}

}}