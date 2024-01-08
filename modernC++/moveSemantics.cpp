#include <iostream>

class Foo
{
    int* data;
    size_t size;
public:
    Foo(size_t size) : size(size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
            data[i] = i;
        std::cout << "basic ctor\n";
    }

    Foo(Foo const& other) {
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
        std::cout << "copy ctor\n";
    }

    Foo(Foo && other) noexcept {
        size = other.size;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        std::cout << "move ctor\n";
    }

    Foo& operator=(Foo const& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        std::cout << "copy assignment\n";
        return *this;
    }

    Foo& operator=(Foo && other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.data = nullptr;
            other.size = 0;
        }
        std::cout << "move assignment\n";
        return *this;
    }

    ~Foo() {
        delete[] data;
        std::cout << "dtor\n";
    }

    void Print () const {
        for (size_t i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

class Bar
{
private:
    Foo foo;
public:
    Bar(Foo const& foo): foo(foo) {}
    Bar(Foo && foo): foo(std::move (foo)) {}
    ~Bar() {}
};

int main(int argc, char const *argv[])
{
    Foo a(5);
    Foo b(2);

    std::cout << "a: "; 
    a.Print ();
    std::cout << "b: ";
    b.Print ();

    b = std::move (a);

    std::cout << "a: "; 
    a.Print ();
    std::cout << "b: ";
    b.Print ();



    //Bar (Foo(2));
    return 0;
}
