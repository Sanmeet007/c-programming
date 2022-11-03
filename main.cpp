#include <iostream>
#include "list.h"
#include "range.h"
#include "functions.h"

using std::cin;
using std::cout;
using std::string;

void handler(int index, string x)
{
    cout << index << x << std::endl;
}

int main(int argc, char const *argv[])
{
    auto li = List<string>();
    li.push("ONE");
    li.push("TWO");
    li.push("THREE");

    li.remove_at(1);
    li.insert_at(1, "TWO");

    li.pop();
    li.push("THREE");

    li.remove("ONE");
    li.prepend("ONE");

    li.update(0, "COOL ONE");

    li.each([](int index, string x)
            { cout << "INDEX " << index << " VALUE : " << x << std::endl; });

    li.map([](int index, string x)
           { return str_lower(x); })
        ->print_values();

    li.filter([](int index, string x)
              { return x == "TWO"; })
        ->print_values();

    li.slice(0, 1)->print_values();

    li.print_values();
    return 0;
}