#include <iostream>
#include <fstream>
#include <iomanip>

std::string int_to_2_digits_hex(const int num)
{
    std::stringstream stream;
    stream << std::setw(2) << std::setfill('0') << std::hex << num;
    std::string result(stream.str());
    return result;
}

int main()
{
    std::ofstream fout("table.html");
    fout << "<!DOCTYPE html><html><head><title></title></head><body>\n";
    fout << "<table>\n";

    // 256 rows
    for (int i = 255; i >= 0; i--)
    {
        fout << "<tr>\n";

        std::string hex = int_to_2_digits_hex(i);

        for (int j = 0; j < 10; j++)
        {
            fout << "<td bgcolor=\"" << hex << hex << hex << "\">&emsp;</td>";
        }
        fout << "</tr>\n";
    }

    fout << "</table>\n";
    fout << "</body></html>\n";
    fout.close();
    return 0;
}
