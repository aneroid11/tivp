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

    try
    {
        const auto& iter = recursive_directory_iterator(path_to_dir);

        for (const auto& dir_entry : iter)
        {
            const std::string entry_str = dir_entry.path().string();

            if (entry_str.length() >= ext.length() + 1)
            {
                if (0 == entry_str.compare(entry_str.length() - ext.length() - 1, ext.length() + 1, "." + ext))
                {
                    std::cout << dir_entry << std::endl;
                }
            }
        }
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        std::cout << "no such directory!\n";
        exit(EXIT_FAILURE);
    }

    return 0;
}
