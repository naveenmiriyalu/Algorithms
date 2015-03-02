#include<iostream>
using namespace std;

class A
{
   public:
   void f()
   {
     cout << "Hello bAse" << endl;
   }
};

class B: public A
{
   public:
   void f( int a =0)
   {
     cout << "hello derived" << endl;
   }
};

int main()
{
   B b;
   b.f();

}
