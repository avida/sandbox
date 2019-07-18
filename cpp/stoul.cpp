#include <iostream>
#include <string>
using namespace std;
int main()
{
string ss = "123bft";
size_t  s;
auto out = stoull(ss, &s, 16);
cout << "hi" << endl;
return 0;
}