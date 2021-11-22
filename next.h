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

// Returns 1 (true) if the string includes the substring or else  returns 0 (false)
int includes(char *string, char *substring);
// Returns an array of indexes ( int ) all of the matching character in a string
int *indicesOf(char string[], char ch);
// Returns ocurrance (int) of a character in a string
int charFrequency(char string[], char ch);
// Returns ocurrance (int) of a substring in a string
int frequency(char *string, char *substring);
// Returns a string with replaced character (only once)
char *replaceChar(char *string, char replaceChar, char withChar);
// Returns a string with all replaced characters
char *replaceAllChar(char *string, char replaceChar, char withChar);
// Prints array of integer ending with a null character ('\0')
void print_r_int(int *array);
// Returns first index (int) of character in a string
int firstIndexOfChar(char string[], char ch);
// Returns last index (int) of character in a string
int lastIndexOfChar(char string[], char ch);
// Check wether a charcter is an integer. eg : '1' is an integer char
int isInt(char ch);
//  Returns integer from a character. eg '1' will return 1 (int)
unsigned int charToInteger(char ch);
// Returns a substring or chunk of string
char *substr(char *string, int from, int to);
// Returns a string with removed spaces from right side of a string
char *rtrim(char *string);
// Returns a string with removed spaces from left side of a string
char *ltrim(char *string);
// Returns a string with removed spaces
char *trim(char *string);
// Returns a string with replaced substring (once)
char *replace(char *string, char *substring, char *with);
// Returns a string with all replaced substring
char *replaceAll(char *string, char *replaceStr, char *withStr);
// Returns an array of strings with last index as a null character ('\0')
char **explode(char string[], char ch);
// Prints an array of the string with last index as a null character ('\0')
void print_r_str(char **array);
// Returns current seconds (s) , minutes (m) or hours (h) based on the argument passed
int currentTime(char type);
// Returns the index of the substring in a string
int indexOf(char *string, char *substring);
// Returns the length of array of strings
int strArrLen(char **array);
// Appends a string to an array of strings
void push_str(char **array, char *string);
// Pops or deletes last element of array of strings
void pop_str(char **array);
// Deletes the index from an array of strings using index
void del_strByIndex(char **array, int index);
// Deletes the index from an array of strings using value
void del_str(char **array, char *string);

