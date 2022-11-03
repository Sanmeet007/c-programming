#include <iostream>
#include <vector>
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
    auto *li = new List<string>();
    li->length();
    li->push("hi");
    li->push("hi 1");
    li->push("hi 2");
    li->remove_at(1);
    li->push("h");
    li->print_values();
    return 0;
}