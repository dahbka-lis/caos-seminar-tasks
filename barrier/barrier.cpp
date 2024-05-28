#include "barrier.h"

Barrier::Barrier(int cnt) : cnt_(cnt) {}

void Barrier::Bump() {
  if (cnt_.load() <= 0) {
    return;
  }

  std::unique_lock lock(mutex_);
  cnt_.fetch_sub(1);

  while (cnt_.load() > 0) {
    wall_.wait(lock, [&] { return cnt_.load() <= 0; });
  }

  wall_.notify_all();
}
