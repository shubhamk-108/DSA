#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swap_flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
                swap_flag = true;
            }
        }
        if (swap_flag == false)
            break;
    }
}         

int main()
{
    int arr[] = {3,5,1,22,4};  
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);

    for(auto x: arr)
        cout<<x<<" ";
    return 0;
}

// time:
// Worst Case: O(n²) — If the array is sorted in reverse, every pair needs to be compared and swapped.
// Best Case: O(n) — If the array is already sorted, the swap_flag optimization allows the function to break after one pass.
// Average Case: O(n²).

// space 
// O(1) — Bubble Sort is an in-place sorting algorithm; it only uses a constant amount of extra space

// logic:

// Bubble Sort is a simple comparison-based sorting algorithm. It works by repeatedly stepping through the list, 
// comparing adjacent elements, and swapping them if they are in the wrong order. This process is repeated until the
//  array is sorted. After each pass, the largest unsorted element "bubbles up" to its correct position at the end of the array.


/*


void bubbleSort(int arr[], int n)
{
    // Loop for each pass through the array
    for (int i = 0; i < n - 1; i++)
    {
        bool swap_flag = false; // Tracks if any swap was performed in this pass
        
        // Compare adjacent elements in the unsorted portion of the array
        // n-1 because we dont need to do extra pass for last element because next element is already being checked using j[i+1] in
        // the same iteration
        // -i because the last element will already be sorted so no need to check that.
        for (int j = 0; j < n - 1 - i; j++)
        {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
                swap_flag = true; // A swap has occurred
            }
        }
        
        // If no swaps occurred, the array is already sorted, so exit early
        if (swap_flag == false)
            break;
    }
}



*/