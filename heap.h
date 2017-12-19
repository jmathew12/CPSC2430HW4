// James Mathew
// heap.h
// This is min Heap

#ifndef HEAP_H
#define HEAP_H

class Heap
{
 public:
  // constructor, creates a heap with val as its first value
  Heap(int val);
  
  // destructor
  ~Heap();
  
  // assignment operator
  Heap & operator = (const Heap& rhs);
  
  // copy constructor
  Heap(const Heap& s);
  
  // insert val into the heap and reorganizes the heap based on the val
  void insert(int val);
  
  // removes the smallest value from the heap and returns it,
  //	reorganizes the heap after the removal of the smallest value
  // returns -1 when the heap is empty.
  int remove();
  
  // removes all intances of val from the heap and reorganizes it
  void flush(int val);
  
 private:
  // moves the first value in the heap to the right position
  void percolateDown(int hole, int* nums, int size);
  
  //
  int remove(int hole, int*& nums, int& size);
  
  // makes the heap bigger when full
  void resize(int*& nums, int size);
  
  // the list that keeps all the vales in the heap
  int* nums;
  
  // size of the heap
  int size;
		
  // maximun number of values at a time
  int capacity;
  
};
#endif
