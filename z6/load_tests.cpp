#include "load_tests.h"
#include "load.h"
#include "test_runner.h"
#include "fstream"

#include <filesystem>
#include <cstring>

namespace
{
    bool compare_files(const std::string& lhs, const std::string& rhs) {
        const std::size_t bufferSize = 4096;

        std::ifstream lhs_file(lhs, std::ios::binary);
        std::ifstream rhs_file(rhs, std::ios::binary);

        if (!lhs_file.is_open() || !rhs_file.is_open()) {
            std::cerr << "Ошибка при открытии файлов." << std::endl;
            return false;
        }

        char lhs_buffer[bufferSize];
        char rhs_buffer[bufferSize];

        do {
            lhs_file.read(lhs_buffer, bufferSize);
            const std::streamsize lhs_bytes_read = lhs_file.gcount();
            rhs_file.read(rhs_buffer, bufferSize);
            const std::streamsize rhs_bytes_read = rhs_file.gcount();

            if (lhs_bytes_read != rhs_bytes_read || std::memcmp(lhs_buffer, rhs_buffer, lhs_bytes_read) != 0) {
                return false;
            }
        } while (!lhs_file.eof() && !rhs_file.eof());

        if (lhs_file.eof() != rhs_file.eof()) {
            return false;
        }

        return true;
    }
}

void test_is_path_exist_empty_path()
{
    std::string path = "";
    bool result = is_path_exist(path);
    ASSERT(result == false);
}

void test_is_path_exist_true()
{
    auto path_to_file = std::filesystem::current_path().parent_path();
    path_to_file.append("TestData");
    path_to_file.append("test_is_path_exist_true");
    path_to_file.append("file");
    std::string path = path_to_file.generic_string();

    bool result = is_path_exist(path);
    ASSERT(result == true);
}

void test_is_path_exist_not_path()
{
    std::string path = "Hello world";

    bool result = is_path_exist(path);
    ASSERT(result == false);
}

void test_load_incorrect_url()
{
    auto path_to_test_dir = std::filesystem::current_path().parent_path();
    path_to_test_dir.append("TestData");
    path_to_test_dir.append("test_load_local_file");

    std::string url = "Hello world";

    auto path_to_write_file = path_to_test_dir;
    path_to_write_file.append("write_file");
    std::string file_to_write = path_to_write_file.generic_string();

    auto result = load(url, file_to_write);

    ASSERT(result == LoadResult::DOWNLOAD_FILE_FAILED);
}

void test_load_local_file()
{
    auto path_to_test_dir = std::filesystem::current_path().parent_path();
    path_to_test_dir.append("TestData");
    path_to_test_dir.append("test_load_local_file");

    auto path_to_read_file = path_to_test_dir;
    path_to_read_file.append("file");
    std::string url = "file://" + path_to_read_file.generic_string();

    auto path_to_write_file = path_to_test_dir;
    path_to_write_file.append("write_file");
    std::string file_to_write = path_to_write_file.generic_string();

    auto result = load(url, file_to_write);

    ASSERT(result == LoadResult::SUCCESS);
    ASSERT(compare_files(path_to_read_file.generic_string(), file_to_write) == true);

}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_is_path_exist_empty_path);
    RUN_TEST(tr, test_is_path_exist_true);
    RUN_TEST(tr, test_is_path_exist_not_path);
    RUN_TEST(tr, test_load_incorrect_url);
    RUN_TEST(tr, test_load_local_file);
}