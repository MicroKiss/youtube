#include <iostream>
#include <vector>


class MyClass
{
private:
    /* data */
public:
    MyClass(std::initializer_list<int> l) {
        std::cout<< "size:" << l.size() << "\n";
         std::cout<< "first:" << *l.begin() << "\n";
        for (auto &&i : l)
        {
            std::cout << i << " ";
        }
    
    }
    ~MyClass() {}
};

void Print(std::initializer_list<int> l, char delim ) {
    for (auto &&i : l)
    {
        std::cout << i << delim;
    }
    
}

int main(int argc, char const *argv[])
{
    Print({1,2,3},'%');
    return 0;
}
