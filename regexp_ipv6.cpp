#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace boost;
using namespace std;

bool checkIpV6(const string& str)
{
   const boost::regex octet_exp(R"([0-9,a-f]{1,4})");
   std::vector<string> tokens;
   boost::split(tokens, str, boost::is_any_of(":"));
   if (str.empty()) return false;
   if (tokens.size() > 8) return false;
   bool has_double_semicolon = false;
   BOOST_FOREACH(auto t, tokens)
   {
      if (t.empty())
         if (has_double_semicolon) return false;
         else 
         {
            has_double_semicolon = true;
            continue;
         }
      cout << "t: " << t <<endl;
      if (!boost::regex_match(t, octet_exp)) return false;
   }
	return true;
}
void check()
{
 const boost::regex ipv6_domain_regex(R"(udp6:([^:,\s]*)(:\d{1,5})?)", boost::regex::icase);
 boost::smatch matches;
	std::string str = "udp6:sdf.sdd:12";
  if (boost::regex_match(str, matches, ipv6_domain_regex) )
	{
		std::cout << "y\n" << matches.size();
      for (auto i = 0; i < matches.size(); ++i)
      {
         std::cout << matches[i] << "\n";
      }
	}
else
   {
      std::cout << "n\n";
   }
}

int main()
{
	check();
	return 1;
   string s = "udp6:[]";
   const boost::regex ipv6_exp(R"(udp6:\[(\S*)\])");
   boost::smatch matches;
   if (boost::regex_match(s, matches, ipv6_exp))
   {
      cout << "Match! "<<matches.size() << endl;
      cout << matches[0] << endl;
      cout << matches[1] << endl;
      cout << checkIpV6(matches[1]) << endl;
   }
   else
   {
      cout << "cannot match :(\n";
   }
   return 0;
}