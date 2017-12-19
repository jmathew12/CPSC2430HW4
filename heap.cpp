// James Mathew
// heap.cpp

#include "heap.h"
#include <iostream>
using namespace std;

Heap :: Heap(int val)
{
  capacity = 1;
  size = 1;
  nums = new int[capacity];
  nums[1] = val;
}

Heap :: ~Heap()
{
  delete [] nums;
  nums = nullptr;
}

Heap& Heap :: operator = (const Heap& other)
{
  if (this != &other) {
    size = other.size;
    capacity = other.capacity;
    nums = new int[capacity];
    for (int i = 1; i <= size; i++) {
      nums[i] = other.nums[i];
    }
  }
  return *this;
}

Heap :: Heap(const Heap& other)
{
  *this = other;
}

void Heap :: insert(int val)
{
  if (size == capacity) {
    resize(nums, size);
  }
  int hole = size + 1;
  while (hole > 1 && val < nums[hole / 2]) {
    nums[hole] = nums[hole / 2];
    hole = hole / 2;
  }
  nums[hole] = val;
  size++;
}


void Heap :: resize(int*& nums, int size)
{	
  (capacity *= 2)++;
  int* temp = new int[capacity];
  for (int i = 1; i <= size; i++) {
    temp[i] = nums[i];
  }
  delete [] nums;
  nums = nullptr;
  nums = temp;
}

int Heap :: remove()
{
  if (size == 0) {
    return -1; // since returning false will return 0
  }
  return remove(1, nums, size);
}
int Heap :: remove(int hole, int*& nums, int& size) {
  
  int x = nums[hole];
  nums[hole] = nums[size];
  size--;
  percolateDown(hole, nums, size);
  return x;
}
void Heap :: percolateDown(int hole, int* nums, int size) 
{
  int temp = nums[hole];
  while ((hole * 2 <= size && temp > nums[hole * 2]) || (hole * 2 + 1 <= 
                                                         size && temp > nums[hole * 2 + 1])) {
    if (hole * 2 + 1 <= size && nums[hole * 2 + 1] < nums[hole * 2]) {
      nums[hole] = nums[hole*2+1];
      hole = hole * 2 + 1;
    } else {
      nums[hole] = nums[hole * 2];
      hole = hole * 2;
    }
  }
  nums[hole] = temp;
  
}

void Heap :: flush(int val)
{
  for (int i = 1; i <= size; i++) {
    if (val == nums[i]) {
      remove(i, nums, size);
      i = 0;
    }
  }
}	
