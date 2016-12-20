#pragma once
#include <atomic>
#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class ThreadWorker
{
public:
   ThreadWorker():m_service(),
                  m_strand(m_service),
                  m_stopped(false),
                  timer(m_service)
   {
      static const int num_threads = 1;
      for (auto i=0; i < num_threads; ++i)
      {
         t_group.create_thread(
               boost::bind(&ThreadWorker::thread_work, this)); 
      }
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

   template <typename Base>
   class repetative_timer_wrapper_base;

   class ITimerContext
   {
   public:
      virtual void CancelTimer() = 0;
   };
   typedef boost::shared_ptr<ITimerContext> TimerContextPtr;

   template <typename Handler, typename Base>
   class TimerContext:public ITimerContext
   {
   friend class repetative_timer_wrapper_base<Base>;
   public:
     void CancelTimer()
     {
        timer.cancel();
     }
   private:
      TimerContext(Handler f, boost::asio::io_service& service, boost::posix_time::seconds interval):
         f(f),
         io_service(service),
         interval(interval),
         timer(io_service)
         {}
      Handler f;
      boost::asio::io_service& io_service;
      boost::posix_time::seconds interval;
      boost::asio::deadline_timer timer;
   };
   typedef boost::function<void()> FHandler;
   
   template <typename Base>
   class repetative_timer_wrapper_base
   {
      public:
       typedef boost::shared_ptr<TimerContext<FHandler, Base>> ContextPtr;

         repetative_timer_wrapper_base(FHandler f, boost::asio::io_service& service, boost::posix_time::seconds interval):
                                  m_ctx(new TimerContext<FHandler, Base>(f, service, interval))
         {
            boost::this_thread::sleep(boost::posix_time::milliseconds(100));
            std::cout << __FUNCTION__ << ":" << __LINE__<< std::endl;
         }
         repetative_timer_wrapper_base(const repetative_timer_wrapper_base<repetative_timer_wrapper_base>& other):m_ctx(other.m_ctx)
         {
            // cout << __FUNCTION__ << ":" << __LINE__<< endl;
            // m_timerptr = other.m_timerptr;
         }
         ~repetative_timer_wrapper_base()
         {
            // cout << __FUNCTION__<< endl;
         }

         void operator()()
         {
          resched_int();
         }

         void operator()(const boost::system::error_code& e)
         {
            if(e)
               return;
            m_ctx->f();
            resched();
         }
       ContextPtr GetContext() const
       {
          return m_ctx;
       }
      protected:
         virtual void resched()
         {
            resched_int();
         }
     private:
         void resched_int()
         {
            m_ctx->timer.expires_from_now(m_ctx->interval);
            m_ctx->timer.async_wait(*static_cast<Base*>(this));
         }
         ContextPtr m_ctx;
   };

   class repetative_timer_wrapper: public repetative_timer_wrapper_base<repetative_timer_wrapper>
   {
   public:
      repetative_timer_wrapper(FHandler f, boost::asio::io_service& service, boost::posix_time::seconds interval):
                  repetative_timer_wrapper_base<repetative_timer_wrapper>(f, service, interval)
                  {}
   };

   class tick_timer: public repetative_timer_wrapper_base<tick_timer>
   {
   public:
      tick_timer(FHandler f, boost::asio::io_service& service, boost::posix_time::seconds interval, int ticks):
                        repetative_timer_wrapper_base<tick_timer>(f, service, interval),
                        m_ticks(ticks)
      {
         // cout <<"ctor\n";
      }

   protected:
      void resched()
      {
         // std::cout << "ticks:" << m_ticks<< std::endl;
         if (--m_ticks == 0)
            return;
       repetative_timer_wrapper_base<tick_timer>::resched();
      }
   private:
      int m_ticks;
   };

   TimerContextPtr
   Schedule(FHandler f, boost::posix_time::seconds time)
   {
      auto wrapper = repetative_timer_wrapper(f, m_service, time);
      m_service.post(wrapper);
      return boost::static_pointer_cast<ITimerContext>(wrapper.GetContext());
   }

   TimerContextPtr
   ScheduleRepetative(FHandler f, boost::posix_time::seconds time, int ticks)
   {
      auto wrapper = tick_timer(f, m_service, time, ticks);
      m_service.post(wrapper);
      return boost::static_pointer_cast<ITimerContext>(wrapper.GetContext());
   }

   void Wait()
   {
      m_stopped = true;
      t_group.join_all();
   }

private:
   void thread_work()
   {
      while(!m_stopped)
      {
         m_service.run();
         // m_service.run_one();
      }
   }
   
   boost::asio::io_service m_service;
   boost::asio::io_service::strand m_strand;
   std::atomic_bool  m_stopped;
   boost::asio::deadline_timer timer;
   // boost::thread t;
   boost::thread_group t_group;
};

template<typename F, typename Handler>
asio_handler_invoke(F& function, ThreadWorker::wrapper<Handler>* w)
{
   function();
   std::cout << "function performed" << std::endl;
}

// template<typename F>
// asio_handler_invoke(F& function, ThreadWorker::three_tick_timer* w)
// {
//    function();
//    cout << "timer function performed" << endl;
// }