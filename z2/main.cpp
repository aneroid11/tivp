#include <iostream>
#include <string>
#include <list>
#include <limits>

struct Person
{
    std::string first_name, last_name;
    unsigned age = 0;
};

int main()
{
    std::list<Person> people;

    do
    {
        std::cout << "continue entering information? (y/n) ";
        std::string choice;
        std::cin >> choice;

        if (choice == "y")
        {
            Person person;
            std::cout << "enter the last name: ";
            std::cin >> person.last_name;
            std::cout << "enter the first name: ";
            std::cin >> person.first_name;
            std::cout << "enter the age: ";

            while (!(std::cin >> person.age) || person.age < 1 || person.age > 150)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "incorrect age! please try again: ";
            }

            people.push_back(person);
        }
        else if (choice == "n")
        {
            break;
        }
        else
        {
            std::cout << "enter y or n!\n";
        }
    } while (true);

    unsigned max_age, min_age;
    max_age = min_age = people.cbegin()->age;

    unsigned total_age = 0;

    for (const Person& p : people)
    {
        std::cout << p.last_name << " " << p.first_name << " " << p.age << "\n";

        total_age += p.age;

        if (max_age < p.age)
        {
            max_age = p.age;
        }
        if (min_age > p.age)
        {
            min_age = p.age;
        }
    }

    std::cout << min_age << " " << max_age << " " << static_cast<float>(total_age) / people.size() << "\n";

    return 0;
}
