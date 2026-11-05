#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
using namespace std;

mutex mtx;
int shared_counter = 0;

void increment(int thread_id)
{
    lock_guard<mutex> lock(mtx);
    shared_counter++;
}

int main()
{
    vector<thread> threads;
    for (int i = 0; i < 100000; i++)
    {
        threads.emplace_back(increment, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    cout << shared_counter << endl;
}