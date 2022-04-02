#pragma once
#include <cstddef>
#include <iostream>

namespace ch { namespace ds {
template<typename T>
class I_Stack {

public:
  virtual void push_back(T t) = 0;
  virtual T pop_back() = 0;
  virtual T peek_back() const = 0;
  virtual bool is_empty() const = 0;
  virtual std::size_t get_size() const = 0;
  virtual void display() const = 0;

};}}