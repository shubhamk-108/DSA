#include <iostream>
#include <algorithm>
using namespace std;

void printTwoSortedArraysWhileMerging(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            cout << arr1[i]<<" ";
            i++;
        }
        else //arr2[j] > arr1[i]
        {
            cout << arr2[j]<<" ";
            j++;
        }
    }
    while(i<m)
    {
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<n)
    {
        cout<<arr2[j]<<" ";
        j++;
    }
}

int main()
{
    int arr1[] = {3,5,33,50};  
    int arr2[] = {14, 33, 60, 72, 80, 100};  
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    printTwoSortedArraysWhileMerging(arr1, arr2, m, n);

    
    return 0;
}

// time : O(m+n)
// space : O(1)

// logic



/*



 * @brief Merges two sorted arrays and prints the result to the console.
 * 
 * This function takes two arrays, arr1 and arr2, which are assumed to be
 * already sorted in non-decreasing order. It iterates through both arrays
 * simultaneously, printing the smaller of the two current elements at each step.
 * This process effectively merges them into a single, sorted output stream.
 * 
 * @param arr1 The first sorted array.
 * @param arr2 The second sorted array.
 * @param m The number of elements in arr1.
 * @param n The number of elements in arr2.

void printTwoSortedArraysWhileMerging(int arr1[], int arr2[], int m, int n)
{
    // Initialize pointers (indices) for the start of both arrays.
    // 'i' will track the current position in arr1.
    int i = 0; 
    // 'j' will track the current position in arr2.
    int j = 0; 

    // This is the main merge loop.
    // It continues as long as there are elements left to compare in BOTH arrays.
    while (i < m && j < n)
    {
        // Compare the current element of arr1 with the current element of arr2.
        if (arr1[i] <= arr2[j])
        {
            // If the element in arr1 is smaller or equal, print it.
            cout << arr1[i] << " ";
            // Move to the next element in arr1.
            i++;
        }
        else // This condition means arr2[j] < arr1[i]
        {
            // If the element in arr2 is smaller, print it.
            cout << arr2[j] << " ";
            // Move to the next element in arr2.
            j++;
        }
    }

    // After the main loop, one of the arrays might still have elements remaining.
    // The following loops handle these leftover elements.
    // Only one of these two 'while' loops will ever execute.

    // If there are any remaining elements in arr1, print them.
    // These elements are guaranteed to be larger than all elements printed so far.
    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }

    // If there are any remaining elements in arr2, print them.
    // These elements are also guaranteed to be larger than all elements printed so far.
    while (j < n)
    {
        cout << arr2[j] << " ";
        j++;
    }
}



*/