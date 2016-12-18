#include <iostream>

using namespace std;
char c_str[17];
int main()
{

cout << "size of char  "<<sizeof(char)<< endl;
cout << "size of int  "<<sizeof(int)<< endl;
cout << "size of long  "<<sizeof(void *)<< endl;
cout << "size of c_str  "<<sizeof(c_str)<< endl;
cout << "size of int  "<<sizeof(int)<< endl;
cout << "size of size_t: "<<sizeof(size_t)<< endl;
int a = 2147483647;
a++;
cout << a << endl;
return 0;
}
