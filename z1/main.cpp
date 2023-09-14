#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "test_runner.h"

void print_hello_world(std::ostream& out)
{
    srand(time(nullptr));

    out << "Hello, world!\n";
    out << "Andhiagain!\n";

    int marks = rand() % 46 + 5;
    for (int i = 0; i < marks; i++)
    {
        out << "!";
    }
    out << "\n";
}

void test_print_hello_world()
{
    std::stringstream ss;
    print_hello_world(ss);

    std::string first_line, second_line, third_line;
    getline(ss, first_line);
    getline(ss, second_line);
    getline(ss, third_line);
    int num_of_exclamation_mark = std::count(third_line.cbegin(), third_line.cend(), '!');
    ss.get();

    ASSERT(ss.eof())
    ASSERT(first_line == "Hello, world!");
    ASSERT(second_line == "Andhiagain!");
    ASSERT(num_of_exclamation_mark == third_line.size())
    ASSERT(5 <= num_of_exclamation_mark);
    ASSERT(num_of_exclamation_mark <= 50);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, test_print_hello_world);

    print_hello_world(std::cout);

    return 0;
}
