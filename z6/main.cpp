#include <iostream>
#include <string>
#include <cstdio>

#include "load.h"
#include "load_tests.h"

int main(int argc, char** argv)
{
    run_tests();

    if (argc != 3)
    {
        std::cout << "you must specify exactly two arguments: url and path!\n";
        exit(EXIT_FAILURE);
    }

    const std::string url = argv[1];
    const std::string path = argv[2];

    if(!is_path_exist(path))
    {
        std::cout << "File " << path << " does not exist";
        exit(EXIT_FAILURE);
    }

    auto result = load(url, path);

    if(result != LoadResult::SUCCESS)
    {
        switch (result)
        {
            case LoadResult::OPEN_FILE_FAILED:
                std::cerr << "Cannot open " << path << " for writing!\n";
                break;
            case LoadResult::DOWNLOAD_FILE_FAILED:
                std::cerr << "cannot download file from url!\n";
                break;
            case LoadResult::INITIALIZE_CURL_FAILED:
                std::cerr << "failed to initialize CURL!\n";
                break;
        }
        exit(EXIT_FAILURE);
    }

    return 0;
}
