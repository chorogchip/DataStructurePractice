#pragma once
#include "I_Stack.h"
#include "Node_Mono.h"

namespace ch { namespace ds {
template<typename T>
class Stack_Linked : public I_Stack<T> {

private:
  Node_Mono<T>* node_ = nullptr;
public:
  Stack_Linked();
  ~Stack_Linked();
  void push_back(T t) override;
  T pop_back() override;
  T peek_back() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
};

template<typename T>
Stack_Linked<T>::Stack_Linked() { }

template<typename T>
Stack_Linked<T>::~Stack_Linked() {
  Node_Mono<T>* nd_new;
  while(node_) {
    nd_new = node_;
    node_ = node_->next;
    delete nd_new;
  }
}

template<typename T>
void Stack_Linked<T>::push_back(T t) {
  Node_Mono<T>* nd_new = new Node_Mono<T>(t);
  nd_new->next = node_;
  node_ = nd_new;
}

template<typename T>
T Stack_Linked<T>::pop_back() {
  if(node_) {
    Node_Mono<T>* nd_new = node_;
    node_ = node_->next;
    T t = nd_new->t;
    delete nd_new;
    return t;
  }
  return node_->t;
}

template<typename T>
T Stack_Linked<T>::peek_back() const {
  if(node_) {
    return node_->t;
  } else {
    return node_->t;
  }
}

template<typename T>
bool Stack_Linked<T>::is_empty() const {
  return node_ == nullptr;
}

template<typename T>
std::size_t Stack_Linked<T>::get_size() const {
  std::size_t sz = 0U;
  Node_Mono<T>* nd_new = node_;
  while(nd_new) {
    sz++;
    nd_new = nd_new->next;
  }
  return sz;
}

template<typename T>
void Stack_Linked<T>::display() const {

  printf("size : %u\n", static_cast<unsigned int>(get_size()));
  Stack_Linked<T> stlk;
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