#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/regex.hpp>
#include <boost/format.hpp>
#include <boost/foreach.hpp>
#include <boost/xpressive/xpressive.hpp>
using namespace std;
using namespace boost::posix_time;

const std::string metadata_date_format = "%Y-%m-%d %H:%M";
const std::string date_match_regexp = "^(?P<year>\\d{4})-(?P<month>\\d{1,2})-(?P<day>\\d{1,2}) ?(?P<time>(?P<hour>(\\d{1,2})|(2?[0-3]?)):(?P<minute>\\d{1,2}))?";
time_facet *facet = new time_facet(metadata_date_format.c_str());
time_input_facet *input_facet = new time_input_facet(metadata_date_format.c_str());

void FormatDate(std::string &date)
{
   static boost::xpressive::sregex r = boost::xpressive::sregex::compile(date_match_regexp);
   static boost::xpressive::smatch m;
   if(boost::xpressive::regex_search(date, m, r ))
      {
         date = (boost::format("%04d-%02d-%02d %02d:%02d") % m["year"] % m["month"] % m["day"] % m["hour"] % m["minute"]).str();
      }else
      {
         date = "not_a_date_time";
      }
}

boost::posix_time::ptime StringToPtime(std::string date)
{
   FormatDate(date);
   std::istringstream is(date);
   static const std::locale input_locale (std::locale::classic(),
      new time_input_facet(metadata_date_format.c_str()));
   is.imbue(input_locale);
   ptime time;
   is >> time;
   return time;
}

std::string PtimeToString(ptime time)
{
   if (time == boost::posix_time::not_a_date_time)
      return "not_a_date_time";
   std::ostringstream ostream;
   //time_facet facet (metadata_date_format.c_str());
   static const std::locale locale (std::locale::classic(),
      new time_facet(metadata_date_format.c_str()));
   ostream.imbue(locale);
   ostream << time;
   return ostream.str();
}

int main ()
{
   ptime pt = boost::posix_time::time_from_string("2002-01-20 23:59:59.000");
   vector<string> dates;
   dates.push_back("2000-01-12 23:2");
   dates.push_back("2000-01-12 23:2");
   dates.push_back("2000-01-12 23:2");
   dates.push_back("2000.2");
   dates.push_back("2000-13-12 23:2");
   dates.push_back("2000-12-12 25:2");
   dates.push_back("2000-12-12 23:70");
   dates.push_back("2000-12-42 23:00");
   dates.push_back("2000-2-29 23:00");
   dates.push_back("2001-2-29 23:00");
   
   BOOST_FOREACH(string date, dates)
   {
      cout << date<<"  ";
      cout <<   StringToPtime(date)<< endl;
   }

	return 0;	
}
