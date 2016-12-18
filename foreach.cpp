#include <iostream>
#include <vector>
#include <string>
#include <boost/foreach.hpp>

typedef std::vector<std::string> strArr;

void printArr(const strArr& ar)
{
  BOOST_FOREACH(auto s, ar)
  {
   std::cout << "el: " << s << std::endl;
   }

}

int main ()
{
  strArr ar;
  std::cout << "Heelo" << std::endl;
 
   ar.push_back("a");
   ar.push_back("b");
   ar.push_back("c");
   ar.push_back("d");
  BOOST_FOREACH(auto& s, ar)
  {
      if (s == "c")
      {
         s = "asd";
      }
   }
   printArr(ar);

 return 0;
}
