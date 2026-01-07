// This algo is also called dutch nathional flag algo

// you need to segregate an array of elements containing three types of elements. The types are:

// Sort an array of 0s, 1s, 2s.
// Three-way partitioning when multiple occurrences of a pivot may exist.
// Partitioning around a range.

// Sort an array of 0s, 1s, 2s.
// ip: {0,1,0,2,1,2}
// op: {0,0,1,1,2,2}

// Three-way partitioning when multiple occurrences of a pivot may exist.
// ip: {2,1,2,20,10,20,1}, pivot : 2
// op: {1,1,2,2,20,10,20}

// Partitioning around a range.
// ip: {10,5,6,3,20,9,40}, range :[5,10]
// op: {3,5,6,9,10,20,40}: All the elements less than 5 should be on left side and then elements between 5 to 10 and all elements
// greater than 10 should be on the right side of 10.

#include <bits/stdc++.h>
using namespace std;

void sortArrOfZerosOnesTwos(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else //if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
            
    }
}

int main()
{

    int arr[] = {0, 1, 1, 2, 0, 1, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortArrOfZerosOnesTwos(arr, n);

    for (int x : arr)
        cout << x << " ";
}


// time : O(n)
// space : O(1)


// logic

/*

// Function to sort an array of 0s, 1s, and 2s using Dutch National Flag Algorithm
void sortArrOfZerosOnesTwos(int arr[], int n)
{
    int low = 0;        // points to the next position of 0
    int mid = 0;        // current element being checked
    int high = n - 1;   // points to the next position of 2

    // Traverse the array until mid crosses high
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap 0 into the beginning section
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            // Leave 1 in the middle section
            mid++;
        }
        else // arr[mid] == 2
        {
            // Swap 2 into the end section
            swap(arr[mid], arr[high]);
            high--;
            // do not increment mid here, because the swapped element may be 0/1/2
        }
    }
}

*/