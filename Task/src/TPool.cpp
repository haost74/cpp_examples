#include "TPool.h"

namespace pool
{


TPool::TPool(size_t threads)
{
  for(size_t i = 0; i<threads; ++i)
         workers.emplace_back([this]{
           for(;;){
               std::packaged_task<void()> task;

               {
                  std::unique_lock<std::mutex> lock(this->queue_mutex);
                this->condition.wait(lock,
                    [this]{ return this->stop || !this->tasks.empty(); });
                if(this->stop && this->tasks.empty())
                    return;
                task = std::move(this->tasks.front());
                this->tasks.pop();
               }

               task();
           }
         });
}

  TPool::~TPool() {
    {
      std::unique_lock<std::mutex> lock(queue_mutex);
      stop = true;
    }
    condition.notify_all();
    for(std::thread& worker : workers)
      worker.join();
  }

}