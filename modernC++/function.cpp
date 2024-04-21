#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


void Print (std::function<void(int)> f, int i)
{
    f (i);
}

void Print(int i)
{
    std::cout << i;
}

struct Functor
{
    void operator ()(int i) {
         std::cout << i;
    }
};


void Sort(std::vector<int> &v, std::function<bool(int,int)> f)
{
    std::sort (v.begin (), v.end (), f);
}

bool sorter (int a, int b) 
{
    return b < a;
}


class EventEmmitter
{
private:
    std::vector<std::function<void()>> callbacks;
public:
    void Subscribe (std::function<void()> f) {
        callbacks.push_back (f);
    }
    void Call () {
        for (auto &&callback : callbacks)
        {
            callback();
        }
    }
};




int main(int argc, char const *argv[])
{
    std::vector<int> v = {2,1,4};

    Sort (v, sorter);
    for (auto &&i : v)
    {
        std::cout << i;
    }
    
    EventEmmitter ee;

    ee.Subscribe ([](){std::cout << std::endl << "it happened\n";});
    ee.Subscribe ([](){Print (3);});

    //..

    ee.Call();

    return 0;
}
