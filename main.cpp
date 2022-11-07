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
    li.print_values();
    return 0;
}