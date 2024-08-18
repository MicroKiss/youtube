#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main (int argc, char const *argv[]) {

    fs::path currPath = fs::current_path ();
    fs::path currPath2 = R"(C:\Users\dinny\Desktop\for youtube\filesystem)";

    std::cout << currPath.string () << std::endl;
    std::cout << currPath2.string () << std::endl;

    //concat
    currPath = currPath / "newFolder" / "newNewFolder";

    std::cout << currPath.string () << std::endl;
    std::cout << currPath.parent_path().string () << std::endl;

    //create
    fs::create_directories (currPath);

    if (!fs::exists (currPath)) {
        std::cout << "does not exists\n";
    } else {
        std::cout << "does exists\n";
    }

    if (fs::is_directory (currPath)) {
        std::cout << "it's a directory\n";
    }

    fs::path sourcePath = fs::current_path () / "filesystem.cpp";
    fs::path outPath = currPath / "filesystemCopy.cpp";

    //copy
    if (!fs::exists (outPath))
        fs::copy (sourcePath,outPath);
    //move
    fs::rename (outPath, outPath.parent_path () / "renamed.cpp");

    //info
    std::cout << "info about: " << sourcePath.string () << std::endl;
    std::cout << sourcePath.stem () << " " << sourcePath.extension() <<  std::endl;
    std::cout << "size: " << fs::file_size (sourcePath) << std::endl;


    return 0;
}
