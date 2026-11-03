#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

// The shared resource is made atomic
std::atomic<int> atomic_counter(0);

void update_data_atomic(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        // Safe, atomic increment operation
        atomic_counter++;
    }
}

int main()
{
    const int iterations = 10;

    std::thread t1(update_data_atomic, iterations);
    std::thread t2(update_data_atomic, iterations);

    t1.join();
    t2.join();

    std::cout << "Final Atomic Counter Value: " << atomic_counter.load() << std::endl;

    return 0;
}
