#include "../library/functions.h"

int main(int argc, char const *argv[])
{
    // For taking inputs
    string userInput = input("Enter a valid string  : ");
    cout << "The entered string was : " << userInput << std::endl;

    // For reading from the file
    string contents;
    file_get_contents("../text/para.txt", contents);
    cout << "The contents of file are : " << std::endl
         << contents << std::endl;

    // For writing to the file
    string str = "Some contents";
    cout << std::boolalpha << file_put_contents("../text/output.txt", str);

    return 0;
}