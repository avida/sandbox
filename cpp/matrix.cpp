#include <iostream>
#include <functional>
#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/foreach.hpp>
                           
using namespace std;


int main()
{
   using namespace boost::numeric::ublas;
   matrix<double> m (4, 4);
   matrix<double> m2 (4, 1);
   m2.clear();
   m2(0,0) = 2;
   m2(1,0) = 1;
   cout << m2 << endl;
   
   m.clear();
   m(0,0) = 4;
   m(0,1) = 1;
   m(1,0) = 3;
   auto m3 = boost::numeric::ublas::prod(m, m2);
   cout << m << endl;
   cout << "m * m2: " << endl;
   cout << m3 << endl;
   

   cout << "hi" << endl;
   return 0;
}

