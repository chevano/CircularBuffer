#ifndef _CircularBuffer_hpp
#define _CircularBuffer_hpp

#include <iostream>
#include <array>
#include <stdexcept>

template <typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
   private:
      Container container;
      int _head;
      int _current;
      int _tail;
      int _size;
      int _capacity;

   public:
      CircularBuffer() : _head(0), _current(0), _tail(0), _size(0), _capacity(cap) {}

      T& head() {
         // at throws an exception if index is out of bound
         return container.at(_head);
      }
      
      T& tail() {
         return container.at(_tail);
      }

      T const& head() const {
         return container.at(_head);
      }

      T const& tail() const {
         return container.at(_tail);
      }

      // Doesn't throw an exception
      void push_back(T val) noexcept {
         if(_current >= _capacity)
            _current = 0;

         container.at(_current++) = val;
         _tail = _current - 1;

         // Preserves the order
         if(_size++ >= _capacity) {
            _size = _capacity;
            _head++;
            
            if(_head >= _capacity)
               _head = 0;
         }
      }

      void append(T val) {
         if(full())
            throw std::overflow_error("Buffer is Full");
         push_back(val);
      }

      // Removes the tail elements
      T pop() {
         if(empty())
            throw std::underflow_error("Buffer is Empty");

         T val = container.at(_head);

         _size--;
         _head++;

         if(_head >= _capacity)
            _head = 0;

         return val;
      }

      std::size_t size() const noexcept {
         return _size;
      }

      std::size_t capacity() const noexcept {
         return _capacity;
      }

      bool empty() const noexcept {
         return _size <= 0;
      }

      bool full() const noexcept {
         return _capacity <= _size;
      }
};

#endif