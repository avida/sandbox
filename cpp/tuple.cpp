#include <tuple>
#include <iostream>
#include <string>
#include <memory>
struct Context
{
   Context(int val):some_val(val)
   {}
   int some_val;
};

template <typename ...Args>
struct TupleContext: public Context
{
public:
   TupleContext(int val): Context(val)
   {}
   std::tuple <Args ...> tupl;
};
typedef TupleContext<std::string, int> MyContext;

main()
{
   MyContext ctx(42);
   std::unique_ptr<int> ptr = std::make_unique<int>();
   ctx.tupl = std::make_tuple("Hello", 23);
   std::cout << "I am tuple." <<std::endl << std::get<0>(ctx.tupl) << " " << std::get<1>(ctx.tupl) <<std::endl;
}