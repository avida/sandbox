#include <iostream>
#include <memory>
class Foo
{
public:
   int getNum()
   {
      return 13;
   }
};
typedef std::shared_ptr<Foo> FooPtr;
FooPtr getFoo()
{
   return std::make_shared<Foo>();
}

int main()
{
   std::cout << "hello\n";
   if (auto foo = getFoo())
   {
      std::cout<<"fff "<< foo->getNum() << "\n";
   }
   std::cout << "bb\n";
    return 0;
}