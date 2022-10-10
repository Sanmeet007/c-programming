/*
**  Author : Sanmeet Singh
**  C library : next.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef _NEXT_H_
#define _NEXT_H_

#define true 1
#define false 0
#define Boolean(x) ((int)x != 0 ? true : false)
#define len(x) (sizeof x) / (sizeof(*x))

typedef char *string;

// Takes the input from the user
string input(const char *);
// Returns 1 (true) if the _str includes the sub_str or else  returns 0 (false)
int includes(string, string);
// Returns an array of indexes ( int ) all of the matching character in a _str
int *indices_of(string, char);
// Returns ocurrance (int) of a character in a _str
int char_frequency(string, char);
// Returns ocurrance (int) of a sub_str in a _str
int frequency(string, string);
// Returns a _str with replaced character (only once)
string replace_char(string, char, char);
// Returns a _str with all replaced characters
string replace_all_char(string, char, char);
// Returns first index (int) of character in a _str
int first_index_of_char(string, char);
// Returns last index (int) of character in a _str
int last_index_of_char(string, char);
// Check wether a charcter is an integer. eg : '1' is an integer char
int is_int(char);
//  Returns integer from a character. eg '1' will return 1 (int)
unsigned int charToInteger(char);
// Returns a sub_str or chunk of _str
string substr(string, int, int);
// Returns a _str with removed spaces from right side of a _str
string rtrim(string);
// Returns a _str with removed spaces from left side of a _str
string ltrim(string);
// Returns a _str with removed spaces
string trim(string);
// Returns a _str with replaced sub_str (once)
string replace(string, string, string);
// Returns a _str with all replaced sub_str
string replace_all(string, string, string);
// Returns an array of _strs with last index as a null character ('\0')
string *split(string, char);
// Prints an array of the _str with last index as a null character ('\0')
void print_r_str(string *);
// Returns current seconds (s) , minutes (m) or hours (h) based on the argument passed
int currentTime(char);
// Returns the index of the sub_str in a _str
int index_of(string, string);
// Returns the length of array of _strs
int str_arr_len(string *);
// Appends a _str to an array of _strs
void push_str(string *, string);
// Pops or deletes last element of array of _strs
void pop_str(string *);
// Deletes the index from an array of _strs using index
void del_str_by_index(string *, int);
// Deletes the index from an array of _strs using value
void del_str(string *, string);

int includes(string _str, string sub_str)
{
    return strstr(_str, sub_str) ? true : false;
}
string rtrim(string _str)
{
    string updatedStr = (string)malloc(sizeof(char) * (strlen(_str) + 1));
    string updatedStr2 = (string)malloc(sizeof(char) * (strlen(_str) + 1));
    int i = 0;
    int started = false;
    strcpy(updatedStr, _str);
    strrev(updatedStr);
    string str = ltrim(updatedStr);
    strcpy(updatedStr2, str);
    free(updatedStr);
    free(str);
    strrev(updatedStr2);
    return updatedStr2;
}
string ltrim(string _str)
{
    string updatedStr = (string)malloc(sizeof(char) * (strlen(_str) + 1));
    int i = 0;
    int started = false;
    while (*_str)
    {
        if (!isspace(*_str) || started)
        {
            started = true;
            updatedStr[i] = *_str++;
            i++;
        }
        else
        {
            *_str++;
        }
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
string trim(string _str)
{
    return rtrim(ltrim(_str));
}
int frequency(string _str, string sub_str)
{
    int count = 0;
    for (int i = 0; _str[i] != '\0'; i++)
    {
        if (strstr(&_str[i], sub_str) == &_str[i])
        {
            count++;
            // saving loop iteration by jumping to next index
            i += strlen(sub_str) - 1;
        }
    }
    return count;
}
int is_int(char ch)
{
    int isTrue = false;
    int i = 48;
    while (i <= 57)
    {
        if ((int)ch == i)
        {
            isTrue = true;
            break;
        }
        i++;
    }
    return isTrue;
}
unsigned int charToInteger(char ch)
{
    // returns from 0 => 9
    unsigned int integer = 0;
    int i = 48;
    int currentIntger = 0;
    while (i <= 57)
    {
        if ((int)ch == i)
        {
            integer = currentIntger;
            break;
        }
        currentIntger++;
        i++;
    }
    return integer;
}
string replace_char(string _str, char rchar, char withChar)
{
    string updatedStr = (string)malloc(sizeof(char) * (strlen(_str) + 1));
    int i = 0;
    short int once = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == rchar && once == 0)
        {
            updatedStr[i] = withChar;
            once++;
        }
        else
        {
            updatedStr[i] = _str[i];
        }
        i++;
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
string replace_all_char(string _str, char rchar, char withChar)
{
    string updatedStr = (string)malloc(sizeof(char) * (strlen(_str) + 1));
    int i = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == rchar)
        {
            updatedStr[i] = withChar;
        }
        else
        {
            updatedStr[i] = _str[i];
        }
        i++;
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
string replace(string _str, string sub_str, string with)
{
    string ptr = strstr(_str, sub_str);
    int startIndex = ptr - _str;
    int endIndex = ptr - _str + strlen(sub_str) - 1;
    string updated_str = (string)malloc(sizeof(char) * (strlen(_str) - strlen(sub_str) + 1));
    string str1 = substr(_str, 0, startIndex - 1);
    string str2 = substr(_str, endIndex + 1, strlen(_str));
    string concat1 = strcat(str1, with);
    string concat2 = strcat(concat1, str2);
    strcpy(updated_str, concat2);
    return updated_str;
}
string replace_all(string _str, string replaceStr, string withStr)
{
    int freq = frequency(_str, replaceStr);
    string updatedStr = (string)malloc(sizeof(char) * (strlen(_str) + freq * (strlen(replaceStr) - strlen(withStr)) + 1));
    int i = 0;
    while (*_str)
    {
        if (strstr(_str, replaceStr) == _str)
        {
            updatedStr[i] = '\0';
            strcat(updatedStr, withStr);
            i += strlen(withStr);
            _str += strlen(replaceStr);
        }
        else
        {
            updatedStr[i++] = *_str++;
        }
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
string substr(string _str, int from, int to)
{
    int lengthOf_str = to - from;
    string sub_str = (string)malloc(sizeof(char) * (lengthOf_str + 1));
    int i = from;
    int start = 0;
    while (i <= to)
    {
        *(sub_str + start) = _str[i];
        start++;
        i++;
    }
    *(sub_str + start) = '\0';
    return sub_str;
}
int last_index_of_char(char _str[], char ch)
{
    int index = 0;
    int i = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == ch)
        {
            index = i;
        }
        i++;
    }
    return index;
}
int first_index_of_char(char _str[], char ch)
{
    int index = -1;
    int i = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == ch)
        {
            index = i;
            break;
        }
        i++;
    }
    return index;
}
int *indices_of(char _str[], char ch)
{
    int indices = char_frequency(_str, ch);
    int *ptr = (int *)malloc(indices * sizeof(int));

    int i = 0;
    short int indexCounter = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == ch)
        {
            *(ptr + indexCounter) = i;
            indexCounter++;
        }
        i++;
    }
    *(ptr + indexCounter) = '\0';
    return ptr;
}
int char_frequency(char _str[], char ch)
{
    int indices = 0;
    int i = 0;
    while (i <= strlen(_str))
    {
        if (_str[i] == ch)
        {
            indices++;
        }
        i++;
    }
    return indices;
}
void print_r_str(string *array)
{
    int i = 0;
    printf("[");
    while (*(array + i))
    {
        printf("'%s',", array[i]);
        i++;
    }
    printf("'\\0']\n");
}
string *split(char _str[], char ch)
{
    string *ptr = (string *)malloc(sizeof(char) * strlen(_str) + 1);
    int *indices = indices_of(_str, ch);

    int startIndex = 0;
    int endIndex = indices[0];
    int i = 0;
    int counter = 0;
    while (_str[i] != '\0')
    {
        if (_str[i] == ch)
        {
            endIndex = i;
            ptr[counter] = substr(_str, startIndex, endIndex - 1);
            startIndex = i + 1;
            counter++;
        }
        i++;
    }

    startIndex = last_index_of_char(_str, ch) + 1;
    endIndex = strlen(_str);
    ptr[counter] = substr(_str, startIndex, endIndex - 1);
    ptr[++counter] = '\0';
    return ptr;
}
int currentTime(char type)
{
    int i = 0;
    string *splitdArray = split(__TIME__, ':');
    switch (type)
    {
    case 'h':
        i = atoi(splitdArray[0]);
        break;
    case 'm':
        i = atoi(splitdArray[1]);
        break;
    case 's':
        i = atoi(splitdArray[2]);
        break;

    default:
        i = 0;
    }
    free(splitdArray);
    return i;
}
int index_of(string _str, string sub_str)
{
    int i = 0;
    i = strstr(_str, sub_str) - _str;
    return i;
}
int str_arr_len(string *array)
{
    int i = 0;
    while (*array)
    {
        i++;
        *array++;
    }
    return i;
}
void push_str(string *array, string _str)
{
    int arrayLength = str_arr_len(array);
    *(array + arrayLength) = _str;
    array[++arrayLength] = '\0';
}
void pop_str(string *array)
{
    int length = str_arr_len(array);
    *(array + (--length)) = '\0';
}
void del_str_by_index(string *array, int index)
{
    int i = index;
    while (*(array + i))
    {
        *(array + i) = *(array + i + 1);
        i++;
    }
}
void del_str(string *array, string _str)
{
    int length = str_arr_len(array);
    int i = 0;
    int index = -1;
    while (i < length)
    {
        if (array[i] == _str)
        {
            index = i;
        }
        i++;
    }
    if (index != -1)
    {
        del_str_by_index(array, index);
    }
}

string input(const char *prompt)
{
    printf("%s", prompt);
    char *istring;
    fflush(stdin);
    scanf("%[^\n]s", istring);
    char *rstring = (char *)malloc(sizeof(char) * (strlen(istring) + 1));
    strcpy(rstring, istring);
    return rstring;
}

#endif
