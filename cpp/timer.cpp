//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

bool stopped = false;
void t_work(boost::asio::io_service* io)
{
   {
      io->run();
   }
}

  boost::asio::io_service io;

  boost::asio::deadline_timer t(io, boost::posix_time::milliseconds(500));

void pst()
{
   t.async_wait(&print);   
}

int main()
{
  // t.async_wait(&print);
  boost::thread tr(boost::bind(t_work, &io));
  //boost::this_thread::sleep(boost::posix_time::seconds(1));
  io.post(pst);
  stopped = true;
  tr.join();
  // io.run();
  return 0;
}