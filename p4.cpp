// James Mathew
// p4.cpp
// This program tests the heap class and its functions to see if it is working properly. 

#include <iostream>
#include "heap.h"
using namespace std;

int main ()
{
  srand(time(0));	
  int maxNums = 15;
  int maxNum = 10;
  int val = rand() % maxNum;
  
  cout << "inserting all the following values " << endl;
  Heap nums(val);
  cout << val << " ";
  for (int i = 0; i < maxNums - 1; i++) {
    val = rand() % maxNum;
	
    nums.insert(val); // testing insert
    cout << val << " ";
  }
  cout << endl;
  
  cout << "removing all the following values " << endl;
  // removing everying and one more to test if both insert and remove works
  // should return 0 at the end.
  int x = nums.remove();
  while(x != -1) {
    cout << x << " ";
    x = nums.remove();
  }
  cout << endl;
  
  cout << "inserting all the following values " << endl;
  int y  = 5;
  nums.insert(y);
  cout << y << " ";
  //inserting a lot of numbers again
  for (int i = 0; i < maxNums - 1; i++) {
    val = rand() % maxNum;
    nums.insert(val); // testing insert
    cout << val << " ";
  }
  cout << endl;
  
  
  cout << "flushing " << y << endl;
  nums.flush(y); 
  cout << "checking to see if all " << y << "s has been removed"<< endl;
  // removing everything to see if flush worked
  x = nums.remove();
  while(x != -1) {
    cout << x << " ";
    x = nums.remove();
  }
  cout << endl;
  
  Heap copyNums = Heap(nums);
  Heap assNums = nums;
  
  //inserting new values to num
  for (int i = 0; i < maxNums - 1; i++) {
    val = rand() % maxNum;
    nums.insert(val);
  }
  cout << "removing all values from nums " << endl;
  // removing all values from num
  x = nums.remove();
  while(x != -1) {
    cout << x << " ";
    x = nums.remove();
  }
  cout << endl;
  
  //inserting new values to num
  for (int i = 0; i < maxNums - 1; i++) {
    val = rand() % maxNum;
    assNums.insert(val);
  }
  cout << "removing all values from assNums " << endl;
  // removing all values from assNum
  x = assNums.remove();
  while(x != -1) {
    cout << x << " ";
    x = assNums.remove();
  }
  cout << endl;
  
  //inserting new values to copyNum
  for (int i = 0; i < maxNums - 1; i++) {
    val = rand() % maxNum;
    copyNums.insert(val);
  }
  cout << "removing all values from copyNums " << endl;
  // removing all values from copyNum
  x = copyNums.remove();
  while(x != -1) {
    cout << x << " ";
    x = copyNums.remove();
  }
  cout << endl;
  return 0;
}
