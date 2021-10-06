#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DriverInformation
{
    char name[31]; // Maximum 30 characters
    char license_number[16]; // Maximum 15 characters
    char route[5]; // maximum 4 digits or string with 4 characters
    int kms;
} Driver;

void printDrivers(Driver driver[], int count)
{
    for (int i = 0; i <= count - 1; i++)
    {
        printf("\n");
        printf("Driver's name : %s \n", driver[i].name);
        printf("License Number : %s  \n", driver[i].route);
        printf("Route : %s \n", driver[i].license_number);
        printf("Kilometers : %d \n", driver[i].kms);
        printf("\n");
    }
}

int main()
{
    int number_of_drivers = 0;
    printf("Please enter total numbers of drivers : \n");
    scanf("%d", &number_of_drivers);
    int max_drivers = 3;
    Driver drivers[max_drivers];

    // Using scanf to take string input [ By this person can't enter his full name  eg. Sanmeet Singh ]

    /*

    // Uncomment for scanf 

    for (int i = 0; i < number_of_drivers; i++)
    {
        printf("\n");
        printf("Please enter your name \n");
        scanf("%s", &drivers[i].name);
        printf("Please enter your license number\n");
        scanf("%s", &drivers[i].license_number);
        printf("Please enter your route\n");
        scanf("%s", &drivers[i].route);
        printf("Please enter your car's kms reading\n");
        scanf("%d", &drivers[i].kms);
    }
*/

    //   Using gets to take user input [ String with full name !]

    for (int i = 0; i < number_of_drivers; i++)
    {
        printf("\n");
        printf("Please enter your name \n");
        gets(drivers[i].name); // Problem statement !
        printf("Please enter your license number\n");
        gets(drivers[i].license_number);
        printf("Please enter your route\n");
        gets(drivers[i].route);
        printf("Please enter your car's kms reading\n");
        scanf("%d", &drivers[i].kms);
    }

    printDrivers(drivers, number_of_drivers);

    getch();
    return 0;
}