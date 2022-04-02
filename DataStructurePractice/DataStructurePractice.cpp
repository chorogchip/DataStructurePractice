
#include <iostream>
#include "Stack_Array.h"
#include "Stack_Linked.h"
#include "CircularQueue_Array.h"

int main() {
    
  ch::ds::CircularQueue_Array<int, 5> st;

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

  return 0;

}
