#ifndef __TIMER_CPP__
#define __TIMER_CPP__

#include <chrono>
#include <functional>
#include <mutex>

class Timer {
public:
  Timer();
  void add(std::chrono::milliseconds delay,
           std::function<void ()> callback);
private:
  bool m_is_running;
  std::mutex m_changing_mutex;
  std::chrono::milliseconds m_delay;
  std::chrono::high_resolution_clock::time_point m_start;
  std::function<void()> m_callback;
};

#endif