#include <iostream>


int main(int argc, char const *argv[])
{
    
    struct CounterStruct
    {
        int c = 0;
        int operator()() {
            return ++c;
        };
    };

    CounterStruct s;
    s ();
    s ();
    std::cout  << s () << std::endl; 

    auto CounterLambda = [c = 0] () mutable {
        return ++c;
    };

    CounterLambda ();
    CounterLambda ();
    
    std::cout  << CounterLambda () << std::endl; 

    auto GeneratorLambda = [c = 1] () mutable {
        c *= 2;
        return c;
    };

    std::cout  << GeneratorLambda () << " " << GeneratorLambda () << " "<< GeneratorLambda () << " " << std::endl; 


    auto CountTrueLambda = [c = 0] (bool b) mutable {
        if (b)
            ++c;
        return c;
    };
    CountTrueLambda(false);
    CountTrueLambda(true);
    CountTrueLambda(false);

    std::cout << CountTrueLambda (true) << std::endl;

    auto WaitUntil = [c = 0] () mutable {
        return c++ < 5;
    };


    while (WaitUntil()) {
        std::cout << "repeated\n";
    }

    return 0;
}
