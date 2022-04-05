#pragma once
#include "IQueue.h"
#include "NodeMono.h"

namespace ch { namespace ds {
template<typename T>
class QueueByLinked : public I_Queue<T> {

private:
  Node_Mono<T>* front_ = nullptr;
  Node_Mono<T>* back_ = nullptr;
public:
  QueueByLinked();
  ~QueueByLinked();
  void push_back(T data) override;
  T pop_front() override;
  T peek_front() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
};

template<typename T>
QueueByLinked<T>::QueueByLinked() { }

template<typename T>
QueueByLinked<T>::~QueueByLinked() {
  Node_Mono<T>* nd_old;
  while(front_) {
    nd_old = front_;
    front_ = front_->next;
    delete nd_old;
  }
}

template<typename T>
void QueueByLinked<T>::push_back(T data) {
  Node_Mono<T>* nd_new = new Node_Mono<T>(data);
  if(front_ == nullptr) {
    front_ = nd_new;
    back_ = nd_new;
  } else {
    back_->next = nd_new;
    back_ = nd_new;
  }
}

template<typename T>
T QueueByLinked<T>::pop_front() {
  //fr, ed 같을떄 예외
  if(front_ == nullptr) {
    return front_->t;  // error
  }
  if(front_ == back_) {
    T data = front_->t;
    delete front_;
    front_ = nullptr;
    back_ = nullptr;
    return data;
  }
  Node_Mono<T>* nd_old = front_;
  front_ = front_->next;
  T data = nd_old->t;
  delete nd_old;
  return data;
}

template<typename T>
T QueueByLinked<T>::peek_front() const {
  return front_->t;
}

template<typename T>
bool QueueByLinked<T>::is_empty() const {
  return front_ == nullptr;
}

template<typename T>
std::size_t QueueByLinked<T>::get_size() const {
  std::size_t sz = 0U;
  Node_Mono<T>* nd_new = front_;
  while(nd_new) {
    sz++;
    nd_new = nd_new->next;
  }
  return sz;
}

template<typename T>
void QueueByLinked<T>::display() const {
  printf("size : %u\n", static_cast<unsigned int>(get_size()));
  Node_Mono<T>* nd_new = front_;
  while(nd_new) {
    std::cout << nd_new->t;
    putchar('\n');
    nd_new = nd_new->next;
  }
  putchar('\n');
}

}}