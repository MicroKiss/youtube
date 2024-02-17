#include <algorithm>
#include <iostream>
#include <vector>

int main (int argc, char const *argv[]) {

    auto PrintLambda = [] (int n) -> void {
        std::cout << n << std::endl;
    };
    PrintLambda (5);

    auto AddOne = [] (int n) -> int {
        return n + 1;
    };
    std::cout << AddOne (5);

    int constant = 5;
    auto WithDataMember = [constant] (int n) {
        std::cout << constant << n << std::endl;
    };

    auto WithInitialisedDataMember = [myConstant = 5] (int n) {
        std::cout << myConstant << n << std::endl;
    };
    auto SeeAllByValue = [=] () {};
    auto SeeAllByReference = [=] () {};
    auto SeeAllByValueAnd1ByRef = [=, &constant] () {};

    std::vector<int> v = {1, 2, 3};

    std::sort (v.begin (), v.end (), [] (int n, int m) -> bool {
        return m < n;
    });

    std::for_each (v.begin (), v.end (), [] (int n) {
        std::cout << n << " ";
    });

    return 0;
}
