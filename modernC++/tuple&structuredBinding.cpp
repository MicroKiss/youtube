#include <iostream>
#include <map>
#include <set>
#include <tuple>

struct FooRetType {
    int err;
    std::string s;
};

FooRetType Foo () {

    return {42, "Alma"};
}

std::tuple<int, std::string> Foo2 () {

    return {42, "Alma"};
    // std::tuple<int, std::string> (42,"Alma");
}

int main (int argc, char const *argv[]) {

    FooRetType a = Foo ();
    std::cout << "struct " << a.err << " " << a.s << std::endl;
    auto b = Foo2 ();

    std::cout << "tuple " << std::get<int> (b) << " " << std::get<std::string> (b) << std::endl;

    auto [c, d] = Foo2 ();

    std::cout << "structured binding " << c << " " << d << std::endl;

    std::string t2;
    std::tie (std::ignore, t2) = Foo2 ();
    std::cout << "tie "
              << " " << t2 << std::endl;

    std::set<int> Set{1, 2};

    auto [it, success] = Set.insert (1);

    std::cout << "siker Set:" << success << std::endl;

    std::map<int, std::string> Map{{0, "0"}, {1, "1"}};

    for (auto [m1, m2] : Map)
        std::cout << "key: " << m1 << " Value: " << m2 << std::endl;

    return 0;
}
