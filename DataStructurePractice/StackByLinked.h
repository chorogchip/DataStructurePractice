#pragma once
#include "IStack.h"
#include "NodeMono.h"

namespace ch { namespace ds {
template<typename T>
class StackByLinked : public IStack<T> {

private:
  Node_Mono<T>* node_ = nullptr;
public:
  StackByLinked();
  ~StackByLinked();
  void push_back(T data) override;
  T pop_back() override;
  T peek_back() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
};

template<typename T>
StackByLinked<T>::StackByLinked() { }

template<typename T>
StackByLinked<T>::~StackByLinked() {
  Node_Mono<T>* nd_old;
  while(node_) {
    nd_old = node_;
    node_ = node_->next;
    delete nd_old;
  }
}

template<typename T>
void StackByLinked<T>::push_back(T data) {
  Node_Mono<T>* nd_new = new Node_Mono<T>(data);
  nd_new->next = node_;
  node_ = nd_new;
}

template<typename T>
T StackByLinked<T>::pop_back() {
  if(node_) {
    Node_Mono<T>* nd_old = node_;
    node_ = node_->next;
    T data = nd_old->t;
    delete nd_old;
    return data;
  }
  return node_->t;
}

template<typename T>
T StackByLinked<T>::peek_back() const {
   return node_->t;
}

template<typename T>
bool StackByLinked<T>::is_empty() const {
  return node_ == nullptr;
}

template<typename T>
std::size_t StackByLinked<T>::get_size() const {
  std::size_t sz = 0U;
  Node_Mono<T>* nd_new = node_;
  while(nd_new) {
    sz++;
    nd_new = nd_new->next;
  }
  return sz;
}

template<typename T>
void StackByLinked<T>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(get_size()));
  StackByLinked<T> stlk;
  Node_Mono<T>* nd_new = node_;
  while(nd_new) {
    stlk.push_back(nd_new->t);
    nd_new = nd_new->next;
  }
  while(!stlk.is_empty()) {
    std::cout << stlk.pop_back();
    putchar('\n');
  }
  putchar('\n');

}

}}