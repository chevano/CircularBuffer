#include <iostream>
#include "CircularBuffer.hpp"

using namespace std;

int main() {

   CircularBuffer<int, 15> buffer;

   cout << "\nBuffer details "  << "at initialization" << endl << endl;
   cout << "Buffer size is " << buffer.size() << endl;
   cout << "Buffer capacity is " << buffer.capacity() << endl;

   for(int i = 0; i < 15; i++)
      buffer.push_back(i);

   cout << "\nBuffer details "  << "before popping" << endl << endl;
   cout << "Buffer size is " << buffer.size() << endl;
   cout << "Buffer capacity is " << buffer.capacity() << endl;

   while(!buffer.empty()) {
      cout << "popping: " << buffer.pop() << "\n";
   }
   
   cout << "\nBuffer details "  << "after popping" << endl << endl;
   cout << "Buffer size is " << buffer.size() << endl;
   cout << "Buffer capacity is " << buffer.capacity() << endl;

   buffer.append(25);
 
   return 0;
}