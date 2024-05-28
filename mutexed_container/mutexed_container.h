#pragma once

#include <mutex>

template <typename Container>
class MutexedContainer {
private:
    class Guarded {
    public:
        Guarded(Container* ref, std::mutex &mutex) : lock_(mutex), objectRef_(ref) {
        }

        Container& operator*() {
            return *objectRef_;
        }

        Container* operator->() {
            return objectRef_;
        }

    private:
        Container *objectRef_;
        std::lock_guard<std::mutex> lock_;
    };

public:
    Guarded Acquire() {
        return Guarded(&container_, mutex_);
    }

private:
    Container container_;
    std::mutex mutex_;
};
