#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(nullptr));

    std::cout << "Hello, world!\n";
    std::cout << "Andhiagain!\n";

    int marks = rand() % 46 + 5;
    for (int i = 0; i < marks; i++)
    {
        std::cout << "!";
    }
    std::cout << "\n";

    return 0;
}
