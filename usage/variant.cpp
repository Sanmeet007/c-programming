#include <iostream>
#include <variant>
#include <vector>
#include <array>
#include "../variant_list.h"

using std::cin;
using std::cout;
using std::string;

void eachCB(size_t current_index, vlt current_value)
{
    std::visit(overloaded{
                   [](string &value) {
                   },
                   [](int &value) {},
                   [](auto &value) {},
               },
               current_value);
}
bool filterCB(size_t index, vlt x)
{
    bool isCorrect = false;
    std::visit(overloaded{
                   [&isCorrect](string &value)
                   {
                       if (value == "Hi")
                       {
                           isCorrect = true;
                       }
                   },
                   [](int &value) {},
                   [](auto &value) {},
               },
               x);
    return isCorrect;
}

vlt mapCB(size_t index, vlt x)
{
    // Any value which vlt data type allows !
    return 10;
}

int main(int argc, char const *argv[])
{
    auto li = VariantList<vlt>();
    li.push("Hello");
    li.push("Hi");
    li.push('h');
    li.each(eachCB);
    li.filter(filterCB)->print_values();
    li.map(mapCB)->print_values();
    li.print_values();
    return 0;
}