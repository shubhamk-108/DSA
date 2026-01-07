// program to search in an infinite size array

#include <iostream>
using namespace std;

int searchedInInfiniteSizeArr(int arr[], int x)
{
    int i = 0;
    while (true)
    {
        if (arr[i] == x)
            return i;

        if (arr[i] > x)
            return -1;
        i++;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 5, 5};

    int x = 3;

    cout << searchedInInfiniteSizeArr(arr, x);

    return 0;
}

// time: O(position_of_element)
// space : O(1)