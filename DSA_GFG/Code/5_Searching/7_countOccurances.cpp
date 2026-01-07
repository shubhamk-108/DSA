// Count occurances in sorted array

#include <iostream>
using namespace std;


int indexOfFirstOccurance(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (x > arr[mid])
            low = mid + 1;

        else if (x < arr[mid])
            high = mid - 1;

        else // This means arr[mid] == x
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;

            else
                high = mid - 1;
        }
    }

    return -1;
}

int indexOfLastOccuranceInSortedArr(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (x > arr[mid])
            low = mid + 1;

        else if (x < arr[mid])
            high = mid - 1;

        else // This means arr[mid] == x
        {
            if (mid == high || arr[mid] != arr[mid + 1])
                return mid;

            else
                low = mid + 1;
        }
    }

    return -1;
}


int countOccurances(int arr[], int n, int x)
{

    int first = indexOfFirstOccurance(arr, n, x);

    if (first == -1)
    {
        return 0; // The count is zero.
    }
    
    int last = indexOfLastOccuranceInSortedArr(arr, n, x);

    return (last - first) + 1;
}

int main()
{

    int arr[] = {5, 10, 10, 10, 10}, n = 5;

    int x = 10;

    cout << countOccurances(arr, n, x);

    return 0;
}



// tiME:O(log n)
// Space: O(1)



// Logic:

// Index of first and last occurances code is written in previous files. Logic is there explaied.