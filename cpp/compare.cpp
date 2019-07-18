#include <string>
#include <iostream>
using namespace std;
int main()
{
   const char* c_str = "Hello";
   cout << "Hi" <<endl;
   if ("Hello" == string(c_str))
      cout << "MATCH!!\n";
   return 0;
}