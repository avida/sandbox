#include <boost/regex.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace std;
int main()
{
string s = "XXX(Down rere)";
string rep = regex_replace(s, regex("\\s?\\(.+\\)"), "");
cout << rep << endl;
return 0;
}