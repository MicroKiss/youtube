#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono;

void Foo() {
    std::this_thread::sleep_for(1s);
}

int main(int argc, char const *argv[])
{   
    minutes min5 = 5min;
    seconds sec10 = 10s;
    std::cout << duration_cast<minutes>(min5 - sec10).count();

    //current time
    auto now = system_clock::now();
    auto nowTime_t = system_clock::to_time_t (now);
    std::cout << std::ctime(&nowTime_t);
   
    //measure time
    auto start = steady_clock::now();
    Foo();
    auto end = steady_clock::now();
    std::cout << duration_cast<milliseconds>(end-start).count() << "\n";

    //deltaTime
    auto lastTime = steady_clock::now();
    while(true) {
        std::this_thread::sleep_for(100ms);
        auto currTime = steady_clock::now();
        auto deltaTime = duration_cast<milliseconds>(currTime-lastTime).count();
        lastTime = currTime;
        std::cout << deltaTime << "\n";
    }
    return 0;
}
