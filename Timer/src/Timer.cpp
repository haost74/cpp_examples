#include "Timer.h"
#include <thread>
#include <thread>

Timer::Timer() : m_is_running(false) {
  std::thread([=]() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::lock_guard<std::mutex> lock(m_changing_mutex);
      if (m_is_running &&
          std::chrono::high_resolution_clock::now() - m_start > m_delay) {
        //m_is_running = false;
        m_callback();
      }
    }
  }).detach();
}

void Timer::add(std::chrono::milliseconds delay,
                std::function<void()> callback) {
  std::lock_guard<std::mutex> lock(m_changing_mutex);
  m_callback = callback;
  m_is_running = true;
  m_start = std::chrono::high_resolution_clock::now();
  m_delay = delay;
}