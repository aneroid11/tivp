#include <sstream>
#include "test_find_files.h"
#include "find_files.h"
#include "test_runner.h"

namespace
{
    bool is_equal(const std::vector<std::string>& lhs, const std::vector<std::string>& rhs)
    {
        if(lhs.size() != rhs.size())
            return false;

        auto size = lhs.size();
        for(int i = 0; i < size; i++)
        {
            if(lhs[i] != rhs[i])
                return false;
        }

        return true;
    }
}

void test_get_extension_simple()
{
    std::string file = "hello.txt";
    auto result = get_extension(file);
    std::string expected_ext = ".txt";
    ASSERT(result == expected_ext);
}

void test_has_extension_simple()
{
    std::string file = "hello.txt";
    std::string ext = ".txt";
    auto result = has_extension(file, ext);

    ASSERT(result == true);
}

void test_has_extension_false()
{
    std::string file = "hello.txt";
    std::string ext = ".ru";
    auto result = has_extension(file, ext);

    ASSERT(result == false);
}

void test_get_all_files_recursive()
{
    auto path_to_dir = std::filesystem::current_path().parent_path();
    path_to_dir.append("TestData");
    path_to_dir.append("test_find_files_with_ext");
    std::string path = path_to_dir.generic_string();

    auto result = get_all_files_recursive(path);

    std::vector<std::string> expected_files = {
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/file_2_2.false",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2/file_3_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2/file_3_2.false",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/file_2_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/file_1_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/file_1_2.false"
    };

    ASSERT(is_equal(result, expected_files));
}

void test_find_files_with_ext()
{
    auto path_to_dir = std::filesystem::current_path().parent_path();
    path_to_dir.append("TestData");
    path_to_dir.append("test_find_files_with_ext");
    std::string path = path_to_dir.generic_string();
    std::string ext = ".true";

    auto result = find_files_with_ext(path, ext);

    std::vector<std::string> expected_files = {
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2/file_3_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/file_2_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/file_1_1.true",
    };

    ASSERT(is_equal(result, expected_files));
}

void test_find_files_with_unused_ext()
{
    auto path_to_dir = std::filesystem::current_path().parent_path();
    path_to_dir.append("TestData");
    path_to_dir.append("test_find_files_with_ext");
    std::string path = path_to_dir.generic_string();
    std::string ext = ".by";

    auto result = find_files_with_ext(path, ext);

    std::vector<std::string> expected_files = {};

    ASSERT(is_equal(result, expected_files));
}

void test_print_files()
{
    std::vector<std::string> files = {
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2/file_3_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/file_2_1.true",
            "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/file_1_1.true",
    };
    std::ostringstream out;

    print_files(files, out);

    auto result = out.str();
    std::string expected_result = "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/chiled_2/file_3_1.true\n"
                                  "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/child/file_2_1.true\n"
                                  "/home/matvey/Documents/EducationalMaterials/7sem/TiVP/lab1/tivp/z5/TestData/test_find_files_with_ext/file_1_1.true\n";
    ASSERT(result == expected_result);
}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_get_extension_simple);
    RUN_TEST(tr, test_has_extension_simple);
    RUN_TEST(tr, test_has_extension_false);
    RUN_TEST(tr, test_get_all_files_recursive);
    RUN_TEST(tr, test_find_files_with_ext);
    RUN_TEST(tr, test_find_files_with_unused_ext);
    RUN_TEST(tr, test_print_files);
}