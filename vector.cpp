#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::string to_string(int a)
{
   std::stringstream ss;
   ss << a;
   return ss.str();
}

class Element
{
public:
   Element(int num)
   {
      el = "el number " + to_string(num);
   }
   std::string el;
};

typedef std::vector<Element> MyVector;

void print_stat(const MyVector& vec)
{
   std::cout << "vec[0]: "<< &vec[0] << std::endl;
   std::cout << "vec["<< vec.size()-1 <<"]: "<< &vec[vec.size()-1] << std::endl;
   std::cout << "capacity: "<< vec.capacity() << std::endl;
}

int main()
{
   MyVector vec;
   std::cout << "capacity: "<< vec.capacity() << std::endl;   
   for (auto i =0; i < 1000; ++i)
   {
      vec.push_back(Element(i));
   }

   std::cout << "Hello" << std::endl;
   print_stat(vec);
   vec.erase(vec.begin()+5, vec.end());
   print_stat(vec);
   //vec.shrink_to_fit();
   MyVector (vec).swap(vec);
   print_stat(vec);
   return 0;
}