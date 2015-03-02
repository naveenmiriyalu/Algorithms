#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class A
{
  public:
  static unsigned count ;
  static unsigned heap ;

  void* operator new(size_t size)
  {
    void *temp =  malloc(size);
	increment_heap();
	return temp;
  }

  void operator delete( void *p)
  {
    A::heap--;
	free(p);
  }

  static void increment_heap()
  {
     heap++;
  }

  A()
  {
    count++;
	x =0;
  }

  A(const A& rhs)
  {
    x = rhs.x;
	count++;
  
  }
  private:
  int x;
};

unsigned A::count =0;
unsigned A::heap =0;

int main()
{
  A *a = new A();
  cout << A::count << endl;
  cout << A::heap << endl;

}
