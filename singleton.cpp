#include <iostream>
using namespace std;

class Basic;

class D : Basic
{
private:
	D(){}	
};


class Basic
{
public:
	static D* get_inst()
	{
		if (!inst)
		{
			inst = new D();
 		}
	}
private:
	static D* inst;
};

D* Basic::inst = 0;

Basic a;
int main(){
D* d = Basic::get_inst();
cout<< "hi"<< endl;

return 0;
}