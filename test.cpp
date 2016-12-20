// g++ test.cpp -Ig:/libs/boost -Lg:/libs/boost/stage/lib -lboost_unit_test_framework
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "asio.hpp"

using namespace std;
using namespace boost;

int a = 0;
void tick()
{
   a++;
}

BOOST_AUTO_TEST_CASE(my_test)
{
   ThreadWorker worker;
   auto timer_ctx = worker.Schedule(bind(tick), posix_time::seconds(2));
   cout << "Wait 5 seconds\n";
   boost::this_thread::sleep(boost::posix_time::seconds(5));
   BOOST_CHECK_EQUAL(a, 2);
}

