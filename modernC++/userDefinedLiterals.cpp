#include <iostream>
#include <chrono>

class Foo
{
private:
    /* data */
public:
    Foo(/* args */) {}
    ~Foo() {}
};

    double operator""_degToRad(long double deg){
        return deg * 3.1415 / 180;
    }

    Foo operator""_createFoo(long double deg){
        return Foo();
    }

    Foo operator""_createFooWithPrint(long double deg){
        std::cout << "created with udl\n";
        return Foo();
    }


int main()
{
    //using namespace std::chrono_literals;
    // auto lesson = 15min
    std::cout << 180.0_degToRad << "\n";
    Foo a = 180.0_createFooWithPrint;
}