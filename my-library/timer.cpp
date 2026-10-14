#include <chrono>

class Timer {
    public:
    void start() {
#if defined(__i386__) || defined(__x86_64__)
        origin = rdtsc();
#else
        origin = clock::now();
#endif
    }
    
    inline double get_time() {
#if defined(__i386__) || defined(__x86_64__)
        return (rdtsc() - origin) * SECONDS_PER_CLOCK;
#else
        return std::chrono::duration<double>(clock::now() - origin).count();
#endif
    }
    
    private:
#if defined(__i386__) || defined(__x86_64__)
    constexpr static double SECONDS_PER_CLOCK = 1 / 3.0e9;
    unsigned long long origin;
    
    inline static unsigned long long rdtsc() {
        unsigned long long lo, hi;
        __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
        return (hi << 32) | lo;
    }
#else
    using clock = std::chrono::steady_clock;
    clock::time_point origin;
#endif
};
