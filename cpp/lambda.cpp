#include <iostream>
#include <functional>

using namespace std;

std::function <int()> lambda;
void f ()
{
   int a = 2;  
   cout << "f a addr = " << &a << endl;
}

int main()
{
   int a = 2;
   int b = 400;
   int c = 20;
   int d = 20;
   lambda = [b]()->int
   {
      int a = 2;
      cout << "lambdaa addr = " << &a << endl;
      cout << "lambdaa b addr = " << &b << endl;
      return 234;
   };

   auto n = new int;
   auto n2 = new int;
   cout << "Hello" << endl;
   cout << "a addr = " << &a << endl;
   cout << "b addr = " << &b << endl;
   cout << "c addr = " << &c << endl;
   cout << "d addr = " << &d << endl;
   cout << "n addr = " << n << endl;
   cout << "n2 addr = " << n2 << endl;
   f();
   cout << lambda() << endl;
   return 0;
}

