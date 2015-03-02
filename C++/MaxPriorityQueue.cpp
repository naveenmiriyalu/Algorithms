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
#include"MaxPriorityQueue.h"
using namespace std;

MaxPQ::MaxPQ():current_size(0)
{
   array.reserve(INITIAL_CAPACITY); 
   array.push_back(-1);
}

void MaxPQ::insert(const int element)
{
  array.push_back(element);
  current_size++;
  swim(current_size);
}

void MaxPQ::swim(size_t curr_pos)
{
   size_t parent_pos = curr_pos/2;
   int  element = array[curr_pos];

   while( ( parent_pos !=0 ) && (element > array[parent_pos]) )
   {
	 array[curr_pos] = array[parent_pos];
     curr_pos = parent_pos;
	 parent_pos /= 2;
   }
    array[curr_pos] = element;
}

bool MaxPQ::isEmpty() const
{
  return (current_size == 0);
}

void MaxPQ::printArray(size_t count) const
{
  for(size_t i = count ;(count > 0) && ( i <= size()) ; i++,count--)
  {
    cout << array[i] << " " ;
  }
  cout << endl;
}

void MaxPQ::printPriorityQueue() const
{
  if(isEmpty()) {
    cout << "MaxPQ empty nothing to print" << endl;
  }
  else {
  	cout << "Printing MaxPQ " << endl;
  	for(size_t count = 1; count <= size(); count *= 2)
  	printArray(count);
  }
}

size_t MaxPQ::size() const
{
  return current_size;
}



