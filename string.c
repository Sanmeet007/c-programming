#include <stdlib.h>
#include <stdio.h>

char *reverse(char *);
int strlen(char *);
void strrev(char *);

int main()
{
    char str[] = "";
    printf("Enter any string : ");
    scanf("%[^\n]s", &str);
    strrev(str);
    printf("The reversed string is : %s", str);
    printf("\nThe original string was : %s", reverse(str));
    return 1;
}

int strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

// The Swapping method
void strrev(char *str)
{
    int i = 0, j = strlen(str) - 1, half = (int)(j / 2);
    char temp;
    while (j > half)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

//  Using heap :-) Dynamic memory
char *reverse(char *string)
{
    int length = strlen(string);
    int i = 0, j = length - 1;
    char *str = (char *)malloc(length * sizeof(char));
    while (j >= 0)
        str[i++] = string[j--];
    str[i] = '\0';
    return str;
}
