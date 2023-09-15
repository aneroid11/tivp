#include <iostream>
#include <string>
#include <list>
#include <limits>
#include <iomanip>
#include <sstream>
#include "test_runner.h"

struct Person
{
    std::string first_name, last_name;
    unsigned age = 0;
};

std::list<Person> read_people(std::ostream& out = std::cout, std::istream& in = std::cin)
{
    std::list<Person> people;
    do
    {
        out << "continue entering information? (y/n) ";
        std::string choice;
        in >> choice;

        if (choice == "y")
        {
            Person person;
            out << "enter the last name: ";
            in >> person.last_name;
            out << "enter the first name: ";
            in >> person.first_name;
            out << "enter the age: ";

            while (!(in >> person.age) || person.age < 1 || person.age > 150)
            {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                out << "incorrect age! please try again: ";
            }

            people.push_back(person);
        }
        else if (choice == "n")
        {
            break;
        }
        else
        {
            out << "enter y or n!\n";
        }
    } while (true);

    return people;
}

void print_result(const std::list<Person>& people, std::ostream& out = std::cout)
{
    unsigned max_age, min_age;
    max_age = min_age = people.cbegin()->age;

    unsigned total_age = 0;

    for (const Person& p : people)
    {
        out << p.last_name << " " << p.first_name << " " << p.age << "\n";

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

    out << min_age << " " << max_age << " "
    << std::fixed << std::setprecision(2)
    << static_cast<float>(total_age) / people.size() << "\n";
}

void test_read_people()
{
    std::stringstream in("y "
                         "Alex Alex 40 "
                         "y "
                         "Dima Mak 41 "
                         "n");

    std::stringstream out;

    read_people(out, in);

    std::string expected_out = "continue entering information? (y/n) "
                               "enter the last name: "
                               "enter the first name: "
                               "enter the age: "
                               "continue entering information? (y/n) "
                               "enter the last name: "
                               "enter the first name: "
                               "enter the age: "
                               "continue entering information? (y/n) ";

    std::string out_str = out.str();

    ASSERT(out_str == expected_out);
}

void test_print_result()
{
    std::list<Person> people = {
            Person{"Alex", "Alex", 40},
            Person{"Dima", "Mak", 20}
    };

    std::ostringstream out;
    print_result(people, out);

    std::string out_str = out.str();
    std::string expected_out = "Alex Alex 40\n"
                               "Mak Dima 20\n"
                               "20 40 30.00\n";

    ASSERT(out_str == expected_out);
}

void run_tests()
{
    TestRunner tr;
    RUN_TEST(tr, test_read_people);
    RUN_TEST(tr, test_print_result);
}

int main()
{
    run_tests();

    std::list<Person> people = read_people();
    print_result(people);



    return 0;
}
