#include <boost/shared_ptr.hpp>
#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>
using namespace std;

class AA
{	
public:
AA() { a = 42;}
int a;
};

class Notifier
{
public:
	void Notify(int a)
	{
	cout << "reached limit " << a <<endl;
	}
};
typedef boost::function<void(int)> NotifyFunction;
class AAPtr: public boost::shared_ptr<AA>
{
public:
	AAPtr(AA* p): shared_ptr<AA>::shared_ptr<AA>(p) 
	{
	}
	void setLimit(NotifyFunction n_f) {
   limit = use_count(); not_func = n_f; 
   cout << "limit is "<< limit << endl;
   };
	AAPtr& operator=(AAPtr	const & p) 
	{
		shared_ptr<AA>::operator =(p);
		cout << "assigning"<< endl;
		limit = p.limit;
      not_func = p.not_func;
	}
	virtual ~AAPtr()
	{
      cout << use_count()<<endl;
      if(use_count()-1 == limit)
      {
         if(!not_func)
         {
            cout << "null"<< endl;
         }else
         {
             not_func((*this)->a);
             
         }
      }
	}
	public:	
	int limit;
	NotifyFunction not_func;
};
Notifier notif;
AAPtr a_p(new AA);
AAPtr createPtr()
{
   a_p;
   NotifyFunction b = boost::bind(&Notifier::Notify, notif, _1);
	a_p.setLimit(b);
   return a_p;
}

int main()
{
	{
   AAPtr c(0);
	{
      AAPtr a = createPtr();
      cout << "hi, b "<< a.use_count()<< endl;
      AAPtr b = a;
      c = a;
      cout << "bb, b"<< endl;
	}
      cout << "bb, c"<< endl;
   }
	cout << "Hi" << endl;
	return 0;		
}