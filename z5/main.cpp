#include <iostream>
#include <string>
#include <filesystem>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "please specify the directory AND the extension!\n";
        exit(EXIT_FAILURE);
    }

    std::string path_to_dir = argv[1];
    std::string ext = argv[2];

    for (const auto& dir_entry : recursive_directory_iterator(path_to_dir))
    {
        std::cout << dir_entry << std::endl;
    }

    std::cout << "find files with extension " << argv[2] << " in " << argv[1] << "\n";
    return 0;
}