int includes(char *string, char *substring)
{
    return strstr(string, substring) ? true : false;
}
char *rtrim(char *string)
{
    char *updatedStr = malloc(sizeof(char) * (strlen(string) + 1));
    char *updatedStr2 = malloc(sizeof(char) * (strlen(string) + 1));
    int i = 0;
    int started = false;
    strcpy(updatedStr, string);
    strrev(updatedStr);
    char *str = ltrim(updatedStr);
    strcpy(updatedStr2, str);
    free(updatedStr);
    free(str);
    strrev(updatedStr2);
    return updatedStr2;
}
char *ltrim(char *string)
{
    char *updatedStr = malloc(sizeof(char) * (strlen(string) + 1));
    int i = 0;
    int started = false;
    while (*string)
    {
        if (!isspace(*string) || started)
        {
            started = true;
            updatedStr[i] = *string++;
            i++;
        }
        else
        {
            *string++;
        }
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
char *trim(char *string)
{
    return rtrim(ltrim(string));
}
int frequency(char *string, char *substring)
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (strstr(&string[i], substring) == &string[i])
        {
            count++;
            // saving loop iteration by jumping to next index
            i += strlen(substring) - 1;
        }
    }
    return count;
}
int isInt(char ch)
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
char *replaceChar(char *string, char replaceChar, char withChar)
{
    char *updatedStr = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    int i = 0;
    short int once = 0;
    while (i <= strlen(string))
    {
        if (string[i] == replaceChar && once == 0)
        {
            updatedStr[i] = withChar;
            once++;
        }
        else
        {
            updatedStr[i] = string[i];
        }
        i++;
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
char *replaceAllChar(char *string, char replaceChar, char withChar)
{
    char *updatedStr = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    int i = 0;
    while (i <= strlen(string))
    {
        if (string[i] == replaceChar)
        {
            updatedStr[i] = withChar;
        }
        else
        {
            updatedStr[i] = string[i];
        }
        i++;
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
char *replace(char *string, char *substring, char *with)
{
    char *ptr = strstr(string, substring);
    int startIndex = ptr - string;
    int endIndex = ptr - string + strlen(substring) - 1;
    char *updatedString = (char *)malloc(sizeof(char) * (strlen(string) - strlen(substring) + 1));
    char *str1 = substr(string, 0, startIndex - 1);
    char *str2 = substr(string, endIndex + 1, strlen(string));
    char *concat1 = strcat(str1, with);
    char *concat2 = strcat(concat1, str2);
    strcpy(updatedString, concat2);
    return updatedString;
}
char *replaceAll(char *string, char *replaceStr, char *withStr)
{
    int freq = frequency(string, replaceStr);
    char *updatedStr = (char *)malloc(sizeof(char) * (strlen(string) + freq * (strlen(replaceStr) - strlen(withStr)) + 1));
    int i = 0;
    while (*string)
    {
        if (strstr(string, replaceStr) == string)
        {
            updatedStr[i] = '\0';
            strcat(updatedStr, withStr);
            i += strlen(withStr);
            string += strlen(replaceStr);
        }
        else
        {
            updatedStr[i++] = *string++;
        }
    }
    updatedStr[i] = '\0';
    return updatedStr;
}
char *substr(char *string, int from, int to)
{
    int lengthOfString = to - from;
    char *subString = (char *)malloc(sizeof(char) * (lengthOfString + 1));
    int i = from;
    int start = 0;
    while (i <= to)
    {
        *(subString + start) = string[i];
        start++;
        i++;
    }
    *(subString + start) = '\0';
    return subString;
}
int lastIndexOfChar(char string[], char ch)
{
    int index = 0;
    int i = 0;
    while (i <= strlen(string))
    {
        if (string[i] == ch)
        {
            index = i;
        }
        i++;
    }
    return index;
}
int firstIndexOfChar(char string[], char ch)
{
    int index = -1;
    int i = 0;
    while (i <= strlen(string))
    {
        if (string[i] == ch)
        {
            index = i;
            break;
        }
        i++;
    }
    return index;
}
int *indicesOf(char string[], char ch)
{
    int indices = charFrequency(string, ch);
    int *ptr = (int *)malloc(indices * sizeof(int));

    int i = 0;
    short int indexCounter = 0;
    while (i <= strlen(string))
    {
        if (string[i] == ch)
        {
            *(ptr + indexCounter) = i;
            indexCounter++;
        }
        i++;
    }
    *(ptr + indexCounter) = '\0';
    return ptr;
}
int charFrequency(char string[], char ch)
{
    int indices = 0;
    int i = 0;
    while (i <= strlen(string))
    {
        if (string[i] == ch)
        {
            indices++;
        }
        i++;
    }
    return indices;
}
void print_r_str(char **array)
{
    int i = 0;
    while (*(array + i))
    {
        printf("%s\n", array[i]);
        i++;
    }
}
char **explode(char string[], char ch)
{
    char **ptr = (char **)malloc(sizeof(char) * strlen(string) + 1);
    int *indices = indicesOf(string, ch);

    int startIndex = 0;
    int endIndex = indices[0];
    int i = 0;
    int counter = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ch)
        {
            endIndex = i;
            ptr[counter] = substr(string, startIndex, endIndex - 1);
            startIndex = i + 1;
            counter++;
        }
        i++;
    }

    startIndex = lastIndexOfChar(string, ch) + 1;
    endIndex = strlen(string);
    ptr[counter] = substr(string, startIndex, endIndex - 1);
    ptr[++counter] = '\0';
    return ptr;
}
int currentTime(char type)
{
    int i = 0;
    char **explodedArray = explode(__TIME__, ':');
    switch (type)
    {
    case 'h':
        i = atoi(explodedArray[0]);
        break;
    case 'm':
        i = atoi(explodedArray[1]);
        break;
    case 's':
        i = atoi(explodedArray[2]);
        break;

    default:
        i = 0;
    }
    free(explodedArray);
    return i;
}
int indexOf(char *string, char *substring)
{
    int i = 0;
    i = strstr(string, substring) - string;
    return i;
}
int strArrLen(char **array)
{
    int i = 0;
    while (*array)
    {
        i++;
        *array++;
    }
    return i;
}
void push_str(char **array, char *string)
{
    int arrayLength = strArrLen(array);
    *(array + arrayLength) = string;
    array[++arrayLength] = '\0';
}
void pop_str(char **array)
{
    int length = strArrLen(array);
    *(array + (--length)) = '\0';
}
void del_strByIndex(char **array, int index)
{
    int i = index;
    while (*(array + i))
    {
        *(array + i) = *(array + i + 1);
        i++;
    }
}
void del_str(char **array, char *string)
{
    int length = strArrLen(array);
    int i = 0;
    int index = -1;
    while (i < length)
    {
        if (array[i] == string)
        {
            index = i;
        }
        i++;
    }
    if (index != -1)
    {
        del_strByIndex(array, index);
    }
}

#endif
