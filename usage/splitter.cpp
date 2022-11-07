#include "../headers/functions.h"

int main(int argc, char const *argv[])
{
    List *arr = string_split("Hello world hello", ' ');
    arr->print_values();
    return 0;
}