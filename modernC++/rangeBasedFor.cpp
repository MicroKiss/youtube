#include <iostream>
#include <vector>


int main (int argc, char const *argv[]) {

    std::vector<int> vec = {1,2,3};

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout <<"\n\n";
    
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
     std::cout <<"\n\n";

     for (int const& e : vec) {
        std::cout << e << " ";
     }
    std::cout <<"\n\n";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        int& e = *it;
        std::cout << e << " ";
    }

    for (auto const& e : vec) {
        std::cout << e << " ";
     }

    int a[] = {1,2,3,4};

    for (auto &&i : a)
    {
        std::cout << i << " ";
    }

    for (auto &&i : {1,2,3,4})
    {
        std::cout << i << " ";
    }
    


    return 0;
}