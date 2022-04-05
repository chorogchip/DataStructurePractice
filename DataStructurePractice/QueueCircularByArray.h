#pragma once
#include "IQueue.h"

namespace ch { namespace ds {
template<typename T, std::size_t sz>
class QueueCircularByArray : public I_Queue<T> {

private:
  T arr_[sz];
  std::size_t front_ = 0;
  std::size_t rear_ = 0;
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
    arr_[++rear_] = data;
    if(rear_ == sz) {
      rear_ = 0;
    }
  }
}

template<typename T, std::size_t sz>
T QueueCircularByArray<T, sz>::pop_front() {
  if(!is_empty()) {
    std::size_t ind = front_ + 1;
    if(ind == sz) {
      ind = 0;
      front_ = 0;
    } else {
      front_++;
    }
    return arr_[ind];
  } else {
    return arr_[0];  // error : empty
  }
}

template<typename T, std::size_t sz>
T QueueCircularByArray<T, sz>::peek_front() const {
  if(!is_empty()) {
    std::size_t ind = front_ + 1;
    if(ind == sz) {
      ind = 0;
    }
    return arr_[ind];
  } else {
    return arr_[0];  // error : empty
  }
}

template<typename T, std::size_t sz>
bool QueueCircularByArray<T, sz>::is_empty() const {
  return rear_ + 1 == front_ || rear_ + 1 == front_ + sz;
}

template<typename T, std::size_t sz>
std::size_t QueueCircularByArray<T, sz>::get_size() const {
  int szz = static_cast<int>(rear_) - static_cast<int>(front_);
  if(szz < 0) {
    szz += sz;
  }
  return szz;
}

template<typename T, std::size_t sz>
void QueueCircularByArray<T, sz>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(get_size()));
  if(front_ == rear_) {
    putchar('\n');
    return;
  }
  std::size_t ind = front_ + 1;
  if(ind == sz) {
    ind = 0;
  }

  if(ind > rear_) {
    for(std::size_t i = ind; i != sz; i++) {
      std::cout << arr_[i];
      putchar('\n');
    }
    for(std::size_t i = 0; i != rear_ + 1; i++) {
      std::cout << arr_[i];
      putchar('\n');
    }
  } else {
    for(std::size_t i = ind; i != rear_ + 1; i++) {
      std::cout << arr_[i];
      putchar('\n');
    }
  }
  putchar('\n');
}

template<typename T, std::size_t sz>
bool QueueCircularByArray<T, sz>::is_full() const {
  return rear_ + 1 == front_ || front_ + sz == rear_ + 1;
}

}}