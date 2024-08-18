#include <memory>
#include <iostream>

class Obj {
    public:
    Obj (int v = 0): value(v) { std::cout << "Constructed\n";}
    ~Obj () {std::cout << "Destructed\n";}
    int value;
};


void ProblemFixed () {
    std::unique_ptr<Obj> a(new Obj());

    if (true) {
        return;
    }

}

void Print (Obj* o) {
    std::cout << o->value << std::endl;
}

void Unique () {
    std::unique_ptr<Obj> a(new Obj());

    std::unique_ptr<Obj> b = std::move (a);

    Print (b.get ());
    Print (&*b);
}

void Shared () {
    std::shared_ptr<Obj> shared(new Obj());
    std::shared_ptr<Obj> shared2(shared);
}

class Circular {
    public:
    Circular () { std::cout << "Constructed\n";}
    ~Circular () {std::cout << "Destructed\n";}
    std::shared_ptr<Circular> other;
};

void CircularProblem () {
    std::shared_ptr<Circular> o1(new Circular());
    std::shared_ptr<Circular> o2(new Circular());
    o1->other = o2;
    o2->other = o1;
}


class CircularFixed {
    public:
    CircularFixed () { std::cout << "Constructed\n";}
    ~CircularFixed () {std::cout << "Destructed\n";}
    std::weak_ptr<CircularFixed> other;
};

void Weak (){
    std::shared_ptr<CircularFixed> o1(new CircularFixed());
    std::shared_ptr<CircularFixed> o2(new CircularFixed());
    o1->other = o2;
    o2->other = o1;
}


void Weak2 (){
    std::weak_ptr<Obj> weak;
    {
        std::shared_ptr<Obj> o(new Obj ());
        weak = o;
    }

    auto s = weak.lock ();
    if (s) {
        std::cout << "exists\n";
    } else {
        std::cout << "expired\n";
    }

    std::shared_ptr<Obj> o(new Obj ());
    weak = o;
    auto s2 = weak.lock ();
    if (s2) {
        std::cout << "exists\n";
    } else {
        std::cout << "expired\n";
    }

}

int main(int argc, char const *argv[])
{
    ProblemFixed();
    Unique ();
    CircularProblem ();
    Weak ();
    Weak2 ();
    return 0;
}

