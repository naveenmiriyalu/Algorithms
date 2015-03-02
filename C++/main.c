#include<iostream>
#include"MaxPriorityQueue.h"

int main()
{
  MaxPQ pq;
  pq.insert(30);
  pq.insert(20);
  pq.insert(50);
  pq.insert(60);
  pq.insert(10);
  pq.printPriorityQueue();
}
