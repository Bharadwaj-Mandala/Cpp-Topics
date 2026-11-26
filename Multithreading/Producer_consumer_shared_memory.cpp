#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <algorithm>

using namespace std;

int shared_memory = 0;
mutex mtx;
condition_variable cv;
bool data_ready = false;

void producer()
{
    while (true)
    {
        /*  Sleep Location  Inside the loop(Correct), Throttles execution; gives threads time to hand off the lock safely.
            Works perfectly forever.
        */

        this_thread::sleep_for(1s);
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()
                { return !data_ready; });
        auto value = ++shared_memory;
        cout << "Produced value : " << value << endl;
        data_ready = true;
        lock.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while (true)
    {
        this_thread::sleep_for(1s);
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()
                { return data_ready; });
        auto value = shared_memory;
        cout << "Consumed value : " << value << endl;
        data_ready = false;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    thread producerThread(producer);
    thread consumerThread(consumer);
    /*
    thread producerThread([]()
                          {
        while(true){
            this_thread::sleep_for(1s);
            producer();
        } });
    thread ConsumerThread([]()
                          {
        while(true){
            this_thread::sleep_for(1s);
            consumer();
        } });
    */
    producerThread.join();
    consumerThread.join();

    return 0;
}