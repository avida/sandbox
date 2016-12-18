#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <iostream>
#include <string>
#include <vector>
int main()
{
std::string s = "10.24.2.131%2C10.24.2.132,111";
std::vector <std::string> fields;
boost::split_regex( fields, s, boost::regex( "(%2C)|(,)" ) );

 for (size_t n = 0; n < fields.size(); n++)
    std::cout << "\"" << fields[ n ] << "\"\n";
  std::cout << std::endl;

return 0;
}     