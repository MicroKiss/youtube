#include <iostream>
#include <vector>
class Foo
{
};

void Helper(Foo &)
{
    std::cout <<"&Helper\n";
}

void Helper(Foo &&)
{
    std::cout <<"&&Helper\n";
}

void Helper(Foo const&)
{
    std::cout <<"const&Helper\n";
}

void Helper(Foo const&&)
{
    std::cout <<"const&&Helper\n";
}

/*
    & && -> &
    && & -> &
    & & -> &
    && && -> &&
*/
template<typename T>
void Wrapper (T&& f) {
    Helper (std::forward<T>(f));
}

int main(int argc, char const *argv[])
{
    std::vector<int> a;
    // this also uses perfect forwarding
    //  ||
    //  \/
    a.emplace_back(2);
    Foo f;
    Foo const fc;

    Wrapper(f);
    Wrapper(std::move(f));
    Wrapper(fc);
    Wrapper(std::move(fc));
    return 0;
}


/*
Foo&& var1 = foo; // here, “&&” means rvalue reference
 
auto&& var2 = var1; // here, “&&” does not mean rvalue reference
 
template<typename T>
void f(std::vector<T>&& param); // here, “&&” means rvalue reference
 
template<typename T>
void f(T&& param);               // here, “&&”does not mean rvalue reference
*/