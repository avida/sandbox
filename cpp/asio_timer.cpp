#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <list>
#include <chrono>

typedef std::list<boost::asio::deadline_timer> TimerList;

long long time_in_ms()
{
   using namespace std::chrono;
   milliseconds ms = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch() );
   return ms.count();
}

void tick(const boost::system::error_code&)
{
   std::cout << time_in_ms()<< std::endl;
   auto result = std::time(nullptr);
   std::cout << "tick " << std::asctime(std::localtime(&result));
}


class AsioTimer
{
public:
   AsioTimer()
   {

   }
   template <typename T>
   int AddTimer(boost::function<void(const boost::system::error_code&)> handler, T timeout)
   {
      m_timers.emplace_back(m_service, timeout);
      auto& tm = m_timers.back();
      tm.async_wait(handler);
   }

   void WaitTimers()
   {
      boost::thread t(boost::bind(t_work, this));
      t.join();
   }
   boost::asio::io_service m_service;
private:
   TimerList m_timers;
   
   void t_work()
   {
      while(true)
      {
         m_service.run_one();
         // boost::this_thread::sleep(boost::posix_time::milliseconds(1));
      }
   }

};

void post()
{
   std::cout << "post\n";
   boost::this_thread::sleep(boost::posix_time::seconds(2));
}

void tick2(AsioTimer& a_timer, const boost::system::error_code&)
{
   std::cout << time_in_ms()<< std::endl;
   auto result = std::time(nullptr);
   std::cout << "tick 2" << std::asctime(std::localtime(&result));
   a_timer.m_service.post(post);
   a_timer.AddTimer(boost::bind(tick2, boost::ref(a_timer), _1), boost::posix_time::seconds(3));
}

int main()
{
   std::cout <<"asio_timer\n";
   AsioTimer a_timer;
   
   std::cout << time_in_ms()<< std::endl;
   a_timer.AddTimer(tick, boost::posix_time::seconds(0));
   a_timer.AddTimer(tick, boost::posix_time::seconds(10));
   a_timer.AddTimer(boost::bind(tick2, boost::ref(a_timer), _1), boost::posix_time::seconds(5));
   a_timer.WaitTimers();
   return 1;
}