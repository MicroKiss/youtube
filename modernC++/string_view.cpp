#include <iostream>
#include <string_view>

// big nono
/*
std::string_view GenerateString () {
    std::string temporary;
    return temporary;
}
*/

void Print (std::string_view s) {
    std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
    std::string s{"almafa"};
    
    std::string_view sv(s);

    s[3] = 'o';

    std::cout << sv << std::endl;
 
    Print (s);
    Print ("kiskutya");
    return 0;
}
