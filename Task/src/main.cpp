#include <iostream>
#include <cstdarg>
#include <thread>
#include "callback.cpp"
#include <functional>

//#include "ThreadPool.h"

#include "TPool.h"
#include "promise.cpp"

#include <functional>
#include <future>
#include <queue>


void foo()
{
    //call(myFunc, "123", 10.5, 48);

   pool::TPool pool(4);
   std::vector<std::future<int>> results;

   for(int i = 0; i < 8; ++i){
       results.emplace_back(
         pool.enqueue([i]{
             std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
         })
       );
   }

   for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void start()
{
    
      pool::TPool pool(4);
      
   std::vector<std::future<int>> results;
    
    for(int i = 0; i < 8; ++i){
       results.emplace_back(
         pool.enqueue([i]{
             std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
         })
       );
   }
   /*

      for(auto && result: results)
        std::cout << result.get() << ' ';
         std::cout << std::endl;
         */
}

int main()
{
     start();
    
   
    //run();
//    std::cout << currentDateTime();
//    std::cout << " start" << '\n';
//    std::this_thread::sleep_for(std::chrono::seconds(100));
//    std::cout << currentDateTime();
//    std::cout << " stop" << '\n';
}