#include "../headers/functions.h"

int main(int argc, char const *argv[])
{
    cout << std::boolalpha << in_str("hello world how are you", "you");
    cout << index_of("h", "hello world how are you");
    return 0;
}