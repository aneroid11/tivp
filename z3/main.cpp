#include <iostream>
#include <limits>

int main()
{
//    std::cout << std::numeric_limits<int>::max() << "\n";
    double width, height;
    while (true)
    {
        std::cout << "enter width and height: ";

        if (!(std::cin >> width >> height) || width < 0 || height < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "incorrect input!\n";
            continue;
        }

        break;
    }

    std::cout << "Rectangle area = " << width * height << "\n";

    return 0;
}
