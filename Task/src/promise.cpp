#include <future>
#include <iostream>
#include <thread>
#include <utility>
#include <cstdarg>

struct data
{
    int a{};
};


void prod(std::promise<data> dataPromise, data x,  data y){
    data r;
    r.a = x.a + y.a;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    dataPromise.set_value(r); 
}

void run()
{
  data x; x.a = 5;
  data y; y.a = 15;
  std::promise<data> dPromise;
  auto dFuture = dPromise.get_future();
  std::thread th(prod, std::move(dPromise), x, y);
  auto res = dFuture.get();
  std::cout << res.a << '\n';
  th.join();
}