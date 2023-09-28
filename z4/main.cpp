#include <iostream>
#include <fstream>
#include <iomanip>
#include "test_runner.h"

std::string int_to_2_digits_hex(const int num)
{
    std::stringstream stream;
    stream << std::setw(2) << std::setfill('0') << std::hex << num;
    std::string result(stream.str());
    return result;
}

void generate_html_table(std::ostream& out)
{
    out << "<!DOCTYPE html><html><head><title></title></head><body>\n";
    out << "<table>\n";

    // 256 rows
    for (int i = 255; i >= 0; i--)
    {
        out << "<tr>\n";

        std::string hex = int_to_2_digits_hex(i);

        for (int j = 0; j < 10; j++)
        {
            out << "<td bgcolor=\"" << hex << hex << hex << "\">&emsp;</td>";
        }
        out << "</tr>\n";
    }

    out << "</table>\n";
    out << "</body></html>\n";
}

void test_int_to_2_digits_hex()
{
    auto hex = int_to_2_digits_hex(20);
    std::string expected_hex = "14";
    ASSERT(hex == expected_hex);
}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_int_to_2_digits_hex);
}

int main()
{
    run_tests();

    std::ofstream fout("table.html");
    generate_html_table(fout);
    fout.close();
    return 0;
}
