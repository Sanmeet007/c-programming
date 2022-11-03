#ifndef FUNCTIONS_HEADER_FILE
#define FUNCTIONS_HEADER_FILE

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <conio.h>

using std::cin;
using std::cout;
using std::getline;
using std::string;

// Returns input string
string input(string prompt)
{
    string inputStr;
    cout << prompt;
    fflush(stdin);
    getline(cin, inputStr);
    return inputStr;
}
// Returns input char
char input_char(string prompt)
{
    char inputChar;
    cout << prompt;
    fflush(stdin);
    inputChar = getch();
    return inputChar;
}

// Checks if file exists or not
bool file_exist(string name)
{
    std::ifstream file(name);
    return file ? true : false;
}

// Getting contents from the file
bool file_get_contents(string filepath, string &contents)
{
    try
    {
        if (file_exist(filepath))
        {
            string inputStr;
            std::fstream file;
            file.open(filepath, std::ios::in);
            getline(file, inputStr, '\r');
            file.close();
            contents = inputStr;
            return true;
        }
        else
            return false;
    }
    catch (std::exception E)
    {
        return false;
    }
}

// Writing contents to the file
bool file_put_contents(string filepath, string contents)
{
    try
    {
        string inputStr;
        std::fstream file;
        file.open(filepath, std::ios::out);
        file << contents;
        file.close();
        return true;
    }
    catch (std::exception E)
    {
        return false;
    }
}

// Returns true if the substring is found in str: string
bool in_str(string str, string substr)
{
    size_t found = str.find(substr);
    return (found != string::npos) ? true : false;
}

// Returns the index of the substr in string if not found then returns -1
signed int index_of(string substr, string str)
{
    signed int found = str.find(substr);
    return (found == string::npos) ? -1 : found;
}

// Returns frequency of substr in string or returns -1 if not found
signed int str_freq(string str, string substr)
{
    int occurrences = 0, pos = 0;
    while ((pos = str.find(substr, pos)) != string::npos)
    {
        ++occurrences;
        pos += substr.length();
    }

    return occurrences;
}

// Splits the string and returns a vector ... based on delimiter char
std::vector<string> string_split(string str, char delimiter)
{
    std::vector<string> splitted_string_vector;
    string sub;
    size_t found;
    while (true)
    {
        found = str.find(delimiter);
        if (found == string::npos)
        {
            splitted_string_vector.push_back(str);
            break;
        }
        else
        {
            sub = str.substr(0, found);
            str = str.substr(found + 1, str.size());
            splitted_string_vector.push_back(sub);
        }
    }
    return splitted_string_vector;
}

template <typename T>
void print(T str)
{
    cout << str << std::endl;
}
void cprint(char ch)
{
    cout << "'" << ch << "'";
}

void clearscr()
{
    system("cls");
}

bool isint(string str)
{
    for (char x : str)
    {
        if (!isdigit(x))
        {
            return false;
        }
    }
    return true;
}

#endif