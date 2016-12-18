#include <iostream>
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>
using namespace std;

void tryMatchDate(std::string &date)
{
   static string expression = "^(?P<year>\\d{1,4})-(?P<month>\\d{1,2})-(?P<day>\\d{1,2})(?P<time> +(?P<hour>\\d{1,2}):(?P<minute>\\d{1,2}))?$";
   static boost::xpressive::sregex rx = boost::xpressive::sregex::compile(expression);
   boost::xpressive::smatch match;
   cout<< date << endl;
   if (boost::xpressive::regex_search(date, match, rx ) )  
   {
      cout << "matched!" << endl;
      string key = "year";
      cout << key << ": " << match[key] << endl;
      key = "month";
      cout << key << ": " << match[key] << endl;
      key = "day";
      cout << key << ": " << match[key] << endl;
      if (! string(match["time"]).empty())
      {
         key = "hour";
         cout << key << ": " << match[key] << endl;
         key = "minute";
         cout << key << ": " << match[key] << endl;
      }
   }
   else
   {
      cout << "  not matched("<< endl;
   }
   cout << endl;
}
void parseAddress(std::string address)
{
   cout << address;
   static string expression = "^(\\[(?P<host>\\S+)\\])?:?(?P<port>\\d+)?$";
   static boost::xpressive::sregex rx = boost::xpressive::sregex::compile(expression);
   boost::xpressive::smatch match;
   if (boost::xpressive::regex_search(address, match, rx ) )  
   {
      cout << " matched ";
      cout <<"host: "<<match["host"];
      cout << " port: "<<match["port"]<<endl;
   }
   else
   {
      cout << "  not matched ("<<endl;
   }
   
}

int main ()
{
#ifdef DATE
   string date = "2000-01-12";
   //boost::regex e (expression);
   tryMatchDate(date);
   date = "2000-01-12 00:00";
   tryMatchDate(date);
   date = "2000-01-10 00::00";
   tryMatchDate(date);
   date = "2000-01-102 00:00";
   tryMatchDate(date);
   date = "2000-01-1 00:00";
   tryMatchDate(date);
   date = "2000-01-1 00:";
   tryMatchDate(date);
   date = "2000-01-1   00:00";
   tryMatchDate(date);
   date = "2000-01-12 23:56:20";
   tryMatchDate(date);
   date = "2013-10-156";
   tryMatchDate(date);
#else
   parseAddress("10.23.2.2:23");
   parseAddress("[10.23.2.2]:23");
   parseAddress("[*]:23");
   parseAddress("[12.*.22]:23");
   parseAddress("[12.*.22:23");
   parseAddress("serge:23");
   parseAddress("sdf.efe.e:23");
   parseAddress("23");
   parseAddress("*:23");
   parseAddress(":23");
   parseAddress("[10.23.1.22]");
#endif   
   return 0;
}
