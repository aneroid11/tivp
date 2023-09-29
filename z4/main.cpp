#include <iostream>
#include <fstream>
#include "html_table_generator.h"
#include "gradient_generator.h"
#include "tests.h"



int main()
{
    run_tests();

    constexpr int elements_num = 10;
    GradientGenerator gradient_generator;
    HTMLTableGenerator table_generator(elements_num, gradient_generator);

    std::ofstream fout("table.html");
    table_generator.generate(fout);
    fout.close();
    return 0;
}
