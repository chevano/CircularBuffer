# CircularBuffer

This program implements a Circular Buffer, recall a Circular Buffer works 
the same as a queue with the added benefit that if the user has filled the buffer. 
The Buffer wraps around and override the front element in the buffer. 

In this implementation of Circular Buffer the head points to the first element, tail points to the last element, and current points to the next empty location.


History
-------
Circular buffers are mostly used as a fixed sized queue. The constant size is useful for embedded systems. They are also useful structures for situations where data production and consumption happens at different rates.
