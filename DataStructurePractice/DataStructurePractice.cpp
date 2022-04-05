
#include <iostream>
#include "DataStructures.h"

int main() {
    
  ch::ds::QueueByLinked<int> st;

  st.push_back(10);
  st.push_back(20);
  st.push_back(30);
  st.push_back(40);
  st.push_back(50);
  st.display();

  st.pop_front();
  st.pop_front();
  st.push_back(100);
  st.push_back(110);
  st.display();

  ch::ds::DequeByArray<int, 10> dq;

  dq.push_back(10);
  dq.push_back(20);
  dq.push_back(30);
  dq.push_front(-10);
  dq.push_front(-20);
  dq.display();

  dq.pop_back();
  dq.pop_front();
  dq.display();

  dq.pop_front();
  dq.pop_front();
  dq.display();

  return 0;

}
