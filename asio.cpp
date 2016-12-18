// g++ asio.cpp -std=gnu++11 -Ig:/libs/boost -Lg:/libs/boost/stage/lib -lboost_system -lws2_32 -lboost_thread
#include <atomic>
#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost;

void work()
{
   cout << "---> work performing"<< endl;
}
void tick()
{
   std::time_t result = std::time(nullptr);
   std::cout << "tick " << std::asctime(std::localtime(&result));
}

class ThreadWorker
{
public:
   ThreadWorker():m_service(),
                  m_stopped(false),
                  timer(m_service),
                  t(bind(&ThreadWorker::thread_work, this), std::ref(m_service))
   {
   }

   template <typename Handler>
   class wrapper
   {
   public:
      wrapper(Handler f): m_f(f) {}
      void operator()()
      {
         m_f();
      }
      void operator()(const boost::system::error_code&)
      {
         m_f();
      }

      Handler m_f;

   };

   template <typename Handler>
   Run(Handler f)
   {
      m_service.post(wrapper<Handler>(f));
   }

   template <typename Handler>
   class TimerContext
   {
   public:
      TimerContext(Handler f, asio::io_service& service, posix_time::seconds interval):
         f(f),
         io_service(service),
         interval(interval),
         timer(io_service)
         {}
      Handler f;
      asio::io_service& io_service;
      posix_time::seconds interval;
      asio::deadline_timer timer;
   };

   template <typename Handler>
   class repetative_timer_wrapper
   {
      public:
         repetative_timer_wrapper(Handler f, asio::io_service& service, posix_time::seconds interval):
                                  m_ctx(new TimerContext<Handler>(f, service, interval) )
         {
            boost::this_thread::sleep(boost::posix_time::milliseconds(100));
            cout << __FUNCTION__ << ":" << __LINE__<< endl;
         }
         repetative_timer_wrapper(const repetative_timer_wrapper<Handler>& other):m_ctx(other.m_ctx)
         {
            // cout << __FUNCTION__ << ":" << __LINE__<< endl;
            // m_timerptr = other.m_timerptr;
         }
         ~repetative_timer_wrapper()
         {
            // cout << __FUNCTION__<< endl;
         }

         void operator()()
         {
            m_ctx->timer.expires_from_now(m_ctx->interval);
            m_ctx->timer.async_wait(std::move(*this));
         }

         void operator()(const boost::system::error_code&)
         {
            m_ctx->f();
            resched();
         }

      protected:
         virtual void resched()
         {
            m_ctx->timer.expires_from_now(m_ctx->interval);
            m_ctx->timer.async_wait(*this);
         }
         boost::shared_ptr<TimerContext<Handler>> m_ctx;
   };

   template <typename Handler>
   class three_tick_timer: public repetative_timer_wrapper<Handler>
   {
   public:
      three_tick_timer(Handler f, asio::io_service& service, posix_time::seconds interval):
                        repetative_timer_wrapper<Handler>(f, service, interval),
                        m_ticks(0)
      {
         // cout <<"ctor\n";
      }

   protected:
      void resched()
      {
         cout << "ticks:" << m_ticks<< endl;
         if (m_ticks++ == 3)
            return;
         this->m_ctx->timer.expires_from_now(this->m_ctx->interval);
         this->m_ctx->timer.async_wait(*this);
      }
   private:
      int m_ticks;
   };

   template <typename Handler>
   void Schedule(Handler f, posix_time::seconds time)
   { 
      m_service.post(three_tick_timer<Handler>(f, m_service, time));
   }

   void Wait()
   {
      m_stopped = true;
      t.join();
   }

private:
   void thread_work()
   {
      while(!m_stopped || m_service.run());
   }
   
   asio::io_service m_service;
   std::atomic_bool  m_stopped;
   boost::asio::deadline_timer timer;
   boost::thread t;
};

template<typename F, typename Handler>
asio_handler_invoke(F& function, ThreadWorker::wrapper<Handler>* w)
{
   function();
   cout << "function performed" << endl;
}

// template<typename F, typename Handler>
// asio_handler_invoke(F& function, ThreadWorker::repetative_timer_wrapper<Handler>* w)
// {
//    function();
//    cout << "function performed" << endl;
// }

int main()
{
   ThreadWorker worker;
   worker.Schedule(bind(tick), posix_time::seconds(1));
   worker.Run(bind(work));
   worker.Run(bind(work));
   worker.Wait();
   return 0;
}