
#include <iostream>
#include "StackByArray.h"
#include "StackByLinked.h"
#include "QueueCircularByArray.h"
#include "QueueByLinked.h"

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

  return 0;

}
