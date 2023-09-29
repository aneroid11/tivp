#include "html_table_generator.h"
#include <iostream>
#include <iomanip>

std::string int_to_2_digits_hex(const int num)
{
    std::stringstream stream;
    stream << std::setw(2) << std::setfill('0') << std::hex << num;
    std::string result(stream.str());
    return result;
}

HTMLTableGenerator::HTMLTableGenerator(int elements_num, IColorGenerator &generator) :
    _elements_num(elements_num), _generator(generator)
{}

void HTMLTableGenerator::generate(std::ostream &out)
{
    out << "<!DOCTYPE html><html><head><title></title></head><body>\n";
    out << "<table>\n";

    while(!_generator.is_end())
    {
        out << "<tr>\n";

        auto rgb = _generator.get();
        std::string r = int_to_2_digits_hex(rgb.r);
        std::string g = int_to_2_digits_hex(rgb.g);
        std::string b = int_to_2_digits_hex(rgb.b);

        for (int j = 0; j < _elements_num; j++)
        {
            out << "<td bgcolor=\"" << r << g << b << "\">&emsp;</td>";
        }
        out << "</tr>\n";
    }


    out << "</table>\n";
    out << "</body></html>\n";
}


