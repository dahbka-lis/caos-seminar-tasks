#pragma once

#include <thread>
#include <functional>

template <typename T = std::thread>
class JThread : public T {
public:
    JThread(std::function<void(void)> func) : T(func) {
    }

    ~JThread() {
        this->join();
    }
};
