//#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <list>
#include <map>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
using namespace std;
template <typename Key, typename Mapped>
class lru_map
{
public:
   typedef size_t                         size_type;
   typedef Key                            key_type;
   typedef Mapped                         mapped_type;
   typedef std::pair<const Key, Mapped>   value_type;
   typedef Mapped&                        reference;
   typedef Mapped*                        pointer;

   lru_map()
   : m_max_size(0), m_miss_cnt(0), m_hit_cnt(0)
   {}

   explicit
   lru_map(size_type max_size)
   : m_max_size(max_size), m_miss_cnt(0), m_hit_cnt(0)
   {}

   bool
   empty() const
   { return m_lookup.empty(); }

   size_type
   size() const
   { return m_lookup.size(); }

   void
   max_size(size_type max_size)
   { m_max_size = max_size; }

   size_type
   max_size() const
   { return m_max_size; }

   // TODO: should return pair or iterator?
   key_type
   lru() const
   { return m_lru.back()->first; }

   // TODO: should return pair or iterator?
   key_type
   mru() const
   { return m_lru.front()->first; }

   // TODO: should return pair or iterator?
   pointer
   insert(const value_type& x)
   {
      // If value is already stored, update it's access time
      assert(m_max_size != 0);
      typename Map::iterator entry = m_lookup.find(x.first);
      if (entry != m_lookup.end())
      {
         bump(entry);
         return &(entry->second.first);
      }

      // If the cache is full, remove the LRU (tail)
      if (size() >= m_max_size)
      {
         m_lookup.erase(m_lru.back());
         m_lru.pop_back();
      }

      // A new item is the MRU (head)
      m_lru.push_front(entry);
      entry = m_lookup.insert(std::make_pair(x.first, std::make_pair( x.second , m_lru.begin()))).first;
      m_lru.front() = entry;
      //m_lru.front() = entry;
      assert(m_lookup.size() <= m_max_size);
      assert(m_lookup.size() == m_lru.size());

      return &(entry->second.first);
   }
   
   pointer 
   replace_tail(key_type key)
   {
      typename Map::iterator entry = m_lookup.find(key);
      if(entry != m_lookup.end())
      {
         //you should use find function for that
         return NULL;
      }
      entry = m_lru.back();
      m_lru.pop_back();
      pointer pnt = &(entry->second.first);
      m_lookup.erase(entry);
      m_lru.push_front(entry);
      entry = m_lookup.insert(std::make_pair(key, std::make_pair( *pnt , m_lru.begin()))).first;
      m_lru.front() = entry;
      return &(entry->second.first);
   }
   // TODO: should return pair or iterator?
   pointer
   find(const key_type& key)
   {
      typename Map::iterator entry = m_lookup.find(key);
      if (entry != m_lookup.end())
      {
         m_hit_cnt++;
         bump(entry);
         return &(entry->second.first);
      }
      m_miss_cnt++;

      return NULL;
   }
   
   pointer 
   tail()
   {
      cout << "tail key is " << m_lru.back()->first<< endl;
      return &(m_lru.back()->second.first);
   }

   std::string
   str() const
   {
      std::ostringstream stream;
      stream << "lru: " << lru() << ", mru: " << mru();

      stream << " (";
      typename List::const_reverse_iterator it = m_lru.rbegin();
      typename List::const_reverse_iterator it_end = m_lru.rend();
      for (; it != it_end; ++it)
      {
         stream << " " << (*it)->first << ":" << *(*it)->second.first;
      }
      stream << ")";

      return stream.str();
   }

   size_type
   miss_count() const
   { return m_miss_cnt; }

   size_type
   hit_count() const
   { return m_hit_cnt; }

private:
   // forward declaration required for circular dependencies
   struct MapIterator;

   // list of data elements, ordered from MRU (head) to LRU (tail)
   typedef std::list<MapIterator> List;
   List m_lru;

   // container for data, provides quick lookup
   typedef std::map<Key, std::pair<Mapped, typename List::iterator> > Map;
   Map m_lookup;

   // required for circular dependencies
   struct MapIterator : Map::iterator
   {
      MapIterator(const typename Map::iterator& it) : Map::iterator(it) {}
   };

   size_type m_max_size;
   size_type m_miss_cnt;
   size_type m_hit_cnt;

   void bump(typename Map::iterator it)
   {
      m_lru.erase(it->second.second);   // it->second.second is a list iterator
      m_lru.push_front(it);
      it->second.second = m_lru.begin();
   }
};
typedef boost::shared_ptr<std::string>  stringPtr;
int main(){
   
   lru_map<int, stringPtr> map(3);
   stringPtr str = boost::make_shared<std::string>("zero");
   std::cout << str.use_count() << std::endl;

   map.insert(std::pair<int, stringPtr >(0, str));
   std::cout << str.use_count() << std::endl;
   map.insert(std::pair<int, stringPtr >(2,boost::make_shared<std::string>("two")));
   map.insert(std::pair<int, stringPtr>(3,boost::make_shared<std::string>("three")));
   map.insert(std::pair<int, stringPtr>(5,boost::make_shared<std::string>("five")));
   map.find(5);
   map.find(2);
   map.find(3);
   map.insert(std::pair<int, stringPtr>(5,boost::make_shared<std::string>("five")));
   stringPtr tal = *map.tail();
   std::cout<< "tail: " << *tal<<std::endl;
   map.replace_tail(23);
   map.find(3);
   map.find(23);
   map.find(5);
   map.find(23);
 
   std::cout<< map.str()<<std::endl;

   std::cout << str.use_count() << std::endl;
   tal= *map.tail();
   std::cout<< "tail: " << *tal<<std::endl;
   return 0;
}