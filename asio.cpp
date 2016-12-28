// g++ asio.cpp -std=gnu++11 -Ig:/libs/boost -Lg:/libs/boost/stage/lib -lboost_system -lws2_32 -lboost_thread
#include "asio.hpp"

using namespace std;
using namespace boost;

void work()
{
   cout << "---> work started"<< endl;
   boost::this_thread::sleep(boost::posix_time::seconds(2));
   cout << "---> work performing"<< endl;
}

void tick()
{
   auto result = std::time(nullptr);
   std::cout << "tick " << std::asctime(std::localtime(&result));
}

void TimerCancel(ThreadWorker::TimerContextPtr timer_ctx)
{
   timer_ctx->CancelTimer();
   cout << "Cancel\n";
}

int main()
{
   ThreadWorker worker;
   auto timer_ctx = worker.Schedule(bind(tick), posix_time::seconds(3));
   // auto t2 = worker.ScheduleRepetative(bind(TimerCancel, timer_ctx), posix_time::seconds(2), 1);
   // worker.Run(bind(work));
   // worker.Run(bind(work));
   // worker.Run(bind(work));
   // worker.Run(bind(work));
   boost::this_thread::sleep(boost::posix_time::seconds(10));
   std::cout << "wait\n";
   worker.Wait();
   return 0;
}