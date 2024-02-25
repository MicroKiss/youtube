#include <iostream>
#include <optional>


std::optional<std::string> GetComment (bool b) 
{
    if (b) {
        return "alma";
    } else {
        return std::nullopt; // {}
    }
}


int main(int argc, char const *argv[])
{
    std::optional<int> num;
    //if (num.has_value ())
    if(num) {
        std::cout<< "value\n";
    } else {
        std::cout<< "no value \n";
    }

    std::cout << num.value_or(0) << std::endl;


    num = 23;

    std::cout << num.value_or(0) << std::endl;

    if(num) {
        std::cout<< "value"<< num.value() << "\n";
    } else {
        std::cout<< "no value \n";
    }

    std::optional<bool> b;

    if (b && b.value()) {
        std::cout << "bool\n";
    }

    auto res = GetComment (false);
    auto res2 = GetComment (true);

    if(res) {
        std::cout<< "value"<< res.value() << "\n";
    } else {
        std::cout<< "no value \n";
    }

    if(res2) {
        std::cout<< "value: "<< res2.value() << "\n";
    } else {
        std::cout<< "no value \n";
    }

    return 0;
}
