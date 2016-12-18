#include <iostream> 
using namespace std; 
  
int fA(int N = 0) 
{ 
    static int A = --N; 
cout << A;
    return ++A; 
} 
int fB(int N ) 
{ 
    return N*2+N; 
} 
 
int main() 
{ 
    int res = fB(fA(1));
    cout << res << endl; 
    return 0; 
}