#ifndef __MAX_PRIORITY_QUEUE__NAVEEN 
#define __MAX_PRIORITY_QUEUE__NAVEEN 
/*
Author: Naveen
Date: January 16 2015
Description: A Max priority queue class that stores integers. 
*/

/*
Test cases:
 1. What if repetition occurs? 6 followed by 6 . What should we do ?
    a. Lazy deletion approach 
	b. Keep count 
	c. Any other approach
 2. When will it fail?? What scenarios it may fail?
 
*/

#include<iostream>
#include<vector>
using namespace std;
#define INITIAL_CAPACITY 100

class MaxPQ 
{
  private:
  vector<int> array;
  void swim(size_t curr_pos);
  void printArray(size_t count) const;
  bool isEmpty() const;
  size_t current_size;
  

  public:
  MaxPQ();
  void insert(const int element);
  size_t size() const;
  void printPriorityQueue() const;
};
#endif

