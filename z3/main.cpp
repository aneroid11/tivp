#include <iostream>
#include <limits>
#include <sstream>
#include <tuple>
#include "test_runner.h"

struct Rectangle
{
    double width;
    double height;
};

Rectangle read_rectangle(std::ostream& out = std::cout, std::istream& in = std::cin)
{
    double width, height;
    while (true)
    {
        out << "enter width and height: ";

        if (!(in >> width >> height) || width < 0 || height < 0)
        {
            in.clear();
            in.ignore(std::numeric_limits<int>::max(), '\n');
            out << "incorrect input!\n";
            continue;
        }

        break;
    }

    return {width, height};
}

void print_result(const Rectangle& rect, std::ostream& out = std::cout)
{
    out << "Rectangle area = " << rect.width * rect.height << "\n";
}

void test_read_rectangle()
{
    std::stringstream in("20 40");
    std::stringstream out;

    Rectangle rect = read_rectangle(out, in);
    double expected_width = 20;
    double expected_height = 40;
    ASSERT(rect.width == expected_width);
    ASSERT(rect.height == expected_height);
}

void test_print_result()
{
    Rectangle rect{20, 40};
    std::stringstream out;

    print_result(rect, out);

    std::string out_str = out.str();
    std::string expected_out = "Rectangle area = 800\n";
    ASSERT(out_str == expected_out);
}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_read_rectangle);
    RUN_TEST(tr, test_print_result);
}

int main()
{
//    std::cout << std::numeric_limits<int>::max() << "\n";

    run_tests();

    auto rect = read_rectangle();
    print_result(rect);

    return 0;
}
