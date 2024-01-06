//https://youtu.be/cL6DYzRC6w4

#include <iostream>

int a = 2;

int Foo() { return 2;}
int& Foo2() { return a;} 


void Write(int& a) {
    std::cout << "LRef\n";
}


void Write(int const& a) {
    std::cout << "const LRef\n";
}


void Write(int&& a) {
    std::cout << "RRef\n";
}


int main(int argc, char const *argv[])
{
    // LValue = RValue
    int b = a;

    a = Foo();

    //Foo() = a;
    Foo2() = 5;

    b = a + a;

    &a;
    //&(a +a);

    const int c = 5;

    Write (a);
    Write (10);
    Write (c);

    return 0;
}
