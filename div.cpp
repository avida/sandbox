#include <iostream>
using namespace std;
int main()
{
    unsigned long long a = 1193368800;
    cout << a / 1024 / (double) 1024 << endl;
    cout << a / (1024 * 1024) << endl;
    return 0;
}