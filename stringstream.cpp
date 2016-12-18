#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

std::list<std::string> parse(std::string str)
{
   std::list<std::string> res;
   boost::tokenizer<> tok(str);
   
   BOOST_FOREACH(auto t, tok)   
   {
      //std::cout << "tok: " << std::stoi(t);
      res.push_back(" 1 ");
   }
   return res;
}

int main()
{
   std::stringstream ss;
   std::cout << "hello" << std::endl;
   auto array = {1,2,5,6};
   BOOST_FOREACH(auto i, array)
   {
      if (ss.tellp())      
         ss << " ";
      ss << i;
   }
   auto output = ss.str();
   std::cout <<"|"<< output <<"|" << std::endl;
   auto r =  parse(output);
   std::cout << boost::algorithm::join(r, "|");
   return 0;
}
