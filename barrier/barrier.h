#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>

class Barrier {
public:
  explicit Barrier(int cnt);

  void Bump();

private:
  std::atomic<int32_t> cnt_;
  std::condition_variable wall_;
  std::mutex mutex_;
};
