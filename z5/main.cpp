#include <iostream>
#include <string>
#include "find_files.h"
#include "test_find_files.h"


int main(int argc, char** argv)
{
    run_tests();

    if (argc != 3)
    {
        std::cout << "please specify the directory AND the extension!\n";
        exit(EXIT_FAILURE);
    }

    std::string path_to_dir = argv[1];
    std::string ext = argv[2];

    print_files(find_files_with_ext(path_to_dir, ext));

    return 0;
}
