#include "../next.h"

int binary_search(int arr[], int ele, int size)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == ele)
            return mid;
        if (arr[mid] < ele)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string user_name = input("Enter user name : ");
    string *arr = split(user_name, ' ');
    return 0;
}