#include <iostream>
#include <vector>
#include <chrono>

auto Foo () {
    return 2;
}

using namespace std::chrono_literals;

int main(int argc, char const *argv[])
{

    std::vector<std::string> vec;

    auto it = vec.begin();

    auto a = 1;
    auto b = 2;
    std::cout << Foo();

    auto mins = 5min;

    
    return 0;
}
