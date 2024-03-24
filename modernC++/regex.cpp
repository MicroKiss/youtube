#include <iostream>
#include <regex>

int main () {
    std::string text = "Hello everyone! :D";
    std::regex pattern ("(\\w+){6,}");
    
    // containment
    if (std::regex_search (text, pattern))
        std::cout << "Pattern found\n";
    else
        std::cout << "Pattern not found\n";
    
    // containment with position
    std::smatch match;
    if (std::regex_search (text, match, pattern))
        std::cout << "Pattern found at position: " << match.position () << " " << match.str () << "\n";
    else
        std::cout << "Pattern not found\n";
    
    // 100% match
    if (std::regex_match (text, pattern))
        std::cout << "Pattern matches\n";
    else
        std::cout << "Pattern does not match\n";
    
    // replacing found matches
    std::string newString = std::regex_replace (text, pattern, "there");
    std::cout << newString << "\n";
    
    // iterate over matches
    std::regex word ("\\w+");
    std::sregex_iterator it = std::sregex_iterator (text.begin (), text.end (), word);
    std::sregex_iterator end;

    int no = 1;
    while (it != end) {
        std::cout << no++ << ": " << std::smatch (*it).str () << "\n";
        it++;
    }
    
    return 0;
}