#include <iostream>
#include <thread>
#include <mutex>

int shared_resource = 0;
const int MAX_VALUE = 20;
std::mutex resource_mutex;

void increment_resource(int thread_id)
{
    while (true)
    {
        // Lock the mutex using RAII (automatically unlocks when leaving the scope)
        std::lock_guard<std::mutex> lock(resource_mutex);

        if (shared_resource >= MAX_VALUE)
        {
            break; // Stop if the maximum value is reached
        }

        shared_resource++;
        std::cout << "Thread " << thread_id << " incremented to " << shared_resource << "\n";
    }
}

int main()
{
    // Create two threads running the same function
    std::thread t1(increment_resource, 1);
    std::thread t2(increment_resource, 2);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Final Value: " << shared_resource << std::endl;
    return 0;
}
