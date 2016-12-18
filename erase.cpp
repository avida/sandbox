#include <iostream>
#include <algorithm> 
#include <set>
#include <vector>
#include <list>
#include <boost/foreach.hpp>

using namespace std;
int main()
{
vector<int> s1;
for (int i = 0; i < 10; ++i)
{
	s1.push_back(i);
}
BOOST_FOREACH(int i, s1)
{
	cout << i << " ";
}

vector<int>::iterator it = s1.begin();

while(it  != s1.end())
{
cout << "checking iteraot " << *it << endl;
//cout << "it == end " <<( (it == s1.end()) ? "true" : "false") << endl;
//cout << "it " <<( *it ? "true" : "false") << endl;
//cout << "it " << it ? "true" : "false" << endl;

	if(9 == *it)
{
		s1.erase(it);
		cout << "iterator after erase " << *it << endl;
}
else
{
    	++it;
}
}

cout<<endl;
BOOST_FOREACH(int i, s1)
{
	cout << i << " ";
}




return 0;
}