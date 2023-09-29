#include "tests.h"
#include "test_runner.h"
#include "rgb.h"
#include "gradient_generator.h"
#include "html_table_generator.h"
#include <sstream>

void test_int_to_2_digits_hex()
{
    auto hex = int_to_2_digits_hex(20);
    std::string expected_hex = "14";
    ASSERT(hex == expected_hex);
}

void test_gradient_generator()
{
    GradientGenerator generator;
    for(int i = 255; i >= 0; i--)
    {
        ASSERT(generator.is_end() == false);
        auto rgb = generator.get();
        ASSERT(rgb.r == i);
        ASSERT(rgb.g == i);
        ASSERT(rgb.b == i);
    }

    ASSERT(generator.is_end() == true);
}

namespace
{
    class TestColorGenerator: public IColorGenerator
    {
    public:
        TestColorGenerator(int num_of_colors) :
            _counter(0), _num_of_colors(num_of_colors)
        {}

        RGB get() override
        {
            _counter++;
            return RGB{0, 0, 0};
        }

        bool is_end() const override
        {
            return _counter == _num_of_colors;
        }

    private:
        int _counter;
        int _num_of_colors;

    };
}

void test_generate_table()
{
    TestColorGenerator color_generator(3);
    HTMLTableGenerator table_generator(1, color_generator);
    std::ostringstream out;
    table_generator.generate(out);

    auto result = out.str();
    std::string expected = "<!DOCTYPE html><html><head><title></title></head><body>\n"
                           "<table>\n"
                           "<tr>\n"
                           "<td bgcolor=\"000000\">&emsp;</td></tr>\n"
                           "<tr>\n"
                           "<td bgcolor=\"000000\">&emsp;</td></tr>\n"
                           "<tr>\n"
                           "<td bgcolor=\"000000\">&emsp;</td></tr>\n"
                           "</table>\n"
                           "</body></html>\n";

    ASSERT(result == expected);
}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_int_to_2_digits_hex);
    RUN_TEST(tr, test_gradient_generator);
    RUN_TEST(tr, test_generate_table);


}