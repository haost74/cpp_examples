#ifndef   __TPOOL_CPP__
#define  __TPOOL_CPP__

#include <functional>
#include <future>
#include <queue>

namespace pool
{

class TPool
{
private:
    std::vector< std::thread > workers;
    std::queue< std::packaged_task<void()> > tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop{0};
public:
    explicit TPool(size_t threads);
    ~TPool();

    template<class F, class... Args>
    decltype(auto) enqueue(F&& f, Args&&... args)
    {
        using return_type = decltype(f(args...));

        std::packaged_task<return_type()> task(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );

        std::future<return_type> res = task.get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // don't allow enqueueing after stopping the pool
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            tasks.emplace(std::move(task));
        }
        condition.notify_one();
        return res;
    }
};

}



#endif