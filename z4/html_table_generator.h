#pragma once

#include <iostream>
#include <string>
#include "icolor_generator.h"

class HTMLTableGenerator
{
public:
    HTMLTableGenerator(int elements_num, IColorGenerator& generator);

    void generate(std::ostream& out = std::cout);

private:
    int _elements_num;
    IColorGenerator& _generator;
};

std::string int_to_2_digits_hex(const int num);
