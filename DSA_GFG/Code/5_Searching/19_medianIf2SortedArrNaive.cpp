#include <iostream>
#include<algorithm>
using namespace std;

    double medianOf2SortedArr(int arr1[], int arr2[], int n1, int n2)
    {
        int temp[n1 + n2];

        int i = 0;

        for (i; i < n1; i++)
        {
            temp[i] = arr1[i];
        }
        for (int j = 0; j < n2; j++)
        {
            temp[i] = arr2[j];
            i++;
        }
        
        sort(temp, temp+(n1+n2));

        int n = n1+n2;

        if((n1+n2) % 2 == 0)
            return ((temp[n/2] + temp[(n/2)-1]) / 2.0);
        else
            return temp[n/2];
    }

    int main()
    {
        int arr1[] = {10, 20, 30, 40, 50};
        int arr2[] = {5, 15, 25, 35, 45};

        cout<<medianOf2SortedArr(arr1,arr2, 5,5);
        return 0;

    }


// Time Complexity: O((n1 + n2) log(n1 + n2)) due to the sorting step.
// Space Complexity: O(n1 + n2) for the temp array.


// logic

/*


double medianOf2SortedArr(int arr1[], int arr2[], int n1, int n2)
{
    // Declare a temporary array to hold all elements from both arr1 and arr2.
    // The size is the sum of the sizes of the two input arrays.
    int temp[n1 + n2];

    // Initialize an index for copying elements into the 'temp' array.
    // This variable will keep track of the current insertion point in 'temp'.
    int current_temp_idx = 0; // Renamed from 'i' for clarity, as 'i' is often used as a loop counter.

    // Loop through the first array (arr1) and copy its elements into 'temp'.
    // 'k' is the loop counter for arr1.
    for (int k = 0; k < n1; k++) // Changed loop variable from 'i' to 'k' for better readability
    {
        temp[current_temp_idx] = arr1[k]; // Copy element from arr1 to temp
        current_temp_idx++;               // Move to the next available position in temp
    }

    // Loop through the second array (arr2) and copy its elements into 'temp'.
    // These elements are appended after the elements copied from arr1.
    // 'j' is the loop counter for arr2.
    for (int j = 0; j < n2; j++)
    {
        temp[current_temp_idx] = arr2[j]; // Copy element from arr2 to temp
        current_temp_idx++;               // Move to the next available position in temp
    }

    // Sort the entire 'temp' array, which now contains all elements from arr1 and arr2.
    // std::sort is an efficient sorting algorithm (typically Introsort).
    // It takes two iterators: 'temp' points to the beginning of the array,
    // and 'temp + (n1 + n2)' points one element past the end of the array, defining the range to be sorted.
    std::sort(temp, temp + (n1 + n2));

    // Calculate the total number of elements in the combined sorted array.
    int n = n1 + n2;

    // Determine the median based on whether the total number of elements (n) is even or odd.
    if (n % 2 == 0) // If 'n' is even (e.g., 4, 6, 8 elements)
    {
        // For an even number of elements, the median is the average of the two middle elements.
        // Example: For n=6, elements are at indices 0,1,2,3,4,5.
        // The middle two elements are at indices n/2 - 1 (index 2) and n/2 (index 3).
        // The division by 2.0 ensures floating-point division, returning a double result.
        return (static_cast<double>(temp[n / 2 - 1] + temp[n / 2]) / 2.0);
    }
    else // If 'n' is odd (e.g., 3, 5, 7 elements)
    {
        // For an odd number of elements, the median is the single middle element.
        // Example: For n=5, elements are at indices 0,1,2,3,4.
        // The middle element is at index n/2 (index 2, as integer division truncates).
        return temp[n / 2];
    }
}


*/
