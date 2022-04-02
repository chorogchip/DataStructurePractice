#pragma once
#include "I_Stack.h"
#include "Node_Mono.h"

namespace ch { namespace ds {
template<typename T>
class Queue_Linked : public I_Queue<T> {

private:
  Node_Mono<T>* front_ = nullptr;
  Node_Mono<T>* back_ = nullptr;
public:
  Queue_Linked();
  ~Queue_Linked();
  void push_back(T t) override;
  T pop_front() override;
  T peek_front() const override;
  bool is_empty() const override;
  std::size_t get_size() const override;
  void display() const override;
};

template<typename T>
Queue_Linked<T>::Queue_Linked() { }

template<typename T>
Queue_Linked<T>::~Queue_Linked() {
  Node_Mono<T>* nd_new;
  while(front_) {
    nd_new = front_;
    front_ = front_->next;
    delete nd_new;
  }
}

template<typename T>
void Queue_Linked<T>::push_back(T t) {
  
}

template<typename T>
T Queue_Linked<T>::pop_front() {

}

template<typename T>
T Queue_Linked<T>::peek_front() const {

}

template<typename T>
bool Queue_Linked<T>::is_empty() const {

}

template<typename T>
std::size_t Queue_Linked<T>::get_size() const {

}

template<typename T>
void Queue_Linked<T>::display() const {

}

}}