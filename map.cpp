#include <map>
#include <list>
#include<iostream>
#include <boost/foreach.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>

using namespace std;
int main()
{
   map<int , string> m_map;
   m_map[0] = "null";
   m_map[2] = "two";
/*   m_map[4] = "four";
   m_map[5] = "five";
*/
   list<int> keys;
   pair<int, string> p;
   boost::copy (m_map | boost::adaptors::map_keys, std::back_inserter(keys));
   int key;
   BOOST_FOREACH(key, keys)
   {
      cout<<key << endl;
   }
    
   map<int , string> map2;
   map2[0] = "null";
   map2[2] = "two";
   std::cout << "m_map == map2 : " << (map2 == m_map) << std::endl;
   
   return 0;
}