#include <iostream>


using namespace std;

class Member
{
public:
   ~Member()
{
   cout << __FUNCTION__ << endl;
}
};

class Member2
{
public:
   ~Member2()
{
   cout << __FUNCTION__ << endl;
}
};


class Parent
{
public:
~Parent()

{
  cout << __FUNCTION__ << endl;
}
Member2 m_m2;
Member m_m;

};

int main()
{
Parent p;
cout << "hi" << endl;
return 0;
}